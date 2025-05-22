#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "vector.hpp"

class TileMap
{
public:
	TileMap(){ }
	void load();
	void draw(SDL_Renderer* pRenderer);
	std::vector<Vector2D> getRects(float x, float y);
private:
	int tilemap[20][15];
	SDL_FRect tile[20][15];
};
