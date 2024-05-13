#pragma once
#include <raylib.h>
#include "Globals.h"
#include <unordered_map>

enum class Tile {

	//empty tile
	AIR = 0,

	BLOCK_SQUARE1_TL = 1, BLOCK_SQUARE1_TR, BLOCK_SQUARE1_BL, BLOCK_SQUARE1_BR,
	BLOCK_SQUARE2_TL, BLOCK_SQUARE2_TR, BLOCK_SQUARE2_BL, BLOCK_SQUARE2_BR,
	BLOCK_VERT2_T, BLOCK_VERT2_B, BLOCK_HORIZ2_L, BLOCK_HORIZ2_R, BLOCK_BLUE,
	BLOCK_HORIZ3_L, BLOCK_HORIZ3_M, BLOCK_HORIZ3_R,
	BLOCK_BEAM_L, BLOCK_BEAM_R,
	
	LADDER_L = 20, LADDER_R, LADDER_TOP_L, LADDER_TOP_R,
	
	LOCK_RED = 30, LOCK_YELLOW, 
	
	LASER_L = 40, LASER_R,
};

class TileMap
{
public:
	TileMap();
	~TileMap();

	AppStatus Initialise();
	AppStatus Load(int data[], int w, int h);
	void Update();
	void Render();
	void Release();

private:
	void InitTileDictionary();

	//Tile map
	Tile* map;
	
	//Size of the tile map
	int width, height;
	//Map is rendered from this position (margin for GUI) 
	int map_y;
	
	//Dictionary of tile frames
	std::unordered_map<int, Rectangle> dict_rect;
	
	//Tile sheet
	Texture2D img_tiles;
};

