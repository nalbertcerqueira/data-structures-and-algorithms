#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack* createStack(){
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->pointer = -1;

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

int isFull(struct Stack *stack){
    return stack->pointer == STACK_SIZE - 1;
}

int isEmpty(struct Stack *stack){
    return stack->pointer == -1;
}
