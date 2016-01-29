#include "Game.hpp"


Ball::Ball()
{
    rect.w = WIDTH;
    rect.h = HEIGHT;
    rect.x = 300;
    rect.y = 300;
    velX = rand() % 16 + (-8);
    velY = rand() % 16 + (-8);
}

Ball::~Ball()
{
    SDL_DestroyTexture(texture);
}

void Ball::init(SDL_Renderer *gfx)
{
    // Load image
    SDL_Surface *yobaSurface = IMG_Load("yoba.png");
    if (yobaSurface == NULL) {
        printf("Can't find yoba.png!");
        SDL_Quit();
        exit(1);
    }
    // set texture
    texture = SDL_CreateTextureFromSurface(gfx, yobaSurface);
    SDL_FreeSurface(yobaSurface);
}

void Ball::render(SDL_Renderer *gfx)
{
    SDL_RenderCopy(gfx, texture, NULL, &rect);
}

void Ball::update()
{
    rect.x += velX;
    rect.y += velY;
    
    if (rect.x < 0)
        velX = abs(velX);
    else if(rect.x > Game::SCREEN_W - WIDTH)
        velX = -(velX);
    
    if (rect.y < 0)
        velY = abs(velY);
    else if (rect.y > Game::SCREEN_H - HEIGHT)
        velY = -(velY);
}

void Ball::checkBatCollision(Bat *bat)
{
    SDL_Rect r;
    if (SDL_IntersectRect(&rect, &bat->rect, &r) == SDL_TRUE ) {
        velY = -(velY);
    }
}

void Ball::checkBlockCollision(Block *blocks)
{
    SDL_Rect r;
    for (int i = 0; i < Game::BLOCKS_COUNT; i++) {
        if (blocks[i].isDestroyed)
            continue;
        
        if (SDL_IntersectRect(&rect, &blocks[i].rect, &r) == SDL_TRUE ) {
            blocks[i].isDestroyed = true;
            velY = abs(velY);
        }
    }
}

