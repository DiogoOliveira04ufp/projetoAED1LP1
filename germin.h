//
// Created by Utilizador on 30/12/2024.
//

#ifndef GERMIN_H
#define GERMIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"          //para as matrizes
#include "kmp.h"

// Define uma estrutura para armazenar palavras
typedef struct {
    char palavra[100];
} Palavra;


void germin(MATRIX_STRINGS *matrix);
int canGerminate(const char *a, const char *b);
void findGerminations(MATRIX_STRINGS *matrix, int index, char **currentPath, int pathSize, int *visited);

#endif //GERMIN_H
