#include <stdio.h>
#define MAX 10

#include <stdio.h>
#define R 10
#define N 10

void Print(int a[], int n){
	int k;
	for (k = 0; k < n; k++)
		printf("%d ", a[k]);
	printf("\n");
}

countingSort(int a[], int n, int r, int p) {
	int i, j, k;
	int exp = 1;
	int b[N];
	int c[R];

	for (j = 0; j < r; j++)
		c[j] = 0;
	for (i = 1; i <= p; i++)
		exp = r * exp;
	for (i = 0; i < n; i++)
		c[(a[i] / exp) % r]++;
	for (j = 1; j < r; j++)
		c[j] = c[j] + c[j - 1];

	if (p == 0)
		Print(c, r);
	for (i = n - 1; i >= 0; i--) {
		b[c[(a[i] / exp) % r] - 1] = a[i];
		c[(a[i] / exp) % r]--;
	}
	for (i = 0; i < n; i++)
		a[i] = b[i];
}

radixSort(int a[], int n, int r, int m) {
	int i, k;
	for (i = 0; i < m; i++) {
		countingSort(a, n, r, i);
		if (i == 1)
			Print(a, n);
	}
}

void main() {
	int a[] = { 512, 193, 741, 321, 562, 783, 823, 112, 911, 901 };
	radixSort(a, N, R, 3);
	Print(a, N);
}
