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

/*
void insertStrings(MATRIX_STRINGS *matrix)
{
    char buffer[200];                   //lista de strings
    int index = 0;                      //index na lista
    char ch;                            //caratere na string
    int stringCount = 0;                //contagem de strings -- vai passar a ser o tamanho do array

    matrix->strings = NULL;
    matrix->size = 0;

    while (1)
    {
        ch = getchar();                          //inserir as strings
        if (ch == '.' || ch == '\n')             //enquanto nao for '.' (condicao final)
        {
            if (index > 0)
            {
                buffer[index] = '\0';                                                                           //finaliza o array
                matrix->strings = realloc(matrix->strings, sizeof(char *) * (stringCount + 1));                 //abre espaco para as strings
                matrix->strings[stringCount] = strdup(buffer);                                                  //insere as strings no array na matriz
                stringCount++;
                index = 0;
            }
            if (ch == '.')
            {
                break;
            }
        }
        else                                      //condicao para inserir as strings
        {
            if (index < 199)
            {
                buffer[index++] = ch;             //cada letra sera inserida na string buffer
            }
        }
    }

    matrix->size = stringCount;                   //tamanho do array inserido no parametro size
}
*/

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