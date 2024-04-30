struct DoubleNode{
    int id;
    int value;
    struct DoubleNode *prev;
    struct DoubleNode *next;
};

struct DoubleLinkedList{
    int nextId;
    struct DoubleNode *head;
    struct DoubleNode *tail;
};

struct DoubleLinkedList* createLinkedList();

int addFirst(int value, struct DoubleLinkedList *list);

int addLast(int value, struct DoubleLinkedList *list);

int addBefore(int value, int targetId, struct DoubleLinkedList *list);

int addAfter(int value, int targetId, struct DoubleLinkedList *list);

int removeNode(int targetId, struct DoubleLinkedList *list);

int getNode(int targetId, struct DoubleLinkedList *list);

int updateNode(int targetId, int value, struct DoubleLinkedList *list);

int isEmpty(struct DoubleLinkedList *list);

int print(struct DoubleLinkedList *list);

static struct DoubleNode* searchNode(int targetId, struct DoubleLinkedList *list);
