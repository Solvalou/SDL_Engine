#include "input.h"

SDL_Input::SDL_Input()
{
    left = false;
    right = false;
    down = false;
    up = false;

    GameRunning = true;
}

void SDL_Input::Read()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                GameRunning = false;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        GameRunning = false;

                    case SDLK_LEFT:
                        left = true;
                        break;

                    case SDLK_RIGHT:
                        right = true;
                        break;

                    case SDLK_DOWN:
                        down = true;
                        break;

                    case SDLK_UP:
                        up = true;
                        break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        left = false;
                        break;

                    case SDLK_RIGHT:
                        right = false;
                        break;

                    case SDLK_DOWN:
                        down = false;
                        break;

                    case SDLK_UP:
                        up = false;
                        break;
                }
                break;
        }
    }
}
