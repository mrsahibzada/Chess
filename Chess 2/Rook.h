#pragma once
#include "ChessPiece.h"
class Rook :
	public ChessPiece
{
public:
	Rook();
	Rook(int t, int i);
	bool move(int r, int c)
	{
		bool validMove;
		if (0 <= r && r <= 7 && 0 <= c && c <= 7
			&& (abs(r - rowNum) == 0 || abs(c - colNum) == 0)
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