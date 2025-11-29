#include <stdio.h>

int main() {
    int m, n; 
    
    printf("Digite a quantidade de numeros sorteados e apostados (m n):\n");
    fflush(stdout);
    scanf("%d %d", &m, &n);

    // Validação básica das entradas m e n
    if (m <= 0 || n < m || m > 30 || n > 50) {
        printf("Valores de m ou n invalidos.\n");
        return 1;
    }

    int sorteados[m];
    int apostados[n];
    int acertos = 0;

    printf("Digite os %d numeros sorteados (separados por espaco):\n", m);
    fflush(stdout);
    for (int i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }

    printf("Digite os %d numeros apostados (separados por espaco):\n", n);
    fflush(stdout);
    for (int i = 0; i < n; i++) {
        scanf("%d", &apostados[i]);
    }

    // Compara os números usando laços aninhados
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) { 
            if (sorteados[i] == apostados[j]) {
                acertos++;
                break; 
            }
        }
    }

    printf("%d\n", acertos);

    return 0;
}