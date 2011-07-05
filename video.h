#ifndef VIDEO_H
#define VIDEO_H

#include "SDL.h"
#include "SDL_image.h"

class SDL_Video{
    private:
        SDL_Rect src, dst;

    public:
        SDL_Surface *screen;
        SDL_Rect screen_m;

        ~SDL_Video();
        SDL_Video(int screenWidth, int screenHeight, const char *caption);
        SDL_Surface* LoadImg(char *filename, int transparentRed, int transparentGreen, int transparentBlue);
        void DrawSprite(SDL_Surface *image, int srcX, int srcY, int dstX, int dstY, int width, int height);
        void StartScene();
        void Render();
        SDL_Surface* GetSurface();
};

#endif
