#ifndef CHARACTER_H
#define CHARACTER_H

#include "SDL.h"
#include "input.h"
#include "video.h"
#include "timer.h"

class SDL_Character
{
    private:
        int speed;
        int FrameCount;

        float x_velocity;
        float y_velocity;
        float dstX, dstY;

        SDL_Rect src, dst;
        SDL_Rect frame[4];      //Number of frames is 4
        SDL_Rect frameLeft[4];
        SDL_Rect frameRight[4];

        SDL_Surface *character;
        SDL_Video *video;
        SDL_Input *input;
        SDL_Timer *timer;

        void SetFrame();

    public:
        SDL_Character(SDL_Video *videoMain, SDL_Input *inputMain, SDL_Timer *timerMain, SDL_Surface *charSurf, SDL_Rect srcIn, SDL_Rect dstIn);
        ~SDL_Character();
        void Move();
        void Draw();
        void Animate();
        void AnimateRight();
        void AnimateLeft();
};

#endif
