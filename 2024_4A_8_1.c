#include <stdio.h>
int accum(int a[], int n, int b) {
	int i, sum = b;
	for (i = 0; a[i] > 0 && i < n; i++) {
		sum += a[i];
		a[i] = sum;
	}
	return sum;
}

int main(void) {
	int res;
	int a[] = { 1, 3, 5, 7, 9 };
	res = accum(a, 10, 10);
	printf("%d ", res);
	return 0;
}