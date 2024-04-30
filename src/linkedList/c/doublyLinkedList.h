struct DoublyNode{
    int id;
    int value;
    struct DoublyNode *prev;
    struct DoublyNode *next;
};

struct DoublyLinkedList{
    int nextId;
    struct DoublyNode *head;
    struct DoublyNode *tail;
};

struct DoublyLinkedList* createLinkedList();

int addFirst(int value, struct DoublyLinkedList *list);

int addLast(int value, struct DoublyLinkedList *list);

int addBefore(int value, int targetId, struct DoublyLinkedList *list);

int addAfter(int value, int targetId, struct DoublyLinkedList *list);

int removeNode(int targetId, struct DoublyLinkedList *list);

int getNode(int targetId, struct DoublyLinkedList *list);

int updateNode(int targetId, int value, struct DoublyLinkedList *list);

int reverse(struct DoublyLinkedList *list);

int isEmpty(struct DoublyLinkedList *list);

int print(struct DoublyLinkedList *list);

static struct DoublyNode* searchNode(int targetId, struct DoublyLinkedList *list);
