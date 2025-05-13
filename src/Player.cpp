#include "Player.hpp"
#include <SDL3/SDL.h>

Player::Player(const LoaderParams* pParams)
    : PhysicsEntity(pParams), m_velocityX(0), m_velocityY(0), m_accelerationY(0.5f), m_onGround(false)
{
}

void Player::handleInput()
{
    const bool* keystates = SDL_GetKeyboardState(nullptr);

    m_velocityX = 0;

    if (keystates[SDL_SCANCODE_A]) {
        m_velocityX = -3.0f;
    }
    if (keystates[SDL_SCANCODE_D]) {
        m_velocityX = 3.0f;
    }

    if (keystates[SDL_SCANCODE_SPACE] && m_onGround) {
        m_velocityY = -10.0f;
        m_onGround = false;
    }
}

void Player::update()
{
    handleInput();

    // Gravity
    m_velocityY += m_accelerationY;

    m_x += m_velocityX;
    m_y += m_velocityY;

    // Simple ground check (replace later with real collision)
    if (m_y > 380) {
        m_y = 380;
        m_velocityY = 0;
        m_onGround = true;
    }

    // m_currentFrame = (SDL_GetTicks() / 100) % 6 + 1;
}
