#include "stdafx.h"
#include "StepFigure.h"


StepFigure::StepFigure(int type) : Figure(type)
{
	figure =
	{
		{ type, BLOCK_TYPES::NONE },
		{ type, type },
		{ BLOCK_TYPES::NONE, type }
	};
}


StepFigure::~StepFigure()
{
}
