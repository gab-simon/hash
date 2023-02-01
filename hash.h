#ifndef HASH_H
#define HASH_H
#include <stdbool.h>

typedef struct hashTable
{
    int key;
    bool used;
    int index;
} hashTable_t;

hashTable_t *createHashTable();
void insertHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key);
int removeHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key);
int searchHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key);

#endif