#include "germin.h"

void germin(MATRIX_STRINGS *matrix)
{
    KMP *pattern;
    char *word;
    char **sequence = malloc(sizeof(char *) * matrix->size);
    int k = 0;

    for (int i = 0; i < matrix->size; i++)
    {
        word = matrix->strings[i];
        k = 0;
        for (int j = 0; j < matrix->size; j++)
        {
            if (matrix->strings[j] != word)
            {
                pattern = KMP_init(word);
                int pos = KMP_search(pattern, matrix->strings[j]);
                if (pos < strlen(matrix->strings[j]))
                {
                    sequence[k] = matrix->strings[j];
                    k++;
                    word = matrix->strings[j];
                }
                KMP_free(pattern);
            }
        }
        //if (k > 0)
        //<<{
            printf("%s-->", matrix->strings[i]);
            for (int j = 0; j < k; j++)
            {
                if (j == k - 1)
                {
                    printf("%s", sequence[j]);
                }
                else
                {
                    printf("%s-->", sequence[j]);
                }
            }
            printf("\n"); // End of sequence
        //}
    }

    free(sequence);
}

/*
// Função para verificar se uma palavra está contida em outra
int contemPalavra(const char principal, const char *outra)
{
    return strstr(principal, outra) != NULL;
}

// Função para encontrar combinações máximas dentro da palavra principal
void verificarMaximoCombinacoes(Palavra *palavras, int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        char palavraPrincipal[100];
        strcpy(palavraPrincipal, palavras[i].palavra);

        printf("\nVerificando combinações para a palavra principal: %s\n", palavraPrincipal);

        int encontrou = 0;

        for (int j = 0; j < tamanho; j++)
        {
            if (i != j && contemPalavra(palavraPrincipal, palavras[j].palavra)) {
                encontrou = 1;
                printf("A palavra '%s' pode ser usada dentro de '%s'\n", palavras[j].palavra, palavraPrincipal);

                // Remover a ocorrência da palavra encontrada
                char pos = strstr(palavraPrincipal, palavras[j].palavra);
                if (pos) {
                    int len = strlen(palavras[j].palavra);
                    memmove(pos, pos + len, strlen(pos + len) + 1);
                }
            }
        }

        if (!encontrou)
        {
            printf("Nenhuma combinação encontrada para '%s'.\n", palavras[i].palavra);
        }
        else
        {
            printf("Restante da palavra principal após combinações: '%s'\n", palavraPrincipal);
        }
    }
}*/

/*

*/