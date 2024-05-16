#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack* createStack(int size){
    if (size <= 0){
        printf("Size must be greater than 0!\n");
        return NULL;
    }

    int *values = malloc(sizeof(int)*size);
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->size = size;
    stack->pointer = -1;
    stack->values = values;

    return stack;
}

int push(struct Stack *stack, int value){
    if (isFull(stack)){
        printf("Stack is full!\n");
        return -1;
    }

    stack->pointer++;
    stack->values[stack->pointer] = value;

    return 0;
}

int pop(struct Stack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }

    int value = stack->values[stack->pointer];
    stack->pointer--;

    return value;
}

int peek(struct Stack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }

    return stack->values[stack->pointer];
}

int print(struct Stack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }

    for (int i=stack->pointer; i>=0; i--){
        printf("[ %d ]\n", stack->values[i]);
    }
    printf("\n");

    return 0;
}

int isFull(struct Stack *stack){
    return stack->pointer == stack->size - 1;
}

int isEmpty(struct Stack *stack){
    return stack->pointer == -1;
}

