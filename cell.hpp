#ifndef CELL_HPP
#define CELL_HPP

#include <string>

class Cell {
  public:
    inline static const std::string PLAYER1 = "O";
    inline static const std::string PLAYER2 = "X";
    inline static const std::string EMPTY = " ";
    Cell();
    std::string getStatus();
    void setPlayerToken(std::string player);
  private:
    std::string status;
};

#endif