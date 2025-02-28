#ifndef PLAYER_H
#define PLAYER_H

class Player {
protected:
    char m_symbol;

public:

    //CONSTRUCTOR
    explicit Player(char s);

    //METHODS
    virtual ~Player() = default;
    char getSymbol() const;

    //virtual void MakeMove(int& row, int& col) = 0;
    virtual void MakeMove(int& row, int& col) = 0;
};

#endif
