#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int top;
	unsigned capacity;
	int* arr;
} Stack;

Stack* createStack(unsigned capacity) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->arr = (int*)malloc(capacity * sizeof(int));
	return stack;
}

int isFull(Stack* stack) {
	return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
	return stack->top == -1;
}

void push(Stack* stack, int data) {
	if (isFull(stack)) return;
	stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
	if (isEmpty(stack)) return -1;
	return stack->arr[stack->top--];
}

int sumOfDigits(int a) {
	int sum = 0;
	while (a > 0) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int queries(int* arr, int N, int i) {
    int sum_i = sumOfDigits(arr[i]);
    for (int j = i + 1; j < N; j++) {
        if ((arr[j] > arr[i]) && (sumOfDigits(arr[j]) < sum_i)) {
            return j + 1;
        }
    }
    return -1;
}

int main(){
    int N, Q;
    scanf("%d%d", &N, &Q);

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    int n;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &n);
        printf("%d\n", queries(arr, N, n - 1));
    }
    
    free(arr);
    return 0;
}
