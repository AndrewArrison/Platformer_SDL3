#include "Player.hpp"
#include "TileMap.hpp"
#include <SDL3/SDL.h>
#include <vector>
#include "vector.hpp"

Player::Player(const LoaderParams* pParams, TileMap* tilemap)
    : PhysicsEntity(pParams), m_velocityX(0), m_velocityY(0), m_accelerationY(0.5f), m_onGround(false), m_tilemap(tilemap)
{
	m_currentFrame = 2;
	m_currenRow = 3;
}

void Player::handleInput()
{
    const bool* keystates = SDL_GetKeyboardState(nullptr);

    m_velocityX = 0;
	m_velocityY = 0;
    if (keystates[SDL_SCANCODE_A]) {
        m_velocityX = -3.0f;
    }
    if (keystates[SDL_SCANCODE_D]) {
        m_velocityX = 3.0f;
    }
	if (keystates[SDL_SCANCODE_W]) {
		m_velocityY = -3.0f;
	}
	if (keystates[SDL_SCANCODE_S]) {
		m_velocityY = 3.0f;
	}

    if (keystates[SDL_SCANCODE_SPACE] && m_onGround) {
        // m_velocityY = -10.0f;
        // m_onGround = false;
    }
}


void Player::update()
{
    handleInput();

    // Gravity
	//    // m_velocityY += _accelerationY;
	// m_velocityY = std::min(10.0f, (m_velocityY + m_accelerationY));
	//    m_x += m_velocityX;
	//    m_y += m_velocityY;
	//
	// if (m_y + 32 > 384) {
	// 	m_y = 384 - 32;
	// 	m_velocityY = 0;
	// 	m_onGround = true;
	// }
	//
	newPlayerX = 0;
	newPlayerY = 0;
	//Resolve on X
	newPlayerX = m_x + m_velocityX;
	std::vector<Vector2D> tile_list = m_tilemap->getRects(newPlayerX, m_y);
	for (Vector2D tile : tile_list) {
		if (m_velocityX > 0) {
			newPlayerX = tile.x - 32.0001;
		} else if (m_velocityX < 0) {
			newPlayerX = tile.x + 32.0001;
		}
	}
	//Resolve on Y
	newPlayerY = m_y + m_velocityY;
	tile_list = m_tilemap->getRects(newPlayerX, newPlayerY);
	for (Vector2D tile : tile_list) {
		if (m_velocityY > 0) {
			newPlayerY = tile.y - 32.0001;
		} else if (m_velocityY < 0) {
			newPlayerY = tile.y + 32.0001;
		}
	}
	//move
	m_y = newPlayerY; 
	m_x = newPlayerX;
}
