
#include <iostream>
#include "board.hpp"
int main(int argc, char *argv[])
{
    std::cout << "Testing board class..." << std::endl;
    Board board(7);
    std::cout << board.place(1, Players::Player1) << std::endl;
    std::cout << board.place(1, Players::Player1) << std::endl;
    std::cout << board.place(1, Players::Player1) << std::endl;
    std::cout << board.place(1, Players::Player1) << std::endl;
    std::cout << board.place(1, Players::Player1) << std::endl;
    std::cout << board.place(1, Players::Player1) << std::endl;
    std::cout << board.place(1, Players::Player1) << std::endl;
    std::cout << board.place(1, Players::Player1) << std::endl;

    std::cout << board.place(3, Players::Player2) << std::endl;
    std::cout << board.place(4, Players::Player1) << std::endl;
    board.draw();
    return 0;
}
