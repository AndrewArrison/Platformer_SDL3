#pragma once
#include "PhysicsEntity.hpp"
#include "TileMap.hpp"
#include "vector.hpp"

class Player : public PhysicsEntity
{
public:
    Player(const LoaderParams* pParams, TileMap* tilemap);
	void moveAxis(Vector2D pos);
    void handleInput();
    void update();
	
private:
    float m_velocityX;
    float m_velocityY;
    float m_accelerationY;
    bool m_onGround;
	TileMap* m_tilemap;
	Vector2D PlayerPos;
};
