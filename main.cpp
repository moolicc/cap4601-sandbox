
#include<iostream>
#include "board.hpp"
int main()
{
    std::cout << "Testing board class..." << std::endl;
    Board board(4);
    board.draw();
    return 0;
}
