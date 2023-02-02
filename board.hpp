#ifndef BOARD_HPP
#define BOARD_HPP

#include "cell.hpp"
#include <vector>
class Board {
  public:
    Board(int size);
    bool place(int col);
    bool checkForWin();
    void draw();
  private:
    // Cell** playingField;
    std::vector<std::vector<Cell>> playingField;
    int size;
    std::string repeat(const std::string str, int num);

};

#endif