#include "TileMap.hpp"
#include "TextureManager.hpp"
#include <stdlib.h>


//adwawdadw
void TileMap::load()
{
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 15; y++) {
			tilemap[x][y] = rand() %4 +1;	
		}
	}

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
		for (int y = 10; y < 15; y++) {
			switch (tilemap[x][y]) {
				case 1:
					TheTextureManager::instance()->drawFrame("testTexture", tile[x][y].x, tile[x][y].y, 32, 32, 1, 1, pRenderer);
				break;
				case 2:
					TheTextureManager::instance()->drawFrame("testTexture", tile[x][y].x, tile[x][y].y, 32, 32, 1, 5, pRenderer);
				break;
			}
		}
	}
}
