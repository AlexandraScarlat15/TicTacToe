#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(char symbol) : Player(symbol) 
{
    //EMPTY
}

void HumanPlayer::MakeMove(int& row, int& col) {
    std::cout << "Enter your move (row and column): ";
    std::cin >> row >> col;
}