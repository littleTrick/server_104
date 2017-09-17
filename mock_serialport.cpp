#include "mock_serialport.h"
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

MockSerialPort::~MockSerialPort()
{
    Close();
}

bool MockSerialPort::Open()
{
    return true;
}

int MockSerialPort::Read(char *buff, int size)
{
    return read(fd_,buff,size);
}

int MockSerialPort::Write(const char *buff, int size)
{
    char output[1024];
    char *p = output;
    char *e = p + sizeof(output);
    p += snprintf(p, e-p, "[^^^^]");
    for (int i = 0; i < size; i++) {
        p += snprintf(p, e-p, "%02X", buff[i]);
    }
    p += snprintf(p, e-p, "<EOF>");
    printf("%s\n", output);

    return e - p;
}

void MockSerialPort::Close()
{

}

bool MockSerialPort::SetSpeed(int speed)
{
    (void)speed;
    return true;
}

bool MockSerialPort::SetParity(bool parity)
{
    (void)parity;
    return true;
}

