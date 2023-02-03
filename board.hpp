#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"
#include <vector>
class Board {
    int size;
    // std::vector<std::vector<Cell>> playingField;
    Cell** playingField;
    std::string repeat(const std::string str, int num);
  public:
    Board();
    ~Board();
    Board(int size);
    bool place(int col);
    bool checkForWin();
    void draw();
    

};

#endif