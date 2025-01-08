#include "ordem.h"

/**
 * Ordena um array de strings utilizando bubble sort
 * @param matrix - array de strings a ordenar
 */
void ordenar_strings(MATRIX_STRINGS *matrix)
{
    for (int i = 0; i < matrix->size - 1; i++)
    {
        for (int j = 0; j < matrix->size - i - 1; j++)
        {
            if (strlen(matrix->strings[j]) > strlen(matrix->strings[j + 1]))
            {
                // Troca as strings
                char *temp = matrix->strings[j];
                matrix->strings[j] = matrix->strings[j + 1];
                matrix->strings[j + 1] = temp;
            }
        }
    }
}