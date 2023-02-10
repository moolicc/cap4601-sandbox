#include "udp-server.hpp"

bool UdpServer::start(unsigned short port) {

  struct sockaddr_in servaddr;
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(port);

  bind(sockfd, (const struct sockaddr*) &servaddr, sizeof(servaddr));

  return true;
}

void UdpServer::stop() { close(sockfd); }

bool UdpServer::send(char outgoing) {
  socklen_t len = sizeof(clientAddr);
  char buffer[1] = {outgoing};

  sendto(sockfd, (const char*) buffer, strlen((const char*) buffer),
         0, (const struct sockaddr*) &clientAddr, len);

  return true;
}

char UdpServer::receive() {
  char buffer[1];

  socklen_t len = sizeof(clientAddr);

  recvfrom(sockfd, (char*) buffer, 1, MSG_WAITALL,
           (struct sockaddr*) &clientAddr, &len);

  return buffer[0];
}