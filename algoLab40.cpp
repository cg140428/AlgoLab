#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class lifeGame
{
	char board[100][101];
	int row;
	int col;
	int liveCell;

public:
	lifeGame(char a[][101], int m, int n);
	bool limit1(int a);
	bool limit2(int a);
	void playGame();
	void numOfPlay(int num);
	void display();
};

lifeGame::lifeGame(char a[][101], int m, int n)
	:row(m), col(n)
{
	liveCell = 0;
	for (int c = 0; c < m; c++)
	{
		for (int b = 0; b < n; b++)
		{
			board[c][b] = a[c][b];

			if (board[c][b] == 'O')
				liveCell++;
		}
	}
}

bool lifeGame::limit1(int a)
{
	if (a >= 0 && a < col)
		return 0;
	else
		return 1;
}

bool lifeGame::limit2(int a)
{
	if (a >= 0 && a < row)
		return 0;
	else
		return 1;
}

void lifeGame::playGame()
{
	char nextBoard[100][101] = {};

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			int sumOfLive = 0;

			for (int c = a - 1; c <= a + 1; c++)
				for (int d = b - 1; d <= b + 1; d++)
				{
					if (limit2(c) || limit1(d))
					{
						continue;
					}
					else if (board[c][d] == 'O')
						sumOfLive++;
				}


			if (board[a][b] == 'O')
			{
				sumOfLive--;
				if (sumOfLive <= 1 || sumOfLive >= 4)
				{
					nextBoard[a][b] = 'X';
					liveCell--;
				}
				else
					nextBoard[a][b] = 'O';
			}
			else
			{
				if (sumOfLive == 3)
				{
					nextBoard[a][b] = 'O';
					liveCell++;
				}
				else
					nextBoard[a][b] = 'X';
			}
		}

	for (int z = 0; z < row; z++)
	{
		for (int x = 0; x < col; x++)
			board[z][x] = nextBoard[z][x];
	}
}

void lifeGame::numOfPlay(int num)
{
	for (int a = 0; a < num; a++)
		playGame();
}

void lifeGame::display()
{
	cout << liveCell << endl;
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
			cout << board[a][b];
		cout << endl;
	}
}

int main(void)
{
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> numTestCases;

	for (int testNum = 0; testNum < numTestCases; testNum++)
	{
		int m, n, play;
		char Board[100][101] = {};

		inStream >> m >> n >> play;

		for (int a = 0; a < m; a++)
			inStream >> Board[a];

		lifeGame life(Board, m, n);

		life.numOfPlay(play);

		life.display();
	}
	inStream.close();
	return 0;
}