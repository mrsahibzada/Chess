#pragma once
#include "ChessPiece.h"
class King :
	public ChessPiece
{
public:
	King();
	King(int t);
	bool move(int r, int c)
	{
		bool validMove;
		if (0 <= r && r <= 7 && 0 <= c && c <= 7 && 0 <= abs(r - rowNum)
			&& abs(r - rowNum) <= 1 && 0 <= abs(c - colNum) && abs(c - colNum) <= 1
			&& !(r == rowNum && c == colNum))
		{
			validMove = true;
		}
		else
		{
			validMove = false;
		}
		return validMove;
	}
	void setNums(int r, int c)
	{
		rowNum = r;
		colNum = c;
	}
	void setOnBoard(bool o)
	{
		onBoard = o;
	}
	char getName()
	{
		return name;
	}
	int getTeamNum()
	{
		return teamNum;
	}
	int getRowNum()
	{
		return rowNum;
	}
	int getColNum()
	{
		return colNum;
	}
	bool isOnBoard()
	{
		return onBoard;
	}
private:
	char name;
	int teamNum;
	int rowNum;
	int colNum;
	bool onBoard;
};