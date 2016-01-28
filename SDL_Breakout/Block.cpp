#include "Block.hpp"
#include "Game.hpp"
#include <stdlib.h>
#include <iostream>

Block::Block()
{
    rect.w = BLOCK_WIDTH;
    rect.h = BLOCK_HEIGHT;
    
    init();
}

void Block::render(SDL_Renderer *gfx)
{
    SDL_SetRenderDrawColor(gfx, red, green, blue, 255);
    SDL_RenderFillRect(gfx, &rect);
}

void Block::update()
{

}

void Block::init()
{
    red = rand() % 255;
    green = rand() % 255;
    blue = rand() % 255;
}