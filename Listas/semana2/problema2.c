#include <stdio.h>

/**
 * @brief Converte uma temperatura de Celsius para Fahrenheit e Kelvin.
 * * O programa lê um valor de temperatura em graus Celsius e utiliza as
 * fórmulas de conversão para calcular os valores equivalentes em Fahrenheit
 * e Kelvin, exibindo ambos com uma casa decimal.
 */
int main() {
    // Variáveis para as três escalas de temperatura
    float celsius, fahrenheit, kelvin;

    // Solicita e lê a temperatura em Celsius
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    // Converte para Fahrenheit [cite: 14]
    fahrenheit = (celsius * 9.0 / 5.0) + 32;

    // Converte para Kelvin [cite: 15]
    kelvin = celsius + 273.15;

    // Exibe os resultados formatados com 1 casa decimal
    printf("Temperatura em Fahrenheit: %.1f F\n", fahrenheit);
    printf("Temperatura em Kelvin: %.1f K\n", kelvin);

    return 0;
}