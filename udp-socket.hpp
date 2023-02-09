#ifndef UDP_SOCKET_HPP
#define UDP_SOCKET_HPP

#include <string>
#include <netinet/in.h> // sockaddr_in

class UdpSocket
{
private:
    int socketId;
    sockaddr_in destination;

public:
    void Connect(std::string address, unsigned short port);
    void Disconnect();

    int SendString(std::string message);
    bool TryRecvString(std::string &message);
};

#endif