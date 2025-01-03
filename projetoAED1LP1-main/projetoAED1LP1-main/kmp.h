//
// Created by Utilizador on 28/12/2024.
//

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

KMP* KMP_init(const char *pat);
int KMP_search(KMP *kmp, const char *txt);
void KMP_free(KMP *kmp);


#endif //KMP_H
