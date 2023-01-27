#ifndef __AVL__
#define __AVL__

struct node {
    bool used;
    int key;
}; typedef struct node node_t;

node_t* createTable(int value);

node_t* insertNode(node_t* root, int value);

node_t* removeNode(node_t* root, int key);

void printAVL(node_t *root, int level);

#endif