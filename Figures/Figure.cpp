#include "stdafx.h"
#include "Figure.h"

Figure::Figure(int type)
{
	this->type = type;
	x = TETRIS_WIDTH / 2;
	y = 0;
}

void Figure::MoveLeft(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	if (CanMoveLeft(grid))
	{
		for (int i = 0; i < static_cast<int>(figure.size()); i++)
		{
			for (int j = 0; j < static_cast<int>(figure[i].size()); j++)
			{
				if (figure[i][j])
					grid[x + j - 1][y + i] = type;
			}
		}
		x--;
	}
}

void Figure::MoveRight(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	if (CanMoveRight(grid))
	{
		for (int i = 0; i < static_cast<int>(figure.size()); i++)
		{
			for (int j = 0; j < static_cast<int>(figure[i].size()); j++)
			{
				if (figure[i][j])
					grid[x + j + 1][y + i] = type;
			}
		}
		x++;
	}
}

void Figure::Fell(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	Clear(grid);
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			if (figure[i][j])
				grid[x + j][y + i + 1] = type;
		}
	}
	y++;
}

bool Figure::CanFell(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	if (y + (int)figure.size() == TETRIS_HEIGHT)
		return false;
	Clear(grid);
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			if (grid[x + j][y + i + 1] && figure[i][j])
			{
				FillBack(grid);
				return false;
			}
		}
	}
	return true;
}

bool Figure::Reset(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	if (CanReset(grid))
	{
		x = TETRIS_WIDTH / 2;
		y = 0;
		for (int i = 0; i < (int)figure.size(); i++)
		{
			for (int j = 0; j < (int)figure[i].size(); j++)
			{
				grid[x + j][y + i] = figure[i][j];
			}
		}
		return true;
	}
	else
		return false;
}

void Figure::Rotate(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	std::vector<std::vector<int>> newFigure;
	newFigure.resize(figure[0].size());
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			newFigure[j].push_back((int)figure[figure.size() - i - 1][j]);
			grid[x + j][y + i] = BLOCK_TYPES::NONE;
		}
	}
	Clear(grid);
	for (int i = 0; i < (int)newFigure.size(); i++)
	{
		for (int j = 0; j < (int)newFigure[i].size(); j++)
		{
			if (newFigure[i][j] && grid[x + j][y + i])
			{
				FillBack(grid);
				return;
			}
		}
	}
	figure = newFigure;
	FillBack(grid);
}

void Figure::Clear(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			if (figure[i][j])
				grid[x + j][y + i] = BLOCK_TYPES::NONE;
		}
	}
}

void Figure::FillBack(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			if (figure[i][j])
				grid[x + j][y + i] = type;
		}
	}
}

Figure::~Figure()
{
}

bool Figure::CanMoveLeft(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	if (x == 0)
		return false;
	Clear(grid);
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			if (grid[x + j - 1][y + i] && figure[i][j])
			{
				FillBack(grid);
				return false;
			}
		}
	}
	return true;
}

bool Figure::CanMoveRight(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	if (x + (int)figure[0].size() == TETRIS_WIDTH)
		return false;
	Clear(grid);
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			if (grid[x + j + 1][y + i] && figure[i][j])
			{
				FillBack(grid);
				return false;
			}
		}
	}
	return true;
}

bool Figure::CanReset(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	x = TETRIS_WIDTH / 2;
	y = 0;
	for (int i = 0; i < (int)figure.size(); i++)
	{
		for (int j = 0; j < (int)figure[i].size(); j++)
		{
			if (grid[x + j][y + i] && figure[i][j])
				return false;
		}
	};
	return true;
}

bool Figure::CanRotate(int grid[TETRIS_WIDTH][TETRIS_HEIGHT])
{
	/*if (x + figure.size() >= TETRIS_WIDTH || y + figure[0].size() >= TETRIS_HEIGHT)
		return false;
	for (int i = 0; i < figure.size(); i++)
	{
		for (int j = 0; j < figure[i].size(); i++)
		{
			if (grid[x + figure.size() - 1 - i][y + j] && figure[i][j])
				return false;
		}
	}*/
	return true;
}
