#include "main.h"

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
        printf("%s", matrix.strings[1]);
    }
}

void insertStrings(MATRIX_STRINGS matrix)
{
    char buffer[200];
    int index = 0;
    char ch;

    while ((ch = getchar()) != '.')
    {
        if (index < 199)
        {
            buffer[index++] = ch;
        }
    }
    buffer[index] = '\0';

    matrix->strings = malloc(sizeof(char *));
    matrix->strings[0] = strdup(buffer);
    matrix->size = 1;
}

int main()
{
    printf("Hello, World!\n");
    return 0;
}