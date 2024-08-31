#include <SDL2/SDL.h>
#include "drawRect.hpp"
#include <iostream>
#include "Player.hpp"
#include "EnemyHandler.hpp"
#include "BulletManager.hpp"

bool keyboard[512];

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("wdwd wd",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if (!window)
    {
        std::cout << "Failed to create window\n";
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << "Failed to create renderer\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    bool isOpen = true;

    Player obj;
    EnemyHandler handler;
    BulletManager manager;
        //manager.addBullet(300, 300);
    for (int eNum = 0; eNum < 20; eNum++) {

        handler.addEnemy((rand() % 480)+100, eNum * -300, eNum);
    }

    while (isOpen)
    {
        Uint64 start = SDL_GetPerformanceCounter();
        SDL_Event e;
        while (SDL_PollEvent(&e) > 0)
        {
            if (e.type == SDL_QUIT)
            {
                isOpen = false;
            }
            
            if (e.type == SDL_KEYDOWN) {
                keyboard[e.key.keysym.sym] = true;
                
            }
            if (e.type == SDL_KEYUP) {
                keyboard[e.key.keysym.sym] = false;
            }
        }
        
        // Clear the renderer with a background color (e.g., black)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderClear(renderer);

        SDL_Color red = {255, 0, 0, 255};
        SDL_Color blue = {0, 255, 0, 255};
        SDL_Color black = {0, 0, 0, 255};

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        obj.movePlayer(keyboard, &manager);

        for (int e = 0; e < handler.enemies.size(); e++) {
            drawRect::DrawFilledRect(renderer, handler.enemies[e].x, handler.enemies[e].y, 50, 50, blue);
            handler.enemies[e].update();
        }

        for (int b = 0; b < manager.bullets.size(); b++) {
            drawRect::DrawFilledRect(renderer, manager.bullets[b].x, manager.bullets[b].y, 30, 30, black);
            manager.bullets[b].update(&handler.enemies, &manager.bullets);

        }

        drawRect::DrawFilledRect(renderer, obj.playerX-25, 300, 50, 50, red);


        SDL_RenderPresent(renderer);
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

        // Cap to 120 FPS
        SDL_Delay(floor(8.33333333f - elapsedMS));
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
