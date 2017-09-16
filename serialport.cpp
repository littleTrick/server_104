#include "serialport.h"
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

SerialPort::~SerialPort()
{
	Close();
}

bool SerialPort::Open()
{
	if (fd_ >= 0) {
		printf("%s alreay opened\n", name_.c_str());
		return false;
	}

    fd_ = open(name_.c_str(), O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd_ == -1)
    {
        printf("Failed to open %s: %s\n", name_.c_str(), strerror(errno));
        return false;
    }

	// set default properties
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd_, &tty) != 0)
    {
        printf("tcgetattr error: %s\n", strerror(errno));
		return false;
    }

    cfsetospeed (&tty, kDefaultSpeed);
    cfsetispeed (&tty, kDefaultSpeed);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    tty.c_iflag &= ~ICRNL;          //close the 0D mapping to 0A
    tty.c_iflag &= ~INLCR;          //close the 0A mapping to 0D
    tty.c_lflag = 0;                // no signaling chars, no echo,
    // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 1;            // block model
    tty.c_cc[VTIME] = 0;            // no timeout
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= 0; // no parity by default
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr (fd_, TCSANOW, &tty) != 0)
    {
        printf ("tcsetattr error: %s\n", strerror(errno));
		return false;
    }
	return true;
}

int SerialPort::Read(char *buff, int size)
{
    return read(fd_,buff,size);
}

int SerialPort::Write(const char *buff, int size)
{
    return write(fd_,buff,size);
}

void SerialPort::Close()
{
	if (fd_ >= 0) {
		printf("closing %s\n", name_.c_str());
    	close(fd_);
	}
}

bool SerialPort::SetSpeed(int speed)
{
    struct termios tty;
    if (tcgetattr (fd_, &tty) != 0)
    {
        printf("error %d from tcgetattr", errno);
		return false;
    }

    cfsetospeed (&tty, speed);
    cfsetispeed (&tty, speed);

    if (tcsetattr (fd_, TCSANOW, &tty) != 0)
    {
        printf ("error %d from tcsetattr", errno);
		return false;
    }
	return true;
}

bool SerialPort::SetParity(bool parity)
{
    struct termios tty;
    if (tcgetattr (fd_, &tty) != 0)
    {
        printf("error %d from tcgetattr", errno);
		return false;
    }

    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= (parity ? 1 : 0);

    if (tcsetattr (fd_, TCSANOW, &tty) != 0)
    {
        printf ("error %d from tcsetattr", errno);
		return false;
    }
	return true;
}

