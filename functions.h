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
    LL_MATRICES *lists; //= malloc(sizeof(LL_MATRICES) * size);
} AD_LL_MATRICES;

char resizeStringArray(char *string, int resize);
void printStrings(MATRIX_STRINGS matrix);
void insertStrings(MATRIX_STRINGS *matrix);
void removeStrings(MATRIX_STRINGS matrix, int index);
void insertStringIntoMatrix(MATRIX_STRINGS *matrix, char str[]);

#endif // FUNCTIONS_H
