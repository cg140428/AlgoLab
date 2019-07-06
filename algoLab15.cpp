#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double getLength(int& x1, int& y1, int& x2, int& y2);
void getMax(int arr[]);
void triangle(int a, int b, int c);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		//ÆÄÀÏ ÀĞ¾î¼­ ÁÂÇ¥¸¦ ¹è¿­¿¡ ÀúÀå
		int off[6];
		for (int i = 0; i < sizeof(off) / sizeof(int); i++) {
			fscanf(f, "%d", &off[i]);
		}

		//»ï°¢ÇüÀÌ ¾Æ´Ñ °æ¿ì: ¼¼ Á¡ÀÌ ¸ğµÎ °°Àº ¼±ºĞ ¼±»ó¿¡ ÀÖÀ» ¶§
		double m1, m2;
		bool vert1 = false, vert2 = false;
		//ºĞ¸ğ°¡ 0ÀÏ ¶§ ·±Å¸ÀÓ¿¡·¯ ¹æÁö
		if (off[2] - off[0] == 0)
			vert1 = true;
		else
			m1 = double(off[3] - off[1]) / (off[2] - off[0]);

		if (off[4] - off[2] == 0)
			vert2 = true;
		else
			m2 = double(off[5] - off[3]) / (off[4] - off[2]);
		if (m1 == m2 || (vert1 && vert2 == true))
			cout << "0" << endl;

		//»ï°¢ÇüÀÎ °æ¿ì
		else {

			int len[3];
			//¼±ºĞÀÇ ±æÀÌÀÇ Á¦°ö ±¸ÇÏ±â
			len[0] = getLength(off[0], off[1], off[2], off[3]);
			len[1] = getLength(off[2], off[3], off[4], off[5]);
			len[2] = getLength(off[4], off[5], off[0], off[1]);

			//¿À¸§Â÷¼øÀ¸·Î Á¤·Ä
			getMax(len);

			//Á÷°¢ µĞ°¢ ¿¹°¢ »ï°¢Çü ÆÇº°
			triangle(len[0], len[1], len[2]);


		}
	}

	return 0;
}

//getLength() _ µÎ ÁÂÇ¥·Î ¼±ºĞ ±æÀÌ¸¦ ±¸ÇÏ´Â ÇÔ¼ö
double getLength(int& x1, int& y1, int& x2, int& y2) {
	return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

//getMax()_¼¼ º¯Áß °¡Àå ±æÀÌ°¡ ±ä º¯ ¯±â
void getMax(int arr[]) {
	int temp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//Á÷°¢, µĞ°¢, ¿¹°¢ »ï°¢Çü ÆÇº°
void triangle(int a, int b, int c) {
	if (a + b == c)
		cout << "1" << endl;
	else if (a + b < c)
		cout << "2" << endl;
	else
		cout << "3" << endl;
}
