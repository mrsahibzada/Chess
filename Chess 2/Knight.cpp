#include "pch.h"
#include "Knight.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Knight::Knight()
{
	name = 'N';
}

Knight::Knight(int t, int i)
{
	teamNum = t;
	if (teamNum == 1)
	{
		name = 'N';
		if (i == 1)
		{
			rowNum = 0;
			colNum = 1;
		}
		else if (i == 2)
		{
			rowNum = 0;
			colNum = 6;
		}
	}
	else if (teamNum == 2)
	{
		name = 'n';
		if (i == 1)
		{
			rowNum = 7;
			colNum = 1;
		}
		else if (i == 2)
		{
			rowNum = 7;
			colNum = 6;
		}
	}
	onBoard = true;
}