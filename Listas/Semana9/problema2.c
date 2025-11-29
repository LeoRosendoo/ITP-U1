#include <stdio.h>

int main() {
    int M;
    printf("Digite o numero de usuarios M (max 100):\n");
    fflush(stdout);
    scanf("%d", &M);

    if (M <= 0 || M > 100) {
        printf("Numero de usuarios invalido.\n");
        return 1;
    }

    int amizades[M][M];

    printf("Digite a matriz de amizades %d x %d (1=amigo, 0=nao amigo):\n", M, M);
    fflush(stdout);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &amizades[i][j]);
        }
    }

    int usuarioX;
    printf("Digite o ID do usuario para sugerir amigos (0 a %d):\n", M - 1);
    fflush(stdout);
    scanf("%d", &usuarioX);

     if (usuarioX < 0 || usuarioX >= M) {
        printf("Usuario X invalido.\n");
        return 1;
    }

    // Saída Descritiva Modificada
    printf("Sugestoes para o usuario %d: ", usuarioX);
    fflush(stdout); // Garante que o cabeçalho apareça antes das sugestões

    int encontrou_sugestao = 0;
    for (int usuarioY = 0; usuarioY < M; usuarioY++) {
        if (usuarioX == usuarioY || amizades[usuarioX][usuarioY] == 1) {
            continue;
        }

        int amigo_em_comum = 0;
        for (int usuarioZ = 0; usuarioZ < M; usuarioZ++) {
            if (amizades[usuarioX][usuarioZ] == 1 && amizades[usuarioY][usuarioZ] == 1) {
                amigo_em_comum = 1;
                break;
            }
        }

        if (amigo_em_comum) {
            printf("%d ", usuarioY);
            encontrou_sugestao = 1;
        }
    }
    
    // Finaliza a linha de saída
    printf("\n");


    return 0;
}