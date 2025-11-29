#include <stdio.h>

/**
 * @brief Realiza um diagnóstico médico simples baseado em sintomas.
 * O programa faz quatro perguntas de sim/não (S/N) ao usuário e,
 * com base nas combinações de respostas, sugere um possível
 * diagnóstico.
 */
int main() {
    char febre, dor_cabeca, dor_corpo, tosse;

    printf("Responda com S (sim) ou N (nao):\n");

    printf("Tem febre? ");
    scanf(" %c", &febre);
    printf("Tem dor de cabeca? ");
    scanf(" %c", &dor_cabeca);
    printf("Tem dor no corpo? ");
    scanf(" %c", &dor_corpo);
    printf("Tem tosse? ");
    scanf(" %c", &tosse);

    printf("\nSugestao de diagnostico: ");

    if (febre == 'S' && dor_cabeca == 'S' && dor_corpo == 'S') {
        printf("Possivel gripe\n");
    } else if (tosse == 'S' && febre == 'S') {
        printf("Possivel resfriado\n");
    } else if (dor_cabeca == 'S' && febre == 'N' && dor_corpo == 'N' && tosse == 'N') {
        printf("Possivel enxaqueca\n");
    } else if (febre == 'S' && dor_cabeca == 'N' && dor_corpo == 'N' && tosse == 'N') {
        printf("Consulte um medico\n");
    } else if (febre == 'N' && dor_cabeca == 'N' && dor_corpo == 'N' && tosse == 'N') {
        printf("Voce parece estar bem\n");
    } else {
        printf("Consulte um medico para avaliacao\n");
    }

    return 0;
}