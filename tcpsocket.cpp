#include "tcpsocket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

TCPSocket::TCPSocket()
{
    fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_ < 0)
    {
        abort();
    }
}
TCPSocket::TCPSocket(int fd)
{
    fd_ = fd;
}

TCPSocket::~TCPSocket()
{
    close(fd_);
}

bool TCPSocket::bind(const std::string &host, int port)
{
    struct sockaddr_in servaddr;
    inet_pton(AF_INET, host.c_str(), &(servaddr.sin_addr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    int r = ::bind(fd_,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(r < 0)
    {
        perror("bind");
        return false;
    }
    return true;
}

bool TCPSocket::listen()
{
    if(::listen(fd_,10) < 0)
    {
        perror("listen");
        return false;
    }
    return true;
}

TCPSocket *TCPSocket::accept()
{
    struct sockaddr_in clientaddr;
    socklen_t clientaddrlen = sizeof(clientaddr);
    int clientfd = ::accept(fd_,(struct sockaddr *)&clientaddr,&clientaddrlen);
    if(clientfd < 0)
    {
        return NULL;
    }
    else
    {
        return new TCPSocket(clientfd);
    }
}

int TCPSocket::read(char *buff, size_t size)
{
    return ::read(fd_, buff, size);
}

int TCPSocket::write(const char *data, size_t len)
{
	return ::write(fd_, data, len);
}

void TCPSocket::setReuseAddr(bool b)
{
    int value = b;
    setsockopt(fd_,SOL_SOCKET, SO_REUSEADDR, &value, sizeof(int));
}
