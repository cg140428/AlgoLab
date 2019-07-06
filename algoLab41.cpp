#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class square
{
	int evenMagicSqare[50][50];
	int n;
public:
	square(int b)
		: n(b)
	{
		for (int a = 0; a < n; a++)
			for (int b = 0; b < n; b++)
				evenMagicSqare[a][b] = 0;
	}
	void create();
	void for4th();
	void forOther();
	void print();
	void L(int a, int b, int c);
	void U(int a, int b, int c);
	void X(int a, int b, int c);
};

class fourSquare
{
	int before;
	int after;
	friend class square;
};

void square::create()
{
	if ((n % 4 == 0))
		for4th();
	else
		forOther();
}

void square::for4th()
{
	fourSquare four[48][48];
	fourSquare squareFour[4][4];
	int num = 1;

	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			four[a][b].before = num;
			four[a][b].after = (n*n + 1) - num;
			num++;
		}
	}

	for (int e = 0; e < n / 4; e++)
	{
		for (int f = 0; f < n / 4; f++)
		{
			for (int c = 0; c < 4; c++)
				for (int d = 0; d < 4; d++)
				{
					if ((c == d) || (3 - c == d))
						evenMagicSqare[c + (e * 4)][d + (f * 4)] = four[c + (e * 4)][d + (f * 4)].after;
					else
						evenMagicSqare[c + (e * 4)][d + (f * 4)] = four[c + (e * 4)][d + (f * 4)].before;
				}
		}
	}
}

void square::forOther()
{
	int test[25][25] = { 0 };
	int row, col, expectLine, expectCol, newN;
	int m = n / 2;

	col = (m - 1) / 2;
	row = m - 1;
	newN = m - 1;

	for (int c = 0; c < m*m; c++)
	{
		if (newN - row <= m / 2)
		{
			if ((col == m / 2) && (newN - row == m / 2))
				U(newN - row, col, 4 * c + 1);
			else
				L(newN - row, col, 4 * c + 1);
		}
		else if (newN - row == m / 2 + 1)
		{
			if (col == m / 2)
				L(newN - row, col, 4 * c + 1);
			else
				U(newN - row, col, 4 * c + 1);
		}
		else
			X(newN - row, col, 4 * c + 1);

		test[newN - row][col] = 1;

		expectLine = (row + 1) % m;
		expectCol = (col + 1) % m;
		if (test[newN - expectLine][expectCol] != 0)
		{
			if (row == 0)
			{
				row = m - 1;
			}
			else
			{
				row--;
			}

			continue;
		}
		row = expectLine;
		col = expectCol;
	}
}

void square::L(int a, int b, int c)
{
	evenMagicSqare[2 * a][2 * b + 1] = c;
	evenMagicSqare[2 * a + 1][2 * b] = c + 1;
	evenMagicSqare[2 * a + 1][2 * b + 1] = c + 2;
	evenMagicSqare[2 * a][2 * b] = c + 3;
}

void square::U(int a, int b, int c)
{
	evenMagicSqare[2 * a][2 * b + 1] = c + 3;
	evenMagicSqare[2 * a + 1][2 * b] = c + 1;
	evenMagicSqare[2 * a + 1][2 * b + 1] = c + 2;
	evenMagicSqare[2 * a][2 * b] = c;
}

void square::X(int a, int b, int c)
{
	evenMagicSqare[2 * a][2 * b + 1] = c + 3;
	evenMagicSqare[2 * a + 1][2 * b] = c + 2;
	evenMagicSqare[2 * a + 1][2 * b + 1] = c + 1;
	evenMagicSqare[2 * a][2 * b] = c;
}

void square::print()
{
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			cout << evenMagicSqare[a][b] << " ";
		}
		cout << endl;
	}
}

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
		int a;
		inStream >> a;

		square play(a);
		play.create();

		play.print();
	}
	inStream.close();
	return 0;
}