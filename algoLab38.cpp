#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;


class mors
{
	char mos[2001];
public:
	mors(char* A);
	void displayMors();
};

char Mos[26][5] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

mors::mors(char* A)
{
	strcpy(mos, A);

	displayMors();
}

void mors::displayMors()
{
	int a = 0;

	while (1)
	{
		char token[5] = {};
		int b = 0;
		while ((mos[a] != '#') && (mos[a] != '|') && (mos[a] != '\0'))
		{
			token[b] = mos[a];
			b++;
			a++;
		}
		for (int c = 0;; c++)
		{
			if (strcmp(Mos[c], token) == 0)
			{
				char output = c + 'A';
				cout << output;
				break;
			}
		}

		if (mos[a] == '|')
		{
			a++;
		}
		else if (mos[a] == '#')
		{
			cout << '_';
			a++;
		}
		else
			break;
	}
	cout << endl;
}

int main(void)
{
	ifstream inStream;
	int turn;

	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> turn;

	for (int num = 0; num < turn; num++)
	{
		char mos[2001];

		inStream >> mos;

		mors good(mos);
	}
	inStream.close();
	return 0;
}