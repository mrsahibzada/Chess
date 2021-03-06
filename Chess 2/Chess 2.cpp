// Chess 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "ChessPiece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "chessFunctions.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	while (true)
	{
		const int ROWS = 8; // Number of Rows
		const int COLS = 8; // Number of Columns
		const int SIZE = 16; // Size of Each Team
		system("COLOR F0");
		bool play;
		while (true)
		{
			cout << setw(49) << "### # # ### ### ###" << endl;
			cout << setw(49) << "#   # # #   #   #  " << endl;
			cout << setw(49) << "#   ### ##  ### ###" << endl;
			cout << setw(49) << "#   # # #     #   #" << endl;
			cout << setw(49) << "### # # ### ### ###" << endl;
			cout << endl;
			cout << setw(74) << "(developed by Sahibzada S. Mansoor, Muhammad S. Gul, and Irfan Javed)" << endl << endl;
			cout << "To play, enter 1." << endl << endl << "To exit, enter 2: ";
			string mode;
			getline(cin, mode);
			if (mode != "1" && mode != "2")
			{
				cout << endl;
				cout << "Invalid input:" << endl << endl;
				cout << "You cannot enter anything but 1 or 2." << endl << endl;
				system("PAUSE");
				system("CLS");
			}
			else if (mode == "1")
			{
				play = true;
				break;
			}
			else if (mode == "2")
			{
				play = false;
				break;
			}
		}
		if (play == false)
		{
			return 0;
		}

		// Here, we would create team 1.

		King k1(1);
		Queen q1(1);
		Rook r1a(1, 1);
		Rook r1b(1, 2);
		Bishop b1a(1, 1);
		Bishop b1b(1, 2);
		Knight d1a(1, 1);
		Knight d1b(1, 2);
		Pawn p1a(1, 1);
		Pawn p1b(1, 2);
		Pawn p1c(1, 3);
		Pawn p1d(1, 4);
		Pawn p1e(1, 5);
		Pawn p1f(1, 6);
		Pawn p1g(1, 7);
		Pawn p1h(1, 8);
		ChessPiece* team1[16];
		team1[0] = &k1;
		team1[1] = &q1;
		team1[2] = &r1a;
		team1[3] = &r1b;
		team1[4] = &b1a;
		team1[5] = &b1b;
		team1[6] = &d1a;
		team1[7] = &d1b;
		team1[8] = &p1a;
		team1[9] = &p1b;
		team1[10] = &p1c;
		team1[11] = &p1d;
		team1[12] = &p1e;
		team1[13] = &p1f;
		team1[14] = &p1g;
		team1[15] = &p1h;

		// Here, we would create team 2.

		King k2(2);
		Queen q2(2);
		Rook r2a(2, 1);
		Rook r2b(2, 2);
		Bishop b2a(2, 1);
		Bishop b2b(2, 2);
		Knight d2a(2, 1);
		Knight d2b(2, 2);
		Pawn p2a(2, 1);
		Pawn p2b(2, 2);
		Pawn p2c(2, 3);
		Pawn p2d(2, 4);
		Pawn p2e(2, 5);
		Pawn p2f(2, 6);
		Pawn p2g(2, 7);
		Pawn p2h(2, 8);
		ChessPiece* team2[16];
		team2[0] = &k2;
		team2[1] = &q2;
		team2[2] = &r2a;
		team2[3] = &r2b;
		team2[4] = &b2a;
		team2[5] = &b2b;
		team2[6] = &d2a;
		team2[7] = &d2b;
		team2[8] = &p2a;
		team2[9] = &p2b;
		team2[10] = &p2c;
		team2[11] = &p2d;
		team2[12] = &p2e;
		team2[13] = &p2f;
		team2[14] = &p2g;
		team2[15] = &p2h;

		// board is our chess board.
		
		ChessPiece* board[ROWS][COLS];
		makeBoard(board, ROWS, COLS);
		setBoard(board, team1, team2, SIZE);
		bool play1 = true;
		bool defeat1 = false;
		bool defeat2 = false;
		bool defeatMate1 = false;
		bool defeatMate2 = false;
		while (true)
		{
			if (play1 == true) // Player 1's Turn
			{
				playTeam1(board, team1, k1, ROWS, COLS, defeat1, defeatMate1);
				if (defeatMate1 == true)
				{
					break;
				}
				if (defeat1 == true)
				{
					break;
				}
				promotePawn1(board, team1);
				play1 = false;
			}
			else // Player 2's Turn
			{
				playTeam2(board, team2, k2, ROWS, COLS, defeat2, defeatMate2);
				if (defeatMate2 == true)
				{
					break;
				}
				if (defeat2 == true)
				{
					break;
				}
				promotePawn2(board, team2);
				play1 = true;
			}
		}
		if (defeatMate1 == true)
		{
			cout << setw(45) << "CHECKMATE!" << endl;
			cout << setw(46) << "Team 2 wins." << endl;
		}
		else if (defeatMate2 == true)
		{
			cout << setw(45) << "CHECKMATE!" << endl;
			cout << setw(46) << "Team 1 wins." << endl;
		}
		if (defeat1 == true)
		{
			cout << setw(46) << "Team 2 wins." << endl;
		}
		else if (defeat2 == true)
		{
			cout << setw(46) << "Team 1 wins." << endl;
		}
		system("PAUSE");
		system("CLS");
	}

	return 0;
}