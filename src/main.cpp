#include "Game.hpp"

int main(int argc, char const *argv[])
{

    TheGame::Instance()->Init("HearBund", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    while (TheGame::Instance()->running())
    {
        TheGame::Instance()->HandleEvents();
        TheGame::Instance()->Update();
        TheGame::Instance()->Render();
        SDL_Delay(16);
    }
    TheGame::Instance()->Clean();
    return 0;
}
