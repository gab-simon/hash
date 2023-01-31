#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define TAM 14
#define SIZE 11

int main(){
    int value;
    char recive[300];
    hashTable_t *hashTable1 = createHashTable();
    hashTable_t *hashTable2 = createHashTable();

    while(fgets(recive, 300, stdin)){
        char *token = strtok(recive, " ");

        if(strcmp(token, "i") == 0){
            token = strtok(NULL, " ");
            value = atoi(token);
            insertHash(hashTable1, hashTable2, value);
        }
        else if (strcmp(token, "r") == 0) {
            token = strtok(NULL, " ");
            value = atoi(token);
            removeHash(hashTable1, hashTable2, value);
        } else {
            printf("\n Error -- opção invalida! \n");
        }
    }

    free(hashTable1);
    free(hashTable2);

    printHashTable(hashTable1, hashTable2);
    
    return 0;
}