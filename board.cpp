#include "board.hpp"
#include <iostream>

// Board::Board(): size(0), playingField(10, std::vector<Cell>(10)){}

// Board::Board(int size): size(size), playingField(size, std::vector<Cell>(size)){

//   for(int i = 0; i < size; i++){
//     for(int j = 0; j < size; j++){
//       // printf("Accessing playingField at row: %d\n", i);
//       playingField.at(i).push_back(Cell());
//       playingField.at(i).at(j).setPlayerToken("X");
//       std::string str = playingField.at(i).at(j).getStatus();
//       std::cout << "Cell status: " << str << '|' << std::endl;
//     }
//   }
// }

Board::Board(int size): size(size) {
  playingField = new Cell*[size];
  for (int i = 0; i < size; ++i) 
    playingField[i] = new Cell[size];
}

Board::~Board() {
  for (int i = 0; i < size; i++)
    delete [] playingField[i];
  
  delete [] playingField;
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
  const std::string hBorder = "---+";
  const std::string vBorder = "|";

  std::string board = "";
  // std::cout << playingField.at(0).at(0).getStatus() << std::endl;
  for(int i = 0; i < size; i++){
    board += hBorderStart + repeat(hBorder, size);
    for(int j = 0; j < size; j++){
      // printf("Accessing playingField at row, col: %d, %d\n", i, j);
      // std::string cellStatus = playingField.at(i).at(j).getStatus();
      board += vBorder + " " + playingField[i][j].getStatus() + " ";
    }
    board += vBorder + '\n';
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
