
#include <iostream>
#include "udp-socket.hpp"

int main()
{
    UdpSocket socket1;
    socket1.Connect("127.0.0.1", 22023);

    UdpSocket socket2;
    socket2.Connect("127.0.0.1", 22023);

    std::cout << socket1.SendString("3") << std::endl;

    std::string msg;
    socket2.TryRecvString(msg);

    std::cout << msg << std::endl;

    socket2.Disconnect();
    socket1.Disconnect();

    return 0;
}
