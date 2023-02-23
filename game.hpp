#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

class Game {
private:
  Board board;
  Players winner;
  Players currentPlayer;
  Players maximizer;
  Players minimizer;
  int boardSize;
  int abSearch(Board state);
  int minValue(short* node, Board problem, int depth, int alpha, int beta);
  int maxValue(short* node, Board problem, int depth, int alpha, int beta);
  int min(int a, int b) {
    if (a <= b) {
      return a;
    }
    return b;
  }
  int max(int a, int b) {
    if (a >= b)
      return a;
    return b;
  }
  int utility(Board problem);

  Players getOpposingPlayer(Players input) {
    if (input == Players::Player1) {
      return Players::Player2;
    } else if (input == Players::Player2) {
      return Players::Player1;
    }
    return Players::None;
  }

public:
  Game() : board() {}
  Game(int boardSize, int winLength, bool humanMoveFirst);
  void start();
  int getHumanMove();
  bool checkForDraw();
  void printWinner();
  int getAgentMove();
};

#endif