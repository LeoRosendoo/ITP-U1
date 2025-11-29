#include <stdio.h>

/**
 * @brief Verifica se um número é primo.
 * Um número é primo se for maior que 1 e não tiver divisores
 * além de 1 e ele mesmo.
 * @param n O número a ser verificado.
 * @return int 1 se o número for primo, 0 caso contrário.
 */
int ehPrimo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

/**
 * @brief Encontra e imprime todos os "primos triplos" até 50000.
 * Um primo triplo é um conjunto de três números primos na forma
 * (x, x + 2, x + 6). O programa utiliza uma função auxiliar
 * para verificar a primalidade de cada componente do trio.
 */
int main() {
    printf("Trios de primos na forma (x, x+2, x+6) ate 50000:\n");

    // Itera por todos os valores possíveis de x
    // O limite é 50000 - 6 para garantir que x+6 não ultrapasse o limite
    for (int x = 1; x <= 50000 - 6; x++) {
        // Verifica se todos os três números do trio são primos
        if (ehPrimo(x) && ehPrimo(x + 2) && ehPrimo(x + 6)) {
            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
        }
    }

    return 0;
}