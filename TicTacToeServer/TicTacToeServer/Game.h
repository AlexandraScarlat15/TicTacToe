//#ifndef GAME_H
//#define GAME_H
//
//#include "Board.h"
//#include "Player.h"
//#include "HumanPlayer.h"
//#include "Opponent.h"
//
//class Game {
//private:
//    Board m_board;
//    Player* m_playerX;
//    Player* m_playerO;
//    char m_currentTurn; 
//    bool m_gameOver;
//
//public:
//    Game(Player* playerX, Player* playerO);
//
//    void Start(); 
//    bool MakeMove(int row, int col); 
//    bool IsGameOver() const;
//    char GetWinner() const;
//    void DisplayBoard() const; 
//};
//
//#endif // GAME_H
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Opponent.h"

class Game {
private:
    Board m_Board;
    Player* m_PlayerX;
    Player* m_PlayerO;
    char m_CurrentTurn;
    bool m_GameOver;

public:
    Game(Player* playerX, Player* playerO);

    void Start(); // Main game loop
    bool MakeMove(int row, int col);
    bool IsGameOver() const;
    char GetWinner() const;
    void DisplayBoard() const; // Print board for debugging
};

#endif // GAME_H
