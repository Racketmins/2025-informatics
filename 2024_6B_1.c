#include <stdio.h>
void sort(char* ptr, int num) {
	int i, j;
	char temp;
	for (i = 1; i < num; i++) {
		temp = ptr[i];
		j = i - 1;
		while (j >= 0 && temp < ptr[j]) {
			ptr[j + 1] = ptr[j];
			j--;
		}
		ptr[j + 1] = temp;
		if (i == 4)
			printf("%s\n", ptr);
	}
	printf("%s \n", ptr);
}

void main() {
	int len;
	char str[] = "excellent";
	len = sizeof(str) - 1;

	sort(str,len);
}
