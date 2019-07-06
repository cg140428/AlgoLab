#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		int cntMoon = 0;
		int year, totalDays;
		fscanf(f, "%d", &year);

		for (int i = 1582; i < year; i++) {
			if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
				cntMoon++;
		}

		totalDays = (year - 1582) * 365 + cntMoon;

		int month;
		fscanf(f, "%d", &month);
		int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		for (int i = 1; i < month; i++) {
			totalDays += months[i - 1];
			if (i == 2) {
				if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
					totalDays++;
			}
		}

		int days = 1;
		totalDays += days;
		int whatDate;

		switch (totalDays % 7)
		{
		case 0: whatDate = 4; break; //목
		case 1: whatDate = 5; break; //금
		case 2: whatDate = 6; break; //토
		case 3: whatDate = 0; break; //일
		case 4: whatDate = 1; break; //월
		case 5: whatDate = 2; break; //화
		case 6: whatDate = 3;		 //수
		}

		cout << year << " " << month << endl;
		int line = 0;
		bool Moon;
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			Moon = true;
		else
			Moon = false;

		for (int i = 0; i < whatDate; i++) {
			cout << "0" << " ";
			line++;
		}
		for (int d = 1; d < months[month - 1] + 1; d++) {
			cout << d;
			line++;
			if (line % 7 == 0 && d != months[month - 1])
				cout << endl;
			else
				cout << " ";
		}
		if (month == 2 && Moon == true) {
			if (line % 7 == 0)
				cout << endl;
			cout << "29 ";

			line++;
		}
		while (line % 7 != 0) {
			cout << "0" << " ";
			line++;
		}
		cout << endl;
	}
	return 0;
}