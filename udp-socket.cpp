#include "udp-socket.hpp"
#include <iostream>
#include <string>

#include <arpa/inet.h>  // htons, inet_addr
#include <sys/types.h>  // uint16_t
#include <sys/socket.h> // socket, sendto
#include <unistd.h>     // close

// Source:
// https://stackoverflow.com/a/69445616

void UdpSocket::Connect(std::string address, unsigned short port)
{
    socketId = socket(AF_INET, SOCK_DGRAM, 0);

    std::cout << socketId << std::endl;

    destination.sin_family = AF_INET;
    destination.sin_port = htons(port);
    destination.sin_addr.s_addr = inet_addr(address.c_str());
    bind(socketId, )
}

void UdpSocket::Disconnect()
{
    close(socketId);
}

int UdpSocket::SendString(std::string message)
{
    if (message.length() != 1)
    {
        return -1;
    }
    return sendto(socketId, message.c_str(), message.length(), 0, reinterpret_cast<sockaddr *>(&destination), sizeof(destination));
}

bool UdpSocket::TryRecvString(std::string &message)
{
    char buffer[1];

    if (recv(socketId, buffer, sizeof(buffer), 0) < 0)
    {
        return false;
    }

    message = buffer[0];
    return true;
}