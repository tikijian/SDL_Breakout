
#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "Bat.hpp"
#include "Block.hpp"
#include "Ball.hpp"


class Game
{
private:
    SDL_Window* window = NULL;
    SDL_Renderer* gfx = NULL;
    
    void init();
    void resetBlocks();
    
public:
    static const int SCREEN_W = 640;
    static const int SCREEN_H = 480;
    static const int BLOCK_COLS = 4;
    static const int BLOCK_ROWS = 6;
    
    Bat bat;
    Ball ball;
    Block blocks[24];
    
    Game();
    ~Game();
    void run();
    void render();
    bool update();
    SDL_Renderer* getRenderer();
};

