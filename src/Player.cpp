#include "Player.hpp"
#include "TileMap.hpp"
#include <SDL3/SDL.h>
#include <cmath>
#include <vector>
#include "TextureManager.hpp"
#include "vector.hpp"

Player::Player(const LoaderParams* pParams, TileMap* tilemap)
    : PhysicsEntity(pParams), m_velocityX(0), m_velocityY(0), m_accelerationY(0.5f), m_onGround(false), m_tilemap(tilemap)
{
	m_currentFrame = 1;
	m_currenRow = 1;
}

void Player::handleInput()
{
    const bool* keystates = SDL_GetKeyboardState(nullptr);

    m_velocityX = 0;
	// m_velocityY = 0;
    if (keystates[SDL_SCANCODE_A]) {
		fliped = true;
        m_velocityX = -3.0f;
    }
    if (keystates[SDL_SCANCODE_D]) {
		fliped = false;
        m_velocityX = 3.0f;
    }
	if (keystates[SDL_SCANCODE_W]) {
		m_velocityY = -3.0f;
	}
	if (keystates[SDL_SCANCODE_S]) {
		m_velocityY = 3.0f;
	}

    if (keystates[SDL_SCANCODE_SPACE] && m_onGround) {
        m_velocityY = -11.0f;
        m_onGround = false;
    }
}


void Player::update()
{
    handleInput();

    // Gravity
	m_velocityY += m_accelerationY;
	if (m_velocityY > 10) {
		m_velocityY = 10;
	}

	newPlayerX = 0;
	newPlayerY = 0;
	//Resolve on X
	newPlayerX = m_x + m_velocityX;
	moveAxis(true);
	//Resolve on Y
	newPlayerY = m_y + m_velocityY;
	moveAxis(false);
	m_y = newPlayerY; 
	m_x = newPlayerX;
	m_currentFrame = 1 + ((SDL_GetTicks() / 100) % (6 - 1));
}

std::vector<Vector2D> Player::getRects(float Px, float Py)
{
	int leftTile = std::floor( Px/ 32);
	int rightTile = leftTile + 1;
	int topTile = std::floor(Py / 32);
	int bottomTile = topTile + 1;

	std::vector<Vector2D> data;
	if (Px < 0 || Px > 20 * 32 || Py > 15 * 32 || Py < 0){
		return data;
	}
	for (int y = topTile; y <= bottomTile; y++) {
		for (int x = leftTile; x <= rightTile; x++) {
			if (m_tilemap->getTile(x, y) == 1) {
				float tileX = x*32.0f;
				float tileY = y*32.0f;
				data.push_back({tileX, tileY});
			} else if (m_tilemap->getTile(x, y) == 2) {
				m_tilemap->setTile(x, y, 0);
			}
		}
	}
	return data;
}

void Player::moveAxis(bool is_x)
{
	if (is_x) {
		m_tile_list = getRects(newPlayerX, m_y);
		for (Vector2D &tile : m_tile_list) {
			if (m_velocityX > 0) {
				newPlayerX = tile.x - 32.0001;
				m_velocityX = 0;
			} else if (m_velocityX < 0) {
				newPlayerX = tile.x + 32.0001;
				m_velocityX = 0;
			}
		}
	}
	else {
		m_tile_list = getRects(newPlayerX, newPlayerY);
		for (Vector2D &tile : m_tile_list) {
			if (m_velocityY > 0) {
				newPlayerY = tile.y - 32.0001;
				m_velocityY = 0;
				m_onGround = true;
			} else if (m_velocityY < 0) {
				newPlayerY = tile.y + 32.0001;
				m_velocityY = 0;
			}
		}
	}

}

void Player::draw(SDL_Renderer* pRenderer)
{
	if (fliped) {
    	TheTextureManager::instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currenRow, m_currentFrame, pRenderer, SDL_FLIP_HORIZONTAL);
	} else {
    	TheTextureManager::instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currenRow, m_currentFrame, pRenderer);
	}
}
