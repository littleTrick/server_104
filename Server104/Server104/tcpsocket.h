#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <string>

class TCPSocket
{
public:
    TCPSocket();
    TCPSocket(int);
    ~TCPSocket();

    bool bind(const std::string &host, int port);
    bool listen();
    TCPSocket *accept();
    int read(unsigned char *buff, size_t size);

    void setReuseAddr(bool b);
    int fd()const
    {
        return fd_;
    }
private:
    int fd_;
};

#endif // TCPSOCKET_H
