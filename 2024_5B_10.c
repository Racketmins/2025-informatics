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
	for (i = 0; i < n; i++)
		if (!graph[i].count) {
			graph[i].count = top;
			top = i;
		}

	for (i = 0; i < n; i++) {
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

void add_edge(int from, int to) {
	node_pointer new_node = (node_pointer)malloc(sizeof(node));
	new_node->vertex = to;
	new_node->link = graph[from].link;
	graph[from].link = new_node;

	graph[to].count++; // 진입차수 증가
}

int main() {
	int n = 7; // 정점 0~6

	// 그래프 초기화
	for (int i = 0; i < n; i++) {
		graph[i].link = NULL;
		graph[i].count = 0;
	}

	// 그래프 정의
	add_edge(0, 3);
	add_edge(0, 2);
	add_edge(0, 1);
	add_edge(1, 4);
	add_edge(2, 6);
	add_edge(2, 5);
	add_edge(2, 4);
	add_edge(3, 5);
	add_edge(4, 6);
	add_edge(5, 6);

	// 위상 정렬 호출
	printf("Topological Order: ");
	topsort(graph, n);

	return 0;
}
