#include <stdio.h>

/**
 * @brief Calcula a média de um aluno e determina sua situação.
 * Lê três notas, calcula a média aritmética e determina se o aluno
 * foi aprovado, reprovado ou está em recuperação. Para o caso de
 * recuperação, calcula a nota necessária na prova final.
 */
int main() {
    float n1, n2, n3, media, nota_final_necessaria;

    printf("Digite as tres notas do aluno: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    media = (n1 + n2 + n3) / 3.0;

    printf("A media do aluno e: %.1f\n", media);

    if (media >= 7.0) {
        printf("Situacao: Aprovado\n");
    } else if (media < 4.0) {
        printf("Situacao: Reprovado\n");
    } else {
        printf("Situacao: Recuperacao\n");
        // Média final desejada é 5.0. (media + nota_final) / 2 = 5.0
        // nota_final = (5.0 * 2) - media
        nota_final_necessaria = 10.0 - media;
        printf("Nota necessaria na prova final: %.1f\n", nota_final_necessaria);
    }

    return 0;
}