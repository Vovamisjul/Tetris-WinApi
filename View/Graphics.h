#pragma once
#include "../Consts.h"
#include "../Controller/Grid.h"
class Graphics
{
public:
	Graphics(HINSTANCE);
	void Draw(HDC, Grid*, int);
	~Graphics();
private:
	HBITMAP blockTextures[BLOCK_COUNT];
	const int playZoneX = 100;
	const int playZoneY = 50;
	const int playZoneWidth = TETRIS_WIDTH * BLOCK_SIZE;
	const int playZoneHeight = TETRIS_HEIGHT * BLOCK_SIZE;
	void DrawBackground(HDC);
	void DrawScore(HDC, int);
};

