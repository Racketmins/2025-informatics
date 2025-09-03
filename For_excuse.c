#include <stdio.h>
int i = 100, j = 20;
void proc();

int main() {
	int i = 50;
	printf("i = %d, j = %d\n", i, j);
	{
		int i = 0, j = 12;
		printf("i=%d, j=%d\n", i, j);
	}
	{
		int j = 100, k = 5;
		printf("i=%d, j=%d, k=%d\n", i, j, k);
	}
	{
		int i = 3;
		printf("i=%d, j=%d\n", i, j);
	}
	printf("i=%d, j=%d\n", i, j); //¤¡
	proc();
}

void proc() {
	int j = 20, k = 35;
	i = j + k;
	printf("i=%d, j=%d, k=%d", i, j, k); //¤¤
}