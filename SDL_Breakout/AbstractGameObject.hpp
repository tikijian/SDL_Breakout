# pragma once

#include <SDL2/SDL.h>

class AbstractGameObject
{
public:
    virtual void render(SDL_Renderer* gfx) = 0;
    virtual void update() = 0;
};