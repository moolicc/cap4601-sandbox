#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

enum Players
{
  None = 0,
  Player1 = 1,
  Player2 = 2
};

class Board
{
private:
  int columnCount;
  int rowCount;
  int *columns;

  Players getMove(int col, int row) const;
  int getColumnValue(int col) const;

  std::string repeat(const std::string str, int num) const;

public:
  Board(int size);
  // explicit Board() { Board(3); }
  // explicit Board(const Board &board);
  ~Board();

  int getColumnCount() const { return columnCount; }
  int getRowCount() const { return rowCount; }

  bool place(int col, Players player);
  Players checkForWin() const;

  void draw() const;
};

#endif