#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#define SIZE 11

// Função que retorna o código hash da primeira tabela
int hashcode1(int key)
{
    return key % SIZE;
}

// Função que retorna o código hash da segunda tabela
int hashcode2(int key)
{
    int floor = key * 0.9;
    float notFloor = key * 0.9;
    return SIZE * (notFloor - floor);
}

// Função que inicia uma tabela hash
hashTable_t *createHashTable()
{
    hashTable_t *newHashTable = malloc(sizeof(hashTable_t) * SIZE);
    if (!newHashTable)
        return NULL;

    // Inicializa os valores da tabela
    for (int i = 0; i < SIZE; i++)
    {
        newHashTable[i].key = 0;
        newHashTable[i].label = 0;
    }

    return newHashTable;
}

// Função que consulta uma chave nas duas tabelas hash
int searchHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key)
{
    int index1 = hashcode1(key);
    int index2 = hashcode2(key);
    if (hashTable1[index1].label == 1 && hashTable1[index1].key == key)
        return index1;
    else if (hashTable2[index2].label == 1 && hashTable2[index2].key == key)
        return index2;
    else
        return -1;
}

// Função que insere uma chave na tabela hash
void insertHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key)
{
    int index1 = hashcode1(key);
    int index2 = hashcode2(key);
    int indexAux;

    // Verifica se a chave já existe na hash
    if (hashTable1[index1].label == 1 && hashTable1[index1].key == key)
        return;
    else if (hashTable2[index2].label == 1 && hashTable2[index2].key == key)
        return;
    // Insere a chave na hash
    else
    {
        // Insere chave na segunda tabela
        if (hashTable1[index1].label == 1)
        {
            indexAux = hashcode2(hashTable1[index1].key);
            hashTable2[indexAux].key = hashTable1[index1].key;
            hashTable2[indexAux].label = 1;
            hashTable1[index1].key = key;
        }
        // Insere a chave na primeira tabela
        else
        {
            hashTable1[index1].key = key;
            hashTable1[index1].label = 1;
        }
    }
}

// Função que remove uma chave da tabela hash
int removeHash(hashTable_t *hashTable1, hashTable_t *hashTable2, int key)
{
    int index1 = hashcode1(key);
    int index2 = hashcode2(key);

    if (hashTable2[index2].label == 1 && hashTable2[index2].key == key)
    {
        hashTable2[index2].label = 2;
        hashTable2[index2].key = 0;
    }
    else if (hashTable1[index1].label == 1 && hashTable1[index1].key == key)
    {
        hashTable1[index1].label = 2;
        hashTable1[index1].key = 0;
    }
    else
        return 0;
    return 1;
}

// Função que imprime a tabela hash
void printHashTable(hashTable_t *hashTable1, hashTable_t *hashTable2)
{
    int i;
    printf("  T1            T2\n");
    printf("---------------------\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable1[i].label == 1 && hashTable1[i].key == 0)
            printf("%2d|%-12d", i, hashTable1[i].key);
        else
            printf("%2d|%-12.d", i, hashTable1[i].key);
        if (hashTable2[i].label == 1 && hashTable2[i].key == 0)
            printf("%2d|%-12d\n", i, hashTable2[i].key);
        else
            printf("%2d|%-12.d\n", i, hashTable2[i].key);
    }
}