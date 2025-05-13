#pragma once
#include <iostream>
#include <map>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class TextureManager
{

public:
    /// @brief Create and return a pointer to singleton TextureManager
    ///
    /// @return pointer to the instace of the TexttureManager
    static TextureManager* instance()
    {
        if(s_pInstance == nullptr)
        {
        s_pInstance = new TextureManager();
        return s_pInstance;
        }
        return s_pInstance;
    }
    ~TextureManager();

    /// @brief Load a image and convert it to a texture object
    /// @param filename 
    /// @param id 
    /// @param pRenderer 
    bool load(std::string filename, std::string id, SDL_Renderer* pRenderer);
    
    /// @brief Render a texture attached to the given id
    /// @param id 
    /// @param x 
    /// @param y 
    /// @param width 
    /// @param height 
    /// @param pRenderer 
    /// @param flip 
    void draw(std::string id, float x, float y, float width, float height, 
                SDL_Renderer* pRenderer, SDL_FlipMode flip = SDL_FLIP_NONE);
    /// @brief Render the part of texture attached to the given id
    /// @param id 
    /// @param x 
    /// @param y 
    /// @param width 
    /// @param height 
    /// @param currentRow 
    /// @param currentFrame 
    /// @param pRenderer 
    /// @param flip 
    void drawFrame(std::string id, float x, float y, float width, float height,
                 int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_FlipMode flip = SDL_FLIP_NONE);
    /// @brief Clear the textures attached to the renderer on the current instance
    void clean();

    
private:
    TextureManager() {}
    static TextureManager* s_pInstance;
    std::map<std::string, SDL_Texture*> m_textureMap;
};
typedef TextureManager TheTextureManager;