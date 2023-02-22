#include "game.hpp"
#include <iostream>

int Game::getHumanMove() {
  int move;
  std::cout << "Please enter your move: ";
  std::cin >> move;
  std::cout << std::endl;
  return move;
}

void Game::printWinner() {
  if (winner == Players::Player1) {
    std::cout << "The winner is: "
              << "Player 1" << std::endl;
    board.draw();
  } else if (winner == Players::Player2) {
    std::cout << "The winner is: "
              << "Player 2" << std::endl;
    board.draw();
  }
}

bool Game::checkForDraw() {
  if (board.full() && winner == Players::None) {
    std::cout << "Game Over" << std::endl;
    board.draw();
    return true;
  }
  return false;
}

void Game::start() {
  while (true) {
    board.draw();
    int move = getHumanMove();
    board.place(move, Players::Player1);
    winner = board.checkForWin(move);
    if (winner != Players::None) {
      printWinner();
      break;
    } else if (checkForDraw()) {
      break;
    }
    board.draw();

    move = getHumanMove();
    board.place(move, Players::Player2);
    winner = board.checkForWin(move);
    if (winner != Players::None) {
      printWinner();
      break;
    } else if (checkForDraw()) {
      break;
    }
  }
}