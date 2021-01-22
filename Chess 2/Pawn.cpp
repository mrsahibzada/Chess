#include "pch.h"
#include "Pawn.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Pawn::Pawn()
{
	name = 'P';
}

Pawn::Pawn(int t, int i)
{
	teamNum = t;
	if (teamNum == 1)
	{
		name = 'P';
		switch (i)
		{
		case 1:
			rowNum = 1;
			colNum = 0;
			break;
		case 2:
			rowNum = 1;
			colNum = 1;
			break;
		case 3:
			rowNum = 1;
			colNum = 2;
			break;
		case 4:
			rowNum = 1;
			colNum = 3;
			break;
		case 5:
			rowNum = 1;
			colNum = 4;
			break;
		case 6:
			rowNum = 1;
			colNum = 5;
			break;
		case 7:
			rowNum = 1;
			colNum = 6;
			break;
		case 8:
			rowNum = 1;
			colNum = 7;
			break;
		}
	}
	else if (teamNum == 2)
	{
		name = 'p';
		switch (i)
		{
		case 1:
			rowNum = 6;
			colNum = 0;
			break;
		case 2:
			rowNum = 6;
			colNum = 1;
			break;
		case 3:
			rowNum = 6;
			colNum = 2;
			break;
		case 4:
			rowNum = 6;
			colNum = 3;
			break;
		case 5:
			rowNum = 6;
			colNum = 4;
			break;
		case 6:
			rowNum = 6;
			colNum = 5;
			break;
		case 7:
			rowNum = 6;
			colNum = 6;
			break;
		case 8:
			rowNum = 6;
			colNum = 7;
			break;
		}
	}
	onBoard = true;
}