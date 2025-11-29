#include <stdio.h>
#include <math.h> // Necessário para a função pow()

/**
 * @brief Calcula o montante final a partir de juros compostos.
 * * Lê o capital inicial, a taxa de juros anual (em %) e o tempo (em anos).
 * Utiliza a função pow() da biblioteca math.h para calcular o montante
 * final e o exibe na tela.
 */
int main() {
    // Variáveis para os componentes do cálculo
    float capital, taxa, montante;
    int tempo;

    // Leitura dos dados de entrada
    printf("Digite o capital inicial: ");
    scanf("%f", &capital);

    printf("Digite a taxa de juros anual (em %%): ");
    scanf("%f", &taxa);

    printf("Digite o tempo do investimento (em anos): ");
    scanf("%d", &tempo);

    // Calcula o montante usando a fórmula de juros compostos
    // A taxa é dividida por 100 para o cálculo
    montante = capital * pow((1 + taxa / 100), tempo);

    // Exibe o resultado
    printf("O montante final apos %d anos sera de: R$ %.2f\n", tempo, montante);

    return 0;
}