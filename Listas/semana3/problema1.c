#include <stdio.h>

/**
 * @brief Calcula e classifica o Índice de Massa Corporal (IMC).
 * Modifica o programa anterior para, além de calcular o IMC,
 * classificar o resultado de acordo com uma tabela de referência.
 */
int main() {
    float peso, altura, imc;

    printf("Digite o seu peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a sua altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Seu IMC e: %.2f\n", imc);
    printf("Classificacao: ");

    // Estrutura condicional para classificar o IMC
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Peso normal\n");
    } else if (imc >= 25.0 && imc <= 29.9) {
        printf("Sobrepeso\n");
    } else {
        printf("Obesidade\n");
    }

    return 0;
}