#include "functions.h"
#include <string.h>

/**
 * 
 * @param string string a redimensionar
 * @param resize novo tamanho
 * @return string redimensionada
 */
char *resizeStringArray(char *string, int resize)
{
    char *newString = realloc(string, resize);
    return newString;
}

/**
 * imrpimir strings
 * ciclo for para percorrer o array tod0 e imprimir cada elemento
 * @param matrix  array de strings a imprimir
 */
void printStrings(MATRIX_STRINGS matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        printf("%s\n", matrix.strings[i]);
    }
}

/**
 * inserir strings na estrutura MATRIX_STRINGS
 * insere uma string no último elemento do array e incrementa a variável size
 * @param matrix array de strings original
 * @param str string a inserir no array
 */
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

/**
 * remover strings de uma MATRIX_STRINGS
 * recebe um índice, remove a string corresondente e passa os elementos a seguir para os seus lugares
 * @param matrix array de strings original
 * @param index índice da string a remover
 */
void removeStrings(MATRIX_STRINGS *matrix, int index)
{
    if (index >= matrix->size)
    {
        printf("string nao existe\n");
        return;
    }
    free(matrix->strings[index]);
    for (int i = index; i < matrix->size - 1; i++)
    {
        matrix->strings[i] = matrix->strings[i + 1];
    }
    matrix->size--;
    matrix->strings = realloc(matrix->strings, matrix->size * sizeof(char *));
}

/**
 * ler strings escritas no ficheiro
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever as strings escritas no ficheiro
 */
void readStringsFromFile(const char *filename, MATRIX_STRINGS *matrix)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    char buffer[1024];                                      // Assumindo que a linha não excede 1024 caracteres
    if (fgets(buffer, sizeof(buffer), file))
    {
        char *token = strtok(buffer, " ");
        while (token != NULL)
        {
            insertStringIntoMatrix(matrix, token);
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

/**
 * escrever strings no ficheiro
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever no ficheiro
 */
void writeStringsToFile(const char *filename, MATRIX_STRINGS matrix)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    for (int i = 0; i < matrix.size; i++)
    {
        fprintf(file, "%s ", matrix.strings[i]);
    }
    fclose(file);
    printf("Dados escritos no ficheiro: %s\n", filename);
}

/**
 * escrever strings no ficheiro em binário
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever no ficheiro
 */
void writeStringsToBinaryFile(const char *filename, MATRIX_STRINGS matrix)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    for (int i = 0; i < matrix.size; i++) {
        size_t length = strlen(matrix.strings[i]) + 1;                              // +1 para incluir o caracter nulo
        if (fwrite(&length, sizeof(size_t), 1, file) != 1) {
            perror("Erro ao escrever o tamanho da string no ficheiro");
            fclose(file);
            return;
        }
        if (fwrite(matrix.strings[i], sizeof(char), length, file) != length) {
            perror("Erro ao escrever a string no ficheiro");
            fclose(file);
            return;
        }

    }

    fclose(file);
    printf("Dados escritos no ficheiro binario: %s\n", filename);
}

/**
 * ler strings em formato binário
 * @param filename nome do ficheiro
 * @param matrix array de strings para escrever as strings lidas
 */
void readStringsFromBinaryFile(const char *filename, MATRIX_STRINGS *matrix)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    while (1) {
        size_t length;
        if (fread(&length, sizeof(size_t), 1, file) != 1) {
            if (feof(file)) break; // Fim do ficheiro
            perror("Erro ao ler o tamanho da string do ficheiro");
            fclose(file);
            return;
        }

        char *str = malloc(length);
        if (str == NULL) {
            perror("Erro ao alocar memória para a string");
            fclose(file);
            return;
        }

        if (fread(str, sizeof(char), length, file) != length) {
            perror("Erro ao ler a string do ficheiro");
            free(str);
            fclose(file);
            return;
        }

        insertStringIntoMatrix(matrix, str);
        free(str);
    }

    fclose(file);
    printf("Dados lidos do ficheiro binario: %s\n", filename);
}

/**
 * Inserir uma matriz num nó, e depois numa lista ligada de nós
 * @param matrix array de strings
 * @param node nó de estruturas MATRIX_STRINGS
 * @param list lista de nós
 */
void insertNodeIntoList(MATRIX_STRINGS matrix, NODE_MATRIX *node, LL_MATRICES *list)
{
    node->lista_strings = matrix;
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
        while (current != NULL &&
               (current->year < node->year ||
               (current->year == node->year && current->month < node->month) ||
               (current->year == node->year && current->month == node->month && current->day < node->day)))
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

/**
 * imprimir nós
 * acessória para os nós
 * @param list lista de nós a imprimir
 */
void printNodeList(LL_MATRICES *list)
{
    NODE_MATRIX *current = list->firstMatrix;
    while (current != NULL)
    {
        printf("Date: %d-%02d-%02d\n", current->year, current->month, current->day);
        printStrings(current->lista_strings);
        current = current->nextNode;
    }
}

/**
 * inserir um nó numa dada posição na lista ligada
 * @param node nó a inserir
 * @param list lista onde inserir
 * @param position posição da lista onde inserir
 */
void insertNodeIntoPosition(NODE_MATRIX *node, LL_MATRICES *list, int position)
{
    if (position < 0 || position > list->size)
    {
        printf("Posicao fora dos limites\n");
        return;
    }

    if (position == 0)
    {
        node->nextNode = list->firstMatrix;
        node->prevNode = NULL;
        if (list->firstMatrix != NULL)
        {
            list->firstMatrix->prevNode = node;
        }
        list->firstMatrix = node;
        if (list->size == 0)
        {
            list->lastMatrix = node;
        }
    }
    else if (position == list->size)
    {
        node->nextNode = NULL;
        node->prevNode = list->lastMatrix;
        if (list->lastMatrix != NULL)
        {
            list->lastMatrix->nextNode = node;
        }
        list->lastMatrix = node;
    }
    else
    {
        NODE_MATRIX *current = list->firstMatrix;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->nextNode;
        }
        node->nextNode = current->nextNode;
        node->prevNode = current;
        current->nextNode->prevNode = node;
        current->nextNode = node;
    }

    list->size++;
}