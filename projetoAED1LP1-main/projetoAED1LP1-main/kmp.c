#include "kmp.h"

// Função para inicializar a estrutura KMP
KMP* KMP_init(const char *pat)
{
    KMP *kmp = (KMP *)malloc(sizeof(KMP));
    kmp->pat = strdup(pat);
    kmp->M = strlen(pat);
    kmp->dfa = (int **)malloc(256 * sizeof(int *));
    for (int i = 0; i < 256; i++)
    {
        kmp->dfa[i] = (int *)calloc(kmp->M, sizeof(int));
    }

    kmp->dfa[(unsigned char)pat[0]][0] = 1;
    for (int X = 0, j = 1; j < kmp->M; j++)
    {
        for (int c = 0; c < 256; c++)
        {
            kmp->dfa[c][j] = kmp->dfa[c][X];
        }
        kmp->dfa[(unsigned char)pat[j]][j] = j + 1;
        X = kmp->dfa[(unsigned char)pat[j]][X];
    }

    return kmp;
}

// Função para buscar o padrão em um texto
int KMP_search(KMP *kmp, const char *txt)
{
    int N = strlen(txt);
    int i, j;
    for (i = 0, j = 0; i < N && j < kmp->M; i++)
    {
        j = kmp->dfa[(unsigned char)txt[i]][j];
    }
    if (j == kmp->M) return i - kmp->M;
    else return N;
}

// Função para liberar a memória alocada pela estrutura KMP
void KMP_free(KMP *kmp)
{
    for (int i = 0; i < 256; i++)
    {
        free(kmp->dfa[i]);
    }
    free(kmp->dfa);
    free(kmp->pat);
    free(kmp);
}