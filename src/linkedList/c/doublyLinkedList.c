#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

struct DoublyLinkedList* createDoublyLinkedList(){
    struct DoublyLinkedList *list = malloc(sizeof(struct DoublyLinkedList));
    list->nextId = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int addFirst(int value, struct DoublyLinkedList *list){
    struct DoublyNode *node = malloc(sizeof(struct DoublyNode));

    list->nextId +=1;
    node->id = list->nextId;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    if (list->head == NULL || list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    }

    return node->id;
}

int addLast(int value, struct DoublyLinkedList *list){
    struct DoublyNode *node = malloc(sizeof(struct DoublyNode));
    struct DoublyNode *current = list->head;

    list->nextId+=1;
    node->id = list->nextId;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (list->head == NULL || list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    return node->id;
}

int addBefore(int targetId, int value, struct DoublyLinkedList *list){
    struct DoublyNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    struct DoublyNode *previousNode = foundNode->prev;
    struct DoublyNode *node = malloc(sizeof(struct DoublyNode));

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

int addAfter(int targetId, int value, struct DoublyLinkedList *list){
    struct DoublyNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    struct DoublyNode *nextNode = foundNode->next;
    struct DoublyNode *node = malloc(sizeof(struct DoublyNode));

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

int removeNode(int targetId, struct DoublyLinkedList *list){
    struct DoublyNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    struct DoublyNode *previousNode = foundNode->prev;
    struct DoublyNode *nextNode = foundNode->next;

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

int getNode(int targetId, struct DoublyLinkedList *list){
    struct DoublyNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    return foundNode->value;
}

int updateNode(int targetId, int value, struct DoublyLinkedList *list){
    struct DoublyNode *foundNode = searchNode(targetId, list);
    if(!foundNode){
        return -1;
    }

    foundNode->value = value;
    return 0;
}

int reverse(struct DoublyLinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty\n");
        return -1;
    }

    struct DoublyNode *listRef = list->head;
    struct DoublyNode *current;
    list->head = NULL;

    while (listRef != NULL) {
        struct DoublyNode *node = malloc(sizeof(struct DoublyNode));
        node->id = listRef->id;
        node->value = listRef->value;
        node->prev = NULL;
        node->next = NULL;

        if (list->head == NULL){
            list->head = node;
            list->tail = node;
        } else {
            list->head->prev = node;
            node->next = list->head;
            node->prev = NULL;
            list->head = node;
        }
        current = listRef;
        listRef = listRef->next;
        free(current);
    }

    return 0;
}

int isEmpty(struct DoublyLinkedList *list){
    return (list->head == NULL || list->tail == NULL) ? 1 : 0;
}

int print(struct DoublyLinkedList *list){
    if (isEmpty(list)){
        printf("%p\n", NULL);
        return -1;
    }

    struct DoublyNode *current = list->head;

    printf("-> head: {id: %d, value: %d}\n", list->head->id, list->head->value);
    while (current != NULL){
        printf("%p - {id: %d, value: %d, prev: %p, next: %p}\n", current, current->id, current->value, current->prev, current->next);
        current = current->next;
    }
    printf("<- tail: {id: %d, value: %d}\n", list->tail->id, list->tail->value);

    return 0;
}

static struct DoublyNode* searchNode(int targetId, struct DoublyLinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty\n");
        return NULL;
    }

    struct DoublyNode *frontNode = list->head;
    struct DoublyNode *backNode = list->tail;

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
