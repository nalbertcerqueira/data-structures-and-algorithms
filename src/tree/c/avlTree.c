#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avlTree.h"

struct AVLBinaryTree* createAVLBinaryTree(){
    struct AVLBinaryTree *tree = malloc(sizeof(struct AVLBinaryTree));
    tree->nodeCount = 0;
    tree->root = NULL;

    return tree;
}

struct AVLNode* createAVLNode(int id, char *data){
    struct AVLNode *node = malloc(sizeof(struct AVLNode));
    int dataLength = strlen(data) + 1;

    node->id = id;
    node->height = 0;
    node->data = malloc(sizeof(char) * dataLength);
    node->left = NULL;
    node->right = NULL;

    strncpy(node->data, data, dataLength);

    return node;
}

int insert(struct AVLBinaryTree *tree, int id, char *data){
    struct AVLNode *rootNode = insertAndBalance(id, data, tree->root, tree);

    if (rootNode == NULL){
        return -1;
    }

    tree->root = rootNode;
    return 0;
}

int deleteNode(struct AVLBinaryTree *tree, int id){
    if(isEmpty(tree)){
        printf("Tree is empty\n");
        return -1;
    }

    tree->root = deleteAndBalance(id, tree->root, tree);
    return 0;
}

int traverse(struct AVLBinaryTree *tree, enum TraverseStrategy strategy){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return -1;
    }

    if (strategy == 0){
        levelTraversal(tree);
        printf("\n");
    } else {
        depthTraversal(tree->root, strategy);
        printf("\n");
    }

    return 0;
}

int update(struct AVLBinaryTree *tree, int id, char* data) {
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return -1;
    }

    struct AVLNode *foundNode = search(id, tree->root);

    if (id != foundNode->id){
        printf("Node with id '%d' not found\n", id);
        return -1;
    }

    free(foundNode->data);
    foundNode->data = malloc(sizeof(char) * strlen(data) + 1);
    strncpy(foundNode->data, data, strlen(data) + 1);

    return 0;
}

char* find(int id, struct AVLBinaryTree *tree){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return NULL;
    }

    struct AVLNode *foundNode = search(id, tree->root);

    if (id != foundNode->id){
        printf("Node with id '%d' not found\n", id);
        return NULL;
    }

    return foundNode->data;
}

char* min(struct AVLBinaryTree *tree){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return NULL;
    }

    struct AVLNode *current = tree->root;

    while (current->left != NULL){
        current = current->left;
    }

    return current->data;
}

char* max(struct AVLBinaryTree *tree){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return NULL;
    }

    struct AVLNode *current = tree->root;

    while (current->right != NULL){
        current = current->right;
    }

    return current->data;
}

int isEmpty(struct AVLBinaryTree *tree){
    return tree->root == NULL;
}

static int depthTraversal(struct AVLNode *root, enum TraverseStrategy strategy){
    switch (strategy) {
        case 1:
            printf("[id: %d, data: %s]\n", root->id, root->data);
            root->left != 0? depthTraversal(root->left, strategy): 0;
            root->right != 0? depthTraversal(root->right, strategy): 0;
            break;
        case 2:
            root->left != 0? depthTraversal(root->left, strategy): 0;
            printf("[id: %d, data: %s]\n", root->id, root->data);
            root->right != 0? depthTraversal(root->right, strategy): 0;
            break;
        case 3:
            root->left != 0? depthTraversal(root->left, strategy): 0;
            root->right != 0? depthTraversal(root->right, strategy): 0;
            printf("[id: %d, data: %s]\n", root->id, root->data);
            break;
        default:
            printf("Traverse strategy not supported\n");
            return -1;
    }

    return 0;
}

static int levelTraversal(struct AVLBinaryTree *tree){
    struct AVLNode *current;
    struct AVLNode **queue = malloc(sizeof(struct AVLNode*) * tree->nodeCount);
    int begin = 0;
    int end = 0;

    queue[end] = tree->root;

    while (begin < tree->nodeCount){
        if (queue[begin] != NULL){
            printf("[id: %d, data: %s]\n", queue[begin]->id, queue[begin]->data);
        }

        current = queue[begin];
        if (current->left != NULL){
            end += 1;
            queue[end] = current->left;
        }
        if (current->right != NULL){
            end += 1;
            queue[end] = current->right;
        }
        begin += 1;
    }

    free(queue);
    return 0;
}

static int getBalanceFactor(struct AVLNode *node){
    if (node == NULL) {
        return 0;
    }

    int leftTreeHeight = node->left != NULL ? node->left->height : -1;
    int rightTreeHeight = node->right != NULL ? node->right->height : -1;

    return leftTreeHeight - rightTreeHeight;
}

static int getNodeHeight(struct AVLNode *node){
    if (node == NULL) {
        return -1;
    }

    int leftHeight = node->left != NULL ? node->left->height : -1;
    int rightHeight = node->right != NULL ? node->right->height : -1;

    return leftHeight > rightHeight ? (leftHeight + 1): (rightHeight + 1);
}

static struct AVLNode* search(int id, struct AVLNode *root){
    if (root && id > root->id){
        return root->right == NULL ? root: search(id, root->right);
    } else if (root && id < root->id){
        return root->left == NULL ? root: search(id, root->left);
    } else {
        return root;
    }
}

static struct AVLNode* deleteAndBalance(int id, struct AVLNode *root, struct AVLBinaryTree *tree){
    if (root == NULL){
        printf("Node with id '%d' not found\n", id);
        return NULL;
    }

    if (id < root->id){
        root->left = deleteAndBalance(id, root->left, tree);
    } else if (id > root->id){
        root->right = deleteAndBalance(id, root->right, tree);
    } else{
        tree->nodeCount -= 1;

        if (root->left == NULL && root->right == NULL){
            free(root->data);
            free(root);
            return NULL;

        } else if (!(root->left && root->right)){
            struct AVLNode *temp = root->left ? root->left : root->right;
            free(root->data);
            free(root);
            return temp;

        } else {
            struct AVLNode *current = root->left;
            struct AVLNode *previous = NULL;

            while (current->right != NULL){
                previous = current;
                current = current->right;
            }

            free(root->data);
            root->id = current->id;
            root->data = malloc(sizeof(char) * strlen(current->data) + 1);
            strncpy(root->data, current->data, strlen(current->data) + 1);

            if (previous){
                previous->right = current->left ? current->left : current->right;
            } else {
                root->left = current->left ? current->left : current->right;
            }

            free(current->data);
            free(current);
        }
    }

    root->height = getNodeHeight(root);
    return rebalanceNode(root);
}

static struct AVLNode* insertAndBalance(int id, char *data, struct AVLNode *root, struct AVLBinaryTree *tree){
    if (root == NULL) {
        tree->nodeCount += 1;
        struct AVLNode *node = createAVLNode(id, data);
        return node;
    }

    if (id > root->id) {
        root->right = insertAndBalance(id, data, root->right, tree);
    } else if (id < root->id) {
        root->left = insertAndBalance(id, data, root->left, tree);
    } else {
        printf("Node with id '%d' already exists\n", id);
        return NULL;
    }

    root->height = getNodeHeight(root);
    return rebalanceNode(root);
}

static struct AVLNode* rebalanceNode(struct AVLNode *node){
    int nodeBalanceFactor = getBalanceFactor(node);

    if (nodeBalanceFactor > 1) {
        int leftBalanceFactor = getBalanceFactor(node->left);
        return leftBalanceFactor < 0 ? rotateLR(node) : rotateRR(node);
    } else if (nodeBalanceFactor < -1) {
        int rightBalanceFactor = getBalanceFactor(node->right);
        return rightBalanceFactor > 0 ? rotateRL(node) : rotateLL(node);
    }

    return node;
}

static struct AVLNode* rotateLL(struct AVLNode *node){
    struct AVLNode *right = node->right;

    if (right) {
        node->right = node->right != NULL ? node->right->left : NULL;
        right->left = node;
        right->left->height = getNodeHeight(right->left);
        right->height = getNodeHeight(right);
        return right;
    }

    return node;
}

static struct AVLNode* rotateRR(struct AVLNode *node){
    struct AVLNode *left = node->left;

    if (left) {
        node->left = node->left != NULL ? node->left->right : NULL;
        left->right = node;
        left->right->height = getNodeHeight(left->right);
        left->height = getNodeHeight(left);
        return left;
    }

    return node;
}

static struct AVLNode* rotateRL(struct AVLNode *node){
    if (node->right) {
        node->right = rotateRR(node->right);
    }

    return rotateLL(node);
}

static struct AVLNode* rotateLR(struct AVLNode *node){
    if (node->left) {
        node->left = rotateLL(node->left);
    }

    return rotateRR(node);
}
