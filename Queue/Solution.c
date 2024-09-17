#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* arr;
} Queue;

Queue* createQueue(unsigned capacity) {
	Queue* queue = (Queue* ) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->arr = (int* ) malloc(capacity * sizeof(int));
	return queue;
}

int isFull(Queue* queue) {
	return queue->size == queue->capacity;
}

int isEmpty(Queue* queue) {
	return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
	if (isFull(queue)) return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->arr[queue->rear] = item;
	queue->size += 1;
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) return 1;
	int item = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -= 1;
	return item;
}

void operation_1(Queue* queue) {
	int item = dequeue(queue);
	enqueue(queue, item);
}

void operation_2(Queue* a, Queue* b) {
		dequeue(a);
		dequeue(b);
}

int main(){
	int n;
	scanf("%d", &n);
	Queue* a = createQueue(n);
	Queue* b = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a->arr[i]);
        a->size++;
        a->rear = i;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b->arr[i]);
        b->size++;
        b->rear = i;
    }
	
	int count = 0;
	while (!isEmpty(a)) {
		if (a->arr[a->front] == b->arr[b->front]) {
			operation_2(a, b);
			count++;
		}
		else {
			operation_1(a);
			count++;
		}
	}

	printf("%d", count);
}
