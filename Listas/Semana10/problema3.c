#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Mistura duas strings alternando seus caracteres.
 * Cria uma nova string alocada dinamicamente contendo os caracteres
 * das duas strings de entrada intercalados. Se uma string for maior,
 * seus caracteres restantes são anexados ao final.
 * @param str1 Primeira string de entrada.
 * @param str2 Segunda string de entrada.
 * @return char* Ponteiro para a nova string misturada (alocada dinamicamente),
 * ou NULL se a alocação falhar. O chamador é responsável por liberar
 * a memória com free().
 */
char* misturar(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len_total = len1 + len2;

    // Aloca memória para a nova string (+1 para o terminador nulo '\0')
    char* resultado = (char*)malloc((len_total + 1) * sizeof(char));
    if (resultado == NULL) {
        printf("Erro: Falha na alocacao de memoria para a string resultado.\n");
        return NULL;
    }

    int i = 0, j = 0, k = 0;
    // Intercala os caracteres enquanto ambas as strings têm caracteres
    while (i < len1 && j < len2) {
        resultado[k++] = str1[i++];
        resultado[k++] = str2[j++];
    }

    // Adiciona os caracteres restantes da string mais longa (se houver)
    while (i < len1) {
        resultado[k++] = str1[i++];
    }
    while (j < len2) {
        resultado[k++] = str2[j++];
    }

    // Adiciona o terminador nulo ao final da string resultado
    resultado[k] = '\0';

    return resultado;
}

/**
 * @brief Lê duas strings (podem conter espaços) e imprime a mistura delas.
 * Utiliza fgets para ler as linhas completas e uma função auxiliar
 * para realizar a mistura com alocação dinâmica.
 */
int main() {
    char str1[102]; // 100 caracteres + 1 para '\n' + 1 para '\0'
    char str2[102];

    printf("Digite a primeira string (ate 100 caracteres):\n");
    fflush(stdout);
    fgets(str1, sizeof(str1), stdin);
    // Remove o '\n' que fgets pode deixar no final
    str1[strcspn(str1, "\n")] = 0;


    printf("Digite a segunda string (ate 100 caracteres):\n");
    fflush(stdout);
    fgets(str2, sizeof(str2), stdin);
    // Remove o '\n'
    str2[strcspn(str2, "\n")] = 0;


    // Chama a função para misturar as strings
    char* string_misturada = misturar(str1, str2);

    // Imprime o resultado se a mistura foi bem-sucedida
    if (string_misturada != NULL) {
        printf("String misturada: %s\n", string_misturada);
        // Libera a memória alocada pela função misturar
        free(string_misturada);
    }

    return 0;
}