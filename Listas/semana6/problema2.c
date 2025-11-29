#include <stdio.h>

/**
 * @brief Identifica as figurinhas faltantes em uma coleção.
 * O programa lê o total de figurinhas do álbum (m) e a quantidade
 * de figurinhas que o usuário possui (n). Um vetor é usado como um
 * mapa para marcar as figurinhas possuídas. Ao final, o programa
 * itera pelo mapa e imprime as figurinhas não marcadas (faltantes).
 */
int main() {
    int m, n; // m = total de figurinhas, n = figurinhas possuídas

    
    printf("Digite o total de figurinhas do album e quantas voce possui:\n");
    scanf("%d %d", &m, &n);

    // Cria um vetor para marcar as figurinhas. Inicializa com 0 (faltante).
    int colecao[m + 1];
    for (int i = 0; i <= m; i++) {
        colecao[i] = 0; // 0 = faltante, 1 = possuída
    }

    
    printf("Digite os numeros das %d figurinhas que voce possui:\n", n);
    for (int i = 0; i < n; i++) {
        int figurinha_atual;
        scanf("%d", &figurinha_atual);
        if (figurinha_atual >= 1 && figurinha_atual <= m) {
            colecao[figurinha_atual] = 1;
        }
    }

    printf("Figurinhas faltantes: \n");
    for (int i = 1; i <= m; i++) {
        if (colecao[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}