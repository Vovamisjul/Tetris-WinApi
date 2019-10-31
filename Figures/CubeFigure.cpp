#include "stdafx.h"
#include "CubeFigure.h"


CubeFigure::CubeFigure(int type) : Figure(type)
{
	figure =
	{
		{ type, type },
		{ type, type }
	};
}


CubeFigure::~CubeFigure()
{
}
