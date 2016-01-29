#include "Game.hpp"
#include "Block.hpp"
#include "Ball.hpp"

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
    resetBlocks();
    ball.init(gfx);
}

void Game::run()
{
    while( update() )
    {
        bat.update();
        ball.update();
        
        ball.checkBatCollision(&bat);
        ball.checkBlockCollision(blocks);
        
        render();
        
        SDL_Delay(1);
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(gfx, 0, 0, 0, 255);
    SDL_RenderClear(gfx);
    
    bat.render(gfx);
    
    for (int i = 0; i < 24; i++) {
        blocks[i].render(gfx);
    }
    
    ball.render(gfx);
    
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

void Game::resetBlocks()
{
    int x = 0;
    int y = 2;
    int j = 0;
    
    for (int i = 0; i < BLOCK_COLS; i++) {
        for (int k = 0; k < BLOCK_ROWS; k++) {
            blocks[j].rect.x = x + Block::BLOCK_WIDTH;
            blocks[j].rect.y = y;
            x += Block::BLOCK_WIDTH;
            j++;
        }
        
        y += Block::BLOCK_HEIGHT + 2;
        x = 0;
    }
}

SDL_Renderer* Game::getRenderer()
{
    return gfx;
}
