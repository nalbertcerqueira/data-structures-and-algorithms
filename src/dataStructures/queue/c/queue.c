#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


struct Queue* createQueue(int size){
    if (size <= 0){
        printf("Size must be greater than 0!\n");
        return NULL;
    }

    int *items = malloc(sizeof(int)*size);
    struct Queue *queue = malloc(sizeof(struct Queue));

    queue->items = items;
    queue->itemCount = 0;
    queue->size = size;
    queue->begin = 0;
    queue->end = 0;

    return queue;
}

int enqueue(struct Queue *queue, int value){
    if (isFull(queue)){
        printf("Queue is full!\n");
        return -1;
    }

    queue->items[queue->end] = value;
    queue->itemCount += 1;
    queue->end = (queue->end + 1) % queue->size;

    return 0;
}

int dequeue(struct Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    int value = queue->items[queue->begin];
    queue->itemCount -= 1;
    queue->begin = (queue->begin + 1) % queue->size;

    return value;

}

int peek(struct Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->items[queue->begin];
}

int print(struct Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    for (int i = 0; i<queue->itemCount; i++){
        int index = (queue->begin + i) % queue->size;
        if (i > 0){
            printf("-");
        }
        printf("(%d)", queue->items[index]);
    }
    printf("\n\n");

    return 0;
}

int isFull(struct Queue *queue){
    return queue->itemCount == queue->size;
}

int isEmpty(struct Queue *queue){
    return queue->itemCount == 0;
}
