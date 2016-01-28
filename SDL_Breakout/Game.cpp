#include "Game.hpp"


Game::Game()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("Breakout!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, 0);
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
    while( update() )
    {
        bat.update();
        
        render();
        
        SDL_Delay(1);
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(gfx, 0, 0, 0, 255);
    SDL_RenderClear(gfx);
    
    bat.render(gfx);
    
    SDL_RenderPresent(gfx);
}

bool Game::update()
{
    SDL_Event event;
    bool is_running = true;
    
    // Check for events
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_WINDOWEVENT_CLOSE:
                SDL_DestroyWindow(window);
                window = NULL;
                is_running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        is_running = false;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                is_running = false;
                break;
        }
    }
    
    return is_running;
}

SDL_Renderer* Game::getRenderer()
{
    return gfx;
}
