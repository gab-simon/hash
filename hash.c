#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#define SIZE 11

// Função hash da primeira tabela
int hashcode1(int key)
{
    return key % SIZE;
}

// Função hash da segunda tabela
int hashcode2(int key)
{
    return (int)(SIZE * (key * 0.9 - (int)(key * 0.9)));
}

// Função que inicia tabela hash
hashTable_t *createHashTable()
{
    hashTable_t *HashTable = malloc(sizeof(hashTable_t) * SIZE);
    if (!HashTable)
        return NULL;

    for (int i = 0; i < SIZE; i++)
    {
        HashTable[i].key = 0;
        HashTable[i].used = false;
    }

    return HashTable;
}

// Função que consulta uma chave nas duas tabelas hash
int searchHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key)
{
    int index1 = hashcode1(key);
    int index2 = hashcode2(key);

    if (hashTable1[index1].used && hashTable1[index1].key == key)
        return index1;
    else if (hashTable2[index2].used && hashTable2[index2].key == key)
        return index2;
    else
        return -1;
}

// Função que insertNodeBST uma chave na tabela hash
void insertHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key)
{
    int index1 = hashcode1(key);
    int index2 = hashcode2(key);
    int indexAux;

    // Verifica se chave já foi inserida
    if (hashTable1[index1].used == true && hashTable1[index1].key == key)
        return;
    else if (hashTable2[index2].used == true && hashTable2[index2].key == key)
        return;

    else
    {
        // Insere chave na segunda tabela
        if (hashTable1[index1].used == true)
        {
            indexAux = hashcode2(hashTable1[index1].key);
            hashTable2[indexAux].key = hashTable1[index1].key;
            hashTable2[indexAux].used = true;
            hashTable1[index1].key = key;
        }
        // Insere a chave na primeira tabela
        else
        {
            hashTable1[index1].key = key;
            hashTable1[index1].used = true;
        }
    }
}

// Função que remove uma chave da tabela hash
int removeHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key)
{
    int index1 = hashcode1(key);
    int index2 = hashcode2(key);

    if (hashTable2[index2].used == true && hashTable2[index2].key == key)
    {
        hashTable2[index2].used = false;
        hashTable2[index2].key = 0;
    }
    else if (hashTable1[index1].used == true && hashTable1[index1].key == key)
    {
        hashTable1[index1].used = false;
        hashTable1[index1].key = 0;
    }
    else
        return 0;
    return 1;
}