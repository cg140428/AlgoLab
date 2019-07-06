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

		int days;
		fscanf(f, "%d", &days);
		totalDays += days;

		switch (totalDays % 7)
		{
		case 0: cout << "4" << endl; break;
		case 1: cout << "5" << endl; break;
		case 2: cout << "6" << endl; break;
		case 3: cout << "0" << endl; break;
		case 4: cout << "1" << endl; break;
		case 5: cout << "2" << endl; break;
		case 6: cout << "3" << endl;
		}
	}
	return 0;
}