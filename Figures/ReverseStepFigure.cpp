#include "stdafx.h"
#include "ReverseStepFigure.h"


ReverseStepFigure::ReverseStepFigure(int type) : Figure(type)
{
	figure =
	{
		{ BLOCK_TYPES::NONE, type },
		{ type, type },
		{ type, BLOCK_TYPES::NONE }
	};
}


ReverseStepFigure::~ReverseStepFigure()
{
}
