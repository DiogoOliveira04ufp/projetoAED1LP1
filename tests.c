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
void testWriteToFile()
{
    MATRIX_STRINGS matrix;
    int size = 6;
    char **conjunto = malloc(sizeof(char *) * size);

    if (conjunto == NULL) {
        perror("Erro ao alocar memória para conjunto");
        return;
    }

    conjunto[0] = strdup("claro");
    conjunto[1] = strdup("aro");
    conjunto[2] = strdup("faro");
    conjunto[3] = strdup("pifaro");
    conjunto[4] = strdup("pifa");
    conjunto[5] = strdup("ar");

    for (int i = 0; i < size; i++)
    {
        if (conjunto[i] == NULL)
        {
            perror("Erro ao duplicar string");
            for (int j = 0; j < i; j++)
            {
                free(conjunto[j]);
            }
            free(conjunto);
            return;
        }
    }

    matrix.strings = conjunto;
    matrix.size = size;

    writeStringsToFile("C:/Users/joaop/OneDrive/Ambiente de Trabalho/projetoAED1LP1-main/texton.txt", matrix);
    writeStringsToBinaryFile("C:/Users/joaop/OneDrive/Ambiente de Trabalho/projetoAED1LP1-main/textob.txt", matrix);
    for (int i = 0; i < size; i++)
    {
        free(conjunto[i]);
    }
    free(conjunto);
    printf("Verifique o ficheiro!\n");
}

void testReadFromFile()
{
    //escrever strings no ficheiro para ler
    testWriteToFile();

    MATRIX_STRINGS matrix;
    matrix.size = 0;
    matrix.strings = NULL;

    readStringsFromFile("C:/Users/joaop/OneDrive/Ambiente de Trabalho/projetoAED1LP1-main/texton.txt", &matrix);

    if (matrix.strings == NULL)
    {
        printf("Erro na leitura\n");
    }
    else
    {
        printStrings(matrix);
    }

    for (int i = 0; i < matrix.size; i++)
    {
        free(matrix.strings[i]);
    }
    free(matrix.strings);
}

void testReadFromBinaryFile()
{
    // Escrever strings no ficheiro binário para ler
    testWriteToFile();

    MATRIX_STRINGS matrix;
    matrix.size = 0;
    matrix.strings = NULL;

    readStringsFromBinaryFile("C:/Users/joaop/OneDrive/Ambiente de Trabalho/projetoAED1LP1-main/textob.txt", &matrix);

    if (matrix.strings == NULL)
    {
        printf("Erro na leitura\n");
    }
    else
    {
        printStrings(matrix);
    }

    for (int i = 0; i < matrix.size; i++)
    {
        free(matrix.strings[i]);
    }
    free(matrix.strings);
}
//ordenação por tamanhos mais pequeno para o maior
void ordemt() {/*
    MATRIX_STRINGS matrix;
    int size = 6;
    char **conjunto = malloc(sizeof(char *) * size);

    conjunto[0] = strdup("claro");
    conjunto[1] = strdup("aro");
    conjunto[2] = strdup("faro");
    conjunto[3] = strdup("pifaro");
    conjunto[4] = strdup("pifa");
    conjunto[5] = strdup("ar");

    matrix.strings = conjunto;
    matrix.size = size;

    // Ordenar as strings usando qsort
    qsort(matrix.strings, matrix.size, sizeof(char *), compare_string_length);

    // Imprimir as strings ordenadas
    printf("Strings ordenadas por tamanho:\n");
    for (int i = 0; i < matrix.size; i++) {
        printf("%s\n", matrix.strings[i]);
    }

    // Libertar a memória alocada
    for (int i = 0; i < matrix.size; i++) {
        free(matrix.strings[i]);
    }
    free(matrix.strings);*/


        MATRIX_STRINGS matrix;
        int size = 6;
        char **conjunto = malloc(sizeof(char *) * size);

        // Preencher as strings
        conjunto[0] = strdup("claro");
        conjunto[1] = strdup("aro");
        conjunto[2] = strdup("faro");
        conjunto[3] = strdup("pifaro");
        conjunto[4] = strdup("pifa");
        conjunto[5] = strdup("ar");

        matrix.strings = conjunto;
        matrix.size = size;

        // Ordenar as strings manualmente
        ordenar_strings(&matrix);

        // Imprimir as strings ordenadas
        printf("Strings ordenadas por tamanho:\n");
        for (int i = 0; i < matrix.size; i++) {
            printf("%s\n", matrix.strings[i]);
        }

        // Liberar a memória alocada
        for (int i = 0; i < matrix.size; i++) {
            free(matrix.strings[i]);
        }
        free(matrix.strings);
    }

