#include "pch.h"
#include "King.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

King::King()
{
	name = 'K';
}

King::King(int t)
{
	teamNum = t;
	if (teamNum == 1)
	{
		name = 'K';
		rowNum = 0;
		colNum = 3;
	}
	else if (teamNum == 2)
	{
		name = 'k';
		rowNum = 7;
		colNum = 3;
	}
	onBoard = true;
}