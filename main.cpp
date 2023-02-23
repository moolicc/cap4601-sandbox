
#include "game.hpp"
#include "udp-client.hpp"
#include "udp-server.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  int size = 0;
  int winLength = 0;

  if (argc == 4) {
    size = std::stoi(argv[1]);
    winLength = std::stoi(argv[2]);
    Game game(size, winLength, 1);
    game.start();
  } else if (argc > 4) {
    size = std::stoi(argv[1]);
    winLength = std::stoi(argv[2]);
    Game game(size, winLength, 1);

    game.start();
    UdpClient client;
    UdpServer server;

    std::string ipAddress = argv[4];
    unsigned short port = std::stoi(argv[5]);

    server.start(port);
    client.start(port, ipAddress);

    client.sendToServer();
    char incomingFromClient = server.receive();

    std::cout << "incoming from client: " << incomingFromClient << std::endl;

    server.send('a');
    char incomingFromServer = client.recieve();

    std::cout << "incoming from server: " << incomingFromServer << std::endl;

    client.stop();
    server.stop();
  }

  // N = board size M = consecutivity H = human goes first? 1: 0

  return 0;
}
