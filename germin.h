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

/**
 * Função principal para encontrar todas as sequências de germinação
 * @param matrix array de strings a examinar
 */
void germin(MATRIX_STRINGS *matrix);

/**
 * Função auxiliar para verificar se a string 'a' cabe dentro da string 'b'
 * @param a primeira string
 * @param b segunda string
 * @return 1 se a string a é um prefixo ou sufixo da string b || 0 caso contrário
 */
int canGerminate(const char *a, const char *b);

/**
 * Função recursiva para encontrar todas as sequências de germinação
 * @param matrix array de strings a examinar
 * @param index índice da string específica
 * @param currentPath caminho atual da sequência de germinação
 * @param pathSize tamanho atual do caminho
 * @param visited array que marca quais strings já foram visitadas
 */
void findGerminations(MATRIX_STRINGS *matrix, int index, char **currentPath, int pathSize, int *visited);

/**
 * Função para imprimir o caminho na ordem correta
 * @param currentPath  caminho atual da sequência de germinação
 * @param pathSize tamanho atual do caminho
 */
void printPath(char **currentPath, int pathSize);

#endif //GERMIN_H
