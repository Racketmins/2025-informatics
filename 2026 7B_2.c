#include <stdio.h>
#include <string.h>
main() {
	char word[] = "CCCOCOACOCOA";
	int i, index;
	int maxoccur = 0;
	int maxindex;
	int count[26];

	for ( i = 0; i < 26; i++)
		count[i] = 0;

	for (i = 0; i < strlen(word); i++) {
		index = word[i] - (int)'A';
		count[index]++;
	}

	for (i = 0; i < 26; i++) {
		if (maxoccur <= count[i]) {
			maxoccur = count[i];
			maxindex = i;
			printf("%d ", maxindex);
		}
	}
	printf("%c\n", (char)(maxindex + (int)'A'));
}
