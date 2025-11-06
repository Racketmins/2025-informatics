#include <stdio.h>
int main() {
	int a = 2, b = 5, c = 7;
	{
		int a = 0;
		printf("%d ", a);
		printf("%d ", b);
		printf("%d\n", c);
		{
			c = 3;
			b = a + b + c + 1;
			printf("%d ", a);
			printf("%d ", b);
			printf("%d\n", c);
		}

		c += (a - b);
		{
			int c = (a - ++b);
			printf("%d ", a);
			printf("%d ", b);
			printf("%d\n", c);
		}
		printf("%d ", a);
		printf("%d ", b);
		printf("%d\n", c);
	}

	printf("%d ", a);
	printf("%d ", b);
	printf("%d\n", c);
	return 0;
}
