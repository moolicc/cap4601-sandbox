#include "udp-client.hpp"

void UdpClient::start(unsigned short port, std::string ipAddress) {
  // Creating socket file descriptor
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  servaddr.sin_addr.s_addr = inet_addr(ipAddress.c_str());
}

bool UdpClient::sendToServer() {
  const char* msg = "1";
  sendto(sockfd, (const char*) msg, 1, 0,
         (const struct sockaddr*) &servaddr, sizeof(servaddr));

  return true;
}

char UdpClient::recieve() {
  char buffer[1];
  n = recvfrom(sockfd, (char*) buffer, 1, MSG_WAITALL,
               (struct sockaddr*) &servaddr, &len);

  return buffer[0];
}