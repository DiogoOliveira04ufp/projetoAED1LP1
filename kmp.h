#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

typedef struct {
    char *pat;
    int **dfa;
    int M;
} KMP;

/**
 *
 * @param pat - padrão a descobrir
 * @return - estrutura preparada para aplicar o algoritmo
 */
KMP* KMP_init(const char *pat);

/**
 * Função para procurar o padrão num texto
 * @param kmp estrutura do padrão a encontrar
 * @param txt string onde se vai procurar o padrão
 * @return índice onde o padrão foi encontrado
 */
int KMP_search(KMP *kmp, const char *txt);

/**
 * Função para libertar a memória alocada pela estrutura KMP
 * @param kmp estrutura do padrão para libertar
 */
void KMP_free(KMP *kmp);


#endif //KMP_H
