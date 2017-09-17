#ifndef MOCK_SERIALPORT_H
#define MOCK_SERIALPORT_H

#include <stdio.h>
#include <string>

class MockSerialPort
{
public:
    MockSerialPort(int fd) : fd_(fd) {
    }
    ~MockSerialPort();

    bool Open();
    void Close();

    // DEFAULT: 9600
    bool SetSpeed(int speed);
    // DEFAULT: false
    bool SetParity(bool parity);

    // Return bytes of read, -1 on error
    int Read(char *buff, int size);
    // Return 0 on success, otherwise -1
    int Write(const char *buff,int size);

    int fd() const{
        return fd_;
    }

    std::string name() const {
        return "mock_serial_port";
    }

private:
    // disable copy and assignment
    MockSerialPort(const MockSerialPort &);
    void operator=(const MockSerialPort &);

    const static int kDefaultSpeed = 9600;

    int fd_;
};

#endif
