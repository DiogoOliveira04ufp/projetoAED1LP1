#include "functions.h"
#include <string.h>

char resizeStringArray(char *string, int resize)
{
    char *newString = realloc(string, resize);
    return newString;
}

void printStrings(MATRIX_STRINGS matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        printf("%s\n", matrix.strings[i]);
    }
}

void insertStringIntoMatrix(MATRIX_STRINGS *matrix, char str[])
{
    char **strings_copy = realloc(matrix->strings, (matrix->size + 1) * sizeof(char *));

    if (strings_copy != NULL)
    {
        matrix->strings = strings_copy;
        matrix->strings[matrix->size] = malloc((strlen(str) + 1) * sizeof(char));
        strcpy(matrix->strings[matrix->size], str);
        matrix->size++;
    }
}

void removeStrings(MATRIX_STRINGS matrix, int index)
{
    if (index > matrix.size)
    {
        printf("string nao existe");
        return;
    }
    for (int i = index; i < matrix.size; i++)
    {
        if (matrix.strings[i + 1] != '\0')
        {
            matrix.strings[i] = matrix.strings[i + 1];
        }
        else
        {
            matrix.strings[i] = '\0';
            break;
        }
    }
}

void insertMatrixIntoNode(MATRIX_STRINGS matrix, NODE_MATRIX *node, LL_MATRICES *list)
{
    node->lista_strings = matrix;
    node->year = 2025;              // Defina o ano conforme necessário
    node->month = 1;                // Defina o mês conforme necessário
    node->day = 8;                  // Defina o dia conforme necessário
    node->nextNode = NULL;
    node->prevNode = NULL;

    if (list->size == 0)
    {
        list->firstMatrix = node;
        list->lastMatrix = node;
    }
    else
    {
        NODE_MATRIX *current = list->firstMatrix;
        while (current != NULL && (current->year < node->year || (current->year == node->year && current->month < node->month) || (current->year == node->year && current->month == node->month && current->day < node->day)))
        {
            current = current->nextNode;
        }

        if (current == NULL)
        {
            node->prevNode = list->lastMatrix;
            list->lastMatrix->nextNode = node;
            list->lastMatrix = node;
        }
        else if (current == list->firstMatrix)
        {
            node->nextNode = list->firstMatrix;
            list->firstMatrix->prevNode = node;
            list->firstMatrix = node;
        }
        else
        {
            node->nextNode = current;
            node->prevNode = current->prevNode;
            current->prevNode->nextNode = node;
            current->prevNode = node;
        }
    }

    list->size++;
}

/*
typedef struct nodeMatrix {
    MATRIX_STRINGS lista_strings;
    int year, month, day;
    struct nodeMatrix * nextNode, * prevNode;
} NODE_MATRIX;

typedef struct llMatrices {
    int size;
    NODE_MATRIX *firstMatrix;
    NODE_MATRIX *lastMatrix;
} LL_MATRICES;
 */