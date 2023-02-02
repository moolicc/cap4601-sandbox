#include "cell.hpp"

Cell::Cell() {
  status = EMPTY;
}

std::string Cell::getStatus() {
  return status;
}

void Cell::setPlayerToken(std::string playerToken){
  status = playerToken;
}