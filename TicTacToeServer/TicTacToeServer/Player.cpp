#include "Player.h"

Player::Player(char s)
    : m_symbol(s) 
{
    //EMPTY
}


char Player::getSymbol() const
{
    return m_symbol; 
}
