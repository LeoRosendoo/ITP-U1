#include <stdio.h>

int main() {
    int M;
    printf("Digite o numero de times M (max 20):\n");
    fflush(stdout);
    scanf("%d", &M);

    if (M < 2 || M > 20) { 
        printf("Numero de times invalido.\n");
        return 1;
    }

    int resultados[M][M];

    printf("Digite a matriz de resultados %d x %d:\n", M, M);
    fflush(stdout);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &resultados[i][j]);
        }
    }

    int empates = 0;

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) { 
            if (resultados[i][j] == resultados[j][i]) {
                empates++;
            }
        }
    }

    // Saída Descritiva Modificada
    printf("Numero total de empates: %d\n", empates);

    return 0;
}