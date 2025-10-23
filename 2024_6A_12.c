#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
	int data;
	struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, int value) {
	ListNode* ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->data = value;
	ptr->link = head;
	head = ptr;
	return head;
}

ListNode* reverse(ListNode* head) {
	ListNode* current = head;
	ListNode* previous = NULL;
	ListNode* trail;

	while (current) {
		trail = previous;
		previous = current;
		current = current->link;
		previous->link = trail;

		if (previous->data == 50)
			printf("%d %d %d\n", trail->link->data, previous->link->data, current->data);
	}
	return previous;
}

int main(void) {
	ListNode* head = NULL;
	head = insert(head, 10);
	head = insert(head, 30);
	head = insert(head, 50);
	head = insert(head, 70);
	head = insert(head, 90);

	head = reverse(head);
	return 0;
}
