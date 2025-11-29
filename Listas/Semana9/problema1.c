#include <stdio.h>

/**
 * @brief Conta setores férteis irrigados e não irrigados em um campo matricial.
 * Lê as dimensões M e N de um campo. Lê a matriz M x N representando o campo,
 * onde 0=infértil, 1=fértil, 2=irrigador. Irrigadores (nunca na borda)
 * irrigam os 4 vizinhos (N, S, L, O). O programa conta quantos setores
 * férteis (1) são irrigados por pelo menos um irrigador e quantos não são,
 * exibindo os resultados com descrições.
 */
int main() {
    int M, N;

    printf("Digite as dimensoes M e N do campo (ex: 4 6):\n");
    fflush(stdout);
    scanf("%d %d", &M, &N);

    if (M <= 0 || N <= 0 || M > 10 || N > 10) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }

    int campo[M][N];
    int irrigado[M][N]; 

    printf("Digite a matriz %d x %d do campo (0=infertil, 1=fertil, 2=irrigador):\n", M, N);
    fflush(stdout);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
            irrigado[i][j] = 0; 
        }
    }

    // Identifica os setores irrigados
    for (int i = 1; i < M - 1; i++) { 
        for (int j = 1; j < N - 1; j++) {
            if (campo[i][j] == 2) { 
                // Marca os 4 vizinhos como irrigados
                irrigado[i - 1][j] = 1; 
                irrigado[i + 1][j] = 1; 
                irrigado[i][j - 1] = 1; 
                irrigado[i][j + 1] = 1; 
            }
        }
    }

    int ferteis_irrigados = 0;
    int ferteis_nao_irrigados = 0;

    // Conta os setores férteis irrigados e não irrigados
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 1) { 
                if (irrigado[i][j] == 1) { 
                    ferteis_irrigados++;
                } else {
                    ferteis_nao_irrigados++;
                }
            }
        }
    }

    // Saída Descritiva Modificada
    printf("%d setores ferteis cobertos por pelo menos um irrigador\n", ferteis_irrigados);
    printf("%d setores ferteis nao coberto por nenhum irrigador\n", ferteis_nao_irrigados);

    return 0;
}