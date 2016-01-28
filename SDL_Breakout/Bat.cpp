#include "Bat.hpp"
#include "Game.hpp"


Bat::Bat()
{
    rect.w = BAT_WIDTH;
    rect.h = BAT_HEIGHT;
    rect.x = Game::SCREEN_W / 2 - 40;
    rect.y = 420;
    red = 255; green = 255; blue = 255;
}

void Bat::render(SDL_Renderer *gfx)
{
    SDL_SetRenderDrawColor(gfx, red, green, blue, 255);
    SDL_RenderFillRect(gfx, &rect);
}

void Bat::update()
{
    const Uint8 *aKeys = SDL_GetKeyboardState(NULL);
    if(aKeys[SDL_SCANCODE_LEFT]) {
        rect.x -= 10;
        if(rect.x < 0)
            rect.x = 0;
    }
    if(aKeys[SDL_SCANCODE_RIGHT]) {
        rect.x += 10;
        if (rect.x > Game::SCREEN_W - BAT_WIDTH) 
            rect.x = Game::SCREEN_W - BAT_WIDTH;
        
    }
}