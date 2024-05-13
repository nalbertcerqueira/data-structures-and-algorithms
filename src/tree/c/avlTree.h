struct AVLNode{
    int id;
    int height;
    char *data;
    struct AVLNode *left;
    struct AVLNode *right;
};

struct AVLBinaryTree {
    int nodeCount;
    struct AVLNode *root;
};

enum TraverseStrategy {
    LEVEL,
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

struct AVLBinaryTree* createAVLBinaryTree();

int insert(struct AVLBinaryTree *tree, int id, char *data);

int deleteNode(struct AVLBinaryTree *tree, int id);

int traverse(struct AVLBinaryTree *tree, enum TraverseStrategy strategy);

int update(struct AVLBinaryTree *tree, int id, char* data);

char* find(int id, struct AVLBinaryTree *tree);

char* min(struct AVLBinaryTree *tree);

char* max(struct AVLBinaryTree *tree);

int isEmpty(struct AVLBinaryTree *tree);

static int depthTraversal(struct AVLNode *root, enum TraverseStrategy strategy);

static int levelTraversal(struct AVLBinaryTree *tree);

static int getBalanceFactor(struct AVLNode *node);

static int getNodeHeight(struct AVLNode *node);

static struct AVLNode* search(int id, struct AVLNode *root);

static struct AVLNode* deleteAndBalance(int id, struct AVLNode *root, struct AVLBinaryTree *tree);

static struct AVLNode* insertAndBalance(int id, char *data, struct AVLNode *root, struct AVLBinaryTree *tree);

static struct AVLNode* rebalanceNode(struct AVLNode *node);

static struct AVLNode* rotateLL(struct AVLNode *node);

static struct AVLNode* rotateRR(struct AVLNode *node);

static struct AVLNode* rotateRL(struct AVLNode *node);

static struct AVLNode* rotateLR(struct AVLNode *node);

