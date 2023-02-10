#ifndef UDP_CLIENT_HPP
#define UDP_CLIENT_HPP

class UdpClient
{
public:
    void start(unsigned short port, string ipAddress);
    void stop();
    bool sendTo();
    bool recieve();
}

#endif