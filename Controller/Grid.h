#pragma once
#include "../Consts.h"
#include "../Figures/Figure.h"
#include "../Figures/LFigure.h"
#include "../Figures/ReverseLFigure.h"
#include "../Figures/StickFigure.h"
#include "../Figures/CubeFigure.h"
#include "../Figures/TFigure.h"
#include "../Figures/StepFigure.h"
#include "../Figures/ReverseStepFigure.h"
#include <vector>

class Grid
{
public:
	int grid[TETRIS_WIDTH][TETRIS_HEIGHT];
	Grid();
	void MoveRight();
	void MoveLeft();
	void Rotate();
	bool CanFell();
	bool SetFallingItem(int);
	void Clear();
	void Fell();
	int TryClearLines();
	~Grid();
private:
	int fallingItem;
	bool IsFilledLine(int);
	void DownBlocks(int);
	int fallingX, fallingY;
	std::vector<Figure *> items = { new LFigure(BLOCK_TYPES::L), new ReverseLFigure(BLOCK_TYPES::REVERSE_L), new StickFigure(BLOCK_TYPES::STICK),
		new CubeFigure(BLOCK_TYPES::CUBE), new TFigure(BLOCK_TYPES::T), new StepFigure(BLOCK_TYPES::STEP), new ReverseStepFigure(BLOCK_TYPES::REVERSE_STEP)};
};

