//#ifndef OPPONENT_H
//#define OPPONENT_H
//
//#include "Player.h"
//#include "Board.h"
//#include <limits>
//
//class Opponent : public Player {
//private:
//    Board* m_board;
//public:
//    explicit Opponent(char symbol);
//    void MakeMove(int& row, int& col) override;
//
//private:
//    int Minimax(Board& board, int depth, bool isMaximizing);
//    int Evaluate(Board& board);
//    bool HasMovesLeft(Board& board);
//};
//
//#endif // OPPONENT_H
#ifndef OPPONENT_H
#define OPPONENT_H

#include "Player.h"
#include "Board.h"
#include <limits>

class Opponent : public Player {
private:
    Board* m_Board;

public:
    explicit Opponent(char symbol, Board* board);
    void MakeMove(int& row, int& col) override;

private:
    int Minimax(Board& board, int depth, bool isMaximizing);
};

#endif // OPPONENT_H
