
#include "board.hpp"
#include <iostream>
int main(int argc, char* argv[]) {

  // N = board size M = consecutivity H = human goes first? 1: 0

  std::cout << "Testing board class..." << std::endl;
  int rows = 7;
  int winLength = 4;
  Board board(rows, winLength);

  // down and to the left win
  // board.place(3, Players::Player2);
  // board.place(3, Players::Player2);
  // board.place(3, Players::Player1);
  // board.place(3, Players::Player1);

  // board.place(2, Players::Player2);
  // board.place(2, Players::Player1);
  // board.place(2, Players::Player1);

  // board.place(1, Players::Player2);
  // board.place(1, Players::Player1);

  // board.place(0, Players::Player1);

  board.place(0, Players::Player2);
  board.place(0, Players::Player2);
  board.place(0, Players::Player1);
  board.place(0, Players::Player1);   // top

  board.place(1, Players::Player2);
  board.place(1, Players::Player1);
  board.place(1, Players::Player1);   // top

  board.place(2, Players::Player2);
  board.place(2, Players::Player1);   // top

  board.place(3, Players::Player1);   // top
  std::cout << board.checkForWin(0) << std::endl;

  // up and to the right test
  // board.place(3, Players::Player1);   // top

  // board.place(4, Players::Player2);
  // board.place(4, Players::Player1);   // top

  // board.place(5, Players::Player2);
  // board.place(5, Players::Player2);
  // board.place(5, Players::Player1);   // top

  // board.place(6, Players::Player2);
  // board.place(6, Players::Player2);
  // board.place(6, Players::Player1);
  // board.place(6, Players::Player1);   // top
  // board.place(2, Players::Player2);
  // board.place(3, Players::Player2);
  // board.place(4, Players::Player2);
  // board.place(5, Players::Player2);
  // std::cout << board.checkForWin(5) << std::endl;

  board.draw();
  return 0;
}