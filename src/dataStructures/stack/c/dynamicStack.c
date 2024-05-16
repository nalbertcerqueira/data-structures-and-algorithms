#include <stdio.h>
#include <stdlib.h>
#include "dynamicStack.h"

struct DynamicStack* createStack(){
    struct DynamicStack *stack = malloc(sizeof(struct DynamicStack));
    stack->head = NULL;

    return stack;
}

int push(struct DynamicStack *stack, int value){
    struct Node *node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = stack->head;
    stack->head = node;

    return 0;
}

int pop(struct DynamicStack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }

    struct Node *node = stack->head;
    int value = node->value;
    stack->head = stack->head->next;

    free(node);

    return value;
}

int peek(struct DynamicStack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }

    return stack->head->value;
}

int print(struct DynamicStack *stack){
    if (isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }

    struct Node *current = stack->head;
    while (current != NULL){
        printf("[ %d ]\n", current->value);
        current = current->next;
    }
    printf("\n");

    return 0;
}

int isEmpty(struct DynamicStack *stack){
    return stack->head == NULL;
}
