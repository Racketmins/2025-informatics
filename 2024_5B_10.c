#include <stdio.h>
#define MAX 10

typedef struct node* node_pointer;
typedef struct node {
	int vertex;
	node_pointer link;
} node;

typedef struct {
	int count;
	node_pointer link;
} Headnode;
Headnode graph[MAX];

void topsort(Headnode graph[], int n) {
	int i, j, k, top;
	node_pointer ptr;
	top = -1;
	for (i = 1; i <= n; i++)
		if (!graph[i].count) {
			graph[i].count = top;
			top = i;
		}

	for (i = 1; i <= n; i++) {
		if (top == -1) {
			printf("Network has a cycle.\n");
			exit(1);
		}
		else {
			j = top;
			top = graph[top].count;

			printf("%d", j);

			for (ptr = graph[j].link; ptr; ptr = ptr->link) {
				k = ptr->vertex;
				graph[k].count--;
				if (!graph[k].count) {
					graph[k].count = top;
					top = k;
				}
			}
		}
	}
}
