#ifndef FONT_H
#define FONT_H

#include <string.h>

#include "SDL.h"
#include "SDL_ttf.h"

#include "video.h"
#include "timer.h"

#include <iostream>
#include <sstream>

using namespace std;

class SDL_Font
{
    private:
        SDL_Video *video;
        SDL_Timer *timer;
        SDL_Surface *message;
        TTF_Font *font;
        SDL_Rect dst;
        SDL_Color textColor;
        int frameCount;
        float fps;
        float time;

        std::string s;
        std::stringstream out;

    public:
        SDL_Font(SDL_Video *videoMain, SDL_Timer *timerMain);
        void DrawFPS();
};

#endif
