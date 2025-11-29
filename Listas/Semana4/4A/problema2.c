#include <stdio.h>
#include <math.h>

/**
 * @brief Simula a trajetória do Homem-Aranha, verificando se a teia alcança os alvos.
 * Lê a posição inicial, o comprimento da teia e uma série de alvos.
 * Para cada alvo, calcula a distância euclidiana. Se a teia for longa o
 * suficiente, a posição do Homem-Aranha é atualizada. Se falhar, a simulação
 * para. Ao final, informa se todos os alvos foram alcançados.
 */
int main() {
    float x_aranha, y_aranha, teia_max, x_alvo, y_alvo, distancia;
    int n_alvos, i;
    int sucesso = 1; // Flag para indicar sucesso (1) ou falha (0)

    printf("Digite a coordenada inicial (x y) do Homem-Aranha: ");
    scanf("%f %f", &x_aranha, &y_aranha);
    printf("Digite o comprimento maximo da teia: ");
    scanf("%f", &teia_max);
    printf("Digite a quantidade de alvos: ");
    scanf("%d", &n_alvos);

    for (i = 0; i < n_alvos; i++) {
        printf("Digite a coordenada do alvo %d (x y): ", i + 1);
        scanf("%f %f", &x_alvo, &y_alvo);

        // Calcula a distância euclidiana
        distancia = sqrt(pow(x_alvo - x_aranha, 2) + pow(y_alvo - y_aranha, 2));

        if (distancia <= teia_max) {
            // Atualiza a posição do Homem-Aranha
            x_aranha = 2 * x_alvo - x_aranha;
            y_aranha = 2 * y_alvo - y_aranha;
        } else {
            sucesso = 0;
            break; // Interrompe o loop se a teia não alcançar
        }
    }

    if (sucesso) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}