// Problem: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1?page=1&category=Linked%20List&sortBy=submissions

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node* ) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* rotate(Node* head, int k) {
    if (k == 0 || head == NULL) return head;

    for (int i = 0; i < k; i++) {
        Node* curr = head;

        while (curr->next) {
            curr = curr->next;
        }

        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = NULL;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    head = rotate(head, 5);
    printList(head);
    return 0;
}
