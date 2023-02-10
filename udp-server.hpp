#ifndef UDP_SERVER_HPP
#define UDP_SERVER_HPP

#include <string>

class UdpServer
{
private:
    int socket;

public:
    void start(unsigned short port);
    void stop();

    bool sendTo();
    std::string receive();
};

#endif