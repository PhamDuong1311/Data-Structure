// Problem: https://www.hackerearth.com/problem/algorithm/dynamic-array/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int *data;
} DynamicArray_t;

void createArray(DynamicArray_t *arr, int capacity);
void resizeArray(DynamicArray_t *arr);
void add(DynamicArray_t *arr, int x);
void delete(DynamicArray_t *arr, int x);
int cmpfunc(const void *a, const void *b);
int smallest(DynamicArray_t *arr, int x);
int gcd(int a, int b);
int gcd_query(DynamicArray_t* arr, int L, int R);

int main() {
    DynamicArray_t *arr = (DynamicArray_t *)malloc(sizeof(DynamicArray_t));
    createArray(arr, 10);

    int Q;
    scanf("%d", &Q);

    for (int i = 1; i <= Q; i++) {
        int K;
        scanf("%d", &K);

        if (K == 1) {
            int x;
            scanf("%d", &x);
            add(arr, x);
        } else if (K == 2) {
            int x;
            scanf("%d", &x);
            delete(arr, x);
        } else if (K == 3) {
            int x;
            scanf("%d", &x);
            printf("%d\n", smallest(arr, x));
        } else if (K == 4) {
            int L, R;
            scanf("%d%d", &L, &R);
            printf("%d\n", gcd_query(arr, L, R));
        }
    }

 
    free(arr);       
    return 0;
}

void createArray(DynamicArray_t *arr, int capacity) {
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

void resizeArray(DynamicArray_t *arr) {
    arr->capacity *= 2;
    arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
}

void add(DynamicArray_t *arr, int x) {
    if (arr->size >= arr->capacity) {
        resizeArray(arr);
    }
    arr->data[arr->size++] = x;
}

void delete(DynamicArray_t *arr, int x) {
    int flag = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == x) {
            flag = 1;
        }

        if (flag == 1) {
            arr->data[i] = arr->data[i + 1];
        }
    }

    if (flag == 1) {
        arr->data[arr->size-- - 1] = 0;
    }
}

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int smallest(DynamicArray_t *arr, int x) {
    qsort(arr->data, arr->size, sizeof(int), cmpfunc);
    return arr->data[x - 1];
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int gcd_query(DynamicArray_t* arr, int L, int R) {
    int result;

    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] >= L && arr->data[i] <= R) {
            result = gcd(result, arr->data[i]);
        }
    }

    return result;
}