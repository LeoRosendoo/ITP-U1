#include <stdio.h>
#include <limits.h> // Para INT_MAX

/**
 * @brief Encontra a rota mais barata entre duas cidades X e Z, com no máximo uma escala Y.
 * Lê o número de cidades M e a matriz de custos M x M, onde a[i][j] é o preço
 * para ir da cidade i para a j. Lê as cidades de origem X e destino Z.
 * O programa calcula o custo direto X -> Z e todos os custos com uma escala
 * X -> Y -> Z. Encontra o menor custo total e imprime a rota e o custo.
 */
int main() {
    int M;
    printf("Digite o numero de cidades M (max 10):\n");
    fflush(stdout);
    scanf("%d", &M);

    if (M < 2 || M > 10) {
        printf("Numero de cidades invalido.\n");
        return 1;
    }

    int custos[M][M];

    printf("Digite a matriz de custos %d x %d:\n", M, M);
    fflush(stdout);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &custos[i][j]);
        }
    }

    int cidadeX, cidadeZ;
    printf("Digite a cidade de origem X e destino Z (0 a %d):\n", M - 1);
    fflush(stdout);
    scanf("%d %d", &cidadeX, &cidadeZ);

    if (cidadeX < 0 || cidadeX >= M || cidadeZ < 0 || cidadeZ >= M) {
        printf("Cidades invalidas.\n");
        return 1;
    }

    int menor_custo = INT_MAX;
    int cidadeY_intermediaria = -1;
    int rota_direta_custo = -1;

    // Verifica a rota direta
    if (custos[cidadeX][cidadeZ] > 0) {
        menor_custo = custos[cidadeX][cidadeZ];
        rota_direta_custo = menor_custo;
    }

    // Verifica rotas com uma escala
    // CORREÇÃO AQUI: city++ foi trocado por cidadeY++
    for (int cidadeY = 0; cidadeY < M; cidadeY++) {
        if (cidadeY == cidadeX || cidadeY == cidadeZ) continue;

        if (custos[cidadeX][cidadeY] > 0 && custos[cidadeY][cidadeZ] > 0) {
            int custo_escala = custos[cidadeX][cidadeY] + custos[cidadeY][cidadeZ];
            if (custo_escala < menor_custo) {
                menor_custo = custo_escala;
                cidadeY_intermediaria = cidadeY;
            }
        }
    }

    // Saída Descritiva
    printf("Rota mais barata encontrada: ");
    if (menor_custo == INT_MAX) {
        printf("Nenhuma rota viavel encontrada.\n");
    } else if (cidadeY_intermediaria != -1 && menor_custo < rota_direta_custo) { // Verifica se a rota com escala é estritamente melhor
         printf("%d-%d-%d R$%d\n", cidadeX, cidadeY_intermediaria, cidadeZ, menor_custo);
    } else if (cidadeY_intermediaria != -1 && rota_direta_custo == -1) { // Só existe rota com escala
         printf("%d-%d-%d R$%d\n", cidadeX, cidadeY_intermediaria, cidadeZ, menor_custo);
    } else { // A melhor rota é a direta (ou tem o mesmo custo da melhor escala)
         printf("%d-%d R$%d\n", cidadeX, cidadeZ, rota_direta_custo); // Usa o custo direto aqui
    }

    return 0;
}