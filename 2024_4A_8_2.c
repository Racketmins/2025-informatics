#include <stdio.h>
int r_accum(int a[], int n, int b) {
	int sum = b;
	if (n == 0 || a[0]<= 0)
		return sum;
	else {
		sum += a[0];
		a[0] = sum;
		return r_accum(a + 1, n - 1, sum);
	}
}

int main(void) {
	int a[] = { 1, 3, 5, 7, 9 };
	printf("%d", r_accum(a, 10, 10));
	return 0;
}
