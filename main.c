#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define M 20

int main(){
    int value;
    char recive[300];
    node_t *h1, *h2;
    h1 = createTable(M);
    h2 = createTable(M);
    
    while(fgets(recive, 300, stdin)){
        char *token = strtok(recive, " ");

        if(strcmp(token, "i") == 0){
            token = strtok(NULL, " ");
            value = atoi(token);
            // root = insertNode(root, value);
        }
        else if (strcmp(token, "r") == 0) {
            token = strtok(NULL, " ");
            value = atoi(token);
            // root = removeNode(root, value);
        } else {
            printf("\n Error -- opção invalida! \n");
        }
    }

    // printAVL(root, 0);
    return 0;
}