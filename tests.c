#include "tests.h"

//Teste para as funções inserir e imprimir, utiliza o exemplo no protocolo tal como maior parte destes testes
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

//Teste para a função remover
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

//Teste para a ordenação por ordem alfabética
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

//Teste para a pesquisa de strings, importante para a funcionalidade principal
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

//Teste da funcionalidade principal, a germinação de strings
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

    writeStringsToFile("C:/Users/Utilizador/CLionProjects/projetoAED1LP1/texton.txt", matrix);

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

    readStringsFromFile("C:/Users/Utilizador/CLionProjects/projetoAED1LP1/texton.txt", &matrix);

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

//Teste da inserção das listas ligadas
void testInsertNodeIntoList()
{
    LL_MATRICES list;
    list.size = 0;
    list.firstMatrix = NULL;
    list.lastMatrix = NULL;

    MATRIX_STRINGS matrix1;
    matrix1.size = 1;
    matrix1.strings = malloc(sizeof(char *));
    matrix1.strings[0] = strdup("string1");

    MATRIX_STRINGS matrix2;
    matrix2.size = 1;
    matrix2.strings = malloc(sizeof(char *));
    matrix2.strings[0] = strdup("string2");

    MATRIX_STRINGS matrix3;
    matrix3.size = 1;
    matrix3.strings = malloc(sizeof(char *));
    matrix3.strings[0] = strdup("string3");

    NODE_MATRIX node1;
    node1.year = 2025;
    node1.month = 1;
    node1.day = 8;

    NODE_MATRIX node2;
    node2.year = 2024;
    node2.month = 12;
    node2.day = 25;

    NODE_MATRIX node3;
    node3.year = 2025;
    node3.month = 1;
    node3.day = 1;

    insertNodeIntoList(matrix1, &node1, &list);
    insertNodeIntoList(matrix2, &node2, &list);
    insertNodeIntoList(matrix3, &node3, &list);

    printNodeList(&list);

    free(matrix1.strings[0]);
    free(matrix1.strings);
    free(matrix2.strings[0]);
    free(matrix2.strings);
    free(matrix3.strings[0]);
    free(matrix3.strings);
}

void testInsertNodeIntoPosition()
{
    LL_MATRICES list;
    list.size = 0;
    list.firstMatrix = NULL;
    list.lastMatrix = NULL;

    // Criar e inserir o primeiro nó na posição 0
    NODE_MATRIX *node1 = malloc(sizeof(NODE_MATRIX));
    node1->year = 2023;
    node1->month = 10;
    node1->day = 1;
    insertNodeIntoPosition(node1, &list, 0);

    // Criar e inserir o segundo nó na posição 1
    NODE_MATRIX *node2 = malloc(sizeof(NODE_MATRIX));
    node2->year = 2023;
    node2->month = 10;
    node2->day = 2;
    insertNodeIntoPosition(node2, &list, 1);

    // Criar e inserir o terceiro nó na posição 1 (entre node1 e node2)
    NODE_MATRIX *node3 = malloc(sizeof(NODE_MATRIX));
    node3->year = 2023;
    node3->month = 10;
    node3->day = 3;
    insertNodeIntoPosition(node3, &list, 1);

    // Imprimir a lista para verificar a ordem dos nós
    printNodeList(&list);

    // Libertar memória
    free(node1);
    free(node2);
    free(node3);
}