
#pragma once

#include <SDL2/SDL.h>
#include "GameObject.hpp"

class Block: public GameObject
{
public:
    static const Uint8 BLOCK_WIDTH  = 80;
    static const Uint8 BLOCK_HEIGHT = 20;
    
    Block();
    
    void render(SDL_Renderer *gfx);
    void update();
    void init();
};
