#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

class Game {
private:
  Board board;
  Players winner;

public:
  Game() : board() {}
  Game(int boardSize, int winLength, bool humanMoveFirst)
      : board(boardSize, winLength), winner(Players::None) {}
  void start();
  int getHumanMove();
  bool checkForDraw();
  void printWinner();
  // int getAgentMove(); to be implemented after the agent
};

#endif