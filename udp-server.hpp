#ifndef UDP_SERVER_HPP
#define UDP_SERVER_HPP

#include <arpa/inet.h>   // htons, inet_addr
#include <cstring>
#include <stdio.h>
#include <string>
#include <sys/socket.h>   // socket, sendto
#include <sys/types.h>    // uint16_t
#include <unistd.h>       // close

class UdpServer {
private:
  int sockfd;
  struct sockaddr_in clientAddr;

public:
  bool start(unsigned short port);
  void stop();

  bool send(char outgoing);
  char receive();
};

#endif