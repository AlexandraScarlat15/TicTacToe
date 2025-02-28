//#include "Game.h"
//
//int main() {
//    HumanPlayer playerX('X');
//    Opponent ai('O');
//
//    Game game(&playerX, &ai);
//    game.Start();
//
//    return 0;
//}
#include "Game.h"

int main() {
    HumanPlayer playerX('X');
    Board board;
    Opponent ai('O', &board);

    Game game(&playerX, &ai);
    game.Start();

    return 0;
}
