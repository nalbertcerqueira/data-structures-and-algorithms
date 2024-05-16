struct Queue{
   int size;
   int *items;
   int itemCount;
   int begin;
   int end;
};


struct Queue* createQueue();

int enqueue(struct Queue *queue, int value);

int dequeue(struct Queue *queue);

int peek(struct Queue *queue);

int print(struct Queue *queue);

int isFull(struct Queue *queue);

int isEmpty(struct Queue *queue);

