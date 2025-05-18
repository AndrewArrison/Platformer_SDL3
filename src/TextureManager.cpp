#include "TextureManager.hpp"

TextureManager* TextureManager::s_pInstance = nullptr;

bool TextureManager::load(std::string filename, std::string id, SDL_Renderer *pRenderer)
{
    SDL_Surface* pTempSurface = nullptr;
    pTempSurface = IMG_Load(filename.c_str());
    // pTempSurface = IMG_Load((SDL_GetCurrentDirectory() + filename).c_str());
    if (!pTempSurface)
    {
        SDL_Log("Error loading image : %s %s \n", filename.c_str() , SDL_GetError());
        return false;
    }
    SDL_Texture* pTexture = nullptr;
    pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_SetTextureScaleMode(pTexture, SDL_SCALEMODE_NEAREST);
    if (!pTexture)
    {
        SDL_Log("Error creating texture from surface : %s \n", SDL_GetError());
        return false;
    }
    SDL_DestroySurface(pTempSurface);

    m_textureMap[id] = pTexture;
    SDL_Log("Texture Loaded : %s", filename.c_str());
    return true;
}

void TextureManager::draw(std::string id, float x, float y, float width, float height, SDL_Renderer *pRenderer, SDL_FlipMode flip)
{
    SDL_FRect srcRect;
    SDL_FRect destRect;

    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderTextureRotated(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, float x, float y, float width, float height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_FlipMode flip)
{
    SDL_FRect srcRect;
    SDL_FRect destRect;

    srcRect.x = width * (currentFrame - 1);
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
	//   	srcRect.w = width;
	// srcRect.h = height;
	// destRect.w = width * 2;
	// destRect.h = height * 2;
	destRect.x = x; 
	destRect.y = y;

    SDL_RenderTextureRotated(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

SDL_Texture* TextureManager::getTexture(std::string id)
{
	return m_textureMap[id];
}

void TextureManager::clean()
{
    for (auto& pair : m_textureMap)
    {
        SDL_DestroyTexture(pair.second);
        SDL_Log("Clean : %s", pair.first.c_str());
    }
    m_textureMap.clear();
}
