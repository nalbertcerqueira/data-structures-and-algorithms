#define STACK_SIZE 30

struct Stack {
   int pointer;
   int values[STACK_SIZE];
};

struct Stack* createStack();

int isFull(struct Stack *stack);

int isEmpty(struct Stack *stack);

int push(struct Stack *stack, int value);

int pop(struct Stack *stack);

int peek (struct Stack *stack);

int print(struct Stack *stack);
