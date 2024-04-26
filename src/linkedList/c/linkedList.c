#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

struct LinkedList* createLinkedList(){
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    list->nextId = 0;
    list->head = NULL;

    return list;
}

int addFirst(int value, struct LinkedList *list){
    struct Node *node = malloc(sizeof(struct Node));
    list->nextId +=1;

    node->id = list->nextId;
    node->value = value;
    node->next = list->head;

    list->head = node;
    return node->id;
}

int addLast(int value, struct LinkedList *list){
    struct Node *node = malloc(sizeof(struct Node));
    struct Node *current = list->head;
    list->nextId+=1;

    node->id = list->nextId;
    node->value = value;
    node->next = NULL;

    if (current == NULL){
        list->head = node;
    } else {
        while (current->next != NULL){
            current = current->next;
        }
        current->next = node;
    }

    return node->id;
}

int addBefore(int targetId, int value, struct LinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty\n");
        return -1;
    }

    struct Node *previous = NULL;
    struct Node *current = list->head;

    while (current->id != targetId){
        if (current->next == NULL){
            printf("Node not found\n");
            return -1;
        }
        previous = current;
        current = current->next;
    }

    struct Node *node = malloc(sizeof(struct Node));
    list->nextId +=1;
    node->id = list->nextId;
    node->value = value;
    node->next = current;

    if (previous == NULL){
        list->head = node;
    } else {
        previous->next = node;
    }

    return node->id;
}

int addAfter(int targetId, int value, struct LinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty\n");
        return -1;
    }

    struct Node *current = list->head;

    while (current->id != targetId){
        if (current->next == NULL){
            printf("Node not found\n");
        }
        current = current->next;
    }

    struct Node *node = malloc(sizeof(struct Node));
    list->nextId +=1;
    node->id = list->nextId;
    node->value = value;
    node->next = current->next;
    current->next = node;

    return node->id;
}

int removeNode(int targetId, struct LinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty\n");
        return -1;
    }

    struct Node *previous = NULL;
    struct Node *current = list->head;

    while (current->id != targetId){
        if (current->next == NULL){
            printf("Node not found\n");
            return -1;
        }
        previous = current;
        current = current->next;
    }

    if (previous == NULL){
        list->head = current->next;
    } else{
        previous->next = current->next;
    }

    free(current);
    return 0;
}

int getNode(int targetId, struct LinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty");
        return -1;
    }

    struct Node *current = list->head;

    while (current->id != targetId){
        if (current->next == NULL){
            printf("Node not found\n");
            return -1;
        }
        current = current->next;
    }

    return current->value;
}

int updateNode(int targetId, int value, struct LinkedList *list){
    if (isEmpty(list)){
        printf("Linked list is empty");
        return -1;
    }

    struct Node *current = list->head;

    while (current->id != targetId){
        if (current->next == NULL){
            printf("Node not found\n");
            return -1;
        }
        current = current->next;
    }

    current->value = value;
    return 0;
}

int isEmpty(struct LinkedList *list){
    return list->head == NULL ? 1 : 0;
}

int print(struct LinkedList *list){
    if (isEmpty(list)){
        printf("%p\n", NULL);
        return -1;
    }

    struct Node *current = list->head;

    while (current != NULL){
        printf("%p - {id: %d, value: %d next: %p}\n", current, current->id, current->value, current->next);
        current = current->next;
    }
    printf("\n");

    return 0;
}
