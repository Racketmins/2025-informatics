#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int sID;
	struct node *next;
} Node;

Node* findLast(Node* start) {
	Node* p;
	if (start == NULL)
		return NULL;
	p = start;
	while (p->next != NULL) {
		printf("finLast: %d \n", p->sID);
		p = p->next;
	}
	return p;
}

void insert (Node * start, int s){
	Node* n, * p;
	p = findLast(start);
	if (p != NULL) {
		printf("insert : %d \n", p->sID);
		n = (Node*)malloc(sizeof(Node));
		n->sID = s;
		n->next = NULL;
		p->next = n;
	}
}

void main(){
	Node* start = NULL;
	start = (Node*)malloc(sizeof(Node));
	start->sID = 10000;
	start->next = NULL;
	insert(start, 20000);
	insert(start, 30000);
	return 0;
}
