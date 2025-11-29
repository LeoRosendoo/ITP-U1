#include <stdio.h>
#include <math.h>

/**
 * @brief Calcula a pontuação em um jogo de dardos modificado.
 * Lê as coordenadas de 10 lançamentos. A pontuação total é a soma de uma
 * pontuação principal (baseada na distância ao centro) e uma pontuação
 * bônus (baseada na distância ao lançamento anterior).
 */
int main() {
    float x_atual, y_atual, x_anterior = 0, y_anterior = 0;
    float dist_centro, dist_anterior;
    int pontuacao_total = 0;

    printf("Digite as coordenadas (x y) dos 10 lancamentos:\n");

    for (int i = 0; i < 10; i++) {
        scanf("%f %f", &x_atual, &y_atual);

        // Calcula pontuação principal
        dist_centro = sqrt(pow(x_atual, 2) + pow(y_atual, 2));
        if (dist_centro <= 1) pontuacao_total += 10;
        else if (dist_centro <= 2) pontuacao_total += 6;
        else if (dist_centro <= 3) pontuacao_total += 4;
        
        // Calcula pontuação bônus (a partir do segundo lançamento)
        if (i > 0) {
            dist_anterior = sqrt(pow(x_atual - x_anterior, 2) + pow(y_atual - y_anterior, 2));
            if (dist_anterior <= 1) pontuacao_total += 5;
            else if (dist_anterior <= 2) pontuacao_total += 3;
            else if (dist_anterior <= 3) pontuacao_total += 2;
        }

        // Atualiza a coordenada anterior
        x_anterior = x_atual;
        y_anterior = y_atual;
    }

    printf("Pontuacao total: %d\n", pontuacao_total);

    return 0;
}