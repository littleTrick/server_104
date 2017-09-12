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
void SerialPort::SetSerialAttribs(int speed, int parity)
{
    struct termios ttyS;
    memset(&ttyS,0,sizeof(ttyS)); //set 0 to every bit of ttyS
    if(tcgetattr(fd_,&ttyS) != 0)
    {
        printf("errors%d from tcgetattr",errno);
    }

    /**set baud rate of read and write**/
    cfsetispeed(&ttyS,speed);
    cfsetospeed(&ttyS,speed);

    /****set data bit*********/
    ttyS.c_cflag &= ~CSIZE; //shielding data bit
    ttyS.c_cflag |= CS8;    //data bit is 8

    ttyS.c_cflag &= ~CSTOPB; //stop bit is 1
    ttyS.c_cflag &= ~(PARENB|PARODD); //no parity
    ttyS.c_cflag |= parity;
    ttyS.c_cflag &= ~CRTSCTS; //close harware control flow

    ttyS.c_iflag &= ~IGNBRK; //disable break processing
    ttyS.c_lflag = 0;        //disable local mode

    ttyS.c_oflag = 0;         //disable output mode
    ttyS.c_cc[VMIN] = 0;      //read dosn't block
    ttyS.c_cc[VTIME] = 5;     //0.5s time out

    ttyS.c_iflag &= ~(IXON | IXOFF | IXANY); //close flow control

    ttyS.c_cflag |= (CLOCAL | CREAD); //ignore mode control

    tcflush(fd_,TCIOFLUSH);   //clear io data of curent

    if(tcsetattr(fd_,TCSANOW,&ttyS) != 0)  //save the settings
    {
        printf("error%d from tcsetattr",errno );
    }

}

/*-------------------------------------------------
 *function name:SetBlock
 *parameter:0 should not Block,1 should Block
 *describe:user select should block or not
 -------------------------------------------------*/
void SerialPort::SetBlocking(int shouldBlock)
{
    struct termios tty;
    memset(&tty,0,sizeof(tty));
    if(tcgetattr(fd_,&tty) != 0)
    {
        printf("error%d from tggetattr",errno);
    }

    tty.c_cc[VMIN] = shouldBlock?1:0;
    tty.c_cc[VTIME] = 5;

    if(tcsetattr(fd_,TCSANOW,&tty) != 0)
    {
        printf("error%d setting term attributes",errno);
    }
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
    int writeNum = write(fd_,buff,size);
    if(writeNum != -1)
    {
        printf("write data to serial successfully ! and the number is :%d \n",writeNum);
    }
    else
    {
        printf("falied to write data to serial ! and the number is :%d \n",writeNum);
    }
    return writeNum;
}

void SerialPort::closePort()
{
    close(fd_);

}
