#include <stdio.h>
int CountOfCalls;

int func(int* n1, int* n2) {
	CountOfCalls++;
	if (*n1 <= 0)
		return 0;

	*n2 = *n2 / 2;
	printf("%d %d\n", *n1, *n2);

	return *n1 + func(n1, n2);
}

int main() {
	int value = 9;

	printf("1: %d\n", func(&value, &value));
	printf("2: %d\n", value);
	printf("3: %d\n", CountOfCalls);

	return 0;
}
