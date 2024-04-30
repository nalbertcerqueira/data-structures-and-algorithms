struct Node{
    int value;
    struct Node *next;
};

struct DynamicQueue{
    struct Node *head;
    struct Node *tail;
};

struct DynamicQueue* createQueue();

int enqueue(struct DynamicQueue *queue, int value);

int dequeue(struct DynamicQueue *queue);

int peek(struct DynamicQueue *queue);

int print(struct DynamicQueue *queue);

int isFull(struct DynamicQueue *queue);

int isEmpty(struct DynamicQueue *queue);

