#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board
{
private:
	std::vector<std::vector<char>> m_grid;

public:
	//CONSTRUCTOR
	Board();

	//METHODS
	void Display() const; 
	bool MakeMove(int row, int col, char player); 
	bool CheckWin(char player) const; 
	bool IsFull() const; 
	void Reset();

};

#endif // BOARD_H