#ifndef LSD_H
#define LSD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ** str;  // array of strings
    int * len;    // array of string lengths
    int N;        // number of strings (size of array of strings)
} StringElementsArray;

/**
 * Ordenação das strings por ordem alfabética
 * @param a estrutura inicializada para começar o algoritmo
 * @param swidth tamanho do array de strings
 * @param radix número de caracteres do standard ASCII a ser considerado para a ordenação
 */
void lsd_sort_stringElements(StringElementsArray *a, int swidth, int radix);

/**
 * Aloca a memória para a estrutura onde o algoritmo vai ser aplicado
 * @param si estrutura vazia a ser populada
 * @param N número de strings
 */
void createStringElementsArray(StringElementsArray * si, int N);

/**
 * Enche a estrutura a ser ordenada
 * @param strArray estrutura vazia a ser populada
 * @param N número de strings
 * @param strings array de strings
 */
void createStringElementsArrayAndFill(StringElementsArray * si, int N, char ** strings);

/**
 * Cria um array de inteiros vazio
 * @param N tamanho do array
 * @return array vazio
 */
int *newIntArray(int N);

/**
 * Liberta a estrutura StringElementsArray criada para o algoritmo
 * @param si estrutura a ser libertada
 */
void freeStringElementsArray(StringElementsArray * si);

#endif //LSD_H
