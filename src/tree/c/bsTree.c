#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"

struct BinaryTree* createBinaryTree(){
    struct BinaryTree *tree = malloc(sizeof(struct BinaryTree));
    tree->root = NULL;
    tree->nodeCount = 0;

    return tree;
}

int insert(struct BinaryTree *tree, int id, char *data){
    struct Node *leaf = search(id, tree->root);

    if (leaf && id == leaf->id){
        printf("Node with id '%d' already exists\n", id);
        return -1;
    }

    struct Node *node = malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->id = id;
    node->data = malloc(sizeof(char) * (strlen(data) + 1));
    strncpy(node->data, data, strlen(data) + 1);

    tree->nodeCount += 1;

    if (leaf == NULL){
        tree->root = node;
        return 0;
    }

    if (id > leaf->id){
        leaf->right = node;
    } else {
        leaf->left = node;
    }

    return 0;
}

int traverse(struct BinaryTree *tree, enum TraverseStrategy strategy){
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

int delete(struct BinaryTree *tree, int id){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return -1;
    }

    tree->root = deleteNode(tree, tree->root, id);
    return 0;

}

int update(struct BinaryTree *tree, int id, char* data) {
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return -1;
    }

    struct Node *foundNode = search(id, tree->root);

    if (id != foundNode->id){
        printf("Node with id '%d' not found\n", id);
        return -1;
    }

    free(foundNode->data);
    foundNode->data = malloc(sizeof(char) * strlen(data) + 1);
    strncpy(foundNode->data, data, strlen(data) + 1);

    return 0;
}

char* find(int id, struct BinaryTree *tree){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return NULL;
    }

    struct Node *foundNode = search(id, tree->root);

    if (id != foundNode->id){
        printf("Node with id '%d' not found\n", id);
        return NULL;
    }

    return foundNode->data;
}

char* min(struct BinaryTree *tree){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return NULL;
    }

    struct Node *current = tree->root;

    while (current->left != NULL){
        current = current->left;
    }

    return current->data;

}

char* max(struct BinaryTree *tree){
    if (isEmpty(tree)){
        printf("Tree is empty\n");
        return NULL;
    }

    struct Node *current = tree->root;

    while (current->right != NULL){
        current = current->right;
    }

    return current->data;

}

int isEmpty(struct BinaryTree *tree){
    return tree->root == NULL;
}

static struct Node* search(int id, struct Node *root){
    if (root && id > root->id){
        return root->right == NULL ? root: search(id, root->right);
    } else if (root && id < root->id){
        return root->left == NULL ? root: search(id, root->left);
    } else {
        return root;
    }
}

static struct Node* deleteNode(struct BinaryTree *tree, struct Node *node, int id){
    if (node == NULL){
        printf("Node with id '%d' not found\n", id);
        return NULL;
    }

    if (id < node->id){
        node->left = deleteNode(tree, node->left, id);
    } else if (id > node->id){
        node->right = deleteNode(tree, node->right, id);
    } else{
        tree->nodeCount -= 1;

        if (node->left == NULL && node->right == NULL){
            free(node->data);
            free(node);
            return NULL;

        } else if (!(node->left && node->right)){
            struct Node *temp = node->left ? node->left : node->right;
            free(node->data);
            free(node);
            return temp;

        } else {
            struct Node *current = node->left;
            struct Node *previous = NULL;

            while (current->right != NULL){
                previous = current;
                current = current->right;
            }

            free(node->data);
            node->id = current->id;
            node->data = malloc(sizeof(char) * strlen(current->data) + 1);
            strncpy(node->data, current->data, strlen(current->data) + 1);

            if (previous){
                previous->right = current->left ? current->left : current->right;
            } else {
                node->left = current->left ? current->left : current->right;
            }

            free(current->data);
            free(current);


            return node;
        }
    }

    return node;
}

static int depthTraversal(struct Node *root, enum TraverseStrategy strategy){
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

static int levelTraversal(struct BinaryTree *tree){
    struct Node *current;
    struct Node **queue = malloc(sizeof(struct Node*) * tree->nodeCount);
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
