#pragma once
#include "PhysicsEntity.hpp"
#include "TileMap.hpp"
#include "vector.hpp"
#include <vector>

class Player : public PhysicsEntity
{
public:
    Player(const LoaderParams* pParams, TileMap* tilemap);
    void handleInput();
    void update();
    void draw(SDL_Renderer* pRenderer);
	void moveAxis(bool is_x);
	std::vector<Vector2D> getRects(float Px, float Py);
private:
    float m_velocityX;
    float m_velocityY;
    float m_accelerationY;
    bool m_onGround;
	bool fliped = false;
	TileMap* m_tilemap;
	std::vector<Vector2D> m_tile_list; 
	float newPlayerX;
	float newPlayerY;
};
