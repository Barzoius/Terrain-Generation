#include <iostream>
#include "SDL.h"
#include "SDL_opengl.h"

#define WinW 256
#define WinH 256

int main(int, char**) {
    SDL_Window* win;
    SDL_Renderer* ren;

    SDL_Event event;
    
    bool isRunning;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        win = SDL_CreateWindow("Terr", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WinW, WinH, 0);

        if(win){
            std::cout<<"WINDOW CREATED "<<std::endl;
        }

        ren = SDL_CreateRenderer(win, - 1, 0);

        if(ren){
            SDL_SetRenderDrawColor(ren, 27, 27, 26, 255);
            std::cout<<"RENDERER CREATED "<<std::endl;
        }

        isRunning = true;
    }
    else{
        isRunning = false;
    }

    while(isRunning)
    {
        frameStart = SDL_GetTicks();

        SDL_PollEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;

            default: break;
        }

        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

