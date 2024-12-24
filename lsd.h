#ifndef LSD_H
#define LSD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ** str;  // array of strings
    int * len;    // array of string lengths
    int N;        // number of strings (size of array of strings)
} StringElementsArray;

void lsd_sort_stringElements(StringElementsArray *a, int swidth, int radix);
void createStringElementsArray(StringElementsArray * si, int N);
int *newIntArray(int N);
void freeStringElementsArray(StringElementsArray * si);

#endif //LSD_H
