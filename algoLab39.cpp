#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class locate
{
	int row;
	int col;
	int player;
	friend class connectFour;
public:

};

class connectFour
{
	int board[6][7];
	int ifFirst;
	int looser;
public:
	connectFour();
	void playgame(int num);
	int check1(int a, int b);
	int check2(int a, int b);
	int check3(int a, int b);
	int check4(int a, int b);
	int whoWin();
};

connectFour::connectFour()
	:ifFirst(1), looser(0)
{
	for (int a = 0; a < 6; a++)
		for (int b = 0; b < 7; b++)
			board[a][b] = 0;
}

void connectFour::playgame(int num)
{
	int easyNum = num - 1;
	int locate;
	for (int a = 0; a < 6; a++)
	{
		locate = a;

		if (board[a][easyNum] == 0)
		{
			if (ifFirst == 1)
			{
				board[a][easyNum] = 1;
				ifFirst = 2;
				break;
			}
			else
			{
				board[a][easyNum] = 2;
				ifFirst = 1;
				break;
			}
		}
	}

	if (!looser)
	{
		if (check1(locate, easyNum) >= 4)
			looser = ifFirst;
		else if (check2(locate, easyNum) >= 4)
			looser = ifFirst;
		else if (check3(locate, easyNum) >= 4)
			looser = ifFirst;
		else if (check4(locate, easyNum) >= 4)
			looser = ifFirst;
	}
}

int connectFour::check1(int a, int b)
{
	int sum = 1, row = a - 1, col = b - 1;
	while ((row >= 0) && (col >= 0))
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			row--;
			col--;
		}
		else
			break;
	}

	row = a + 1, col = b + 1;

	while ((row < 6) && (col < 7))
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			row++;
			col++;
		}
		else
			break;
	}

	return sum;
}

int connectFour::check2(int a, int b)
{
	int sum = 1, row = a - 1, col = b + 1;
	while ((row >= 0) && (col < 7))
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			row--;
			col++;
		}
		else
			break;
	}

	row = a + 1, col = b - 1;

	while ((row < 6) && (col >= 0))
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			row++;
			col--;
		}
		else
			break;
	}

	return sum;
}

int connectFour::check3(int a, int b)
{
	int sum = 1, row = a + 1, col = b;
	while (row < 6)
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			row++;
		}
		else
			break;
	}

	row = a - 1, col = b;

	while (row >= 0)
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			row--;
		}
		else
			break;
	}

	return sum;
}

int connectFour::check4(int a, int b)
{
	int sum = 1, row = a, col = b + 1;
	while (col < 7)
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			col++;
		}
		else
			break;
	}

	row = a, col = b - 1;

	while (col >= 0)
	{
		if (board[row][col] == board[a][b])
		{
			sum++;
			col--;
		}
		else
			break;
	}

	return sum;
}

int connectFour::whoWin()
{
	if (looser == 1)
		return 2;
	else if (looser == 2)
		return 1;
	else
		return 0;
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
		connectFour game;
		int NumOfPlay;
		inStream >> NumOfPlay;

		for (int a = 0; a < NumOfPlay; a++)
		{
			int num;
			inStream >> num;

			game.playgame(num);
		}

		cout << game.whoWin() << endl;
	}
	inStream.close();
	return 0;
}