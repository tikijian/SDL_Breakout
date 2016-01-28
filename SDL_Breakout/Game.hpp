
#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "Bat.hpp"


class Game
{
private:
    SDL_Window* window = NULL;
    SDL_Renderer* gfx = NULL;
    
    void init();
    
public:
    static const int SCREEN_W = 640;
    static const int SCREEN_H = 480;
    Bat bat;
    
    Game();
    ~Game();
    void run();
    void render();
    bool update();
    SDL_Renderer* getRenderer();
};

