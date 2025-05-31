#include "Game.hpp"
#include "TextureManager.hpp"
#include "TileMap.hpp"
#include <cmath>

Game* Game::s_pInstance = nullptr;

bool Game::Init(const char *title, int width, int height, int flags)
{
	SDL_Log("Compiled %d.%d", SDL_VERSIONNUM_MAJOR(SDL_VERSION), SDL_VERSIONNUM_MINOR(SDL_VERSION));
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

    if(!TheTextureManager::instance()->load("SS.png", "test", m_pRenderer))
    {
        return false;
    }
	SDL_Log("Window initialized");
    LoaderParams* params = new LoaderParams(320, 320, 32, 32, "test");
	tile = new TileMap();
	tile->load();
	player = new Player(params, tile);
	delete params;
	m_bRunning = true;
	return true;
}

void Game::Update()
{
    player->update();
}

void Game::Render()
{
    SDL_SetRenderDrawColor(m_pRenderer, 75, 72, 50, 225);
    SDL_RenderClear(m_pRenderer);
    tile->draw(m_pRenderer);
	player->draw(m_pRenderer);
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
					case SDL_SCANCODE_ESCAPE:
						m_bRunning = false;
						break;
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
	if (player) {
		delete player;
	}
    delete tile;
	TheTextureManager::instance()->clean();
	SDL_Quit();
}
