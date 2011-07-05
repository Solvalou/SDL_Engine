#include "font.h"

SDL_Font::SDL_Font(SDL_Video *videoMain, SDL_Timer *timerMain)
{
    video = videoMain;
    timer = timerMain;
    font = NULL;
    dst.x = 5;
    dst.y = 5;
    frameCount = 0;

    textColor = {255, 255, 255};

    if (TTF_Init() == -1)
    {
        exit(1);
    }

    font = TTF_OpenFont("DejaVuSans.ttf", 12);
    if (font == NULL)
    {
        exit(1);
    }
}

void SDL_Font::DrawFPS()
{
    frameCount++;
    if (frameCount >= 60)
    {
        float fps = (frameCount/Time);
    }

    float i = timer->DeltaTime;
    std::string s;
    std::stringstream out;
    out << i;
    s = out.str();

    const char * string = s.c_str();

    message = TTF_RenderText_Solid(font, string, textColor);
    if (message == NULL)
    {
        exit(1);
    }
    SDL_BlitSurface(message, 0, video->screen, 0);
}
