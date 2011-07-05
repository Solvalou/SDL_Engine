#include "character.h"

SDL_Character::SDL_Character(SDL_Video *videoMain, SDL_Input *inputMain, SDL_Timer *timerMain, SDL_Surface *charSurf, SDL_Rect srcIn, SDL_Rect dstIn)
{
    speed = 1;
    FrameCount = 0;
    SetFrame();

    x_velocity = 0.1;
    y_velocity = 0.1;
    dstX = dstIn.x;
    dstY = dstIn.y;

    character = charSurf;
    video = videoMain;
    input = inputMain;
    timer = timerMain;

    src = srcIn;
    dst = dstIn;
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
            dstX = (dstX - x_velocity * (timer->DeltaTime));
        }
    }

    if (input->right == true)
    {
        if (dstX < ((video->screen_m.w) - dst.w))
        {
            dstX = (dstX + x_velocity * (timer->DeltaTime));;
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
            dstY = dstY - speed;
        }
    }

    if (input->down == true)
    {
        if (dstY < ((video->screen_m.h) - dst.h))
        {
            dstY = dstY + speed;
        }
    }

    if (!(input->up || input->down || input->left || input->right))
    {
        Animate();
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
    switch (FrameCount)
    {
        case 0:
            src = frame[0];
            dst.w = frame[0].w;
            dst.h = frame[0].h;
            break;

        case 1:
            src = frame[1];
            dst.w = frame[1].w;
            dst.h = frame[1].h;
            break;

        case 2:
            src = frame[2];
            dst.w = frame[2].w;
            dst.h = frame[2].h;
            break;

        case 3:
            src = frame[3];
            dst.w = frame[3].w;
            dst.h = frame[3].h;
            break;

        case 4:
            FrameCount = 0;
            break;
    }
}

void SDL_Character::AnimateRight()
{
    switch (FrameCount)
    {
        case 0:
            src = frameRight[0];
            dst.w = frameRight[0].w;
            dst.h = frameRight[0].h;
            break;

        case 1:
            src = frameRight[1];
            dst.w = frameRight[1].w;
            dst.h = frameRight[1].h;
            break;

        case 2:
            src = frameRight[2];
            dst.w = frameRight[2].w;
            dst.h = frameRight[2].h;
            break;

        case 3:
            FrameCount = 0;
            break;
    }
}

void SDL_Character::AnimateLeft()
{

}

void SDL_Character::SetFrame()
{
    frame[0].x = 172;
    frame[0].y = 37;
    frame[0].w = 20;
    frame[0].h = 24;

    frame[1].x = 195;
    frame[1].y = 39;
    frame[1].w = 24;
    frame[1].h = 22;

    frame[2].x = 221;
    frame[2].y = 37;
    frame[2].w = 16;
    frame[2].h = 24;

    frame[3].x = 239;
    frame[3].y = 39;
    frame[3].w = 21;
    frame[3].h = 22;

    frameRight[0].x = 195;
    frameRight[0].y = 39;
    frameRight[0].w = 24;
    frameRight[0].h = 22;

    frameRight[1].x = 221;
    frameRight[1].y = 37;
    frameRight[1].w = 16;
    frameRight[1].h = 24;

    frameRight[2].x = 239;
    frameRight[2].y = 39;
    frameRight[2].w = 21;
    frameRight[2].h = 22;
}
