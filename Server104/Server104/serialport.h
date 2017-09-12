#ifndef SERIALPORT_H
#define SERIALPORT_H

class SerialPort
{
public:
    SerialPort();
    int serialData_;

    void SetSerialAttribs(int speed, int parity);
    void SetBlocking(int shouldBlock);
    bool openPort(const char *portName);
    int readPort(char buff[],int size);
    int writePort(char buff[],int size);
    void closePort();

private:
    int fd_;
};

#endif // SERIALPORT_H
