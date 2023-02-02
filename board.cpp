#include "board.hpp"
#include <iostream>


Board::Board(int size): size(size){
  // Create a blank field of the appropriate size;
  
  std::vector<std::vector<Cell>> playingField(size, std::vector<Cell>(size));
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
void Board::draw() {
  const std::string hBorderStart = "+";
  const std::string vBorderStart = "| ";
  const std::string hBorder = "---+";
  const std::string vBorder = " | ";

  std::string board = "";
  
  for(int i = 0; i < size; i++){
    board += hBorderStart + repeat(hBorder, size);
    board += vBorderStart + ' ';
    for(int j = 0; j < size; j++){
      // printf("Accessing playingField at row, col: %d, %d\n", i, j);
      // std::string cellStatus = playingField.at(i).at(j).getStatus();
      board += vBorder + ' ';
    }
    board += '\n';
  }
  board += hBorderStart + repeat(hBorder, size);

  std::cout << board << std::endl;
}

std::string Board::repeat(const std::string str, int num){
  std::string ret = "";
  for(int i = 0; i < num; i++) {
    ret += str;
  }
  ret += '\n';
  return ret;
}