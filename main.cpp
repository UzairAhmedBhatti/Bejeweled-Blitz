#include <iostream>
#include <conio.h>
#include <time.h>
#include <fstream>
#include "help.h"

using namespace std;

void randomBoard(int board[8][8]) //**********Generating the RANDOM values to fill the BOARD**********
{
	srand(time(0));
	for (int i = 0;i < 8;i++)
		for (int j = 0;j < 8;j++)
			board[i][j] = (rand() % 5 + 1);
}
void printBoard(int board[8][8]) //**********Printing the numbers on the Board**********
{
	for (int i = 0; i < 8; i++)
	{
		int n;
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 1)
				myDiamondin((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 255, 255, 0, 155,0,0);
			else if (board[i][j] == 2)
				myCircleIn((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 255, 255, 0, 255,100,255);
			else if (board[i][j] == 3)
				myRectIn((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 0, 0, 255, 0,0,100);
			else if (board[i][j] == 4)
				myTrianglein((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 230, 255, 0, 255,255,255);
			else if (board[i][j] == 5)
				myStar((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 230, 255, 0, 255, 255, 255);
			if (board[i][j] == 6)
				myFDiamondin((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 255, 255, 0, 155, 0, 0);
			else if (board[i][j] == 7)
				myFCircleIn((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 255, 255, 0, 255, 100, 255);
			else if (board[i][j] == 8)
				myFRectIn((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 0, 0, 255, 0, 0, 100);
			else if (board[i][j] == 9)
				myFTrianglein((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 230, 255, 0, 255, 255, 255);
			else if (board[i][j] == 10)
				myFStar((100 + j * 50) + 5, (50 + i * 50) + 5, (150 + j * 50) - 5, (100 + i * 50) - 5, 230, 255, 0, 255, 255, 255);

			cout << " ";
		}
	}
}
void checkingNmakingZero(int board[8][8], int &score) //**********Checking Conditions to make the matching GEMS zero**********
{
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++) //Condition for the Elbows
		{
			if (board[row][column] == 1)
			{
				if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
				{
					board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
					board[row][column] = 6;
				}
				if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
				{
					board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
					board[row][column] = 6;
				}
				if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
				{
					board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
					board[row][column] = 6;
				}
				if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
				{
					board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
					board[row][column] = 6;
				}
			}
			else if (board[row][column] == 2)
			{
				{
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
						board[row][column] = 7;
					}
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
						board[row][column] = 7;
					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
						board[row][column] = 7;
					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
						board[row][column] = 7;
					}
				}
			}
			else if (board[row][column] == 3)
			{
				{
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
						board[row][column] = 8;
					}
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
						board[row][column] = 8;
					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
						board[row][column] = 8;
					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
						board[row][column] = 8;
					}
				}
			}
			else if (board[row][column] == 4)
			{
				{
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
						board[row][column] = 9;
					}
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
						board[row][column] = 9;
					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column + 1] = board[row][column + 2] = 0;
						board[row][column] = 9;
					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column - 1] = board[row][column - 2] = 0;
						board[row][column] = 9;
					}

				}
			}
			else if (board[row][column] == 5)
			{
				{
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column + 1] = board[row][column + 2] = 0;

					}
					if (board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row - 1][column] = board[row - 2][column] = board[row][column - 1] = board[row][column - 2] = 0;

					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column + 1] = board[row][column + 2] = 0;

					}
					if (board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column] && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
					{
						board[row][column] = board[row + 1][column] = board[row + 2][column] = board[row][column - 1] = board[row][column - 2] = 0;

					}
				}
			}
			if (board[row][column] == 6 && board[row][column - 1] == 1&&board[row][column - 1] == board[row][column + 1])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 6 && board[row - 1][column]==1 && board[row - 1][column] == board[row + 1][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 6 && board[row - 1][column] ==1&&board[row - 1][column] == board[row - 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;

			}
			else if (board[row][column] == 6 && board[row + 1][column] == 1&&board[row + 1][column] == board[row + 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;

			}
			else if (board[row][column] == 6 && board[row][column + 1] == 1&&board[row][column + 1] == board[row][column + 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;

			}

			else if (board[row][column] == 6 && board[row][column - 1] == 1 && board[row][column - 1] == board[row][column - 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;

			}




			if (board[row][column] == 7 && board[row][column - 1] == 2 && board[row][column - 1] == board[row][column + 1])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 7 && board[row - 1][column] == 2 && board[row - 1][column] == board[row + 1][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 7 && board[row - 1][column] == 2 && board[row - 1][column] == board[row - 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 7 && board[row + 1][column] == 2 && board[row + 1][column] == board[row + 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 7 && board[row][column + 1] == 2 && board[row][column + 1] == board[row][column + 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 7 && board[row][column - 1] == 2 && board[row][column - 1] == board[row][column - 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}




			if (board[row][column] == 8 && board[row][column - 1] == 3 && board[row][column - 1] == board[row][column + 1])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 8 && board[row - 1][column] == 3 && board[row - 1][column] == board[row + 1][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 8 && board[row - 1][column] == 3 && board[row - 1][column] == board[row - 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 8 && board[row + 1][column] == 3 && board[row + 1][column] == board[row + 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 8 && board[row][column + 1] == 3 && board[row][column + 1] == board[row][column + 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}

			else if (board[row][column] == 8 && board[row][column - 1] == 3 && board[row][column - 1] == board[row][column - 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}



			else if (board[row][column] == 9 && board[row - 1][column] == 4 && board[row - 1][column] == board[row + 1][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 9 && board[row - 1][column] == 4&& board[row - 1][column] == board[row - 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 9 && board[row + 1][column] == 4 && board[row + 1][column] == board[row + 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 9 && board[row][column + 1] == 4 && board[row][column + 1] == board[row][column + 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 9 && board[row][column - 1] == 4 && board[row][column - 1] == board[row][column - 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;

			}
			if (board[row][column] == 9 && board[row][column - 1] == 4 && board[row][column - 1] == board[row][column + 1])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}



			else if (board[row][column] == 10 && board[row - 1][column] == 5 && board[row - 1][column] == board[row + 1][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 10 && board[row - 1][column] == 5 && board[row - 1][column] == board[row - 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 10 && board[row + 1][column] == 5 && board[row + 1][column] == board[row + 2][column])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 10 && board[row][column + 1] == 5 && board[row][column + 1] == board[row][column + 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			else if (board[row][column] == 10 && board[row][column - 1] == 5&& board[row][column - 1] == board[row][column - 2])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;

			}
			if (board[row][column] == 10 && board[row][column - 1] == 5 && board[row][column - 1] == board[row][column + 1])
			{
				board[row][column] = 0;
				board[row][column - 1] = 0;
				board[row][column + 1] = 0;
				board[row - 1][column - 1] = 0;
				board[row - 1][column + 1] = 0;
				board[row + 1][column - 1] = 0;
				board[row + 1][column + 1] = 0;
				score = score + 100;
			}
			


			//Part of function

			if (row < 6 && board[row][column] == board[row + 1][column] && board[row][column] == board[row + 2][column])
			{
				if (row < 5 && board[row + 2][column] == board[row + 3][column])
				{
					board[row + 3][column] = 0;
					if (row < 4 && board[row + 2][column] == board[row + 4][column])
						board[row + 4][column] = 0;
				}
				board[row][column] = board[row + 1][column] = board[row + 2][column] = 0;
				score = score + 10;
			}
			else if (row > 2 && board[row][column] == board[row - 1][column] && board[row][column] == board[row - 2][column])
			{
				if (row > 4 && board[row - 2][column] == board[row - 3][column])
				{
					board[row - 3][column] = 0;
					if (row > 5 && board[row - 2][column] == board[row - 4][column])
						board[row - 4][column] = 0;
				}
				board[row][column] = board[row - 1][column] = board[row - 2][column] = 0;
				score = score + 10;
			}
			else if (column < 6 && board[row][column] == board[row][column + 1] && board[row][column] == board[row][column + 2])
			{
				if (column < 5 && board[row][column + 2] == board[row][column + 3])
				{
					board[row][column + 3] = 0;
					if (column < 4 && board[row][column + 2] == board[row][column + 4])
						board[row][column + 4] = 0;
				}
				board[row][column] = board[row][column + 1] = board[row][column + 2] = 0;
				score = score + 10;
			}
			else if (column > 2 && board[row][column] == board[row][column - 1] && board[row][column] == board[row][column - 2])
			{
				if (column > 4 && board[row][column - 2] == board[row][column - 3])
				{
					board[row][column - 3] = 0;
					if (column > 5 && board[row][column - 2] == board[row][column - 4])
						board[row][column - 4] = 0;
				}
				board[row][column] = board[row][column - 1] = board[row][column - 2] = 0;
				score = score + 10;
			}
			//else
			//{
			//	swap(board[row1][column1], board[row2][column2]);
			//}
		}
	}
}
bool searchBoardForZero(int board[8][8]) //**********Just checking the ZEROES**********
{
	int condition = 0;
	for (int j = 0;j < 8;j++)
	{
		for (int i = 0;i < 8;i++)
		{
			if (board[j][i] == 0)
				condition++;
		}
	}
	return condition;
}
void checkMyBoardNmakeRandom(int board[8][8]) //***********Placing the RANDOM number in place of ZEROES**********
{
	searchBoardForZero(board);
	for (int row = 0;row < 8;row++)
	{
		for (int column = 0;column < 8;column++)
		{
			if (board[row][column] == 0)
			{
				board[row][column] = ((rand() % 5) + 1);
			}
		}
	}
}
void gemsFallling(int board[8][8])  //Making the germs to tg j0h
{
	//for (int y = 0;y < 3;y++)
	//{
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			if (board[i][j] == 0)
			{
				for (int term = 0; term < i; term++)
				{
					system("cls");
					swap(board[i - term][j], board[i - term - 1][j]);
					printBoard(board);
					Sleep(10);
				}
			}
		}
	}
	//}
}
void firstChecck(int board[8][8],int &score)
{
	checkingNmakingZero(board,score);
	while (searchBoardForZero(board) == true)
	{
		checkMyBoardNmakeRandom(board);

	}
	checkMyBoardNmakeRandom(board);
	system("cls");
	printBoard(board);
}


//******************Main Function calling*******************

int main()
{
	int score = 0;
	int i = 0, j = 0, random = 0;
	int x = 0, y = 0;
	int secTime = 0;
	int cursor;
	int row1 = 0, row2 = 0, column1 = 0, column2 = 0;
	int row, col;
	int board[8][8];
	randomBoard(board);
	firstChecck(board, score);
	//boardStructure(board);
	printBoard(board);
	//secTime = time(NULL) + 60;
	//while (difftime(secTime, time(NULL)) >= 0)
	for (int i = 0; i < 9;i++)
	{

		cout << "Score :"<< score;
		int ntime;
		int cursor, x = 100, y = 50, row = 0, col = 0;
		myLine(x, y + 50, x + 50, y + 50, 255);
		cursor = 0;
		while (cursor != 13)
		{
			if (isCursorKeyPressed(cursor) == true)
			{

				if (cursor == 1 && x > 100)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);

					x -= 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}

				if (cursor == 2 && y > 50)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);
					y -= 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}
				if (cursor == 3 && x < 450)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);
					x += 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}
				if (cursor == 4 && y < 400)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);
					y += 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}

				if (cursor == 5)
				{
					ofstream fout("save.txt");
					for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						fout << board[i][j] << " ";
					fout << " " << score << " " << difftime(secTime, time(0));
					fout.close();
				}
				if (cursor == 6)
				{
					ifstream fin("save.txt");
					for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						fin >> board[i][j];
					fin >> score;
					fin >> ntime;
					fin.close();
					secTime = (secTime - 60) + ntime;
					system("cls");
					printBoard(board);
					gotoxy(0, 0);
					cout << "Time left!" << endl << ntime << " sec" << endl;
					cout << "score" << endl << score;
					gotoxy(0, 0);
				}
			}
		}
		col = (x - 100) / 50;
		row = (y - 50) / 50;


		row1 = row, column1 = col;
		cursor = 0;
		while (cursor != 13)
		{
			if (isCursorKeyPressed(cursor) == true)
			{

				if (cursor == 1 && x > 100)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);
					x -= 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}

				if (cursor == 2 && y > 50)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);
					y -= 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}
				if (cursor == 3 && x < 450)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);
					x += 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}

				if (cursor == 4 && y < 400)
				{
					myLine(x, y + 50, x + 50, y + 50, 0);
					y += 50;
					myLine(x, y + 50, x + 50, y + 50, 255);
				}
				if (cursor == 5)
				{
					ofstream fout("save.txt");
					for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						fout << board[i][j] << " ";
					fout << " " << score << " " << difftime(secTime, time(0));
					fout.close();
				}
				if (cursor == 6)
				{
					ifstream fin("save.txt");
					for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						fin >> board[i][j];
					fin >> score;
					fin >> ntime;
					fin.close();
					secTime = (secTime - 60) + ntime;
					system("cls");
					printBoard(board);
					gotoxy(0, 0);
					cout << "Time left!" << endl << ntime << " sec" << endl;
					cout << "score" << endl << score;
					gotoxy(0, 0);
				}
			}
		}
		col = (x - 100) / 50;
		row = (y - 50) / 50;

		row2 = row, column2 = col;
		cout << score;
		swap(board[row1][column1], board[row2][column2]);
		printBoard(board);

		checkingNmakingZero(board, score);
		cout << "Score is :" << score;

		while (searchBoardForZero(board) == true)
		{
			gemsFallling(board);
			checkMyBoardNmakeRandom(board);
			checkingNmakingZero(board, score);
		}

		system("cls");
		//gotoxy(900, 900);
		printBoard(board);
	}
	system("cls");
	cout << "time's up:\n";
	cout << "Score is : " << score << endl;
	_getch();
	system("PAUSE");
}