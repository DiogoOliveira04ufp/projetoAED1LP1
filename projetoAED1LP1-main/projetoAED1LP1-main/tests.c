#include "tests.h"


void testInsertPrint()
{
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
    printf("----------------------------------------------\n");
    insertStringIntoMatrix(&matrix, nstring);
    printStrings(matrix);

    free(conjunto);
}

void testRemove()
{
    MATRIX_STRINGS matrix;
    int size = 6;
    char **conjunto = malloc(sizeof(char *) * 6);
    conjunto[0] = strdup("claro");
    conjunto[1] = strdup("aro");
    conjunto[2] = strdup("faro");
    conjunto[3] = strdup("pifaro");
    conjunto[4] = strdup("pifa");
    conjunto[5] = strdup("ar");

    matrix.strings = conjunto;
    matrix.size = size;

    printStrings(matrix);                            //imprimir todas as strings ({"claro", "aro", "faro", "pifaro", "pifa", "ar"})
    printf("---------------------------\n");
    removeStrings(matrix, 5);                        //remover a ultima string
    printStrings(matrix);                            //imprimir o novo array sem a ultima string ({"claro", "aro", "faro", "pifaro", "pifa"})

    for (int i = 0; i < matrix.size; i++)
    {
        free(matrix.strings[i]);
    }
    free(conjunto);
}

void testLSDsort()
{
    MATRIX_STRINGS matrix;
    int size = 6;
    char **conjunto = malloc(sizeof(char *) * 6);
    conjunto[0] = strdup("claro");
    conjunto[1] = strdup("aro");
    conjunto[2] = strdup("faro");
    conjunto[3] = strdup("pifaro");
    conjunto[4] = strdup("pifa");
    conjunto[5] = strdup("ar");

    matrix.strings = conjunto;
    matrix.size = size;

    printStrings(matrix);                            //imprimir todas as strings ({"claro", "aro", "faro", "pifaro", "pifa", "ar"})
    printf("---------------------------\n");

    StringElementsArray str;
    createStringElementsArrayAndFill(&str, 6, matrix.strings);
    lsd_sort_stringElements(&str, 6, 128);

    for (int i = 0; i < 6; i++)
    {
        matrix.strings[i] = str.str[i];
    }

    printStrings(matrix);                            //imprimir o novo array organizado ({"ar", "aro", "claro", "faro", "pifa", "pifaro"})

    for (int i = 0; i < size; i++)
    {
        free(matrix.strings[i]);
    }
    free(matrix.strings);
    free(str.str);
    free(str.len);
}

void testKMP()
{
    const char *pat = "ABABAC";
    const char *txt = "ABABABABABAC";

    KMP *kmp = KMP_init(pat);
    int pos = KMP_search(kmp, txt);

    if (pos < strlen(txt)) {
        printf("Padrao encontrado na posicao: %d\n", pos);
    } else {
        printf("Padrao nao encontrado.\n");
    }

    KMP_free(kmp);
}

void testGermin()
{
    MATRIX_STRINGS matrix;
    int size = 6;
    char **conjunto = malloc(sizeof(char *) * 6);
    conjunto[0] = strdup("claro");
    conjunto[1] = strdup("aro");
    conjunto[2] = strdup("faro");
    conjunto[3] = strdup("pifaro");
    conjunto[4] = strdup("pifa");
    conjunto[5] = strdup("ar");

    matrix.strings = conjunto;
    matrix.size = size;

    printStrings(matrix);                            //imprimir todas as strings ({"claro", "aro", "faro", "pifaro", "pifa", "ar"})
    printf("---------------------------\n");

    germin(&matrix);

    for (int i = 0; i < size; i++)
    {
        free(matrix.strings[i]);
    }
    free(matrix.strings);
}