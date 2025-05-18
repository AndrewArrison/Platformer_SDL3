#pragma once
#include <SDL3/SDL.h>

class TileMap
{
public:
	TileMap(){ }
	void load();
	void draw(SDL_Renderer* pRenderer);

private:
	int tilemap[20][15];
	SDL_FRect tile[20][15];
};
