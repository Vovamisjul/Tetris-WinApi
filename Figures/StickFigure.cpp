#include "stdafx.h"
#include "StickFigure.h"


StickFigure::StickFigure(int type) : Figure(type)
{
	figure =
	{
		{ type },
		{ type },
		{ type },
		{ type }
	};
}


StickFigure::~StickFigure()
{
}
