#include <stdio.h>
#define MAX 10
int step;
int acount, bcount;
void merge(int list[], int temp[], int left, int middle, int right) {
	int i = left, j = middle + 1, k = left, t;
	for (; i <= middle && j <= right;) {
		if (list[i] <= list[j])
			temp[k] = list[i++];
		else
			temp[k] = list[j++];
		k++;
	}
	if (i > middle) {
		for (t = j; t <= right;)
			temp[k++] = list[t++];
	}
	else {
		for (t = i; t <= middle;)
			temp[k++] = list[t++];
	}
	for (t = left; t <= right; t++)
		list[t] = temp[t];

	step++;
	if (step == 5)
		for (int b = 0; b < 10; b++)
			printf("%d ", list[b]);
}

void mergeSort(int list[], int temp[], int left, int right) {
	int middle = 0;
	acount++;

	if (left < right) {
		bcount++;
		middle = (left + right) / 2;
		mergeSort(list, temp, left, middle);
		mergeSort(list, temp, middle + 1, right);
		merge(list, temp, left, middle, right);
	}
}

int main() {
	int source[10] = { 26, 13, 77, 61, 35, 11, 8, 48, 15, 19 };
	int temp[10] = { 0x0, }; //그냥 0 채우겠다는 뜻... 16진수로 넣겠다는 의미 아님
	mergeSort(source, temp, 0, 9);

	printf("%d %d ", acount, bcount);
}
