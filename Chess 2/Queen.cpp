#include "pch.h"
#include "Queen.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Queen::Queen()
{
	name = 'Q';
}

Queen::Queen(int t)
{
	teamNum = t;
	if (teamNum == 1)
	{
		name = 'Q';
		rowNum = 0;
		colNum = 4;
	}
	else if (teamNum == 2)
	{
		name = 'q';
		rowNum = 7;
		colNum = 4;
	}
	onBoard = true;
}