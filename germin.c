#include "germin.h"

#include "germin.h"
#include <string.h>

// Variáveis globais para contagem de sequências e tamanho da maior sequência
int totalSequences = 0;
int maxSequenceLength = 0;

int canGerminate(const char *a, const char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);

    // Verificar se 'a' é prefixo ou sufixo de 'b'
    if (lenA > lenB) return 0;                                                 // `a` não pode ser maior que `b`
    return (strncmp(a, b, lenA) == 0 || strncmp(a, b + lenB - lenA, lenA) == 0);
}

void printPath(char **currentPath, int pathSize)
{
    printf("Sequencia: ");
    for (int i = 0; i < pathSize; i++)                                         // Imprimir na ordem natural
    {
        printf("%s%s", currentPath[i], (i == pathSize - 1) ? "\n" : " --> ");
    }

    // Atualizar contagem de sequências e tamanho da maior sequência
    totalSequences++;
    if (pathSize > maxSequenceLength)
    {
        maxSequenceLength = pathSize;
    }
}

void findGerminations(MATRIX_STRINGS *matrix, int index, char **currentPath, int pathSize, int *visited)
{
    currentPath[pathSize] = matrix->strings[index];
    pathSize++;
    visited[index] = 1;

    // Expandir para outras strings
    int found = 0;
    for (int i = 0; i < matrix->size; i++)
    {
        if (!visited[i] && canGerminate(matrix->strings[index], matrix->strings[i]))
        {
            findGerminations(matrix, i, currentPath, pathSize, visited);
            found = 1;
        }
    }

    // Se não houver mais strings para expandir, imprimir o caminho
    if (!found)
    {
        printPath(currentPath, pathSize);
    }

    // Backtrack
    visited[index] = 0;
}

void germin(MATRIX_STRINGS *matrix)
{
    char **currentPath = malloc(sizeof(char *) * matrix->size);
    int *visited = calloc(matrix->size, sizeof(int));

    totalSequences = 0;
    maxSequenceLength = 0;

    for (int i = 0; i < matrix->size; i++)
    {
        findGerminations(matrix, i, currentPath, 0, visited);
    }

    printf("\nC = %d\n", totalSequences);
    printf("L = %d\n", maxSequenceLength);

    free(currentPath);
    free(visited);
}