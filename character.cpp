#include "character.h"

SDL_Character::SDL_Character(SDL_Video *videoMain, SDL_Input *inputMain, SDL_Timer *timerMain, SDL_Surface *spritesheet, SDL_Rect startPosition,
                                int stanceFrames, SDL_Rect srcStance1, SDL_Rect srcStance2, SDL_Rect srcStance3,
                                int leftFrames, SDL_Rect srcLeft1, SDL_Rect srcLeft2, SDL_Rect srcLeft3,
                                int rightFrames, SDL_Rect srcRight1, SDL_Rect srcRight2, SDL_Rect srcRight3)
{
    FrameCount = 0;
    numberOfFrames_Stance = stanceFrames;
    numberOfFrames_Left = leftFrames;
    numberOfFrames_Right = rightFrames;

    frameStance[0] = srcStance1;
    frameStance[1] = srcStance2;
    frameStance[2] = srcStance3;

    frameLeft[0] = srcLeft1;
    frameLeft[1] = srcLeft2;
    frameLeft[2] = srcLeft3;

    frameRight[0] = srcRight1;
    frameRight[1] = srcRight2;
    frameRight[2] = srcRight3;

    x_velocity = 0.1;
    y_velocity = 0.1;
    dstX = startPosition.x;
    dstY = startPosition.y;

    character = spritesheet;
    video = videoMain;
    input = inputMain;
    timer = timerMain;

    src = startPosition;
    dst = frameStance[0];

    timeSum = 0.0;

    step1 = false;
    step2 = false;
    step3 = false;
    step4 = false;
}

SDL_Character::~SDL_Character()
{
    SDL_FreeSurface(character);
}

void SDL_Character::Move()
{
    if (input->left == true)
    {
        if (dstX > 0)
        {
            // dst.x = dst.x - speed;
            dstX = (dstX - x_velocity * (timer->GetDeltaTime()));
            if (input->right == false)
            {
                AnimateLeft();
            }
        }
    }

    if (input->right == true)
    {
        if (dstX < ((video->screen_m.w) - dst.w ))
        {
            dstX = (dstX + x_velocity * (timer->GetDeltaTime()));;
            if (input->left == false)
            {
                AnimateRight();
            }
        }
    }

    if (input->up == true)
    {
        if (dstY > 0)
        {
        }
    }

    if (input->down == true)
    {
        if (dstY < ((video->screen_m.h) - dst.h))
        {
        }
    }

    if (!(input->up || input->down || input->left || input->right))
    {
        AnimateStance();
    }
}

void SDL_Character::Draw()
{
    dst.x = static_cast<int>(dstX);
    dst.y = static_cast<int>(dstY);

    SDL_BlitSurface(character, &src, video->screen, &dst);
    FrameCount++;
}

void SDL_Character::Animate()
{
    timeSum += timer->GetDeltaTime();
    if (numberOfFrames >= 1)
    {
        if ((timeSum >= 0) && (timeSum < 10000/60))
        {
            printf("Step1\n");
            src = frame[0];
            dst.w = frame[0].w;
            dst.h = frame[0].h;
        }

        if (numberOfFrames >= 2)
        {
            if ((timeSum >= 10000/60) && (timeSum < 20000/60))
            {
                printf("Step2\n");
                src = frame[1];
                dst.w = frame[1].w;
                dst.h = frame[1].h;
            }

            if (numberOfFrames >= 3)
            {
                if ((timeSum >= 20000/60) && (timeSum < 30000/60))
                {
                    printf("Step3\n");
                    src = frame[2];
                    dst.w = frame[2].w;
                    dst.h = frame[2].h;
                }
            }
        }
    }

    if (timeSum > (30000/60))
    {
        printf("Step4\n");
        timeSum = 0.0;
    }
}

void SDL_Character::AnimateStance()
{
    frame[0] = frameStance[0];
    frame[1] = frameStance[1];
    frame[2] = frameStance[2];
    numberOfFrames = numberOfFrames_Stance;
    Animate();
}

void SDL_Character::AnimateRight()
{
    frame[0] = frameRight[0];
    frame[1] = frameRight[1];
    frame[2] = frameRight[2];
    numberOfFrames = numberOfFrames_Right;
    Animate();
}

void SDL_Character::AnimateLeft()
{
    frame[0] = frameLeft[0];
    frame[1] = frameLeft[1];
    frame[2] = frameLeft[2];
    numberOfFrames = numberOfFrames_Left;
    Animate();
}
