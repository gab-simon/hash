#ifndef _BST_
#define _BST_
#include <stdbool.h>

struct node {
    int key;
    int table;
    int index;
    int used;
    struct node *dir;
    struct node *esq;
};
typedef struct node t_node;

t_node *createNodeBST(int key, int table, int index, bool used);
void insertNodeBST(t_node *root, t_node *in);
void destroyNodeBST(t_node *root);
void printTable(t_node *root);

#endif