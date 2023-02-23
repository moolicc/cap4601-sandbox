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

  bool checkHorizontalWin(int refCol, int refRow, Players player,
                          bool allowEmpty, int preCount) const;
  bool checkVerticalWin(int refCol, int refRow, Players player, bool allowEmpty,
                        int preCount) const;
  bool checkLeftRightDiagonalWin(int refCol, int refRow, Players player,
                                 bool allowEmpty, int preCount) const;
  bool checkRightLeftDiagonalWin(int refCol, int refRow, Players player,
                                 bool allowEmpty, int preCount) const;

  int countHorizontalConnections(int refCol, int refRow, Players player,
                                 int connections);
  int countVerticalConnections(int refCol, int refRow, Players player,
                               int connections);

public:
  Board() { Board(3, 4); }
  Board(int size, int winLength);
  // Board(short* node, int size, int winLength);
  Board(const Board& other);
  Board& operator=(const Board& other);
  ~Board();
  short* getState() { return this->columns; }
  Players getMove(int col, int row) const;
  int getSize() const { return size; }
  Status place(int col, Players player);
  Players checkForWin(int col) const;
  int getPossibleWins(Players player);
  void draw() const;
  bool full() const;
  void remove(int col);
  int getWinLength() { return winLength; }
};

#endif