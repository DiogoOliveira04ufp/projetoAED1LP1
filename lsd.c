#include "lsd.h"

                                        /* Utiliza código feito em aula */

void lsd_sort_stringElements(StringElementsArray *a, int swidth, int radix)
{
    int i, r, d, c;
    int N = a -> N;
    int *count = newIntArray(radix + 1);
    StringElementsArray aux;
    createStringElementsArray(&aux, N);

    for(d = swidth - 1; d >= 0; d--)
    {
        for (i = 0; i < radix + 1; i++)
            count[i] = 0;

        for (i = 0; i < N; i++)
            count[a -> str[i][d] + 1]++;

        for(r = 0; r < radix; r++)
            count[r + 1] += count[r];

        for (i = 0; i < N; i++)
        {
            c = a -> str[i][d];
            aux.str[count[c]] = a -> str[i];
            aux.len[count[c]] = a -> str[i];
            count[c]++;
        }

        for(i = 0; i < N; i++)
        {
            a -> str[i] = aux.str[i];
            a -> len[i] = aux.len[i];
        }
    }
    freeStringElementsArray(&aux);
}

void freeStringElementsArray(StringElementsArray * si)
{
    free(si->str);
    free(si->len);
}

void createStringElementsArray(StringElementsArray *si, int N)
{
    si->N = N;
    si->str = (char **) malloc(sizeof(char *)*N);
    si->len = (int *) malloc(sizeof(int)*N);
}

void createStringElementsArrayAndFill(StringElementsArray *strArray, int N, char **strings)
{
    strArray->N = N;
    strArray->str = (char **)malloc(sizeof(char *) * N);
    strArray->len = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        strArray->str[i] = strdup(strings[i]);
        strArray->len[i] = strlen(strings[i]);
    }
}

int *newIntArray(int N) {
    return (int *) malloc(sizeof(int) * N);
}