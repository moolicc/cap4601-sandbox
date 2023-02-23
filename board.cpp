#include "board.hpp"
#include <bitset>
#include <iostream>

Board::Board(int size, int winLength) : size(size), winLength(winLength) {
  this->columns = new short[size];

  for (int i = 0; i < size; i++) {
    columns[i] = 0;
  }
}

Board::Board(const Board& other) {
  size = other.size;
  winLength = other.winLength;

  this->columns = new short[size];
  for (int i = 0; i < size; i++) {
    columns[i] = other.columns[i];
  }
}

Board& Board::operator=(const Board& other) {
  size = other.size;
  columns = new short[size];
  for (int i = 0; i < size; i++) {
    columns[i] = other.columns[i];
  }
  return *this;   // IMPORTANT! return the current object by reference
}

Board::~Board() { delete[] columns; }

Players Board::getMove(int col, int row) const {
  short colValue = columns[col];

  // Check for no move.
  int colLength = colValue >> MOVE_BITS;
  if (row >= colLength) {
    return Players::None;
  }

  short rowMask = 1 << row;

  return (Players) ((colValue & rowMask) >> row);
}

short Board::getColumnValue(int col) const { return columns[col]; }

std::string Board::repeat(const std::string str, int num) const {
  std::string ret = "";
  for (int i = 0; i < num; i++) {
    ret += str;
  }
  ret += '\n';
  return ret;
}

int Board::countHorizontalConnections(int refCol, int refRow, Players player,
                                      int connections) {

  int count = 0;

  if (connections != 0) {
    count = connections;
  }

  // base case 1: no more columns to check
  std::cout << "segfault check in countHC" << std::endl;
  if (refCol < 0 || refCol >= size) {
    return count;
  }

  // base case 2: player in the current cell is not the same as previous
  if (getMove(refCol, refRow) != player) {
    return count;
  }

  count++;
  countHorizontalConnections(++refCol, refRow, player, count);   // check right
  countHorizontalConnections(--refCol, refRow, player, count);   // check left

  return count;
}

int Board::countVerticalConnections(int refCol, int refRow, Players player,
                                    int connections) {

  std::cout << "segfault check in conutVC" << std::endl;
  int count = 0;

  if (connections != 0) {
    count = connections;
  }

  // base case 1: no more columns to check
  if (refRow < 0 || refRow >= size) {
    return count;
  }

  // base case 2: player in the current cell is not the same as previous
  if (getMove(refCol, refRow) != player) {
    return count;
  }

  count++;
  countVerticalConnections(refCol, ++refRow, player, count);
  countVerticalConnections(refCol, --refRow, player, count);

  return count;
}

bool Board::checkHorizontalWin(int refCol, int refRow, Players player,
                               bool allowEmpty, int preCount) const {
  int count = 0;
  // check horizontal right
  for (int col = refCol; col < refCol + winLength && col < size; col++) {
    if (getMove(col, refRow) == player) {
      count++;
    } else {
      break;
    }
    if (count == winLength) {
      return true;
    }
  }
  count = 0;

  // check horizontal left
  for (int col = refCol; col >= refCol - winLength && col >= 0; col--) {
    Players playerAt = getMove(col, refRow);
    if (playerAt == player || (allowEmpty && playerAt == Players::None)) {
      count++;
    } else {
      break;
    }
    if (count == winLength) {
      return true;
    }
  }
  return false;
}

bool Board::checkVerticalWin(int refCol, int refRow, Players player,
                             bool allowEmpty, int preCount) const {
  int count = preCount;
  // check vertical down
  for (int row = refRow; row >= refRow - winLength && row >= 0; row--) {
    Players playerAt = getMove(refCol, row);
    if (playerAt == player || (allowEmpty && playerAt == Players::None)) {
      count++;
    } else {
      break;
    }
    if (count == winLength) {
      return true;
    }
  }
  count = 0;

  if (allowEmpty) {
    // check vertical up
    for (int row = refRow; row <= refRow + winLength && row < size; row++) {
      Players playerAt = getMove(refCol, row);
      if (playerAt == Players::None) {
        count++;
      } else {
        break;
      }
      if (count == winLength) {
        return true;
      }
    }
    count = 0;
  }

  return false;
}

bool Board::checkLeftRightDiagonalWin(int refCol, int refRow, Players player,
                                      bool allowEmpty, int preCount) const {
  int count = preCount;

  // diagonal up to the left
  // row increases , col decreases
  for (int col = refCol, row = refRow;
       col > refCol - winLength && row <= refRow + winLength; col--, row++) {
    Players playerAt = getMove(col, row);
    if (playerAt == player || (allowEmpty && playerAt == Players::None)) {
      count++;
    } else {
      break;
    }
    if (count == winLength) {
      return true;
    }
  }
  count = 0;

  // diagonal down to the right
  // row ++ , col++
  for (int col = refCol, row = refRow;
       col <= refCol + winLength && row > refRow - winLength && col < size &&
       row >= 0;
       col++, row--) {
    Players playerAt = getMove(col, row);
    if (playerAt == player || (allowEmpty && playerAt == Players::None)) {
      count++;
    } else {
      break;
    }
    if (count == winLength) {
      return true;
    }
  }

  return false;
}

bool Board::checkRightLeftDiagonalWin(int refCol, int refRow, Players player,
                                      bool allowEmpty, int preCount) const {
  int count = preCount;

  // diagonal up to the right
  // row increases , col increases
  for (int col = refCol, row = refRow;
       col <= refCol + winLength && row <= refRow + winLength; col++, row++) {
    Players playerAt = getMove(col, row);
    if (playerAt == player || (allowEmpty && playerAt == Players::None)) {
      count++;
    } else {
      break;
    }
    if (count == winLength) {
      return true;
    }
  }
  count = 0;

  // diagonal down to the left
  // row decreases , col decreases
  for (int col = refCol, row = refRow;
       col > refCol - winLength && row > refRow - winLength && col >= 0 &&
       row >= 0;
       col--, row--) {
    Players playerAt = getMove(col, row);
    if (playerAt == player || (allowEmpty && playerAt == Players::None)) {
      count++;
    } else {
      break;
    }
    if (count == winLength) {
      return true;
    }
  }

  return false;
}

Status Board::place(int col, Players player) {
  // Ensure the column is valid.
  if (col < 0 || col >= size) {
    return Status::OutOfBounds;
  }
  short colValue = columns[col];

  // Add our new move to the column.
  // Using the MOVE_MASK will remove the column length data.
  // We replace this data below with the new length.
  // This is intentional, as below performing a simple OR on the column length
  // bits would cause inaccurate lengths to be held.

  // For example, if the current length is 1 (0b0001...) and we add a new move
  // then naturally the length should go to 2 (0b0010...). However, using the
  // OR below WITHOUT a mask here to clear the old length would result in a
  // length of 3 (0b0001 | 0b0010 = 0b0011).

  // If a player was provided, set their move and increment the column length.
  // If a player was not provided, then consider this a REMOVE operation and
  // decrement the length.
  int colLength = colValue >> MOVE_BITS;
  if (player != Players::None) {
    // Ensure there is space on the column for another move.
    if (colLength >= MAX_LENGTH) {
      return Status::FullCol;
    }

    // Set the move.
    colValue = MOVE_MASK & (colValue | (player << colLength));

    // Update the column's length.
    colLength++;
  } else {
    colLength--;
  }

  colValue |= colLength << MOVE_BITS;

  // Add our new move to the column.
  columns[col] = colValue;

  return Status::Success;
}

Players Board::checkForWin(int refCol) const {
  // int count = 0;

  // Get the most recently placed row.
  int refRow = (columns[refCol] >> MOVE_BITS) - 1;

  if (refRow < 0) {
    return Players::None;
  }

  Players player = getMove(refCol, refRow);

  if (checkHorizontalWin(refCol, refRow, player, false, 0)) {
    return player;
  }

  if (checkVerticalWin(refCol, refRow, player, false, 0)) {
    return player;
  }

  if (checkLeftRightDiagonalWin(refCol, refRow, player, false, 0)) {
    return player;
  }

  if (checkRightLeftDiagonalWin(refCol, refRow, player, false, 0)) {
    return player;
  }

  return Players::None;
}

// how many connected moves do we have in a particular direction, and how many
// more do we need for a win in that direction?
int Board::getPossibleWins(Players player) {
  int winCount = 0;

  for (int i = 0; i < size; i++) {
    int refRow = (columns[i] >> MOVE_BITS) - 1;

    if (refRow < 0 || refRow > size) {
      return 0;
    }

    Players player = getMove(i, refRow);
    // get the number of already connected pieces
    int preCount = 0;
    // vertical down
    // preCount += countHorizontalConnections(i, refRow, player, 0);
    // preCount += countVerticalConnections(i, refRow, player, 0);

    if (checkHorizontalWin(i, refRow, player, true, preCount)) {
      winCount++;
    }
    if (checkVerticalWin(i, refRow, player, true, preCount)) {
      winCount++;
    }
    if (checkLeftRightDiagonalWin(i, refRow, player, true, preCount)) {
      winCount++;
    }
    if (checkRightLeftDiagonalWin(i, refRow, player, true, preCount)) {
      winCount++;
    }
  }

  return winCount;
}

/**
 * @brief A simple function to draw a board of the following layout based on
the size of the playingField.
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

bool Board::full() const {
  int fullCols = 0;
  for (int col = 0, colLength = 0; col < this->size; col++) {
    colLength = columns[col] >> MOVE_BITS;
    if (colLength == size)
      fullCols++;

    printf("col: %d, colLength: %d, fullCols: %d\n", col, colLength, fullCols);
  }

  return fullCols == this->size;
}

void Board::remove(int col) { place(col, Players::None); }