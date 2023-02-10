
#include "board.hpp"
#include <iostream>
int main(int argc, char* argv[]) {

  // N = board size M = consecutivity H = human goes first? 1: 0

  // std::cout << "Testing board class..." << std::endl;
  int cols = 0;
  int winLength = 0;

  if (argc == 4) {
    cols = std::stoi(argv[1]);
    winLength = std::stoi(argv[2]);
  }

  Board board(cols, winLength);
  printf("board size: %d, winLength: %d\n", cols, winLength);

  // Game Loop
  while (true) {
    int move;
    board.draw();
    Players winner;

    std::cout << "Player 1 please enter your move: ";
    std::cin >> move;
    std::cout << std::endl;
    board.place(move, Players::Player1);
    winner = board.checkForWin(move);
    if (winner == Players::Player1) {
      std::cout << "The winner is: "
                << "Player 1" << std::endl;
      break;
    }

    if (board.full()) {
      std::cout << "Game Over" << std::endl;
      board.draw();
      break;
    }

    board.draw();
    std::cout << "Player 2 please enter your move: ";
    std::cin >> move;
    std::cout << std::endl;
    board.place(move, Players::Player2);
    winner = board.checkForWin(move);
    // std::cout << (winner == Players::Player2) << std::endl;
    if (winner == Players::Player1) {
      std::cout << "The winner is: "
                << "Player 2" << std::endl;
      break;
    }

    if (board.full()) {
      std::cout << "Game Over\n Winner: " << winner << std::endl;
      board.draw();
      break;
    }
  }

  return 0;
}