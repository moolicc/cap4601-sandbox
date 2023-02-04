#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

enum Players { None = 0, Player1 = 1, Player2 = 2 };

class Board {
private:
  int size;
  int winLength;
  int* columns;

  int getColumnValue(int col) const;

  std::string repeat(const std::string str, int num) const;

public:
  Players getMove(int col, int row) const;
  Board(int size, int winLength);
  // explicit Board() { Board(3); }
  // explicit Board(const Board &board);
  ~Board();

  int getSize() const { return size; }

  bool place(int col, Players player);
  Players checkForWin(int col) const;

  void draw() const;
};

#endif