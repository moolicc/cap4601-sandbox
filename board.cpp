#include "board.hpp"
#include <iostream>
#include <bitset>

Board::Board(int columnCount) : columnCount(columnCount)
{
  this->columns = new int[columnCount];

  for (int i = 0; i < columnCount; i++)
  {
    columns[i] = Players::None;
  }
}

// Board::Board(const Board &other)
// {
//   this->columnCount = other.columnCount;
//   this->columns = new  int[columnCount];

//   for (int i = 0; i < columnCount; i++)
//   {
//     columns[i] = other.getColumnValue(i);
//   }
// }

Board::~Board()
{
  delete[] columns;
}

Players Board::getMove(int col, int row) const
{
  int colValue = columns[col];

  // Check for no move.
  Players checkPlayer = Players::None;
  int rowOffset = (row * 3) + checkPlayer;
  if ((colValue & (1 << rowOffset)) == (1 << rowOffset))
  {
    return checkPlayer;
  }

  // Check for a player1 move.
  checkPlayer = Players::Player1;
  rowOffset = (row * 3) + checkPlayer;
  if ((colValue & (1 << rowOffset)) == (1 << rowOffset))
  {
    return checkPlayer;
  }

  // Check for a player2 move.
  checkPlayer = Players::Player2;
  rowOffset = (row * 3) + checkPlayer;
  if ((colValue & (1 << rowOffset)) == (1 << rowOffset))
  {
    return checkPlayer;
  }

  return Players::None;
}

int Board::getColumnValue(int col) const
{
  return columns[col];
}

bool Board::place(int col, Players player)
{
  // Ensure the column is valid.
  if (col < 0 && col >= columnCount)
  {
    return false;
  }

  // Find the first unused row.
  int row = 0;

  while (row < columnCount && getMove(col, row) != Players::None)
  {
    row++;
  }

  // Ensure the row is valid.
  if (row >= columnCount)
  {
    return false;
  }

  // Add our new move to the column.
  columns[col] = columns[col] | (1 << ((row * 3) + player));

  return true;
}

Players Board::checkForWin() const
{
  int count = 0;

  // if adjacent cell is same as current cell, count++;
  return Players::None;
}

/**
 * @brief A simple funciton to draw a board of the following layout based on the size of the playingField.
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
void Board::draw() const
{
  const std::string hBorderStart = "+";
  const std::string hBorder = "---+";
  const std::string vBorder = "|";

  std::string board = "";
  for (int rows = 0; rows < columnCount; rows++)
  {
    std::cout << "  " << rows + 1 << " ";
  }
  std::cout << std::endl;
  for (int i = columnCount - 1; i >= 0; i--)
  {
    board += hBorderStart + repeat(hBorder, columnCount);
    for (int j = 0; j < columnCount; j++)
    {
      board += vBorder + ' ' + (char)(getMove(j + 1, i) + 0x30) + ' ';
    }
    board += vBorder + '\n';
  }
  board += hBorderStart + repeat(hBorder, columnCount);

  std::cout << board << std::endl;
}

std::string Board::repeat(const std::string str, int num) const
{
  std::string ret = "";
  for (int i = 0; i < num; i++)
  {
    ret += str;
  }
  ret += '\n';
  return ret;
}
