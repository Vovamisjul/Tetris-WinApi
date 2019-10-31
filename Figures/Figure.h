#pragma once
#include "../Consts.h"
#include <vector>

class Figure
{
public:
	Figure(int);
	void MoveLeft(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	void MoveRight(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	void Fell(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	bool CanFell(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	bool Reset(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	void Rotate(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	void Clear(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	void FillBack(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	~Figure();
protected:
	//type of the figure
	int type;
	//left top corner of the figure
	int x, y;
	std::vector<std::vector<int>> figure;
private:
	bool CanMoveLeft(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	bool CanMoveRight(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	bool CanReset(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
	bool CanRotate(int[TETRIS_WIDTH][TETRIS_HEIGHT]);
};

