#include "ordem.h"


/*int compare_string_length(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strlen(str1) - strlen(str2);
}*/
//bubble sort
void ordenar_strings(MATRIX_STRINGS *matrix) {
    for (int i = 0; i < matrix->size - 1; i++) {
        for (int j = 0; j < matrix->size - i - 1; j++) {
            if (strlen(matrix->strings[j]) > strlen(matrix->strings[j + 1])) {
                // Troca as strings
                char *temp = matrix->strings[j];
                matrix->strings[j] = matrix->strings[j + 1];
                matrix->strings[j + 1] = temp;
            }
        }
    }
}