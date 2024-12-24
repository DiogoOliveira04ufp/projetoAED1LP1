#include "lsd.h"

void lsd_sort_stringElements(StringElementsArray *a, int swidth, int radix)
{
    int i, r, d, c;
    int N = a -> N;
    int *count = newIntArray(radix + 1);
    StringElementsArray aux;                // aux Array
    createStringElementsArray(&aux, N);     // create aux array

    for(d = swidth - 1; d >= 0; d--)
    {
        // reset count[] array
        for (i = 0; i < radix + 1; i++)
            count[i] = 0;

        // compute frequency counts
        for (i = 0; i < N; i++)
            count[a -> str[i][d] + 1]++;

        // transform counts to indicies
        for(r = 0; r < radix; r++)
            count[r + 1] += count[r];

        // distribute
        for (i = 0; i < N; i++) {
            c = a -> str[i][d];
            aux.str[count[c]] = a -> str[i];
            aux.len[count[c]] = a -> str[i];
            count[c]++;
        }

        // copy back
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
    return;
}

void createStringElementsArray(StringElementsArray *si, int N)
{
    si->N = N;
    si->str = (char **) malloc(sizeof(char *)*N);
    si->len = (int *) malloc(sizeof(int)*N);
    return;
}

int *newIntArray(int N) {
    return (int *) malloc(sizeof(int) * N);
}