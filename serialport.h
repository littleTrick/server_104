#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <string>

class SerialPort
{
public:
    SerialPort(const char *name) : name_(name), fd_(-1) {
    }
    SerialPort(const std::string &name) : name_(name), fd_(-1) {
    }
    ~SerialPort();

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

    const std::string &name() const {
        return name_;
    }
private:
    // disable copy and assignment
    SerialPort(const SerialPort &);
    void operator=(const SerialPort &);

    const static int kDefaultSpeed = 9600;

    std::string name_;
    int fd_;
};

#endif // SERIALPORT_H
