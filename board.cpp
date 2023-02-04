#include "board.hpp"
#include <bitset>
#include <iostream>

Board::Board(int size, int winLength) : size(size), winLength(winLength) {
  this->columns = new int[size];

  for (int i = 0; i < size; i++) {
    columns[i] = Players::None;
  }
}

// Board::Board(const Board &other)
// {
//   this->size = other.size;
//   this->columns = new  int[size];

//   for (int i = 0; i < size; i++)
//   {
//     columns[i] = other.getColumnValue(i);
//   }
// }

Board::~Board() { delete[] columns; }

Players Board::getMove(int col, int row) const {
  int colValue = columns[col];

  // Check for no move.
  Players checkPlayer = Players::None;
  int rowOffset = (row * 3) + checkPlayer;
  if ((colValue & (1 << rowOffset)) == (1 << rowOffset)) {
    return checkPlayer;
  }

  // Check for a player1 move.
  checkPlayer = Players::Player1;
  rowOffset = (row * 3) + checkPlayer;
  if ((colValue & (1 << rowOffset)) == (1 << rowOffset)) {
    return checkPlayer;
  }

  // Check for a player2 move.
  checkPlayer = Players::Player2;
  rowOffset = (row * 3) + checkPlayer;
  if ((colValue & (1 << rowOffset)) == (1 << rowOffset)) {
    return checkPlayer;
  }

  return Players::None;
}

int Board::getColumnValue(int col) const { return columns[col]; }

bool Board::place(int col, Players player) {
  // Ensure the column is valid.
  if (col < 0 && col >= size) {
    return false;
  }

  // Find the first unused row.
  int row = 0;

  while (row < size && getMove(col, row) != Players::None) {
    row++;
  }

  // Ensure the row is valid.
  if (row >= size) {
    return false;
  }

  // Add our new move to the column.
  columns[col] = columns[col] | (1 << ((row * 3) + player));

  return true;
}

Players Board::checkForWin(int refCol) const {
  // Find the first empty row along the column.
  int refRow = -1;
  int count = 0;

  while (getMove(refCol, refRow + 1) != Players::None && refRow < size) {
    refRow++;
  }

  std::cout << "refCol: " << refCol << " refRow: " << refRow << std::endl;
  Players player = getMove(refCol, refRow);

  // check horizontal right
  for (int col = refCol; col < refCol + winLength && col < size; col++) {
    if (getMove(col, refRow) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength)
      return player;
  }
  count = 0;

  // check horizontal left
  for (int col = refCol; col >= refCol - winLength && col >= 0; col--) {
    if (getMove(col, refRow) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength)
      return player;
  }
  count = 0;

  // check vertical down
  for (int row = refRow; row >= refRow - winLength && row >= 0; row--) {
    if (getMove(refCol, row) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength)
      return player;
  }
  count = 0;

  // diagonal down to the left
  // row decreases , col decreases
  for (int col = refCol, row = refRow;
       col > refCol - winLength && row > refRow - winLength; col--, row--) {
    if (getMove(col, row) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength)
      return player;
  }
  count = 0;

  // dialgonal down to the right
  // row ++ , col++
  for (int col = refCol, row = refRow;
       col <= refCol + winLength && row > refRow - winLength; col++, row--) {
    if (getMove(col, row) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength)
      return player;
  }
  count = 0;

  // diagonal up to the left
  // row increases , col decreases
  for (int col = refCol, row = refRow;
       col > refCol - winLength && row <= refRow + winLength; col--, row++) {
    if (getMove(col, row) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength)
      return player;
  }
  count = 0;

  // diagonal up to the right
  // row increases , col increases
  for (int col = refCol, row = refRow;
       col <= refCol + winLength && row <= refRow + winLength; col++, row++) {
    if (getMove(col, row) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength)
      return player;
  }
  count = 0;

  return Players::None;
}

/**
 * @brief A simple funciton to draw a board of the following layout based on the
size of the playingField.
 *        This example assumes a board size of 4X4
 *
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
 *
 */
void Board::draw() const {
  const std::string hBorderStart = "+";
  const std::string hBorder = "---+";
  const std::string vBorder = "|";

  std::string board = "";
  for (int rows = 0; rows < size; rows++) {
    std::cout << "  " << rows << " ";
  }
  std::cout << std::endl;
  for (int i = size - 1; i >= 0; i--) {
    board += hBorderStart + repeat(hBorder, size);
    for (int j = 0; j < size; j++) {
      board += vBorder + ' ' + (char) (getMove(j, i) + 0x30) + ' ';
    }
    board += vBorder + '\n';
  }
  board += hBorderStart + repeat(hBorder, size);

  std::cout << board << std::endl;
}

std::string Board::repeat(const std::string str, int num) const {
  std::string ret = "";
  for (int i = 0; i < num; i++) {
    ret += str;
  }
  ret += '\n';
  return ret;
}
