#include <stdio.h>

// Função para verificar se um número é primo
int eh_primo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int a, b;
    do {
        printf("Digite dois inteiros a e b (com a > b): ");
        scanf("%d %d", &a, &b);
    } while (a <= b);

    printf("Numeros primos entre %d e %d:\n", b, a);
    for (int i = b; i <= a; i++) {
        if (eh_primo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}