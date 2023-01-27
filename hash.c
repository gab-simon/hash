#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

node_t *createTable(int size)
{
    node_t *table = malloc(size * sizeof(node_t));
    for (int i = 0; i < size; i++)
    {
        table[i].key = -1;
        table[i].used = true;
    }
    return table;
}

// node_t *insertNode(node_t *root, int x)
// {
//     // Árvore vazia
//     if (root == NULL)
//         return createNode(x);
//     // Inserção será à esquerda ou à direita
//     else
//     {
//         if (x < root->value)
//             root->lef = insertNode(root->lef, x);
//         else
//             root->rig = insertNode(root->rig, x);
//     }

//     // Recalcula a altura de todos os nós entre a root e o novo nó inserido
//     root->height = larger(heightNode(root->lef), heightNode(root->rig)) + 1;

//     // Verifica a necessidade de rebalancear a árvore
//     root = balance(root);

//     return root;
// }

// node_t *removeNode(node_t *root, int key)
// {
//     if (root == NULL)
//         return root;

//     // Busca valor (BST)
//     if (key < root->value)
//         root->lef = removeNode(root->lef, key);
//     else if (key > root->value)
//         root->rig = removeNode(root->rig, key);
//     else
//     { // Encontrou o valor.

//         // Verifica se um dos filhos é nulo.
//         if ((root->lef == NULL) || (root->rig == NULL))
//         {
//             node_t *temp = NULL;
//             if (root->lef != NULL)
//                 temp = root->lef;
//             else
//                 temp = root->rig;

//             if (temp == NULL)
//             {
//                 // Se é uma folha, ele exclui.
//                 temp = root;
//                 root = NULL;
//             }
//             else
//             {
//                 // Atualizando o no da root da subarvore.
//                 *root = *temp;
//             }

//             free(temp);
//         }
//         else
//         {
//             // Substituição pelo antecessor.
//             node_t *temp = maxNo(root->lef);
//             root->value = temp->value;
//             root->lef = removeNode(root->lef, temp->value);
//         }
//     }

//     if (root == NULL)
//         return root;

//     // Atualiza a altura do nó atual.
//     root->height = larger(heightNode(root->lef), heightNode(root->rig)) + 1;

//     // Verifica o fator de balanceamento entre os dois filhos do nó.
//     int fator = checkBalance(root);
//     if (fator > 1)
//     {
//         if (checkBalance(root->lef) >= 0)
//         {
//             return rightRotation(root);
//         }
//         else
//         {
//             root->lef = leftRotation(root->lef);
//             return rightRotation(root);
//         }
//     }
//     else if (fator < -1)
//     {
//         if (checkBalance(root->rig) <= 0)
//         {
//             return leftRotation(root);
//         }
//         else
//         {
//             root->rig = rightRotation(root->rig);
//             return leftRotation(root);
//         }
//     }

//     return root;
// }

// void printAVL(node_t *root, int level)
// {
//     if (root)
//     {
//         printAVL(root->lef, level + 1);
//         printf("%d,%d\n", root->value, level);
//         printAVL(root->rig, level + 1);
//     }
// }