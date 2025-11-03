#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10
#define EMPTY -1
int cnt1, cnt2;

int trans_pos(int dt) {
	int magic[] = { 4, 0, 6, 3, 2, 1, 8, 7, 9, 0 };
	return magic[dt / MAXSIZE];
}

int main(void) {
	int i, ptr, ptr1, value;
	bool full = false; //stdbool.h 추가 필요
	int data[MAXSIZE];
	int loc[] = { 16, 52, 27, 79, 37, 13, 78 };

	for (i = 0; i < MAXSIZE; i++)
		data[i] = -1;

	for (i = 0; i < sizeof(loc) / sizeof(int); i++) {
		value = loc[i];
		ptr = ptr1 = trans_pos(value);

		while (data[ptr] != EMPTY) {
			if (value < 50) {
				ptr = (ptr + 1) % MAXSIZE;
				cnt1++;
			}
			else {
				ptr = (ptr + 3) % MAXSIZE;
				cnt2++;
			}
			if (ptr == ptr1) {
				printf("full: %d\n", value);
				full = true;
				break;
			}
		}

		if (full != true) {
			data[ptr] = value;
			printf("%d ", ptr);
		}
	}

	printf("\n % d % d", cnt1, cnt2);
	for (i = 0; i < MAXSIZE; i++)
		printf("%d ", data[i]);
}
