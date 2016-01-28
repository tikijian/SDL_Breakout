#pragma once


#include <SDL2/SDL.h>
#include "AbstractGameObject.hpp"

class GameObject: AbstractGameObject
{
public:
    Uint8 red   = 0;
    Uint8 green = 0;
    Uint8 blue  = 0;
    SDL_Rect rect;
    
    void render(SDL_Renderer* gfx);
    void update();
    SDL_Color getColor();
};