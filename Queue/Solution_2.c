// Problem: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
   int top;
   unsigned capacity;
   int *arr;
} Stack;

Stack *createStack(unsigned capacity) {
   Stack *stack = (Stack*)malloc(sizeof(Stack));
   stack->top = -1;
   stack->capacity = capacity;
   stack->arr = (int*)malloc(capacity * sizeof(int));
   return stack;
}

int F(Stack *stack, int i, int N) {
   for (int j = i + 1; j < N; j++) {
      if (stack->arr[j] > stack->arr[i]) {
         return j;
      }
   }
   return -1;
}

int G(Stack *stack, int j, int N) {
   if (j == -1) return -1;

   for (int k = j + 1; k < N; k++) {
      if(stack->arr[k] < stack->arr[j]) {
         return k;
      }
   }
   return -1;
}

int index(Stack *stack, int i, int N) {
   return G(stack, F(stack, i, N), N);
}

int main() {
   int N;
   scanf("%d", &N);

   Stack *stack = createStack(N);
   for (int i = 0; i < N; i++) {
      scanf("%d", &stack->arr[i]);
   }

   for (int i = 0; i < N; i++) {
      if (index(stack, i, N) == -1) printf("-1 ");
      else {
         printf("%d ", stack->arr[index(stack, i, N)]);
      }
   }
   return 0;
}