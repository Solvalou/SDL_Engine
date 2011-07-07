#include "timer.h"

SDL_Timer::SDL_Timer()
{
    TimeOfLastCall = 0.0;
    DeltaTime = 0.0;
    Framerate = 60.0;
    Limit = false;
    TimeSum = 0.0;
}

void SDL_Timer::StartTime()
{
    TimeOfLastCall = SDL_GetTicks();
}

void SDL_Timer::StopTime()
{
    float temp = SDL_GetTicks();
    DeltaTime = temp - TimeOfLastCall;
    TimeSum += DeltaTime;
}

void SDL_Timer::LimitFramerate()
{
    //printf("%i, %i\n", static_cast<int>(DeltaTime), static_cast<int>((1000.0/FrameRate) - DeltaTime));
    //SDL_Delay((1000.0/FrameRate) - DeltaTime);

    if ((1000.0/Framerate) >= TimeSum)
    {
        Limit = true;
        //TimeSum = 0;
    }
    else
    {
        Limit = false;
        TimeSum = 0;
    }
}

float SDL_Timer::GetDeltaTime()
{
    return DeltaTime;
}

bool SDL_Timer::GetLimit()
{
    return Limit;
}
