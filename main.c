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
        printf("%s\n", matrix.strings[i]);
    }
}

void insertStrings(MATRIX_STRINGS *matrix)
{
    char buffer[200];
    int index = 0;
    char ch;
    int stringCount = 0;

    matrix->strings = NULL;
    matrix-> size = 0;

    while (1)
    {
        ch = getchar();
        if (ch == '.' || ch == '\n')
        {
            if (index > 0)
            {
                buffer[index] = '\0';
                matrix->strings = realloc(matrix->strings, sizeof(char *) * (stringCount + 1));
                matrix->strings[stringCount] = strdup(buffer);
                stringCount++;
                index = 0;
            }
            if (ch == '.')
            {
                break;
            }
        }
        else
        {
            if (index < 199)
            {
                buffer[index++] = ch;
            }
        }
    }

    matrix->size = stringCount;
}

int main()
{
    //printf("Hello, World!\n");
    MATRIX_STRINGS matrix;

    insertStrings(&matrix);
    printStrings(matrix);

    free(matrix.strings);

    return 0;
}