#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

class SDL_Timer
{
    private:
        float TimeOfLastCall;
        float Framerate;

    public:
        float DeltaTime;
        float TimeSum;
        bool Limit;

        SDL_Timer();
        void StartTime();
        void StopTime();
        void LimitFramerate();
        float GetDeltaTime();
        bool GetLimit();
};

#endif
