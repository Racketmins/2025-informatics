#include <stdio.h>
int Q[9] = { 0 };
int front = 0;
int rear = 0;
int enqueue(int item) {
	rear = (rear + 1) % 9;
	if (front == rear) {
		printf("Queue is full.\n");
		return -1;
	}
	Q[rear] = item;
}
int dequeue() {
	int item;
	if (front == rear) {
		printf("Queue is empty.\n");
		return -1;
	}
	else {
		front = (front + 1) % 9;
		item = Q[front];
		Q[front] = 0;
		return item;
	}
}
int main() {
	int i;
	for (i = 1; i <= 7; i++) enqueue(i);
	dequeue(); dequeue(); dequeue();
	for (i = 1; i <= 5; i++) enqueue(i);
	for (i = 0; i < 9; i++)
		printf("%d ", Q[i]);
}
