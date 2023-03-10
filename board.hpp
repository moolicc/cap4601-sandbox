#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

enum Players { None = -1, Player1 = 0, Player2 = 1 };
enum Status { FullCol = 1, OutOfBounds = -1, Success = 0 };
class Board {
private:
  const short MOVE_MASK = 0b0000111111111111;
  const int MOVE_BITS = 12;
  // const short LENGTH_MASK = 0b1111000000000000;
  // const int LENGTH_BITS = 4;
  const int MAX_LENGTH = 15;

  int size;
  int winLength;
  short* columns;

  short getColumnValue(int col) const;
  std::string repeat(const std::string str, int num) const;

public:
  explicit Board() { Board(3, 4); }
  explicit Board(int size, int winLength);
  // explicit Board(const Board &board);
  ~Board();
  Players getMove(int col, int row) const;
  int getSize() const { return size; }
  Status place(int col, Players player);
  Players checkForWin(int col) const;
  void draw() const;
  bool full() const;
};

#endif