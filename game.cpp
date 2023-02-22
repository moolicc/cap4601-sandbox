#include "game.hpp"
#include <iostream>

int Game::getHumanMove() {
  int move;
  if (currentPlayer == Players::Player1) {
    std::cout << "Player 1, please enter your move: ";
  } else {
    std::cout << "Player 2, please enter your move: ";
  }
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
    Status moveStatus;
    int move;
    currentPlayer = Player1;
    do {
      move = getHumanMove();
      moveStatus = board.place(move, Players::Player1);
      if (moveStatus == Status::OutOfBounds) {
        std::cout << "Please enter a column from 0 to " << boardSize - 1
                  << std::endl;
      }
    } while (moveStatus != Status::Success);
    winner = board.checkForWin(move);
    if (winner != Players::None) {
      printWinner();
      break;
    } else if (checkForDraw()) {
      break;
    }
    board.draw();

    currentPlayer = Player2;
    do {
      move = getHumanMove();
      moveStatus = board.place(move, Players::Player2);
      if (moveStatus == Status::OutOfBounds) {
        std::cout << "Please enter a column from 0 to " << boardSize - 1
                  << std::endl;
      }
    } while (moveStatus != Status::Success);
    winner = board.checkForWin(move);
    if (winner != Players::None) {
      printWinner();
      break;
    } else if (checkForDraw()) {
      break;
    }
  }
}