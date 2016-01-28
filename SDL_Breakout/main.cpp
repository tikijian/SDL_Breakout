#include <stdlib.h>
#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL)); // init random seed
    Game game;
    game.run();
    return 0;
}
