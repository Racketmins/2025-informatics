#include <stdio.h>
int cnt;
void Swap(int* x, int* y) {
	int temp;
	temp = *x;

	*x = *y;
	*y = temp;
}

void Qsort(int list[], int m, int n) {
	int i, j, k;
	int Middle, PartElem, Value;
	if (n - m > 1) {
		cnt++;

		Middle = (m + n) / 2;
		if (list[m] > list[Middle])
			Swap(&list[m], &list[Middle]);
		if (list[m] > list[n])
			Swap(&list[m], &list[n]);
		if (list[Middle] > list[n])
			Swap(&list[Middle], &list[n]);

		Swap(&list[Middle], &list[m + 1]);
		i = PartElem = m + 1;
		j = n;
		Value = list[PartElem];

		while (1) {
			while (list[++i] < Value);
			while (list[--j] > Value);
			if (i < j) Swap(&list[i], &list[j]);
			else break;
		}
		list[PartElem] = list[j];
		list[j] = Value;

		if (cnt == 1)
			for (k = 0; k <= 8; k++)
				printf("%d", list[k]);

		printf("\n");
		Qsort(list, m, j - 1);
		Qsort(list, j + 1, n);
	}
	else if (list[m] > list[n])
		Swap(&list[m], &list[n]);
}

void main() {
	int list[9] = { 9, 4, 7, 6, 5, 8, 3, 2, 1 };
	Qsort(list, 0, 8);
	printf("%d", cnt);
}
