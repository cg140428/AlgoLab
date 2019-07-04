#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE * f;
	f = fopen("input.txt", "r");

	int turn;
	int num1, num2;

	fscanf(f, "%d", &turn);
	
	for (int i = 0; i < turn; i++) {
		fscanf(f, "%d %d", &num1, &num2);
		cout << num1 + num2 << " ";
		cout << num1 - num2 << " ";
		if (num1 - num2 > 0)
			cout << num1 - num2 << " ";
		else
			cout << num2 - num1 << " ";
		cout << num1 * num2 << " ";
		cout << num1 / num2 << " ";
		cout << num1 % num2 << " ";
		if (num1 > num2)
			cout << num1 << " ";
		else
			cout << num2 << " ";
		if (num1 == num2)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}


	return 0;
}