#include "video.h"

SDL_Video::SDL_Video(int screenWidth, int screenHeight, const char *caption)
{
    screen_m.w = screenWidth;
    screen_m.h = screenHeight;

    SDL_Init(SDL_INIT_EVERYTHING);

    screen = SDL_SetVideoMode(screenWidth, screenHeight, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == 0){
        exit(1);
    }

    SDL_WM_SetCaption(caption, 0);
}

SDL_Video::~SDL_Video()
{
    SDL_FreeSurface(screen);
    SDL_Quit();
}

SDL_Surface* SDL_Video::LoadImg(char *filename, int transparentRed, int transparentGreen, int transparentBlue)
{
    SDL_Surface *image;
    SDL_Surface *temp = IMG_Load(filename);

    image = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    if (image == 0)
    {
        exit(1);
    }

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, transparentRed, transparentGreen, transparentBlue));

    return image;
}

void SDL_Video::DrawSprite(SDL_Surface *image, int srcX, int srcY, int dstX, int dstY, int width, int height)
{
    src.x = srcX;
    src.y = srcY;
    src.w = width;
    src.h = height;

    dst.x = dstX;
    dst.y = dstY;
    dst.w = width;
    dst.h = height;

    SDL_BlitSurface(image, &src, screen, &dst);
}

void SDL_Video::StartScene()
{
    SDL_FillRect(screen, 0, 0);
}

void SDL_Video::Render()
{
    SDL_Flip(screen);
}

SDL_Surface* SDL_Video::GetSurface()
{
    return screen;
}

