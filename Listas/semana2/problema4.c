#include <stdio.h>

/**
 * @brief Realiza um conjunto de operações aritméticas com dois inteiros.
 * * Lê dois números inteiros e calcula e exibe a soma, diferença, produto,
 * divisão real, resto da divisão inteira e a média aritmética entre eles.
 */
int main() {
    // Variáveis para os dois números de entrada
    int num1, num2;

    // Solicita e lê os dois números inteiros
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &num2);

    // Realiza e exibe as operações
    printf("\n--- Resultados ---\n");
    printf("Soma: %d\n", num1 + num2); // [cite: 23]
    printf("Diferenca (primeiro - segundo): %d\n", num1 - num2); //
    printf("Produto: %d\n", num1 * num2); // [cite: 25]
    
    // Para a divisão real, é necessário converter um dos operandos para float
    printf("Divisao Real: %.2f\n", (float)num1 / num2);
    
    printf("Resto da Divisao Inteira: %d\n", num1 % num2); //
    printf("Media Aritmetica: %.2f\n", (float)(num1 + num2) / 2); //

    return 0;
}