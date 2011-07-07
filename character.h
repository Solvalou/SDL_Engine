#ifndef CHARACTER_H
#define CHARACTER_H

#include "SDL.h"
#include "input.h"
#include "video.h"
#include "timer.h"

class SDL_Character
{
    private:
        int FrameCount;
        int numberOfFrames;
        int numberOfFrames_Stance;
        int numberOfFrames_Left;
        int numberOfFrames_Right;

        bool step1;
        bool step2;
        bool step3;
        bool step4;

        float x_velocity;
        float y_velocity;
        float dstX, dstY;

        SDL_Rect src, dst;
        SDL_Rect frame[4];
        SDL_Rect frameStance[4];      //Number of frames is 4
        SDL_Rect frameLeft[4];
        SDL_Rect frameRight[4];

        SDL_Surface *character;
        SDL_Video *video;
        SDL_Input *input;
        SDL_Timer *timer;

        float timeSum;

        void Animate();
        void AnimateStance();
        void AnimateRight();
        void AnimateLeft();

    public:
        SDL_Character(SDL_Video *videoMain, SDL_Input *inputMain, SDL_Timer *timerMain, SDL_Surface *spritesheet, SDL_Rect startPosition,
                        int stanceFrames, SDL_Rect srcStance1, SDL_Rect srcStance2, SDL_Rect srcStance3,
                        int leftFrames, SDL_Rect srcLeft1, SDL_Rect srcLeft2, SDL_Rect srcLeft3,
                        int rightFrames, SDL_Rect srcRight1, SDL_Rect srcRight2, SDL_Rect srcRight3);

        ~SDL_Character();
        void Move();
        void Draw();
};

#endif
