#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

struct DoubleLinkedList* createDoubleLinkedList(){
    struct DoubleLinkedList *list = malloc(sizeof(struct DoubleLinkedList));
    list->nextId = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int addFirst(int value, struct DoubleLinkedList *list){
    struct DoubleNode *node = malloc(sizeof(struct DoubleNode));

    list->nextId +=1;
    node->id = list->nextId;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    }

    return node->id;
}

int addLast(int value, struct DoubleLinkedList *list){
    struct DoubleNode *node = malloc(sizeof(struct DoubleNode));
    struct DoubleNode *current = list->head;

    list->nextId+=1;
    node->id = list->nextId;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        if (list->tail) {
            list->tail->next = node;
        }
        node->prev = list->tail;
        list->tail = node;
    }

    return node->id;
}

int addBefore(int targetId, int value, struct DoubleLinkedList *list){
    struct DoubleNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    struct DoubleNode *previousNode = foundNode->prev;
    struct DoubleNode *node = malloc(sizeof(struct DoubleNode));

    list->nextId+=1;
    node->id = list->nextId;
    node->value = value;

    node->next = foundNode;
    foundNode->prev = node;

    if (previousNode) {
        previousNode->next = node;
        node->prev = previousNode;
    } else {
        list->head = node;
    }

    return node->id;
}

int addAfter(int targetId, int value, struct DoubleLinkedList *list){
    struct DoubleNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    struct DoubleNode *nextNode = foundNode->next;
    struct DoubleNode *node = malloc(sizeof(struct DoubleNode));

    list->nextId +=1;
    node->id = list->nextId;
    node->value = value;

    node->prev = foundNode;
    node->next = foundNode->next;
    foundNode->next = node;

    if (nextNode) {
        nextNode->prev = node;
    } else {
        list->tail = node;
    }

    return node->id;
}

int removeNode(int targetId, struct DoubleLinkedList *list){
    struct DoubleNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    struct DoubleNode *previousNode = foundNode->prev;
    struct DoubleNode *nextNode = foundNode->next;

     if (previousNode) {
        previousNode->next = foundNode->next;
        if (nextNode) {
            nextNode->prev = previousNode;
        } else{
            list->tail = previousNode;
        }
    } else {
        list->head = foundNode->next;
        if (!nextNode) {
            list->tail = NULL;
        }
        if (list->head) {
            list->head->prev = NULL;
        }
    }

    free(foundNode);
    return 0;
}

int getNode(int targetId, struct DoubleLinkedList *list){
    struct DoubleNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    return foundNode->value;
}

int updateNode(int targetId, int value, struct DoubleLinkedList *list){
    struct DoubleNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    foundNode->value = value;
    return 0;
}

int isEmpty(struct DoubleLinkedList *list){
    return (list->head == NULL || list->tail == NULL) ? 1 : 0;
}

int print(struct DoubleLinkedList *list){
    if (isEmpty(list)){
        printf("%p\n", NULL);
        return -1;
    }

    struct DoubleNode *current = list->head;

    printf("-> head: {id: %d, value: %d}\n", list->head->id, list->head->value);
    while (current != NULL){
        printf("%p - {id: %d, value: %d, prev: %p, next: %p}\n", current, current->id, current->value, current->prev, current->next);
        current = current->next;
    }
    printf("<- tail: {id: %d, value: %d}\n", list->tail->id, list->tail->value);

    return 0;
}

static struct DoubleNode* searchNode(int targetId, struct DoubleLinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty\n");
        return NULL;
    }

    struct DoubleNode *frontNode = list->head;
    struct DoubleNode *backNode = list->tail;

    while (frontNode->id != targetId && backNode->id != targetId){
        if (frontNode == backNode){
            printf("Node not found\n");
            return NULL;
        }
        frontNode = frontNode->next;
        backNode = backNode->prev;
    }

    return frontNode->id == targetId ? frontNode : backNode;
}
