#include "PhysicsEntity.hpp"
#include "TextureManager.hpp"

PhysicsEntity::PhysicsEntity(const LoaderParams *pParams)
{
    m_x = pParams->getX();
    m_y = pParams->getY();
    m_height = pParams->getHeight();
    m_width = pParams->getWidth();
    m_textureID = pParams->getTextureID();

    m_currenRow = 1;
    m_currentFrame = 1;
}

void PhysicsEntity::update()
{
    SDL_Log("is called");
}

void PhysicsEntity::draw(SDL_Renderer* pRenderer)
{
    TheTextureManager::instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currenRow, m_currentFrame, pRenderer);

}