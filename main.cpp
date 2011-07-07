#include "defs.h"

int main (int argc, char *argv[])
{
    //+---------------------------------------------------------+
    //| INITIALIZATION OF VARIABLES                             |
    //+---------------------------------------------------------+

    const int screenWidth = 512;
    const int screenHeight = 480;
    const char *caption = "SDL_Test starring MegaMan";

    //+---------------------------------------------------------+
    //| INITIALIZATION OF SUBSYSTEMS                            |
    //+---------------------------------------------------------+

    //define main video-surface
    SDL_Video *video = NULL;
    video = new SDL_Video(screenWidth, screenHeight, caption);

    //define input
    SDL_Input *input = NULL;
    input = new SDL_Input;

    //define timer
    SDL_Timer *timer = NULL;
    timer = new SDL_Timer;

    //+---------------------------------------------------------+
    //| INITIALIZATION OF CHARACTER  - MEGAMAN                  |
    //+---------------------------------------------------------+

    SDL_Surface *megaMan;
    megaMan = video->LoadImg("MegaManSheet.png", 0xFF, 0, 0xFF);

    // - Stance Animation -

    int framesStance = 1;
    SDL_Rect dummyRect;
    SDL_Rect srcStance, dstStartPosition;

    srcStance.x = 172;
    srcStance.y = 37;
    srcStance.w = 20;
    srcStance.h = 24;

    dstStartPosition.x = 20;
    dstStartPosition.y = 24;
    dstStartPosition.w = srcStance.w;
    dstStartPosition.h = srcStance.h;

    // - Left Animation -

    int framesLeft = 3;
    SDL_Rect srcLeft[framesLeft];

    srcLeft[0].x = 115;
    srcLeft[0].y = 39;
    srcLeft[0].w = 24;
    srcLeft[0].h = 23;

    srcLeft[1].x = 97;
    srcLeft[1].y = 37;
    srcLeft[1].w = 16;
    srcLeft[1].h = 24;

    srcLeft[2].x = 74;
    srcLeft[2].y = 39;
    srcLeft[2].w = 21;
    srcLeft[2].h = 22;

    // - Right Animation -

    int framesRight = 3;
    SDL_Rect srcRight[framesRight];

    srcRight[0].x = 195;
    srcRight[0].y = 39;
    srcRight[0].w = 24;
    srcRight[0].h = 22;

    srcRight[1].x = 221;
    srcRight[1].y = 37;
    srcRight[1].w = 16;
    srcRight[1].h = 24;

    srcRight[2].x = 239;
    srcRight[2].y = 39;
    srcRight[2].w = 21;
    srcRight[2].h = 22;

    SDL_Character *character = NULL;
    character = new SDL_Character(video, input, timer, megaMan, dstStartPosition,
                                  framesStance, srcStance, dummyRect, dummyRect,
                                  framesLeft, srcLeft[0], srcLeft[1], srcLeft[2],
                                  framesRight, srcRight[0], srcRight[1], srcRight[2]);

    SDL_Font font(video, timer);

    //+---------------------------------------------------------+
    //| GAME LOOP - EXIT BY PRESSING ESC                        |
    //+---------------------------------------------------------+

    while (input->GameRunning)
    {
        timer->StartTime();

        video->StartScene();
        input->Read();

        character->Draw();
        font.DrawFPS();
        video->Render();

        timer->StopTime();
        character->Move();
        //timer->LimitFramerate();
    }

    //+---------------------------------------------------------+
    //| DELETE VARIABLES, QUIT SDL                              |
    //+---------------------------------------------------------+

    delete video;
    delete input;
    delete character;
    delete timer;

    SDL_Quit();
    return 0;
}
