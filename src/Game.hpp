#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include "TextureManager.hpp"
#include "PhysicsEntity.hpp"
#include "Player.hpp"

class Game
{
public:
    static Game* Instance()
    {
        if(s_pInstance == nullptr)
        {
        s_pInstance = new Game();
        return s_pInstance;
        }
        return s_pInstance;
    }
    ~Game() {}

    bool Init(const char* title, int xPos, int yPos, int width, int height, int flags);
    void Update();
    void Render();
    void HandleEvents();
    void Clean();

    SDL_Renderer* getRenderer() const { return m_pRenderer; }

    bool running() { return m_bRunning; }
private:
    Game() { }
    static Game* s_pInstance;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    Player* player;
    bool m_bRunning;
};
typedef Game TheGame;