#ifndef UDP_CLIENT_HPP
#define UDP_CLIENT_HPP

#include <arpa/inet.h>
#include <netinet/in.h>
// #include <stdio.h>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

class UdpClient {
private:
  int n;
  int sockfd;
  socklen_t len;
  struct sockaddr_in servaddr;

public:
  void start(unsigned short port, std::string ipAddress);
  void stop() { close(sockfd); }
  bool sendToServer();
  char recieve();
};

#endif