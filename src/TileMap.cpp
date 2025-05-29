#include "TileMap.hpp"
#include "TextureManager.hpp"
#include <stdlib.h>

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
	tilemap[8][9] = 1;
	tilemap[8][10] = 1;

	
	tilemap[14][11] = 2;

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
					TheTextureManager::instance()->drawFrame("test", tile[x][y].x, tile[x][y].y, 32, 32, 2, 1, pRenderer);
				break;
				case 2:
					TheTextureManager::instance()->drawFrame("test", tile[x][y].x, tile[x][y].y, 32, 32, 2, 2, pRenderer);
				break;
				// case 3:
				// 	TheTextureManager::instance()->drawFrame("testTexture", tile[x][y].x, tile[x][y].y, 32, 32, 1, 5, pRenderer);
				// break;
				// case 4:
				// 	TheTextureManager::instance()->drawFrame("testTexture", tile[x][y].x, tile[x][y].y, 32, 32, 1, 6, pRenderer);
				// break;
			}
		}
	}
}

int TileMap::getTile(int x, int y){
	return tilemap[x][y];
}
