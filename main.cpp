#include "defs.h"

int main (int argc, char *argv[])
{
    SDL_Surface *spriteOne;

    const int screenWidth = 512;
    const int screenHeight = 480;
    const char *caption = "SDL_Test starring MegaMan";

    SDL_Rect src, dst;

    //define main video-surface
    SDL_Video *video = NULL;
    video = new SDL_Video(screenWidth, screenHeight, caption);

    //define input
    SDL_Input *input = NULL;
    input = new SDL_Input;

    SDL_Timer *timer = NULL;
    timer = new SDL_Timer;

    //define sprite for character
    spriteOne = video->LoadImg("MegaManSheet.png", 0xFF, 0, 0xFF);

    //define new character
    //set coordinates for character-sprite
    src.x = 172;
    src.y = 37;
    src.w = 20;
    src.h = 24;

    dst.x = 20;
    dst.y = 24;
    dst.w = src.w;
    dst.h = dst.h;

    SDL_Character *character = NULL;
    character = new SDL_Character(video, input, timer, spriteOne, src, dst);

    SDL_Font font(video, timer);

    //game-loop
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

    delete video;
    delete input;
    delete character;
    delete timer;

    SDL_Quit();
    return 0;
}
