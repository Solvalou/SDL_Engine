#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"

class SDL_Input{
    private:
        SDL_Event event;

    public:
        bool left;
        bool right;
        bool down;
        bool up;
        bool GameRunning;

        SDL_Input();
        void Read();
};

#endif
