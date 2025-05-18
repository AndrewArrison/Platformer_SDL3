#pragma once
#include <SDL3/SDL.h>
#include "LoaderParams.hpp"

class PhysicsEntity
{
public:
    PhysicsEntity(const LoaderParams *pParams);

    virtual void update();
    void draw(SDL_Renderer* pRenderer);
    void clean() { }

protected:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    /// @brief starts from 1
    int m_currentFrame;
    /// @brief starts from 1
    int m_currenRow;

    std::string m_textureID;
};
