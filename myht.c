#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "bst.h"

#define TAM 14
#define SIZE 11

int main()
{
    int value;
    char recive[300];

    hashTable_t *hashTable1 = createHashTable();
    hashTable_t *hashTable2 = createHashTable();

    t_node *tree, *aux;

    while (fgets(recive, 300, stdin))
    {
        char *token = strtok(recive, " ");

        if (strcmp(token, "i") == 0)
        {
            token = strtok(NULL, " ");
            value = atoi(token);
            insertHash(hashTable1, hashTable2, value);
        }
        else if (strcmp(token, "r") == 0)
        {
            token = strtok(NULL, " ");
            value = atoi(token);
            removeHash(hashTable1, hashTable2, value);
        }
        else
        {
            printf("\n Error -- opção invalida! \n");
        }
    }

    tree = createNodeBST(hashTable1[0].key, 1, 0, hashTable1[0].used);
    for (int i = 1; i < SIZE; i++)
    {
        if (hashTable1[i].used == true)
        {
            aux = createNodeBST(hashTable1[i].key, 1, i, hashTable1[i].used);
            insertNodeBST(tree, aux);
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable2[i].used == true)
        {
            aux = createNodeBST(hashTable2[i].key, 2, i, hashTable2[i].used);
            insertNodeBST(tree, aux);
        }
    }

    printTable(tree);

    free(hashTable1);
    free(hashTable2);

    return 0;
}