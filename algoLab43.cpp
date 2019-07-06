#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct
{
	int m;
	int n;
	int find;
} coordinate;

coordinate findWord(char board[][201], char* str, int m, int n, int row, int col);

int main(void)
{
	ifstream inStream;
	int turns;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> turns;

	for (int testNum = 0; testNum < turns; testNum++)
	{
		char board[200][201] = {};
		int m, n;

		inStream >> m >> n;

		for (int a = 0; a < m; a++)
			inStream >> board[a];

		int z;

		inStream >> z;

		for (int b = 0; b < z; b++)
		{
			char str[201] = {};
			coordinate compass = { 0, 0, -1 };
			inStream >> str;

			for (int c = 0; c < m; c++)
			{
				for (int d = 0; d < n; d++)
				{
					if (str[0] == board[c][d])
					{
						compass = findWord(board, str, c, d, m, n);

						if (compass.find != -1)
							break;
					}
				}
				if (compass.find != -1)
					break;
			}

			if (compass.find != -1)
			{
				cout << compass.m << " " << compass.n << " ";
			}
			cout << compass.find << endl;

		}
	}
	inStream.close();
	return 0;
}

coordinate findWord(char board[][201], char* str, int m, int n, int row, int col)
{
	coordinate test = { 0, 0, -1 };
	int figure[8][2] = { -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1 };

	for (int a = 0; a < 8; a++)
	{
		int M = m, N = n;
		int index = 0;

		while (1)
		{

			if ((M >= 0) && (M < row) && (N >= 0) && (N < col))
			{
				if (board[M][N] == str[index])
				{
					index++;
					M += figure[a][0];
					N += figure[a][1];

					if (str[index] == '\0')
					{
						test.find = a;
						test.m = m + 1;
						test.n = n + 1;

						return test;
					}

					continue;
				}
				else
					break;
			}
			else
				break;
		}
	}
	return test;
}