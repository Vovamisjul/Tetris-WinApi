#include "stdafx.h"
#include "TFigure.h"


TFigure::TFigure(int type) : Figure(type)
{
	figure =
	{
		{ BLOCK_TYPES::NONE, type, BLOCK_TYPES::NONE },
		{ type, type, type }
	};
}


TFigure::~TFigure()
{
}
