#include <stdio.h>

/**
 * @brief Determina o comprimento de uma ponte entre os dois pontos mais altos.
 * O programa lê uma série de alturas de um terreno. Primeiro, encontra
 * a altura máxima. Em seguida, encontra os índices da primeira e da segunda
 * ocorrência dessa altura máxima. O comprimento da ponte é o número de
 * segmentos de terreno entre esses dois pontos.
 */
int main() {
    int n; // Número de medições de altura
    
    printf("Digite o numero de medicoes do terreno: ");
    
    fflush(stdout);
    scanf("%d", &n);

    int terreno[n];
    int altura_maxima = 0;

    printf("Digite as %d medicoes de altura (separadas por espaco): ", n);
    
    fflush(stdout);
    for (int i = 0; i < n; i++) {
        scanf("%d", &terreno[i]);
        if (terreno[i] > altura_maxima) {
            altura_maxima = terreno[i];
        }
    }

    int p1 = -1, p2 = -1; // Índices dos dois pontos mais altos

    // Encontra os índices da primeira e segunda ocorrência da altura máxima
    for (int i = 0; i < n; i++) {
        if (terreno[i] == altura_maxima) {
            if (p1 == -1) {
                p1 = i;
            } else {
                p2 = i;
                break;
            }
        }
    }

    // CORREÇÃO DE LÓGICA: O comprimento é o número de vãos entre os pilares.
    int comprimento = p2 - p1 - 1;
    printf("%d\n", comprimento);

    return 0;
}