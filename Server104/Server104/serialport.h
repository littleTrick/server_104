#ifndef SERIALPORT_H
#define SERIALPORT_H

class SerialPort
{
public:
    SerialPort();
    int fd_;

    void SetSerialAttribs(int speed, int parity);
    void SetBlocking(int shouldBlock);
    bool openPort(const char *portName);
    int readPort(unsigned char buff[], int size);
    int writePort(char buff[],int size);
    void closePort();
};

#endif // SERIALPORT_H
