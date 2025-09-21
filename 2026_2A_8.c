#include <stdio.h>
#define N 10
int step;
int cnt;
void Swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void QuickSort(int list[], int left, int right) {
		int i, j, pivot;
		if (left < right) {
			step++;
			i = left;
			j = right + 1;
			pivot = list[left];
			do {
				do { i++; } while (list[i] < pivot);
				do { j--; } while (list[j] > pivot);
				cnt++;
				if (i < j)
					Swap(&list[i], &list[j]);
			} while (i < j);

			Swap(&list[left], &list[j]);

			if (step == 6)
				for (i = 0; i < N; i++)
					printf("%d ", list[i]);

			QuickSort(list, left, j - 1);
			QuickSort(list, j + 1, right);
		}
}
void main(){
	int list[N] = { 31, 8, 49, 73, 11, 3, 20, 29, 65, 15 };
	QuickSort(list, 0, N - 1);
	printf("%d", cnt);
}
