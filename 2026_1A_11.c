#include <stdio.h>
#define N 7
static int ht[N];
int NumOfCom;

void insertHT(int data) {
	int hV;
	hV = data % N;

	while (ht[hV] != 0)
		hV = (hV + 1) % N;

	ht[hV] = data;
}

int searchHT(int data) {
	int i, hV;
	hV = i = data % N;

	while (1) {
		NumOfCom++;
		if (ht[i] == data)
			return i;
		i = (i + 1) % N;
		if (i == hV)
			return -1;
	}
}

int main(void) {
	int i;
	int key[] = { 3, 18, 14, 17, 11, 31 };

	for (i = 0; i < sizeof(key) / sizeof(int); i++)
		insertHT(key[i]);

	for (i = 0; i < sizeof(key) / sizeof(int); i++)
		searchHT(key[i]);

	printf("\n%d", NumOfCom);
}
