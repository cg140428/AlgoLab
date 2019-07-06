#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	vector<int> bin1;
	vector<int> bin2;

	while (turn--) {
		unsigned int num1, num2;
		fscanf(f, "%d %d", &num1, &num2);




		unsigned int cnt1 = 0, cnt2 = 0;
		int bit;
		while (num1 != 0) {
			bit = num1 % 2;
			bin1.push_back(bit);
			if (bit == 1)
				cnt1++;
			num1 /= 2;
		}
		while (num2 != 0) {
			bit = num2 % 2;
			bin2.push_back(bit);
			if (bit == 1)
				cnt2++;
			num2 /= 2;
		}



		cout << cnt1 << " " << cnt2 << " ";

		int gap1 = bin1.size() - bin2.size();
		int gap2 = bin2.size() - bin1.size();
		if (bin1.size() < bin2.size()) {
			for (int i = 0; i < gap2; i++) {
				bin1.push_back(0);
			}
		}
		else {
			for (int i = 0; i < gap1; i++) {
				bin2.push_back(0);
			}
		}

		int count = 0;

		for (int i = 0; i < max(bin1.size(), bin2.size()); i++) {
			if (bin1[i] != bin2[i])
				count++;
		}

		cout << count << endl;
		bin1.clear();
		bin2.clear();
	}
	return 0;
}