#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		unsigned int element, element_cpy;
		int oneCount = 0;
		fscanf(f, "%d", &element);
		element_cpy = element;
		while (element_cpy != 0) {
			if (element_cpy % 2)
				oneCount++;
			element_cpy /= 2;
		}

		if (oneCount % 2) {
			//1의 개수가 홀수일 때
			element = element + (1 << 31);
			cout << element << endl;
		}
		//1의 개수가 짝수일 때
		else {
			cout << element << endl;
		}
	}
	return 0;
}