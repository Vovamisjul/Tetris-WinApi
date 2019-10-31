#include "stdafx.h"
#include "ReverseLFigure.h"


ReverseLFigure::ReverseLFigure(int type) : Figure(type)
{
	figure =
	{
		{ BLOCK_TYPES::NONE, type },
		{ BLOCK_TYPES::NONE, type },
		{ type, type }
	};
}


ReverseLFigure::~ReverseLFigure()
{
}
