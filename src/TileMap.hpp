#pragma once
#include <SDL3/SDL.h>

class TileMap
{
public:
	TileMap(){ }
	void load();
	void draw(SDL_Renderer* pRenderer);
	int getTile(int x, int y);
	void setTile(int x, int y, int tile) { tilemap[x][y] = tile; }
private:
	int tilemap[20][15];
	SDL_FRect tile[20][15];
};
