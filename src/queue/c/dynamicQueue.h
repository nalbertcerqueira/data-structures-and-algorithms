struct Node{
    int value;
    struct Node *next;
};

struct DynamicStack{
    struct Node *head;
};

struct DynamicStack* createQueue();

int enqueue(struct DynamicStack *queue, int value);

int dequeue(struct DynamicStack *queue);

int peek(struct DynamicStack *queue);

int print(struct DynamicStack *queue);

int isFull(struct DynamicStack *queue);

int isEmpty(struct DynamicStack *queue);

