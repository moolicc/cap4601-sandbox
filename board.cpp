#include "board.hpp"
#include <bitset>
#include <iostream>

Board::Board(int size, int winLength) : size(size), winLength(winLength) {
  this->columns = new short[size];

  for (int i = 0; i < size; i++) {
    columns[i] = 0;
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
  short colValue = columns[col];

  // Check for no move.
  int colLength = colValue >> MOVE_BITS;
  std::cout << "row: " << row << " colLength: " << colLength << std::endl;

  if (row >= colLength) {
    return Players::None;
  }

  short rowMask = 1 << row;

  return (Players) (!(col & rowMask) >> row);
}

short Board::getColumnValue(int col) const { return columns[col]; }

bool Board::place(int col, Players player) {
  // Ensure the column is valid.
  if (col < 0 && col >= size) {
    return false;
  }
  short colValue = columns[col];

  // Ensure there is space on the column for another move.
  int colLength = colValue >> MOVE_BITS;
  // std::cout << "colLength: " << colLength << std::endl;
  if (colLength >= MAX_LENGTH) {
    return false;
  }

  // Add our new move to the column.
  // Using the MOVE_MASK will remove the column length data.
  // We replace this data below with the new length.
  // This is intentional, as below performing a simple OR on the column length
  // bits would cause inaccurate lengths to be held.

  // For example, if the current length is 1 (0b0001...) and we add a new move
  // then naturally the length should go to 2 (0b0010...). However, using the OR
  // below WITHOUT a mask here to clear the old length would result in a length
  // of 3 (0b0001 | 0b0010 = 0b0011).

  // std::cout << "Placing in col: " << col << std::endl;
  // std::cout << "  old value: " << colValue << " old len " << colLength
  //           << std::endl;
  colValue = MOVE_MASK & (colValue | (player << colLength));

  // Update the column's length.
  colLength++;

  colValue |= colLength << MOVE_BITS;
  // std::cout << "  new value: " << colValue << " new len " << colLength
  //           << std::endl;

  // Add our new move to the column.
  columns[col] = colValue;

  return true;
}

Players Board::checkForWin(int refCol) const {
  int count = 0;

  // Get the most recently placed row.
  int refRow = (columns[refCol] >> MOVE_BITS);

  // std::cout << "refCol: " << refCol << " refRow: " << refRow << std::endl;
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
      // only show the contents of the cell if a player occupies it with their
      // disk
      if (getMove(j, i) != Players::None) {
        Players player = getMove(j, i);
        char playerChar = '\0';
        switch (player) {
        case Players::Player1:
          playerChar = 'X';
          break;
        case Players::Player2:
          playerChar = 'O';
          break;
        default:
          break;
        }
        board += vBorder + ' ' + playerChar + ' ';
      } else   // otherwise show an empty cell
        board += vBorder + "   ";
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
