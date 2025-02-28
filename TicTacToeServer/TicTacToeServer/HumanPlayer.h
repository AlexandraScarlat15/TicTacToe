#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    explicit HumanPlayer(char symbol);
    void MakeMove(int& row, int& col) override;
};

#endif // HUMANPLAYER_H
