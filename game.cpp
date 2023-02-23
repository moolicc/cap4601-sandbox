#include "game.hpp"
#include <iostream>
#include <limits>

Game::Game(int boardSize, int winLength, bool humanMoveFirst)
    : board(boardSize, winLength), winner(Players::None),
      currentPlayer(Players::None), boardSize(boardSize) {
  if (humanMoveFirst) {
    minimizer = Players::Player1;
    maximizer = Players::Player2;
  } else {
    maximizer = Players::Player1;
    minimizer = Players::Player2;
  }
}

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

int Game::abSearch(Board problem) {
  int alpha = -INT32_MAX, alphaPrime = 0, beta = INT32_MAX, a = NULL,
      depthLimit = 5;

  short* node = problem.getState();

  // loop through all possible moves from
  for (int action = 0; action < boardSize; ++action) {
    if (problem.place(action, Player2) == Status::FullCol) {
      continue;
    }

    // NOTES FOR DR.R
    // does apply action make a move on a copy of the current board state and
    // then apply the given action to it? How does it keep track of the current
    // player?
    alphaPrime =
        minValue(problem.getState(), problem, depthLimit--, alpha, beta);

    if (alphaPrime > alpha) {
      alpha = alphaPrime;
      a = action;
    }

    board.remove(action);
  }

  return a;
}

int Game::minValue(short* node, Board problem, int depth, int alpha, int beta) {
  if (depth == 0) {
    return utility(problem);
  }

  for (int action = 0; action < boardSize; ++action) {

    // NOTES FOR DR.R
    // what is the difference between making a move on the board and
    // applyState(node, action)
    board.place(action, minimizer);
    beta = min(beta, maxValue(problem.getState(), Board(problem), depth--,
                              alpha, beta));
  }
}

int Game::maxValue(short* node, Board problem, int depth, int alpha, int beta) {
  if (depth == 0) {
    return utility(problem);
  }

  for (int action = 0; action < boardSize; ++action) {
    board.place(action, maximizer);
    alpha = max(alpha, minValue(problem.getState(), Board(problem), depth--,
                                alpha, beta));
    if (alpha >= beta)
      return INT32_MAX;
  }
  return alpha;
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

// what gets passed in here? the leaf node of the search tree after all
// recursion?
int Game::utility(Board problem) {
  int maximizerUtil = board.getPossibleWins(maximizer);
  int minimizerUtil = board.getPossibleWins(minimizer);

  return maximizerUtil - minimizerUtil;
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