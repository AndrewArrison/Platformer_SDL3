#include "TileMap.hpp"
#include "TextureManager.hpp"
#include "vector.hpp"
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <vector>

void TileMap::load()
{
	// for (int x = 0; x < 20; x++) {
	// 	for (int y = 0; y < 15; y++) {
	// 		tilemap[x][y] = rand() %4 +1;
	// 	}
	// }
	//
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 15; y++) {
			tilemap[x][y] = 0;
		}
	}
	for (int x = 0; x < 20; x++) {
		tilemap[x][12] = 1;
	}
	
	tilemap[3][11] = 1;
	tilemap[6][5] = 1;
	tilemap[8][10] = 1;

	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 15; y++) {
			tile[x][y].x = x*32;
			tile[x][y].y = y*32;
			tile[x][y].w = 32;
			tile[x][y].h = 32;
		}	
	}
	
}

void TileMap::draw(SDL_Renderer* pRenderer)
{
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 15; y++) {
			switch (tilemap[x][y]) {
				case 1:
					TheTextureManager::instance()->drawFrame("tilemap", tile[x][y].x, tile[x][y].y, 32, 32, 2, 3, pRenderer);
				break;
				case 2:
					TheTextureManager::instance()->drawFrame("testTexture", tile[x][y].x, tile[x][y].y, 32, 32, 1, 3, pRenderer);
				break;
				case 3:
					TheTextureManager::instance()->drawFrame("testTexture", tile[x][y].x, tile[x][y].y, 32, 32, 1, 5, pRenderer);
				break;
				case 4:
					TheTextureManager::instance()->drawFrame("testTexture", tile[x][y].x, tile[x][y].y, 32, 32, 1, 6, pRenderer);
				break;
			}
		}
	}
}

std::vector<Vector2D> TileMap::getRects(float Px, float Py)
{
	int leftTile = std::floor( Px/ 32);
	int rightTile = leftTile + 1;
	int topTile = std::floor(Py / 32);
	int bottomTile = topTile + 1;
	std::vector<Vector2D> data;
	for (int y = topTile; y <= bottomTile; y++) {
		for (int x = leftTile; x <= rightTile; x++) {
			if (tilemap[x][y] == 1) {
				int tileX = x*32.0f;
				int tileY = y*32.0f;
				int overlapX = std::max(0, std::min((int)(tileX + 32), (int)(Px + 32)) - std::max((int)(tileX), (int)(Px)));
				int overlapY = std::max(0, std::min((int)(tileY + 32), (int)(Py + 32)) - std::max((int)(tileY), (int)(Py)));
				// SDL_Log("X OVERLAP :: %d", overlapX);
				// SDL_Log("Y OVERLAP :: %d", overlapY);
				// Vector2D v2 = { (float)(overlapX), (float)(overlapY)};
				Vector2D v2 = { (float)(tileX), (float)(tileY)};
				
				data.push_back(v2);
			}
		}
	}
	return data;
}
