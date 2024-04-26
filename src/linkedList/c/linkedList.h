struct Node{
    int id;
    int value;
    struct Node *next;
};

struct LinkedList{
    int nextId;
    struct Node *head;
};

struct LinkedList* createLinkedList();

int addFirst(int value, struct LinkedList *list);

int addLast(int value, struct LinkedList *list);

int addBefore(int value, int targetId, struct LinkedList *list);

int addAfter(int value, int targetId, struct LinkedList *list);

int removeNode(int targetId, struct LinkedList *list);

int getNode(int targetId, struct LinkedList *list);

int updateNode(int targetId, int value, struct LinkedList *list);

int isEmpty(struct LinkedList *list);

int print(struct LinkedList *list);
