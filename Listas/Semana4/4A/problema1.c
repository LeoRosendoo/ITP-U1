#include <stdio.h>

/**
 * @brief Calcula o número de dobras necessárias para uma folha caber em um bolso.
 * Lê as dimensões de uma folha e o comprimento de um bolso. A cada iteração,
 * o maior lado da folha é dividido por 2, simulando uma dobra. O processo
 * se repete até que uma das dimensões da folha seja menor que o bolso.
 */
int main() {
    float comprimento_folha, largura_folha, comprimento_bolso;
    int dobras = 0;

    printf("Digite o comprimento e a largura da folha: ");
    scanf("%f %f", &comprimento_folha, &largura_folha);
    printf("Digite o comprimento do bolso: ");
    scanf("%f", &comprimento_bolso);

    while (comprimento_folha >= comprimento_bolso && largura_folha >= comprimento_bolso) {
        if (comprimento_folha > largura_folha) {
            comprimento_folha /= 2;
        } else {
            largura_folha /= 2;
        }
        dobras++;
    }

    printf("Numero de dobras necessarias: %d\n", dobras);

    return 0;
}