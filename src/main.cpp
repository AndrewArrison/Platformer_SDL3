#include "Game.hpp"

int main()
{

    TheGame::Instance()->Init("HearBund", 640, 480, 0);

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
