#include "udp-server.hpp"

#include <arpa/inet.h>  // htons, inet_addr
#include <sys/types.h>  // uint16_t
#include <sys/socket.h> // socket, sendto
#include <unistd.h>     // close

bool UdpServer::start(unsigned short port)
{
    socket = socket(AF_INET, SOCK_DGRAM, 0);

    destination.sin_family = AF_INET;
    destination.sin_port = htons(port);
    destination.sin_addr.s_addr = inet_addr(address.c_str());
}

void UdpServer::stop()
{
}

bool UdpServer::sendTo()
{
}

bool UdpServer::stop()
{
}