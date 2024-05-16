struct Node{
    int value;
    struct Node *next;
};

struct DynamicStack{
    struct Node *head;
};

struct DynamicStack* createStack();

int isEmpty(struct DynamicStack *stack);

int push(struct DynamicStack *stack, int value);

int pop(struct DynamicStack *stack);

int peek (struct DynamicStack *stack);

int print(struct DynamicStack *stack);
