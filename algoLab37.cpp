#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

class Read
{
	int num[4];
	int sum;
public:
	Read(unsigned int Num);
	void displayRead();
};

char BMT[4][9] = { "", "Thousand", "Million", "Billion" };
char one[9][6] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
char ten[10][10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
char twenty[8][10] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
char hundred[8] = "Hundred";

Read::Read(unsigned int Num)
{
	sum = 0;
	for (int a = 0; a < 4; a++)
	{
		num[a] = (Num % 1000);
		sum += num[a];
		Num /= 1000;
	}
	displayRead();
}

void Read::displayRead()
{
	for (int a = 3; a >= 0; a--)
	{
		int Num = num[a];

		if (Num / 100)
		{
			cout << one[Num / 100 - 1] << '_' << hundred;
			sum -= Num / 100 * 100;
			if ((a == 0) && (sum == 0))
				break;

			cout << '_';
		}

		Num %= 100;

		if (Num / 10 == 1)
		{
			cout << ten[Num % 10];
			sum -= Num;
			if (a&&sum)
				cout << '_';
		}
		else
		{
			if (Num / 10 > 1)
			{
				cout << twenty[(Num / 10) - 2];
				sum -= Num / 10 * 10;

				if ((a == 0) && (sum == 0))
					break;

				cout << '_';
			}
			Num %= 10;

			if (Num)
			{
				cout << one[Num - 1];
				sum -= Num;

				if (a)
					cout << '_';
			}
		}

		if (num[a])
		{
			cout << BMT[a];

			if (a&&sum)
				cout << '_';
		}
	}
	cout << endl;
}

int main(void)
{
	ifstream inStream;
	int turns;

	inStream.open("input.txt");

	inStream >> turns;

	for (int testNum = 0; testNum < turns; testNum++)
	{
		unsigned int num;

		inStream >> num;

		Read Mynum(num);
	}
	inStream.close();

	return 0;
}