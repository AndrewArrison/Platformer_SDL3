#include "Game.hpp"
#include "TextureManager.hpp"
#include "TileMap.hpp"

Game* Game::s_pInstance = nullptr;

bool Game::Init(const char *title, int width, int height, int flags)
{
	tile = new TileMap();
	tile->load();
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Error initalizing SDL_VIDEO : %s \n", SDL_GetError());
        return false;
    }
    
    if(!SDL_CreateWindowAndRenderer(title, width, height, flags, &m_pWindow, &m_pRenderer))
    {
        SDL_Log("Error create window and renderer : %s \n", SDL_GetError());
        return false;
    }

    if(!TheTextureManager::instance()->load("test.png", "testTexture", m_pRenderer))
    {
        return false;
    }
	SDL_Log("Window Ready");
    LoaderParams* params = new LoaderParams(100, 100, 32, 32, "testTexture");
    
	player = new Player(params);
    m_bRunning = true;
	return true;
}

void Game::Update()
{
    player->update();
}

void Game::Render()
{
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 225);
    SDL_RenderClear(m_pRenderer);
    tile->draw(m_pRenderer);
	player->draw(m_pRenderer);
	// SDL_SetTextureScaleMode(TheTextureManager::instance()->getTexture("testTexture"), SDL_SCALEMODE_NEAREST);
    // TheTextureManager::instance()->draw("testTexture", 400, 400, 100, 100, m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
                m_bRunning = false;
                return;

            case SDL_EVENT_KEY_DOWN:
                switch (event.key.scancode)
                {
                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void Game::Clean()
{
    if (m_pWindow)
    {
        SDL_DestroyWindow(m_pWindow);
        SDL_Log("Destroy Window. \n");
    }
    if (m_pRenderer)
    {
        SDL_DestroyRenderer(m_pRenderer);
        SDL_Log("Destroy renderer. \n");
    }
    delete tile;
	TheTextureManager::instance()->clean();
	SDL_Quit();
}
