#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Inicia a arvore
t_node *createNodeBST(int key, int table, int index, bool used)
{
    t_node *node = malloc(sizeof(t_node));
    node->key = key;
    node->table = table;
    node->index = index;
    node->used = used;
    node->dir = NULL;
    node->esq = NULL;

    return node;
}

// Insere um no na arvore
void insertNodeBST(t_node *root, t_node *in)
{
    t_node *aux = root;
    t_node *auxFather;

    if (root == NULL)
        root = in;
    while (aux != NULL)
    {
        auxFather = aux;
        if (in->key < aux->key)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    if (in->key < auxFather->key)
        auxFather->esq = in;
    else
        auxFather->dir = in;
}


// Destroi a arvore
void destroyNodeBST(t_node *root)
{
    if (root == NULL)
        return;

    destroyNodeBST(root->esq);
    destroyNodeBST(root->dir);
    free(root);
}

// Imprime a tabela hash em forma de arvore
void printTable(t_node *root)
{
    if (root)
    {
        printTable(root->esq);
        if (root->used == true)
            printf("%d,T%d,%d\n", root->key, root->table, root->index);
        printTable(root->dir);
    }
}
