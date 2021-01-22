#include "pch.h"
#include "Rook.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Rook::Rook()
{
	name = 'R';
}

Rook::Rook(int t, int i)
{
	teamNum = t;
	if (teamNum == 1)
	{
		name = 'R';
		if (i == 1)
		{
			rowNum = 0;
			colNum = 0;
		}
		else if (i == 2)
		{
			rowNum = 0;
			colNum = 7;
		}
	}
	else if (teamNum == 2)
	{
		name = 'r';
		if (i == 1)
		{
			rowNum = 7;
			colNum = 0;
		}
		else if (i == 2)
		{
			rowNum = 7;
			colNum = 7;
		}
	}
	onBoard = true;
}