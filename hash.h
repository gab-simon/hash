#ifndef HASH_H
#define HASH_H

// Label: 0 - vazia; 1 - preenchida; 2 - excluído
typedef struct hashTable {
    int key;
    int label;

} hashTable_t;

// API
hashTable_t *createHashTable();
void insertHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key);
int removeHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key);
int searchHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key);
void printHashTable(hashTable_t *hashTable1, hashTable_t *hashTable2);
#endif