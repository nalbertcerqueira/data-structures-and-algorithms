struct Data {
    int key;
    char *value;
};

struct Registry {
    struct Data *data;
    struct Registry *next;
};

struct HashTable {
    int size;
    struct Registry **values;
};

struct HashTable* createHashTable(int size);

int set(int key, char *value, struct HashTable *hashTable);

int delete(int key, struct HashTable *hashTable);

char* get(int key, struct HashTable *hashTable);

int print(struct HashTable *hashTable);

static int hash(int key, struct HashTable *hashTable);
