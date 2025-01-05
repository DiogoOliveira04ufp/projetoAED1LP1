#include "functions.h"
#include <string.h>

char resizeStringArray(char *string, int resize)
{
    char *newString = realloc(string, resize);

    newString = string;

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
void readStringsFromFile(const char *filename, MATRIX_STRINGS *matrix) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        insertStringIntoMatrix(matrix, buffer);
    }

    fclose(file);
}

void writeStringsToFile(const char *filename, MATRIX_STRINGS matrix) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    for (int i = 0; i < matrix.size; i++) {
        fprintf(file, "%s\n", matrix.strings[i]);
    }
    fflush(file);
    fclose(file);
    printf("Dados escritos no ficheiro: %s\n", filename);
}
