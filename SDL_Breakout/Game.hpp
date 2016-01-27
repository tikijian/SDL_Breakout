
#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Game
{
private:
    SDL_Window* window;
    SDL_Renderer* gfx;
    void init();
    
    
public:
    Game();
    ~Game();
    void run();
};

