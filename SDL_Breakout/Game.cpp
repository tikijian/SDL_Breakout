#include "Game.hpp"


Game::Game()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("Breakout!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    gfx = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    init();
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(gfx);
    
    SDL_Quit();
}

void Game::init()
{
    
}

void Game::run()
{
    SDL_Delay(3000);
}

