#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

class credit
{
	int num[20];
	int length;

public:
	credit(char *str);
	int checkCompany();
};

credit::credit(char *str)
{
	length = strlen(str);
	for (int a = 0; a < 20; a++)
	{
		if (str[a] != 0)
			num[a] = str[a] - '0';
		else
			num[a] = -1;
	}
}

int credit::checkCompany()
{
	switch (num[0])
	{
	case 3:
	{
		if ((length != 14) && (length != 15))
			return 0;
		break;
	}
	case 4:
	{
		if ((length != 13) && (length != 16))
			return 0;
		break;
	}
	case 5:
	{
		if (length != 16)
			return 0;
		break;
	}
	case 6:
	{
		if (length != 16)
			return 0;
		break;
	}
	default:
		return 0;
	}

	int locate = length - 2;
	int sum = 0;
	for (int a = locate; a >= 0; a--)
	{
		if ((locate - a) % 2 == 0)
		{
			int b = num[a] * 2;

			if (b >= 10)
				b -= 9;
			sum += b;
		}
		else
			sum += num[a];
	}

	if ((sum + num[length - 1]) % 10)
		return 0;
	else
		return 1;
}

int main(void)
{
	ifstream inStream;
	int turn;

	inStream.open("input.txt");

	inStream >> turn;

	for (int num = 0; num < turn; num++)
	{
		char number[21];
		inStream >> number;

		credit check(number);

		cout << check.checkCompany() << endl;
	}
	inStream.close();
	return 0;
}