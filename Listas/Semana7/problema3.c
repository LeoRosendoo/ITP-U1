#include <stdio.h>
#include <string.h>
#include <ctype.h> // LICENÇA INCLUÍDA para usar isdigit()

/**
 * @brief Processa um relatório de presença do OpenMeet para contar ausências.
 * O programa solicita e lê o nome de um aluno e a string de frequências. 
 * Ele então conta o número total de aulas (buscando por datas no formato DD/MM) 
 * e o número de vezes que o nome do aluno aparece, calculando a diferença
 * para encontrar o número de ausências.
 */
int main() {
    char nome_aluno[11];
    char frequencias[1001];
    
    // Arauto para o nome do aluno
    printf("Digite o nome do aluno a ser verificado:\n");
    fflush(stdout);
    scanf("%s", nome_aluno);
    
    // Arauto para a string de frequências
    printf("Cole a string de frequencias completa:\n");
    fflush(stdout);
    scanf(" %[^\n]", frequencias);

    int total_aulas = 0;
    int presencas = 0;
    
    char *ptr = frequencias;
    char *data_ptr;
    char *nome_ptr;

    // Conta o número total de aulas procurando por datas (DD/MM)
    while ((data_ptr = strstr(ptr, "/")) != NULL) {
        // Assegura que estamos olhando para posições válidas na string
        if (data_ptr > frequencias + 1 && data_ptr < frequencias + strlen(frequencias) - 2) {
            // Verifica se os caracteres ao redor da '/' são dígitos
            if (isdigit(*(data_ptr - 2)) && isdigit(*(data_ptr - 1)) &&
                isdigit(*(data_ptr + 1)) && isdigit(*(data_ptr + 2))) {
                total_aulas++;
            }
        }
        ptr = data_ptr + 1; // Avança o ponteiro para evitar recontagem da mesma data
    }

    // Reseta o ponteiro para o início da string para contar as presenças
    ptr = frequencias;
    
    // Conta o número de presenças do aluno
    while ((nome_ptr = strstr(ptr, nome_aluno)) != NULL) {
        presencas++;
        // Avança o ponteiro para depois do nome encontrado para evitar loops infinitos
        ptr = nome_ptr + strlen(nome_aluno);
    }

    printf("Numero de ausencias de %s: %d\n", nome_aluno, total_aulas - presencas);

    return 0;
}