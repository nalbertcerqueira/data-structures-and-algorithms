#include <stdio.h>
#include <stdlib.h>
#include "dynamicQueue.h"


struct DynamicStack* createQueue(){
    struct DynamicStack *queue = malloc(sizeof(struct DynamicStack));
    return queue;
}

int enqueue(struct DynamicStack *queue, int value){
    struct Node *current = queue->head;
    struct Node *node = malloc(sizeof(struct Node));

    node->value = value;
    node->next = NULL;

    if (isEmpty(queue)){
        queue->head = node;
    } else {
        while (current->next != NULL){
            current = current->next;
        }
        current->next = node;
    }

    return 0;
}

int dequeue(struct DynamicStack *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node *node = queue->head;
    int value = node->value;
    queue->head = queue->head->next;

    free(node);

    return value;
}

int peek(struct DynamicStack *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->head->value;
}

int print(struct DynamicStack *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node *current = queue->head;

    while (current != NULL){
        printf("(%d)", current->value);
        if (current->next != NULL){
            printf("-");
        }
        current = current->next;
    }
    printf("\n\n");

    return 0;
}

int isEmpty(struct DynamicStack *queue){
    return queue->head == NULL;
}


