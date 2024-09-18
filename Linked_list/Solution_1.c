// Problem: https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/reversed-linked-list-01b722df/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* reverseSublist(Node* start, Node* end);
Node* retrieveOriginalList(Node* head);
void printList(Node* head);

int main() {
    int n, data;
    Node *head = NULL, *tail = NULL;
    
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &data);
        Node* newNode = createNode(data);
        if (!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }
    
    head = retrieveOriginalList(head);
    printList(head);
    
    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* reverseSublist(Node* start, Node* end) {
    Node *prev = NULL, *curr = start;
    while (curr != end) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* retrieveOriginalList(Node* head) {
    Node dummy = {0, head};
    Node* prev = &dummy;
    
    while (head) {
        if (head->data % 2 == 0) {
            Node* start = head;
            while (head && head->data % 2 == 0) head = head->next;
            prev->next = reverseSublist(start, head);
            start->next = head;
        }
        prev = head ? head : prev;
        head = head ? head->next : head;
    }
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
