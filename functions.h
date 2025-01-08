#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrixStrings{
    char **strings;         //lista de strings
    int size;               //número de strings
} MATRIX_STRINGS;

typedef struct nodeMatrix {
    MATRIX_STRINGS lista_strings;
    int year, month, day;
    struct nodeMatrix * nextNode, * prevNode;
} NODE_MATRIX;

typedef struct llMatrices {
    int size;
    NODE_MATRIX *firstMatrix;
    NODE_MATRIX *lastMatrix;
} LL_MATRICES;

typedef struct adllMatrices {
    int size;
    LL_MATRICES *lists;
} AD_LL_MATRICES;

/**
 *
 * @param string string a redimensionar
 * @param resize novo tamanho
 * @return string redimensionada
 */
char *resizeStringArray(char *string, int resize);

/**
 * imrpimir strings
 * ciclo for para percorrer o array tod0 e imprimir cada elemento
 * @param matrix  array de strings a imprimir
 */
void printStrings(MATRIX_STRINGS matrix);

/**
 * inserir strings na estrutura MATRIX_STRINGS
 * insere uma string no último elemento do array e incrementa a variável size
 * @param matrix array de strings original
 * @param str string a inserir no array
 */
void insertStringIntoMatrix(MATRIX_STRINGS *matrix, char str[]);

/**
 * remover strings de uma MATRIX_STRINGS
 * recebe um índice, remove a string corresondente e passa os elementos a seguir para os seus lugares
 * @param matrix array de strings original
 * @param index índice da string a remover
 */
void removeStrings(MATRIX_STRINGS *matrix, int index);

/**
 * ler strings escritas no ficheiro
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever as strings escritas no ficheiro
 */
void readStringsFromFile(const char *filename, MATRIX_STRINGS *matrix);

/**
 * escrever strings no ficheiro
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever no ficheiro
 */
void writeStringsToFile(const char *filename, MATRIX_STRINGS matrix);

/**
 * escrever strings no ficheiro em binário
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever no ficheiro
 */
void writeStringsToBinaryFile(const char *filename, MATRIX_STRINGS matrix);

/**
 * ler strings em formato binário
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever as strings lidas
 */
void readStringsFromBinaryFile(const char *filename, MATRIX_STRINGS *matrix);

/**
 * Inserir uma matriz num nó, e depois numa lista ligada de nós
 * @param matrix array de strings
 * @param node nó de estruturas MATRIX_STRINGS
 * @param list lista de nós
 */
void insertNodeIntoList(MATRIX_STRINGS matrix, NODE_MATRIX *node, LL_MATRICES *list);

/**
 * imprimir nós
 * acessória para os nós
 * @param list lista de nós a imprimir
 */
void printNodeList(LL_MATRICES *list);

/**
 * inserir um nó numa dada posição na lista ligada
 * @param node nó a inserir
 * @param list lista onde inserir
 * @param position posição da lista onde inserir
 */
void insertNodeIntoPosition(NODE_MATRIX *node, LL_MATRICES *list, int position);

#endif // FUNCTIONS_H
