#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int val);
TreeNode* buildTree();
int maxPathSum(TreeNode* root, int* maxSum);
int findMaxPath(TreeNode* node, int* maxSum);

int main() {
    TreeNode* root = buildTree();
    int maxSum = INT_MIN;
    maxPathSum(root, &maxSum);
    printf("Maximum Path Sum %d\n", maxSum);
    return 0;
}


TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


TreeNode* buildTree() {
    int rootValue;
    scanf("%d", &rootValue);
    if (rootValue == -1) {
        return NULL;
    }

    TreeNode* root = createNode(rootValue);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int maxPathSum(TreeNode* root, int* maxSum) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = findMaxPath(root->left, maxSum);
    int rightSum = findMaxPath(root->right, maxSum);

    int currentPathSum = root->val + (leftSum > 0 ? leftSum : 0) + (rightSum > 0 ? rightSum : 0);

    if (currentPathSum > *maxSum) {
        *maxSum = currentPathSum;
    }

    return root->val + (leftSum > rightSum ? leftSum : rightSum);
}


int findMaxPath(TreeNode* node, int* maxSum) {
    if (node == NULL) {
        return 0;
    }

    int leftSum = findMaxPath(node->left, maxSum);
    int rightSum = findMaxPath(node->right, maxSum);

    int currentPathSum = node->val + (leftSum > 0 ? leftSum : 0) + (rightSum > 0 ? rightSum : 0);

    if (currentPathSum > *maxSum) {
        *maxSum = currentPathSum;
    }

    return node->val + (leftSum > rightSum ? leftSum : rightSum);
}

