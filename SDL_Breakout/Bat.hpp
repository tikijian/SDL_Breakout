#pragma once

#include <SDL2/SDL.h>
#include "GameObject.hpp"

class Bat: public GameObject
{

public:
    const Uint8 BAT_WIDTH  = 80;
    const Uint8 BAT_HEIGHT = 20;
    
    Bat();

    void render(SDL_Renderer *gfx);
    void update();
};