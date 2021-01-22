#include "pch.h"
#include "Bishop.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Bishop::Bishop()
{
	name = 'B';
}

Bishop::Bishop(int t, int i)
{
	teamNum = t;
	if (teamNum == 1)
	{
		name = 'B';
		if (i == 1)
		{
			rowNum = 0;
			colNum = 2;
		}
		else if (i == 2)
		{
			rowNum = 0;
			colNum = 5;
		}
	}
	else if (teamNum == 2)
	{
		name = 'b';
		if (i == 1)
		{
			rowNum = 7;
			colNum = 2;
		}
		else if (i == 2)
		{
			rowNum = 7;
			colNum = 5;
		}
	}
	onBoard = true;
}