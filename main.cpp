
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
  board.place(3, Players::Player2);
  board.place(3, Players::Player2);
  board.place(3, Players::Player2);
  board.place(3, Players::Player2);
  board.place(3, Players::Player2);

  board.place(0, Players::Player1);
  board.place(0, Players::Player1);
  board.place(0, Players::Player1);
  board.place(0, Players::Player1);
  board.place(0, Players::Player1);
  board.draw();

  Players winner = board.checkForWin(0);

  std::cout << "winner: ";
  if (winner == Players::Player1) {
    std::cout << "Player 1";
  } else if (winner == Players::Player2) {
    std::cout << "Player 2";
  } else {
    std::cout << "Nobody";
  }
  std::cout << std::endl;

  // board.place(3, Players::Player1);
  // board.place(3, Players::Player1);

  // board.place(2, Players::Player2);
  // board.place(2, Players::Player1);
  // board.place(2, Players::Player1);

  // board.place(1, Players::Player2);
  // board.place(1, Players::Player1);

  // board.place(0, Players::Player1);

  // board.place(0, Players::Player2);
  // board.place(0, Players::Player2);
  // board.place(0, Players::Player1);
  // board.place(0, Players::Player1);   // top

  // board.place(1, Players::Player2);
  // board.place(1, Players::Player1);
  // board.place(1, Players::Player1);   // top

  // board.place(2, Players::Player2);
  // board.place(2, Players::Player1);   // top

  // board.place(3, Players::Player1);   // top
  // std::cout << board.checkForWin(0) << std::endl;

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