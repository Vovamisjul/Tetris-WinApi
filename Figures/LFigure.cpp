#include "stdafx.h"
#include "LFigure.h"

LFigure::LFigure(int type) : Figure(type)
{
	figure =
	{
		{ type, BLOCK_TYPES::NONE },
		{ type, BLOCK_TYPES::NONE },
		{ type, type }
	};
}

LFigure::~LFigure()
{
}
