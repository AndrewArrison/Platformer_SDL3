#include "Player.hpp"


Player::Player(const LoaderParams *pParams) : PhysicsEntity(pParams)
{

}

void Player::Update()
{
    PhysicsEntity::Update();
}

void Player::Draw()
{
    PhysicsEntity::Draw();
}

void Player::Clean()
{
    PhysicsEntity::Clean();
}