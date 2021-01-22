#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ChessPiece
{
public:
	virtual bool move(int r, int c) = 0;
	virtual void setNums(int r, int c) = 0;
	virtual void setOnBoard(bool o) = 0;
	virtual char getName() = 0;
	virtual int getTeamNum() = 0;
	virtual int getRowNum() = 0;
	virtual int getColNum() = 0;
	virtual bool isOnBoard() = 0;
};