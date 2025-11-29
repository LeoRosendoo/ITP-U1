#include <stdio.h>
#include <stdlib.h> // Para a função abs()

/**
 * @brief Calcula a soma dos divisores próprios de um número.
 * @param n O número para o qual a soma dos divisores será calculada.
 * @return A soma de todos os divisores de n, exceto n.
 */
int soma_divisores_proprios(int n) {
    int soma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

/**
 * @brief Verifica se dois números são "colegas".
 * Dois números A e B são colegas se |D(A) - B| <= 2 e |D(B) - A| <= 2,
 * onde D(x) é a soma dos divisores próprios de x.
 */
int main() {
    int a, b;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    int soma_div_a = soma_divisores_proprios(a);
    int soma_div_b = soma_divisores_proprios(b);

    if (abs(soma_div_a - b) <= 2 && abs(soma_div_b - a) <= 2) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}