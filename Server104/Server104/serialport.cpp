#include "serialport.h"
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

SerialPort::SerialPort()
{
}

/*-----------------------------------------------
 *function name: SetSerialAttribs
 *parameter: baud rate,parity
 *describe: set serial basic infomation
 ----------------------------------------------*/
int SerialPort::SetSerialAttribs(int speed, int parity)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd_, &tty) != 0)
    {
        printf("error %d from tcgetattr", errno);
        return -1;
    }

    cfsetospeed (&tty, speed);
    cfsetispeed (&tty, speed);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    tty.c_lflag = 0;                // no signaling chars, no echo,
    // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 1;            // read doesn't block
    tty.c_cc[VTIME] = 50;            // 0.5 seconds read timeout
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr (fd_, TCSANOW, &tty) != 0)
    {
        printf ("error %d from tcsetattr", errno);
        return -1;
    }
    return 0;
}


bool SerialPort::openPort(const char *portName)
{

    fd_ = open(portName,O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd_ == -1)
    {
        printf("failed to open serialport,error%d open %s:%s",errno,portName,strerror(errno));
        return false;
    }
    return true;
}

/*-------------------------------------------------
 *function name:read
 *parameter:char buff[], int size
 *describe:read serial data
 -------------------------------------------------*/
int SerialPort::readPort(unsigned char buff[], int size)
{
    return read(fd_,buff,size);
}

/*-------------------------------------------------
 *function name:writePort
 *parameter:char buff[], int size
 *describe:write serial data
 -------------------------------------------------*/
int SerialPort::writePort(char buff[], int size)
{
    return write(fd_,buff,size);
}

void SerialPort::closePort()
{
    close(fd_);

}
