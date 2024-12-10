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
                matrix->strings = realloc(matrix->strings, sizeof(char *) * (stringCount + 1));         //abre espaco para as strings
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

int main()
{
    //printf("Hello, World!\n");
    MATRIX_STRINGS matrix;

    insertStrings(&matrix);
    printStrings(matrix);

    free(matrix.strings);

    return 0;
}