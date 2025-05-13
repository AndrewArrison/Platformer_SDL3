#pragma once
#include "PhysicsEntity.hpp"

class Player : public PhysicsEntity
{
public:
    Player(const LoaderParams* pParams);

    void handleInput();
    void update();

private:
    float m_velocityX;
    float m_velocityY;
    float m_accelerationY;
    bool m_onGround;
};
