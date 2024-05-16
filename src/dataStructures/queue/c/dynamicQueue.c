#include <stdio.h>
#include <stdlib.h>
#include "dynamicQueue.h"


struct DynamicQueue* createQueue(){
    struct DynamicQueue *queue = malloc(sizeof(struct DynamicQueue));
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

int enqueue(struct DynamicQueue *queue, int value){
    struct Node *current = queue->head;
    struct Node *node = malloc(sizeof(struct Node));

    node->value = value;
    node->next = NULL;

    if (isEmpty(queue)){
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }

    return 0;
}

int dequeue(struct DynamicQueue *queue){
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

int peek(struct DynamicQueue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->head->value;
}

int print(struct DynamicQueue *queue){
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

int isEmpty(struct DynamicQueue *queue){
    return queue->head == NULL;
}
