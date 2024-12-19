#include <stdio.h>
#include "functions.h"

int main()
{
    //printf("Hello, World!\n");
    MATRIX_STRINGS matrix;
    int size = 5;
    char nstring[] = "ar";
    char **conjunto = malloc(sizeof(char *) * 5);
    conjunto[0] = "claro";
    conjunto[1] = "aro";
    conjunto[2] = "faro";
    conjunto[3] = "pifaro";
    conjunto[4] = "pifa";



    matrix.strings = conjunto;
    matrix.size = size;

    printStrings(matrix);

    insertStringIntoMatrix(&matrix, nstring);
    printStrings(matrix);
    //printf("%d", matrix.size);

    //free(conjunto);
    //free(matrix.strings);

    return 0;
}