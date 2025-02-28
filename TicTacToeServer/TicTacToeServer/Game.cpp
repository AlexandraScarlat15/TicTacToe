//#include "Game.h"
//
//Game::Game(Player* playerX, Player* playerO)
//    : m_playerX(playerX)
//    , m_playerO(playerO)
//    , m_currentTurn('X')
//    , m_gameOver(false)
//{
//    // EMPTY
//}
//
//void Game::DisplayBoard() const
//{
//    m_board.Display();
//}
//
//bool Game::MakeMove(int row, int col)
//{
//    if (m_gameOver)
//        return false;
//
//    if (m_board.MakeMove(row, col, m_currentTurn))
//    {
//        if (m_board.CheckWin(m_currentTurn))
//        {
//            m_gameOver = true;
//            return true;
//        }
//        if (m_board.IsFull())
//        {
//            m_gameOver = true;
//            return false;
//        }
//        m_currentTurn = (m_currentTurn == 'X') ? 'O' : 'X';
//        return true;
//    }
//    return false;
//}
//
//bool Game::IsGameOver() const
//{
//    return m_gameOver;
//}
//
//char Game::GetWinner() const
//{
//    if (!m_gameOver) return ' ';
//    return (m_board.CheckWin('X')) ? 'X' : (m_board.CheckWin('O') ? 'O' : ' ');
//}
//
////void Game::Start()
////{
////    int row, col;
////    DisplayBoard();
////
////    while (!m_gameOver)
////    {
////        if (m_currentTurn == 'X')
////        {
////            std::cout << "Player X, enter your move (row and col): ";
////            std::cin >> row >> col;
////        }
////        else
////        {
////            Opponent* ai = dynamic_cast<Opponent*>(m_playerO);
////            if (ai) ai->MakeMove(row, col);
////        }
////
////        if (MakeMove(row, col))
////        {
////            DisplayBoard();
////        }
////        else
////        {
////            std::cout << "Invalid move! Try again.\n";
////        }
////    }
////
////    char winner = GetWinner();
////    if (winner == ' ')
////    {
////        std::cout << "Game Over! It's a draw.\n";
////    }
////    else
////    {
////        std::cout << "Game Over! Winner: " << winner << "\n";
////    }
////}
//void Game::Start()
//{
//    int row, col;
//    DisplayBoard();
//
//    while (!m_gameOver)
//    {
//        std::cout << "Current turn: " << m_currentTurn << std::endl;
//
//        if (m_currentTurn == 'X')
//        {
//            std::cout << "Player X, enter your move (row and col): ";
//            std::cin >> row >> col;
//        }
//        else
//        {
//            Opponent* ai = dynamic_cast<Opponent*>(m_playerO);
//            if (ai) {
//                std::cout << "AI is making a move...\n";
//                ai->MakeMove(row, col);
//                std::cout << "AI chose: " << row << ", " << col << std::endl;
//            }
//        }
//
//        if (MakeMove(row, col))
//        {
//            DisplayBoard();
//        }
//        else
//        {
//            std::cout << "Invalid move! Try again.\n";
//        }
//    }
//
//    char winner = GetWinner();
//    if (winner == ' ')
//    {
//        std::cout << "Game Over! It's a draw.\n";
//    }
//    else
//    {
//        std::cout << "Game Over! Winner: " << winner << "\n";
//    }
//}

#include "Game.h"
#include <iostream>

Game::Game(Player* playerX, Player* playerO)
    : m_PlayerX(playerX), m_PlayerO(playerO), m_CurrentTurn('X'), m_GameOver(false) {
}

void Game::DisplayBoard() const {
    m_Board.Display();
}

bool Game::MakeMove(int row, int col) {
    if (m_GameOver) return false;

    if (m_Board.MakeMove(row, col, m_CurrentTurn)) {
        if (m_Board.CheckWin(m_CurrentTurn)) {
            m_GameOver = true;
            return true;
        }
        if (m_Board.IsFull()) {
            m_GameOver = true;
            return false;
        }
        m_CurrentTurn = (m_CurrentTurn == 'X') ? 'O' : 'X';
        return true;
    }
    return false;
}

bool Game::IsGameOver() const {
    return m_GameOver;
}

char Game::GetWinner() const {
    if (!m_GameOver) return ' ';
    return (m_Board.CheckWin('X')) ? 'X' : (m_Board.CheckWin('O') ? 'O' : ' ');
}

void Game::Start() {
    int row, col;
    DisplayBoard();
    
    while (!m_GameOver) {
        std::cout << "Current turn: " << m_CurrentTurn << std::endl;

        if (m_CurrentTurn == 'X') {
            std::cout << "Player X, enter your move (row and col): ";
            std::cin >> row >> col;
            if (MakeMove(row, col)) {
                DisplayBoard();
            }
            else {
                std::cout << "Invalid move! Try again.\n";
                continue;
            }
        }

        if (!m_GameOver && m_CurrentTurn == 'O') {
            Opponent* ai = dynamic_cast<Opponent*>(m_PlayerO);
            if (ai) {
                std::cout << "AI is making a move...\n";
                ai->MakeMove(row, col);
                std::cout << "AI chose: " << row << ", " << col << std::endl;
                MakeMove(row, col); // Ensure AI's move is applied
                DisplayBoard();
            }
        }
    }

    char winner = GetWinner();
    if (winner == ' ') {
        std::cout << "Game Over! It's a draw.\n";
    }
    else {
        std::cout << "Game Over! Winner: " << winner << "\n";
    }
}
