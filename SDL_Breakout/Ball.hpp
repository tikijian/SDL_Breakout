#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "GameObject.hpp"
//#include "Bat.hpp"

class Ball: public GameObject
{
public:
    static const Uint8 WIDTH  = 20;
    static const Uint8 HEIGHT = 20;
    int velX = 0;
    int velY = 0;
    SDL_Texture *texture = NULL;
    
    Ball();
    ~Ball();
    
    void render(SDL_Renderer *gfx);
    void update();
    void init(SDL_Renderer *gfx);
    void checkBatCollision(Bat *bat);
    void checkBlockCollision(Block *blocks);
};
