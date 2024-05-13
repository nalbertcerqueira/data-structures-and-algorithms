struct Node{
    int id;
    char *data;
    struct Node *left;
    struct Node *right;
};

struct BinaryTree {
    int nodeCount;
    struct Node *root;
};

enum TraverseStrategy {
    LEVEL,
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

struct BinaryTree* createBinaryTree();

int insert(struct BinaryTree *tree, int id, char *data);

int traverse(struct BinaryTree *tree, enum TraverseStrategy strategy);

int delete(struct BinaryTree *tree, int id);

int update(struct BinaryTree *tree, int id, char* data);

char* find(int id, struct BinaryTree *tree);

char* min(struct BinaryTree *tree);

char* max(struct BinaryTree *tree);

int isEmpty(struct BinaryTree *tree);

static struct Node* search(int id, struct Node *root);

static struct Node* deleteNode(struct BinaryTree *tree, struct Node *node, int id);

static int depthTraversal(struct Node *root, enum TraverseStrategy strategy);

static int levelTraversal(struct BinaryTree *tree);
