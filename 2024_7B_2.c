#include <stdio.h>

int count;
char* search_string(char* s1, char* s2) {
	char* beg1 = s1, * beg2 = s2;
	while (*s1 && *s2) {
		if (*s1 == *s2) {
			s1++;
			s2++;
		}
		else {
			s1 = ++beg1;
			s2 = beg2;
		}
		count++;
	}
	if (!*s2)
		return (char*)beg1;
	else
		return NULL;
}
void main() {
	char* string = "aaaaaab";
	char* pat = "aab";
	printf("%s", search_string(string, pat));
	printf("%d", count);
}
