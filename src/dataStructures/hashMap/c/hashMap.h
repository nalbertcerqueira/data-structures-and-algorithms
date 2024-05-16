struct Data {
    int key;
    char *value;
};

struct Registry {
    struct Data *data;
    struct Registry *next;
};

struct HashMap {
    int size;
    struct Registry **values;
};

struct HashMap* createHashMap(int size);

int set(int key, char *value, struct HashMap *hashMap);

int delete(int key, struct HashMap *hashMap);

char* get(int key, struct HashMap *hashMap);

int print(struct HashMap *hashMap);

static int hash(int key, struct HashMap *hashMap);
