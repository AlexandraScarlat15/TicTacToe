//#include "Opponent.h"
//
//Opponent::Opponent(char symbol) : Player(symbol) 
//{
//	//EMPTY
//}
//
////void Opponent::MakeMove(Board& board, int& row, int& col)
////{
////    int bestScore = std::numeric_limits<int>::min();
////    row = -1, col = -1;
////
////    for (int i = 0; i < 3; i++)
////    {
////        for (int j = 0; j < 3; j++) 
////        {
////            if (board.MakeMove(i, j, m_symbol)) 
////            {
////                int score = Minimax(board, 0, false);
////                board.MakeMove(i, j, ' '); 
////
////                if (score > bestScore)
////                {
////                    bestScore = score;
////                    row = i;
////                    col = j;
////                }
////            }
////        }
////    }
////}
////void Opponent::MakeMove(int& row, int& col) {
////    int bestScore = std::numeric_limits<int>::min();
////    row = -1, col = -1;
////
////    for (int i = 0; i < 3; i++) {
////        for (int j = 0; j < 3; j++) {
////            if (m_board->MakeMove(i, j, m_symbol)) 
////            { 
////                int score = Minimax(*m_board, 0, false);
////                m_board->MakeMove(i, j, ' ');
////
////                if (score > bestScore) {
////                    bestScore = score;
////                    row = i;
////                    col = j;
////                }
////            }
////        }
////    }
////}
//void Opponent::MakeMove(int& row, int& col) {
//    std::cout << "AI is selecting a move...\n";
//
//    int bestScore = std::numeric_limits<int>::min();
//    row = -1, col = -1;
//
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            if (m_board->MakeMove(i, j, m_symbol)) {
//                int score = Minimax(*m_board, 0, false);
//                m_board->MakeMove(i, j, ' ');
//
//                if (score > bestScore) {
//                    bestScore = score;
//                    row = i;
//                    col = j;
//                }
//            }
//        }
//    }
//
//    std::cout << "AI selected move: " << row << ", " << col << std::endl;
//}
//
//
//
//int Opponent::Minimax(Board& board, int depth, bool isMaximizing)
//{
//    char opponent = (m_symbol == 'X') ? 'O' : 'X';
//
//    if (board.CheckWin(m_symbol)) return 10 - depth;
//    if (board.CheckWin(opponent)) return depth - 10;
//    if (board.IsFull()) return 0;
//
//    if (isMaximizing) {
//        int bestScore = std::numeric_limits<int>::min();
//        for (int i = 0; i < 3; i++) 
//        {
//            for (int j = 0; j < 3; j++) 
//            {
//                if (board.MakeMove(i, j, m_symbol)) 
//                { 
//                    int score = Minimax(board, depth + 1, false);
//                    board.MakeMove(i, j, ' ');
//                    bestScore = std::max(bestScore, score);
//                }
//            }
//        }
//        return bestScore;
//    }
//    else 
//    {
//        int bestScore = std::numeric_limits<int>::max();
//        for (int i = 0; i < 3; i++)
//        {
//            for (int j = 0; j < 3; j++) 
//            {
//                if (board.MakeMove(i, j, opponent)) 
//                {
//                    int score = Minimax(board, depth + 1, true);
//                    board.MakeMove(i, j, ' ');
//                    bestScore = std::min(bestScore, score);
//                }
//            }
//        }
//        return bestScore;
//    }
//}

#include "Opponent.h"
#include <iostream>

Opponent::Opponent(char symbol, Board* board) : Player(symbol), m_Board(board) {}

void Opponent::MakeMove(int& row, int& col) {
    std::cout << "AI selecting move...\n";

    int bestScore = std::numeric_limits<int>::min();
    row = -1, col = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m_Board->MakeMove(i, j, m_symbol)) {
                int score = Minimax(*m_Board, 0, false);
                m_Board->MakeMove(i, j, ' ');

                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    if (row == -1 || col == -1) {
        std::cout << "ERROR: AI didn't select a valid move!\n";
    }
    else {
        std::cout << "AI selected move: " << row << ", " << col << std::endl;
    }
}

int Opponent::Minimax(Board& board, int depth, bool isMaximizing) {
    char opponent = (m_symbol == 'X') ? 'O' : 'X';

    if (board.CheckWin(m_symbol)) return 10 - depth;
    if (board.CheckWin(opponent)) return depth - 10;
    if (board.IsFull()) return 0;

    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.MakeMove(i, j, m_symbol)) {
                    int score = Minimax(board, depth + 1, false);
                    board.MakeMove(i, j, ' ');
                    bestScore = std::max(bestScore, score);
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.MakeMove(i, j, opponent)) {
                    int score = Minimax(board, depth + 1, true);
                    board.MakeMove(i, j, ' ');
                    bestScore = std::min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}
