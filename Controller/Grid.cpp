#include "stdafx.h"
#include "Grid.h"

Grid::Grid()
{
	memset(grid, 0, sizeof(grid));
}

void Grid::MoveRight()
{
	items[fallingItem]->MoveRight(grid);
}

void Grid::MoveLeft()
{
	items[fallingItem]->MoveLeft(grid);
}

void Grid::Rotate()
{
	items[fallingItem]->Rotate(grid);
}

bool Grid::CanFell()
{
	return items[fallingItem]->CanFell(grid);
}

bool Grid::SetFallingItem(int item)
{
	fallingItem = item;
	return items[fallingItem]->Reset(grid);
}

void Grid::Clear()
{
	memset(grid, 0, sizeof(grid));
	items[fallingItem]->Reset(grid);
}

void Grid::Fell()
{
	items[fallingItem]->Fell(grid);
}

int Grid::TryClearLines()
{
	int i = 0, result = 0;
	while (i < TETRIS_HEIGHT)
	{
		if (IsFilledLine(i))
		{
			DownBlocks(i);
			result++;
		}
		else
		{
			i++;
		}
	}
	return result;
}


Grid::~Grid()
{
}

bool Grid::IsFilledLine(int line)
{
	for (int i = 0; i < TETRIS_WIDTH; i++)
	{
		if (!grid[i][line])
			return false;
	}
	return true;
}

void Grid::DownBlocks(int line)
{
	for (int i = 0; i < TETRIS_WIDTH; i++)
	{
		for (int j = line; j > 0; j--)
		{
			grid[i][j] = grid[i][j - 1];
		}
	}
	for (int i = 0; i < TETRIS_WIDTH; i++)
	{
		grid[i][0] = BLOCK_TYPES::NONE;
	}
}
