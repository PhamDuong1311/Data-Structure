// Problem: https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    long long value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(long long value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, long long value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

int search(TreeNode* root, long long value) {
    if (root == NULL) {
        return 0; 
    }
    if (value == root->value) {
        return 1; 
    }
    if (value < root->value) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M); 

        TreeNode* root = NULL;
        for (int i = 0; i < N; i++) {
            long long candies;
            scanf("%lld", &candies);
            root = insert(root, candies); 
        }

        for (int i = 0; i < M; i++) {
            long long newCandies;
            scanf("%lld", &newCandies);
            
            if (search(root, newCandies)) {
                printf("YES\n");
            } else {
                printf("NO\n");
                root = insert(root, newCandies); 
            }
        }

        freeTree(root);
    }

    return 0;
}
