#include "Board.h"

Board::Board()
	: m_grid(3, std::vector<char>(3, ' ')) 
{
	//EMPTY
}

void Board::Display() const
{
	for (const auto& row : m_grid)
	{
		for (char cell : row)
		{
			std::cout << (cell == ' ' ? '.' : cell) << " ";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

bool Board::MakeMove(int row, int col, char player)
{
	if (row < 0 || row >= 3 || col < 0 || col >= 3 || m_grid[row][col] != ' ')
		return false;

	m_grid[row][col] = player;
	return true;
}

bool Board::CheckWin(char player) const
{
	for (int i = 0; i < 3; ++i)
	{
		if ((m_grid[i][0] == player && m_grid[i][1] == player && m_grid[i][2] == player) || 
			(m_grid[0][i] == player && m_grid[1][i] == player && m_grid[2][i] == player))   
			return true;
	}
	if ((m_grid[0][0] == player && m_grid[1][1] == player && m_grid[2][2] == player) || 
		(m_grid[0][2] == player && m_grid[1][1] == player && m_grid[2][0] == player))   
		return true;
}

bool Board::IsFull() const
{
	for (const auto& row : m_grid) 
	{
		for (char cell : row)
		{
			if (cell == ' ')
				return false;
		}
	}
	return true;
}

void Board::Reset()
{
	for (auto& row : m_grid)
	{
		std::fill(row.begin(), row.end(), ' ');
	}
}
