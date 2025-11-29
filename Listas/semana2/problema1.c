#include <stdio.h>

/**
 * @brief Calcula o Índice de Massa Corporal (IMC).
 * * O programa solicita ao usuário o peso em kg e a altura em metros,
 * calcula o IMC usando a fórmula peso / (altura * altura) e exibe
 * o resultado formatado com duas casas decimais.
 */
int main() {
    // Declaração das variáveis para peso, altura e IMC.
    // O tipo float é usado para acomodar valores decimais.
    float peso, altura, imc;

    // Solicita e lê o peso do usuário
    printf("Digite o seu peso em kg: ");
    scanf("%f", &peso);

    // Solicita e lê a altura do usuário
    printf("Digite a sua altura em metros: ");
    scanf("%f", &altura);

    // Calcula o IMC conforme a fórmula fornecida
    imc = peso / (altura * altura);

    // Exibe o resultado formatado com 2 casas decimais
    printf("O seu Indice de Massa Corporal (IMC) e: %.2f\n", imc);

    return 0;
}