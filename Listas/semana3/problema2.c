#include <stdio.h>

/**
 * @brief Calcula o valor da conta de energia elétrica.
 * O programa lê o consumo em kWh e o tipo de consumidor (R, C ou I).
 * Calcula o valor final da conta com base em tarifas específicas por tipo
 * e uma taxa fixa.
 */
int main() {
    float consumo, valor_total;
    char tipo_consumidor;

    printf("Digite o consumo em kWh: ");
    scanf("%f", &consumo);

    // Limpa o buffer de entrada para ler o caractere corretamente
    while (getchar() != '\n');

    printf("Digite o tipo de consumidor (R-Residencial, C-Comercial, I-Industrial): ");
    scanf("%c", &tipo_consumidor);

    valor_total = 15.00; // Taxa fixa

    // Estrutura switch para lidar com os diferentes tipos de consumidor
    switch (tipo_consumidor) {
        case 'R':
        case 'r':
            valor_total += consumo * 0.60;
            break;
        case 'C':
        case 'c':
            valor_total += consumo * 0.48;
            break;
        case 'I':
        case 'i':
            valor_total += consumo * 1.29;
            break;
        default:
            printf("Tipo de consumidor invalido!\n");
            return 1; // Encerra o programa com código de erro
    }

    printf("O valor total da conta de energia e: R$ %.2f\n", valor_total);

    return 0;
}