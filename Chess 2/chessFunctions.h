#pragma once
#include "pch.h"
#include "ChessPiece.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/**
   This function creates an empty board.
*/
void makeBoard(ChessPiece* board[8][8], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = NULL;
		}
	}
}

/**
   This function puts chess pieces on the created board.
*/
void setBoard(ChessPiece* board[8][8], ChessPiece* team1[16], ChessPiece* team2[16], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		if ((*team1[i]).isOnBoard() == true)
		{
			board[(*team1[i]).getRowNum()][(*team1[i]).getColNum()] = team1[i];
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if ((*team2[i]).isOnBoard() == true)
		{
			board[(*team2[i]).getRowNum()][(*team2[i]).getColNum()] = team2[i];
		}
	}
}

/**
   This function displays the current state of the chess board.
*/
void displayBoard(ChessPiece* board[8][8], const int B_ROWS, const int B_COLS)
{
	cout << setw(47) << "Current Board" << endl << endl;
	for (int i = 0; i < B_ROWS; i++)
	{
		cout << setw(24);
		if (i % 2 == 0 && (i / 2) % 2 != 0)
		{
			cout << 9 - ((i / 2) + 1) / 2;
		}
		else
		{
			cout << " ";
		}
		for (int j = 0; j < B_COLS; j++)
		{
			if (i % 4 == 0 || j % 4 == 0)
			{
				cout << "#";
			}
			else if (i % 2 == 0 && j % 2 == 0)
			{
				if (board[i / 2 - (1 + (i - 2) / 4)][j / 2 - (1 + (j - 2) / 4)] == NULL)
				{
					cout << " ";
				}
				else
				{
					cout << (*board[i / 2 - (1 + (i - 2) / 4)][j / 2 - (1 + (j - 2) / 4)]).getName();
				}
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << setw(55) << "A   B   C   D   E   F   G   H" << endl << endl;
}

/**
   This function capitalizes the first character of a string if it is an alphabet.
*/
void capitalize(string& str)
{
	if ('a' <= str[0] && str[0] <= 'z')
	{
		str[0] = static_cast<char>(static_cast<int>(str[0]) - 32);
	}
}

/**
   This function takes input from player 1.
*/
void input1(ChessPiece* board[8][8], int& rowNum1, int& colNum1, int& rowNum2, int& colNum2, bool& invalidInput)
{
	do
	{
		string rowStr;
		cout << "Enter the number of the row (1-8) containing your starting position." << endl << endl;
		cout << "To quit, enter -1: ";
		getline(cin, rowStr);
		int tempRowNum1 = atoi(rowStr.c_str());
		if (tempRowNum1 == -1)
		{
			rowNum1 = -1;
			return;
		}
		if (1 <= tempRowNum1 && tempRowNum1 <= 8)
		{
			rowNum1 = 8 - tempRowNum1;
			break;
		}
		else
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Row numbers must be between 1 and 8 inclusive." << endl;
			cout << endl;
		}
	} while (true);
	cout << endl;
	do
	{
		string colStr;
		cout << "Enter the name of the column (A-H) containing your starting position." << endl << endl;
		cout << "To quit, enter q: ";
		getline(cin, colStr);
		if (colStr == "q")
		{
			colNum1 = -1;
			return;
		}
		capitalize(colStr);
		if (colStr != "A" && colStr != "B" && colStr != "C" && colStr != "D" && colStr != "E"
			&& colStr != "F" && colStr != "G" && colStr != "H")
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Column names must be between A and H inclusive." << endl;
			cout << endl;
		}
		else
		{
			colNum1 = static_cast<int>(colStr[0]) - 65;
			break;
		}
	} while (true);
	cout << endl;
	do
	{
		string rowStr;
		cout << "Enter the number of the row (1-8) containing your ending position." << endl << endl;
		cout << "To quit, enter -1: ";
		getline(cin, rowStr);
		int tempRowNum2 = atoi(rowStr.c_str());
		if (tempRowNum2 == -1)
		{
			rowNum2 = -1;
			return;
		}
		if (1 <= tempRowNum2 && tempRowNum2 <= 8)
		{
			rowNum2 = 8 - tempRowNum2;
			break;
		}
		else
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Row numbers must be between 1 and 8 inclusive." << endl;
			cout << endl;
		}
	} while (true);
	cout << endl;
	do
	{
		string colStr;
		cout << "Enter the name of the column (A-H) containing your ending position." << endl << endl;
		cout << "To quit, enter q: ";
		getline(cin, colStr);
		if (colStr == "q")
		{
			colNum2 = -1;
			return;
		}
		capitalize(colStr);
		if (colStr != "A" && colStr != "B" && colStr != "C" && colStr != "D" && colStr != "E"
			&& colStr != "F" && colStr != "G" && colStr != "H")
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Column names must be between A and H inclusive." << endl;
			cout << endl;
		}
		else
		{
			colNum2 = static_cast<int>(colStr[0]) - 65;
			break;
		}
	} while (true);
	cout << endl;
	if (board[rowNum1][colNum1] == NULL || (*board[rowNum1][colNum1]).getTeamNum() == 2)
	{
		invalidInput = true;
		cout << "Invalid input:" << endl;
		cout << "Your starting position does not have a valid chess piece." << endl << endl;
		system("PAUSE");
        system("CLS");
        return;
	}
	if (board[rowNum2][colNum2] != NULL && (*board[rowNum2][colNum2]).getTeamNum() == 1)
	{
		invalidInput = true;
		cout << "Invalid input:" << endl;
		cout << "Your ending position has one of your own chess pieces." << endl << endl;
		system("PAUSE");
		system("CLS");
		return;
	}
}

/**
   This function takes input from player 2.
*/
void input2(ChessPiece* board[8][8], int& rowNum1, int& colNum1, int& rowNum2, int& colNum2, bool& invalidInput)
{
	do
	{
		string rowStr;
		cout << "Enter the number of the row (1-8) containing your starting position." << endl << endl;
		cout << "To quit, enter -1: ";
		getline(cin, rowStr);
		int tempRowNum1 = atoi(rowStr.c_str());
		if (tempRowNum1 == -1)
		{
			rowNum1 = -1;
			return;
		}
		if (1 <= tempRowNum1 && tempRowNum1 <= 8)
		{
			rowNum1 = 8 - tempRowNum1;
			break;
		}
		else
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Row numbers must be between 1 and 8 inclusive." << endl;
			cout << endl;
		}
	} while (true);
	cout << endl;
	do
	{
		string colStr;
		cout << "Enter the name of the column (A-H) containing your starting position." << endl << endl;
		cout << "To quit, enter q: ";
		getline(cin, colStr);
		if (colStr == "q")
		{
			colNum1 = -1;
			return;
		}
		capitalize(colStr);
		if (colStr != "A" && colStr != "B" && colStr != "C" && colStr != "D" && colStr != "E"
			&& colStr != "F" && colStr != "G" && colStr != "H")
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Column names must be between A and H inclusive." << endl;
			cout << endl;
		}
		else
		{
			colNum1 = static_cast<int>(colStr[0]) - 65;
			break;
		}
	} while (true);
	cout << endl;
	do
	{
		string rowStr;
		cout << "Enter the number of the row (1-8) containing your ending position." << endl << endl;
		cout << "To quit, enter -1: ";
		getline(cin, rowStr);
		int tempRowNum2 = atoi(rowStr.c_str());
		if (tempRowNum2 == -1)
		{
			rowNum2 = -1;
			return;
		}
		if (1 <= tempRowNum2 && tempRowNum2 <= 8)
		{
			rowNum2 = 8 - tempRowNum2;
			break;
		}
		else
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Row numbers must be between 1 and 8 inclusive." << endl;
			cout << endl;
		}
	} while (true);
	cout << endl;
	do
	{
		string colStr;
		cout << "Enter the name of the column (A-H) containing your ending position." << endl << endl;
		cout << "To quit, enter q: ";
		getline(cin, colStr);
		if (colStr == "q")
		{
			colNum2 = -1;
			return;
		}
		capitalize(colStr);
		if (colStr != "A" && colStr != "B" && colStr != "C" && colStr != "D" && colStr != "E"
			&& colStr != "F" && colStr != "G" && colStr != "H")
		{
			cout << endl;
			cout << "Invalid Input:" << endl;
			cout << "Column names must be between A and H inclusive." << endl;
			cout << endl;
		}
		else
		{
			colNum2 = static_cast<int>(colStr[0]) - 65;
			break;
		}
	} while (true);
	cout << endl;
	if (board[rowNum1][colNum1] == NULL || (*board[rowNum1][colNum1]).getTeamNum() == 1)
	{
		invalidInput = true;
		cout << "Invalid input:" << endl;
		cout << "Your starting position does not have a valid chess piece." << endl << endl;
		system("PAUSE");
		system("CLS");
		return;
	}
	if (board[rowNum2][colNum2] != NULL && (*board[rowNum2][colNum2]).getTeamNum() == 2)
	{
		invalidInput = true;
		cout << "Invalid input:" << endl;
		cout << "Your ending position has one of your own chess pieces." << endl << endl;
		system("PAUSE");
		system("CLS");
		return;
	}
}

/**
   This function confirms if a move is valid.
*/
bool validMove(ChessPiece* board[8][8], int rowNum1, int colNum1, int rowNum2, int colNum2, const int ROWS, const int COLS)
{
	char name = (*board[rowNum1][colNum1]).getName();
	bool valid1;
	bool valid2;
	if ((*board[rowNum1][colNum1]).move(rowNum2, colNum2) == true)
	{
		valid1 = true;
	}
	else
	{
		valid1 = false;
	}
	switch (name)
	{
	case 'K': case 'k':
	{
		if (board[rowNum2][colNum2] != NULL && (*board[rowNum2][colNum2]).getTeamNum() == (*board[rowNum1][colNum1]).getTeamNum())
		{
			valid2 = false;
		}
		else
		{
			valid2 = true;
		}
		break;
	}
	case 'Q': case 'q':
	{
		if (rowNum2 == rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1, j = colNum1 + 1; j <= colNum2; j++)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && j < colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1 + 1; i >= rowNum2 && j <= colNum2; i--, j++)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i > rowNum2 && j < colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1; i >= rowNum2; i--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i > rowNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1 - 1; i >= rowNum2 && j >= colNum2; i--, j--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i > rowNum2 && j > colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 == rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1, j = colNum1 - 1; j >= colNum2; j--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && j > colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 - 1; i <= rowNum2 && j >= colNum2; i++, j--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i < rowNum2 && j > colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1; i <= rowNum2; i++)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i < rowNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 + 1; i <= rowNum2 && j <= colNum2; i++, j++)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i < rowNum2 && j < colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		break;
	}
	case 'R': case 'r':
	{
		if (rowNum2 == rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1, j = colNum1 + 1; j <= colNum2; j++)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && j < colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1; i >= rowNum2; i--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i > rowNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 == rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1, j = colNum1 - 1; j >= colNum2; j--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && j > colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1; i <= rowNum2; i++)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i < rowNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		break;
	}
	case 'B': case'b':
	{
		if (rowNum2 < rowNum1 && colNum2 > colNum1)
		{
		    for (int i = rowNum1 - 1, j = colNum1 + 1; i >= rowNum2 && j <= colNum2; i--, j++)
		    {
			    if (board[i][j] == NULL)
			    {
				    valid2 = true;
			    }
			    else if (board[i][j] != NULL && i > rowNum2 && j < colNum2)
			    {
				    valid2 = false;
				    break;
			    }
			    else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
			    {
				    if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
				    {
					    valid2 = true;
				    }
				    else
				    {
					    valid2 = false;
					    break;
				    }
			    }
		    }
		}
		else if (rowNum2 < rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1 - 1; i >= rowNum2 && j >= colNum2; i--, j--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i > rowNum2 && j > colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 - 1; i <= rowNum2 && j >= colNum2; i++, j--)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i < rowNum2 && j > colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 + 1; i <= rowNum2 && j <= colNum2; i++, j++)
			{
				if (board[i][j] == NULL)
				{
					valid2 = true;
				}
				else if (board[i][j] != NULL && i < rowNum2 && j < colNum2)
				{
					valid2 = false;
					break;
				}
				else if (board[i][j] != NULL && i == rowNum2 && j == colNum2)
				{
					if ((*board[i][j]).getTeamNum() != (*board[rowNum1][colNum1]).getTeamNum())
					{
						valid2 = true;
					}
					else
					{
						valid2 = false;
						break;
					}
				}
			}
		}
		break;
	}
	case 'N': case 'n':
	{
		if (board[rowNum2][colNum2] != NULL && (*board[rowNum2][colNum2]).getTeamNum() == (*board[rowNum1][colNum1]).getTeamNum())
		{
			valid2 = false;
		}
		else
		{
			valid2 = true;
		}
		break;
	}
	case 'P':
	{
		if (rowNum1 == 1 && rowNum2 - rowNum1 == 1 && colNum2 - colNum1 == 0 && board[rowNum2][colNum2] == NULL)
		{
			valid2 = true;
		}
		else if (rowNum1 == 1 && rowNum2 - rowNum1 == 2 && colNum2 - colNum1 == 0 && board[rowNum2][colNum2] == NULL)
		{
			valid2 = true;
		}
		else if (rowNum1 != 1 && rowNum2 - rowNum1 == 1 && colNum2 - colNum1 == 0 && board[rowNum2][colNum2] == NULL)
		{
			valid2 = true;
		}
		else if (rowNum2 - rowNum1 == 1 && (colNum2 - colNum1 == -1 || colNum2 - colNum1 == 1) && board[rowNum2][colNum2] != NULL
			&& (*board[rowNum2][colNum2]).getTeamNum() == 2)
		{
			valid2 = true;
		}
		else
		{
			valid2 = false;
		}
		break;
	}
	case 'p':
	{
		if (rowNum1 == 6 && rowNum2 - rowNum1 == -1 && colNum2 - colNum1 == 0 && board[rowNum2][colNum2] == NULL)
		{
			valid2 = true;
		}
		else if (rowNum1 == 6 && rowNum2 - rowNum1 == -2 && colNum2 - colNum1 == 0 && board[rowNum2][colNum2] == NULL)
		{
			valid2 = true;
		}
		else if (rowNum1 != 6 && rowNum2 - rowNum1 == -1 && colNum2 - colNum1 == 0 && board[rowNum2][colNum2] == NULL)
		{
			valid2 = true;
		}
		else if (rowNum2 - rowNum1 == -1 && (colNum2 - colNum1 == -1 || colNum2 - colNum1 == 1) && board[rowNum2][colNum2] != NULL
			&& (*board[rowNum2][colNum2]).getTeamNum() == 1)
		{
			valid2 = true;
		}
		else
		{
			valid2 = false;
		}
		break;
	}
	}
	return (valid1 && valid2);
}

/**
   This function confirms if player 1 is in check.
*/
ChessPiece* isInCheck1(ChessPiece* board[8][8], King& piece)
{
	int rowNum = piece.getRowNum();
	int colNum = piece.getColNum();
	ChessPiece* tempPtr = NULL;
	for (int i = rowNum, j = colNum + 1; j <= 7; j++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'r'
				|| ((*board[i][j]).getName() == 'k' && i == rowNum && j == colNum + 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum - 1, j = colNum + 1; i >= 0 && j <= 7; i--, j++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'b'
				|| ((*board[i][j]).getName() == 'k' && i == rowNum - 1 && j == colNum + 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum - 1, j = colNum; i >= 0; i--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'r'
				|| ((*board[i][j]).getName() == 'k' && i == rowNum - 1 && j == colNum))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum - 1, j = colNum - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'b'
				|| ((*board[i][j]).getName() == 'k' && i == rowNum - 1 && j == colNum - 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum, j = colNum - 1; j >= 0; j--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'r'
				|| ((*board[i][j]).getName() == 'k' && i == rowNum && j == colNum - 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum + 1, j = colNum - 1; i <= 7 && j >= 0; i++, j--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'b'
				|| (((*board[i][j]).getName() == 'p' || (*board[i][j]).getName() == 'k')
					&& i == rowNum + 1 && j == colNum - 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum + 1, j = colNum; i <= 7; i++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'r'
				|| ((*board[i][j]).getName() == 'k' && i == rowNum + 1 && j == colNum))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = board[i][j];
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum + 1, j = colNum + 1; i <= 7 && j <= 7; i++, j++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'q' || (*board[i][j]).getName() == 'b'
				|| (((*board[i][j]).getName() == 'p' || (*board[i][j]).getName() == 'k')
					&& i == rowNum + 1 && j == colNum + 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if ((abs(i - rowNum) == 1 && abs(j - colNum) == 2) || (abs(i - rowNum) == 2 && abs(j - colNum) == 1))
			{
				if (board[i][j] != NULL)
				{
					if ((*board[i][j]).getName() == 'n')
					{
						tempPtr = board[i][j];
						return tempPtr;
					}
					else
					{
						tempPtr = NULL;
					}
				}
			}
		}
	}
	return tempPtr;
}

/**
   This function confirms if player 2 is in check.
*/
ChessPiece* isInCheck2(ChessPiece* board[8][8], King& piece)
{
	int rowNum = piece.getRowNum();
	int colNum = piece.getColNum();
	ChessPiece* tempPtr = NULL;
	for (int i = rowNum, j = colNum + 1; j <= 7; j++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'R'
				|| ((*board[i][j]).getName() == 'K' && i == rowNum && j == colNum + 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum - 1, j = colNum + 1; i >= 0 && j <= 7; i--, j++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'B'
				|| (((*board[i][j]).getName() == 'P' || (*board[i][j]).getName() == 'K')
					&& i == rowNum - 1 && j == colNum + 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum - 1, j = colNum; i >= 0; i--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'R'
				|| ((*board[i][j]).getName() == 'K' && i == rowNum - 1 && j == colNum))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum - 1, j = colNum - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'B'
				|| (((*board[i][j]).getName() == 'P' || (*board[i][j]).getName() == 'K')
					&& i == rowNum + 1 && j == colNum + 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum, j = colNum - 1; j >= 0; j--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'R'
				|| ((*board[i][j]).getName() == 'K' && i == rowNum && j == colNum - 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum + 1, j = colNum - 1; i <= 7 && j >= 0; i++, j--)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'B'
				|| ((*board[i][j]).getName() == 'K' && i == rowNum + 1 && j == colNum - 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum + 1, j = colNum; i <= 7; i++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'R'
				|| ((*board[i][j]).getName() == 'K' && i == rowNum + 1 && j == colNum))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = rowNum + 1, j = colNum + 1; i <= 7 && j <= 7; i++, j++)
	{
		if (board[i][j] != NULL)
		{
			if ((*board[i][j]).getName() == 'Q' || (*board[i][j]).getName() == 'B'
				|| ((*board[i][j]).getName() == 'K' && i == rowNum + 1 && j == colNum + 1))
			{
				tempPtr = board[i][j];
				return tempPtr;
			}
			else
			{
				tempPtr = NULL;
				break;
			}
		}
		else
		{
			tempPtr = NULL;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((abs(i - rowNum) == 1 && abs(j - colNum) == 2) || (abs(i - rowNum) == 2 && abs(j - colNum) == 1))
			{
				if (board[i][j] != NULL)
				{
					if ((*board[i][j]).getName() == 'N')
					{
						tempPtr = board[i][j];
						return tempPtr;
					}
					else
					{
						tempPtr = NULL;
					}
				}
			}
		}
	}
	return tempPtr;
}

/**
   This function updates the board.
*/
void updateBoard(ChessPiece* board[8][8], int rowNum1, int colNum1, int rowNum2, int colNum2, const int ROWS, const int COLS)
{
	if (board[rowNum2][colNum2] == NULL)
	{
		board[rowNum2][colNum2] = board[rowNum1][colNum1];
		board[rowNum1][colNum1] = NULL;
		(*board[rowNum2][colNum2]).setNums(rowNum2, colNum2);
	}
	else
	{
		(*board[rowNum2][colNum2]).setOnBoard(false);
		board[rowNum2][colNum2] = board[rowNum1][colNum1];
		board[rowNum1][colNum1] = NULL;
		(*board[rowNum2][colNum2]).setNums(rowNum2, colNum2);
	}
}

/**
   This function confirms if player 1 has been checkmated.
*/
bool checkmate1(ChessPiece* board[8][8], ChessPiece* team1[16], King& piece1, ChessPiece* enem)
{
	bool mate;
	for (int i = 0; i < 16; i++)
	{
		if ((*team1[i]).isOnBoard() == true)
		{
			bool valid = validMove(board, (*team1[i]).getRowNum(), (*team1[i]).getColNum(),
				(*enem).getRowNum(), (*enem).getColNum(), 8, 8);
			if (valid == true)
			{
				int rowNum = (*team1[i]).getRowNum();
				int colNum = (*team1[i]).getColNum();
				updateBoard(board, rowNum, colNum, (*enem).getRowNum(), (*enem).getColNum(), 8, 8);
				ChessPiece* tempPtr = isInCheck1(board, piece1);
				if (tempPtr == NULL)
				{
					mate = false;
					(*team1[i]).setNums(rowNum, colNum);
					(*enem).setOnBoard(true);
					board[rowNum][colNum] = team1[i];
					board[(*enem).getRowNum()][(*enem).getColNum()] = enem;
					return mate;
				}
				else
				{
					mate = true;
					(*team1[i]).setNums(rowNum, colNum);
					(*enem).setOnBoard(true);
					board[rowNum][colNum] = team1[i];
					board[(*enem).getRowNum()][(*enem).getColNum()] = enem;
				}
			}
		}
	}
	if (!(abs(piece1.getRowNum() - (*enem).getRowNum()) <= 1
		&& abs(piece1.getColNum() - (*enem).getColNum()) <= 1)
		&& (*enem).getName() != 'n')
	{
		int rowNum1 = piece1.getRowNum();
		int colNum1 = piece1.getColNum();
		int rowNum2 = (*enem).getRowNum();
		int colNum2 = (*enem).getColNum();
		if (rowNum2 == rowNum1 && colNum2 - colNum1 > 0)
		{
			for (int i = rowNum1, j = colNum1 + 1; j < colNum2; j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team1[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team1[k]).getRowNum();
							int colNum = (*team1[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck1(board, piece1);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1 + 1; i > rowNum2 && j < colNum2; i--, j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team1[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team1[k]).getRowNum();
							int colNum = (*team1[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck1(board, piece1);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1; i > rowNum2; i--)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team1[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team1[k]).getRowNum();
							int colNum = (*team1[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck1(board, piece1);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 < colNum1)
		{
		    for (int i = rowNum1 - 1, j = colNum1 - 1; i > rowNum2 && j > colNum2; i--, j--)
		    {
			    for (int k = 0; k < 16; k++)
			    {
				    if ((*team1[k]).isOnBoard() == true)
				    {
					    bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
					    if (valid == true)
					    {
						    int rowNum = (*team1[k]).getRowNum();
						    int colNum = (*team1[k]).getColNum();
						    updateBoard(board, rowNum, colNum, i, j, 8, 8);
						    ChessPiece* tempPtr = isInCheck1(board, piece1);
						    if (tempPtr == NULL)
						    {
							    mate = false;
							    (*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							    return mate;
						    }
						    else
						    {
							    mate = true;
							    (*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
						    }
					    }
				    }
			    }
		    }
        }
		else if (rowNum2 == rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1, j = colNum1 - 1; j > colNum2; j--)
			{
				for (int k = 0; k < 16; k++)
				{
				    if ((*team1[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team1[k]).getRowNum();
							int colNum = (*team1[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck1(board, piece1);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							}
						}
					}
				}
		    }
		}
		else if (rowNum2 > rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 - 1; i < rowNum2 && j > colNum2; i++, j--)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team1[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team1[k]).getRowNum();
							int colNum = (*team1[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck1(board, piece1);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1; i < rowNum2; i++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team1[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team1[k]).getRowNum();
							int colNum = (*team1[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck1(board, piece1);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 + 1; i < rowNum2 && j < colNum2; i++, j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team1[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team1[k]).getRowNum(), (*team1[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team1[k]).getRowNum();
							int colNum = (*team1[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck1(board, piece1);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team1[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team1[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		int rowMoves[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
		int colMoves[8] = { 1, 0, 1, -1, -1, -1, 0, 1 };
		for (int i = 0; i < 8; i++)
		{
			int rowNum1 = piece1.getRowNum();
			int colNum1 = piece1.getColNum();
			int rowNum2 = rowNum1 + rowMoves[i];
			int colNum2 = colNum1 + colMoves[i];
			if (0 <= rowNum1 && rowNum1 <= 7 && 0 <= rowNum2 && rowNum2 <= 7
				&& 0 <= colNum1 && colNum1 <= 7 && 0 <= colNum1 && colNum2 <= 7)
			{
				ChessPiece* tempPiece = NULL;
				if (board[rowNum2][colNum2] != NULL)
				{
					tempPiece = board[rowNum2][colNum2];
				}
				bool valid = validMove(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
				if (valid == true)
				{
					updateBoard(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
					ChessPiece* tempPtr = isInCheck1(board, piece1);
					if (tempPtr == NULL)
					{
						mate = false;
						piece1.setNums(rowNum1, colNum1);
						board[rowNum1][colNum1] = &piece1;
						if (tempPiece != NULL)
						{
							(*tempPiece).setOnBoard(true);
						}
						board[rowNum2][colNum2] = tempPiece;
						return mate;
					}
					else
					{
						mate = true;
						piece1.setNums(rowNum1, colNum1);
						board[rowNum1][colNum1] = &piece1;
						if (tempPiece != NULL)
						{
							(*tempPiece).setOnBoard(true);
						}
						board[rowNum2][colNum2] = tempPiece;
					}
				}
			}
		}
	}
	return mate;
}

/**
   This function confirms if player 2 has been checkmated.
*/
bool checkmate2(ChessPiece* board[8][8], ChessPiece* team2[16], King& piece2, ChessPiece* enem)
{
	bool mate;
	for (int i = 0; i < 16; i++)
	{
		if ((*team2[i]).isOnBoard() == true)
		{
			bool valid = validMove(board, (*team2[i]).getRowNum(), (*team2[i]).getColNum(),
				(*enem).getRowNum(), (*enem).getColNum(), 8, 8);
			if (valid == true)
			{
				int rowNum = (*team2[i]).getRowNum();
				int colNum = (*team2[i]).getColNum();
				updateBoard(board, rowNum, colNum, (*enem).getRowNum(), (*enem).getColNum(), 8, 8);
				ChessPiece* tempPtr = isInCheck2(board, piece2);
				if (tempPtr == NULL)
				{
					mate = false;
					(*team2[i]).setNums(rowNum, colNum);
					(*enem).setOnBoard(true);
					board[rowNum][colNum] = team2[i];
					board[(*enem).getRowNum()][(*enem).getColNum()] = enem;
					return mate;
				}
				else
				{
					mate = true;
					(*team2[i]).setNums(rowNum, colNum);
					(*enem).setOnBoard(true);
					board[rowNum][colNum] = team2[i];
					board[(*enem).getRowNum()][(*enem).getColNum()] = enem;
				}
			}
		}
	}
	if (!(abs(piece2.getRowNum() - (*enem).getRowNum()) <= 1
		&& abs(piece2.getColNum() - (*enem).getColNum()) <= 1)
		&& (*enem).getName() != 'N')
	{
		int rowNum1 = piece2.getRowNum();
		int colNum1 = piece2.getColNum();
		int rowNum2 = (*enem).getRowNum();
		int colNum2 = (*enem).getColNum();
		if (rowNum2 == rowNum1 && colNum2 - colNum1 > 0)
		{
			for (int i = rowNum1, j = colNum1 + 1; j < colNum2; j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1 + 1; i > rowNum2 && j < colNum2; i--, j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1; i > rowNum2; i--)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 < rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1 - 1, j = colNum1 - 1; i > rowNum2 && j > colNum2; i--, j--)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 == rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1, j = colNum1 - 1; j > colNum2; j--)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 < colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 - 1; i < rowNum2 && j > colNum2; i++, j--)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 == colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1; i < rowNum2; i++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		else if (rowNum2 > rowNum1 && colNum2 > colNum1)
		{
			for (int i = rowNum1 + 1, j = colNum1 + 1; i < rowNum2 && j < colNum2; i++, j++)
			{
				for (int k = 0; k < 16; k++)
				{
					if ((*team2[k]).isOnBoard() == true)
					{
						bool valid = validMove(board, (*team2[k]).getRowNum(), (*team2[k]).getColNum(), i, j,
							8, 8);
						if (valid == true)
						{
							int rowNum = (*team2[k]).getRowNum();
							int colNum = (*team2[k]).getColNum();
							updateBoard(board, rowNum, colNum, i, j, 8, 8);
							ChessPiece* tempPtr = isInCheck2(board, piece2);
							if (tempPtr == NULL)
							{
								mate = false;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
								return mate;
							}
							else
							{
								mate = true;
								(*team2[k]).setNums(rowNum, colNum);
								board[rowNum][colNum] = team2[k];
								board[i][j] = NULL;
							}
						}
					}
				}
			}
		}
		int rowMoves[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
		int colMoves[8] = { 1, 0, 1, -1, -1, -1, 0, 1 };
		for (int i = 0; i < 8; i++)
		{
			int rowNum1 = piece2.getRowNum();
			int colNum1 = piece2.getColNum();
			int rowNum2 = rowNum1 + rowMoves[i];
			int colNum2 = colNum1 + colMoves[i];
			if (0 <= rowNum1 && rowNum1 <= 7 && 0 <= rowNum2 && rowNum2 <= 7
				&& 0 <= colNum1 && colNum1 <= 7 && 0 <= colNum2 && colNum2 <= 7)
			{
				ChessPiece* tempPiece = NULL;
				if (board[rowNum2][colNum2] != NULL)
				{
					tempPiece = board[rowNum2][colNum2];
				}
				bool valid = validMove(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
				if (valid == true)
				{
					updateBoard(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
					ChessPiece* tempPtr = isInCheck2(board, piece2);
					if (tempPtr == NULL)
					{
						mate = false;
						piece2.setNums(rowNum1, colNum1);
						board[rowNum1][colNum1] = &piece2;
						if (tempPiece != NULL)
						{
							(*tempPiece).setOnBoard(true);
						}
						board[rowNum2][colNum2] = tempPiece;
						return mate;
					}
					else
					{
						mate = true;
						piece2.setNums(rowNum1, colNum1);
						board[rowNum1][colNum1] = &piece2;
						if (tempPiece != NULL)
						{
							(*tempPiece).setOnBoard(true);
						}
						board[rowNum2][colNum2] = tempPiece;
					}
				}
			}
		}
	}
	return mate;
}

/**
   This function deals with player 1's turn.
*/
void playTeam1(ChessPiece* board[8][8], ChessPiece* team1[16], King& piece1, const int ROWS,
	const int COLS, bool& defeat1, bool& defeatMate1)
{
	system("COLOR F3");
	while (true)
	{
		system("CLS");
		displayBoard(board, 33, 33);
		ChessPiece* enem1 = isInCheck1(board, piece1);
		bool mate = false;
		if (enem1 != NULL)
		{
			mate = checkmate1(board, team1, piece1, enem1);
		}
		if (enem1 != NULL && mate == false)
		{
			cout << setw(43) << "CHECK!" << endl << endl;
		}
		else if (enem1 != NULL && mate == true)
		{
			defeatMate1 = true;
			return;
		}
		while (true)
		{
			cout << "Team 1's turn:" << endl << endl;
			cout << "To play, enter 1. To concede defeat, enter anything else: ";
			string input;
			getline(cin, input);
			cout << endl;
			if (input != "1")
			{
				defeat1 = true;
				return;
			}
			else
			{
				int rowNum1, rowNum2, colNum1, colNum2;
				bool invalidInput = false;
				input1(board, rowNum1, colNum1, rowNum2, colNum2, invalidInput);
				if (rowNum1 == -1 || colNum1 == -1 || rowNum2 == -1 || colNum2 == -1)
				{
					break;
				}
				else if (invalidInput == true)
				{
					break;
				}
				bool valid1 = validMove(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
				bool valid2 = true;
				if (valid1 == true)
				{
					ChessPiece* piece = NULL;
					if (board[rowNum2][colNum2] != NULL)
					{
						piece = board[rowNum2][colNum2];
					}
					updateBoard(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
					ChessPiece* enem2 = isInCheck1(board, piece1);
					if (enem2 != NULL)
					{
						valid2 = false;
					}
					if (valid2 == true)
					{
						return;
					}
					else
					{
						if (piece != NULL)
						{
							(*piece).setOnBoard(true);
						}
						(*board[rowNum2][colNum2]).setNums(rowNum1, colNum1);
						board[rowNum1][colNum1] = board[rowNum2][colNum2];
						board[rowNum2][colNum2] = piece;
						cout << "Your move is invalid." << endl << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}
				else
				{
					cout << "Your move is invalid." << endl << endl;
					system("PAUSE");
					system("CLS");
					break;
				}
			}
		}
	}
}

/**
   This function deals with player 2's turn.
*/
void playTeam2(ChessPiece* board[8][8], ChessPiece* team2[16], King& piece2, const int ROWS,
	const int COLS, bool& defeat2, bool& defeatMate2)
{
	system("COLOR F4");
	while (true)
	{
		system("CLS");
		displayBoard(board, 33, 33);
		ChessPiece* enem1 = isInCheck2(board, piece2);
		bool mate = false;
		if (enem1 != NULL)
		{
			mate = checkmate2(board, team2, piece2, enem1);
		}
		if (enem1 != NULL && mate == false)
		{
			cout << setw(43) << "CHECK!" << endl << endl;
		}
		else if (enem1 != NULL && mate == true)
		{
			defeatMate2 = true;
			return;
		}
		while (true)
		{
			cout << "Team 2's turn:" << endl << endl;
			cout << "To play, enter 1. To concede defeat, enter anything else: ";
			string input;
			getline(cin, input);
			cout << endl;
			if (input != "1")
			{
				defeat2 = true;
				return;
			}
			else
			{
				int rowNum1, rowNum2, colNum1, colNum2;
				bool invalidInput = false;
				input2(board, rowNum1, colNum1, rowNum2, colNum2, invalidInput);
				if (rowNum1 == -1 || colNum1 == -1 || rowNum2 == -1 || colNum2 == -1)
				{
					break;
				}
				else if (invalidInput == true)
				{
					break;
				}
				bool valid1 = validMove(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
				bool valid2 = true;
				if (valid1 == true)
				{
					ChessPiece* piece = NULL;
					if (board[rowNum2][colNum2] != NULL)
					{
						piece = board[rowNum2][colNum2];
					}
					updateBoard(board, rowNum1, colNum1, rowNum2, colNum2, 8, 8);
					ChessPiece* enem2 = isInCheck2(board, piece2);
					if (enem2 != NULL)
					{
						valid2 = false;
					}
					if (valid2 == true)
					{
						return;
					}
					else
					{
						if (piece != NULL)
						{
							(*piece).setOnBoard(true);
						}
						(*board[rowNum2][colNum2]).setNums(rowNum1, colNum1);
						board[rowNum1][colNum1] = board[rowNum2][colNum2];
						board[rowNum2][colNum2] = piece;
						cout << "Your move is invalid." << endl << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}
				else
				{
					cout << "Your move is invalid." << endl << endl;
					system("PAUSE");
					system("CLS");
					break;
				}
			}
		}
	}
}

/**
   This function promotes player 1's pawns.
*/
void promotePawn1(ChessPiece* board[8][8], ChessPiece* team1[16])
{
	for (int i = 0; i < 16; i++)
	{
		if ((*team1[i]).getName() == 'P' && (*team1[i]).getRowNum() == 7)
		{
			ChessPiece* piece;
			do
			{
				system("CLS");
				displayBoard(board, 8, 8);
				cout << "Team 1's turn:" << endl << endl;
				cout << "Enter 1 to promote to queen." << endl << endl;
				cout << "Enter 2 to promote to rook." << endl << endl;
				cout << "Enter 3 to promote to bishop." << endl << endl;
				cout << "Enter 4 to promote to knight: ";
				cout << endl;
				string input;
				getline(cin, input);
				if (input != "1" && input != "2" && input != "3" && input != "4")
				{
					cout << endl;
					cout << "Invalid input:" << endl << endl;
					cout << "You cannot enter anything but 1, 2, 3, or 4." << endl << endl;
					system("PAUSE");
					system("CLS");
				}
				else if (input == "1")
				{
					piece = new Queen(1);
					int rowNum = (*team1[i]).getRowNum();
					int colNum = (*team1[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team1[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team1[i] = piece;
					break;
				}
				else if (input == "2")
				{
					piece = new Rook(1, 1);
					int rowNum = (*team1[i]).getRowNum();
					int colNum = (*team1[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team1[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team1[i] = piece;
					break;
				}
				else if (input == "3")
				{
					piece = new Bishop(1, 1);
					int rowNum = (*team1[i]).getRowNum();
					int colNum = (*team1[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team1[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team1[i] = piece;
					break;
				}
				else if (input == "4")
				{
					piece = new Knight(1, 1);
					int rowNum = (*team1[i]).getRowNum();
					int colNum = (*team1[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team1[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team1[i] = piece;
					break;
				}
			} while (true);
		}
	}
}

/**
   This function promotes player 2's pawns.
*/
void promotePawn2(ChessPiece* board[8][8], ChessPiece* team2[16])
{
	for (int i = 0; i < 16; i++)
	{
		if ((*team2[i]).getName() == 'p' && (*team2[i]).getRowNum() == 0)
		{
			ChessPiece* piece;
			do
			{
				system("CLS");
				displayBoard(board, 33, 33);
				cout << "Team 2's turn:" << endl << endl;
				cout << "Enter 1 to promote to queen." << endl << endl;
				cout << "Enter 2 to promote to rook." << endl << endl;
				cout << "Enter 3 to promote to bishop." << endl << endl;
				cout << "Enter 4 to promote to knight: ";
				string input;
				getline(cin, input);
				cout << endl;
				if (input != "1" && input != "2" && input != "3" && input != "4")
				{
					cout << endl;
					cout << "Invalid input:" << endl << endl;
					cout << "You cannot enter anything but 1, 2, 3, or 4." << endl << endl;
					system("PAUSE");
					system("CLS");
				}
				else if (input == "1")
				{
					piece = new Queen(2);
					int rowNum = (*team2[i]).getRowNum();
					int colNum = (*team2[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team2[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team2[i] = piece;
					break;
				}
				else if (input == "2")
				{
					piece = new Rook(2, 1);
					int rowNum = (*team2[i]).getRowNum();
					int colNum = (*team2[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team2[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team2[i] = piece;
					break;
				}
				else if (input == "3")
				{
					piece = new Bishop(2, 1);
					int rowNum = (*team2[i]).getRowNum();
					int colNum = (*team2[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team2[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team2[i] = piece;
					break;
				}
				else if (input == "4")
				{
					piece = new Knight(2, 1);
					int rowNum = (*team2[i]).getRowNum();
					int colNum = (*team2[i]).getColNum();
					(*piece).setNums(rowNum, colNum);
					(*team2[i]).setOnBoard(false);
					board[rowNum][colNum] = piece;
					team2[i] = piece;
					break;
				}
			} while (true);
		}
	}
}