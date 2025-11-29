#include <stdio.h>

/**
 * @brief Calcula o desconto progressivo em uma compra.
 * Com base no valor da compra, o programa aplica diferentes
 * percentuais de desconto e exibe o valor do desconto,
 * o valor final e o percentual aplicado.
 */
int main() {
    float valor_compra, valor_desconto, valor_final;
    int perc_desconto = 0;

    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valor_compra);

    if (valor_compra > 1000.00) {
        perc_desconto = 20;
    } else if (valor_compra > 500.00) {
        perc_desconto = 15;
    } else if (valor_compra > 100.00) {
        perc_desconto = 10;
    } else {
        perc_desconto = 0;
    }

    valor_desconto = valor_compra * (perc_desconto / 100.0);
    valor_final = valor_compra - valor_desconto;

    printf("\n--- Resumo da Compra ---\n");
    printf("Percentual de desconto aplicado: %d%%\n", perc_desconto);
    printf("Valor do desconto: R$ %.2f\n", valor_desconto);
    printf("Valor final a ser pago: R$ %.2f\n", valor_final);

    return 0;
}