
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

  // down and to the left win
  // board.place(0, Players::Player1);
  // std::cout << (board.checkForWin(0) == Players::Player1) << std::endl;
  // board.place(0, Players::Player2);
  // std::cout << (board.checkForWin(0) == Players::Player2) << std::endl;
  board.place(1, Players::Player1);
  std::cout << (board.checkForWin(1) == Players::Player1) << std::endl;

  board.draw();

  // while (true) {
  //   int move;
  //   board.draw();

  //   std::cout << "Player 1 please enter your move: ";
  //   std::cin >> move;
  //   std::cout << std::endl;
  //   board.place(move, Players::Player1);

  //   if (board.checkForWin(move) == Players::Player1) {
  //     std::cout << "The winner is: "
  //               << "Player 1" << std::endl;
  //     break;
  //   }

  //   board.draw();
  //   std::cout << "Player 2 please enter your move: ";
  //   std::cin >> move;
  //   std::cout << std::endl;
  //   board.place(move, Players::Player2);

  //   // std::cout << (winner == Players::Player2) << std::endl;
  //   if (board.checkForWin(move) == Players::Player1) {
  //     std::cout << "The winner is: "
  //               << "Player 2" << std::endl;
  //     break;
  //   }
  // }

  return 0;
}