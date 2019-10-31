#include "stdafx.h"
#include "Control.h"


Control::Control()
{
	lastTetrisStep = std::chrono::high_resolution_clock::now();
	grid->SetFallingItem(rand() % FIGURE_COUNT);
}

bool Control::Process()
{
	if (!endGame)
	{
		auto now = std::chrono::high_resolution_clock::now();
		if (now - lastTetrisStep >= stepSpan)
		{
			lastTetrisStep = now;
			if (grid->CanFell())
			{
				grid->Fell();
			}
			else
			{
				score += grid->TryClearLines() * scoreForLine;
				int nextItem = nextStick ? (nextStick = false, 2) : rand() % FIGURE_COUNT;
				if (!grid->SetFallingItem(nextItem))
				{
					endGame = true;
					return false;
				}
				else
				{
					score += scoreForBlock;
				}
			}
		}
	}
	return true;
}

void Control::MoveRight()
{
	grid->MoveRight();
}

void Control::MoveLeft()
{
	grid->MoveLeft();
}

void Control::Rotate()
{
	grid->Rotate();
}

void Control::Fell()
{
	if (grid->CanFell())
	{
		grid->Fell();
	}
}

void Control::SetNextStick()
{
	nextStick = true;
}

int Control::getScore()
{
	return score;
}

void Control::Restart()
{
	score = 0;
	grid->Clear();
	endGame = false;
}

Control::~Control()
{
}
