#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


struct Queue* createQueue(){
    struct Queue *queue = malloc(sizeof(struct Queue));
    return queue;
}

int enqueue(struct Queue *queue, int value){
    if (isFull(queue)){
        printf("Queue is full!\n");
        return -1;
    }

    queue->items[queue->end] = value;
    queue->itemCount += 1;
    queue->end = (queue->end + 1) % MAX_QUEUE_SIZE;

    return 0;
}

int dequeue(struct Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }

    int value = queue->items[queue->begin];
    queue->itemCount -= 1;
    queue->begin = (queue->begin + 1) % MAX_QUEUE_SIZE;

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
        int index = (queue->begin + i) % MAX_QUEUE_SIZE;
        if (i > 0){
            printf("-");
        }
        printf("(%d)", queue->items[index]);
    }
    printf("\n\n");

    return 0;
}

int isFull(struct Queue *queue){
    return queue->itemCount == MAX_QUEUE_SIZE;
}

int isEmpty(struct Queue *queue){
    return queue->itemCount == 0;
}

