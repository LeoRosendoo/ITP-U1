#include <stdio.h>
#include <math.h>

/**
 * @brief Calcula a altura do terreno em uma coordenada (x, y).
 * A altura é modelada pela função f(x,y) = sin(cos(y)+x)+cos(y+sin(x)).
 * @param x A coordenada x.
 * @param y A coordenada y.
 * @return float A altura calculada.
 */
float calcularAltura(float x, float y) {
    return sin(cos(y) + x) + cos(y + sin(x));
}

/**
 * @brief Verifica se um ponto de pouso (x, y) é seguro.
 * Um ponto é seguro se a altura em 5 locais (centro e 4 cantos da sonda)
 * estiver dentro da faixa permitida [0, 2].
 * @param x A coordenada x do ponto central.
 * @param y A coordenada y do ponto central.
 * @return int 1 se o ponto for seguro, 0 caso contrário.
 */
int ehPontoSeguro(float x, float y) {
    // Array de offsets para os 5 pontos da sonda a serem checados
    float offsets[5][2] = {
        {0.0, 0.0},
        {0.2, 0.2},
        {-0.2, -0.2},
        {0.2, -0.2},
        {-0.2, 0.2}
    };

    for (int i = 0; i < 5; i++) {
        float altura = calcularAltura(x + offsets[i][0], y + offsets[i][1]);
        if (altura < 0.0 || altura > 2.0) {
            return 0; // Ponto inseguro
        }
    }
    return 1; // Todos os 5 locais são seguros
}

/**
 * @brief Lê uma coordenada de pouso e classifica o local.
 * Se o ponto inicial não for seguro, a classificação é "troque de coordenada".
 * Caso contrário, verifica 4 locais vizinhos distantes e classifica o ponto como
 * "seguro", "relativamente seguro" ou "inseguro" com base no número
 * de vizinhos seguros.
 */
int main() {
    float x, y;

    printf("Digite a coordenada de pouso da sonda (x y): ");
    scanf("%f %f", &x, &y);

    // Fase 1: Verifica o ponto de pouso principal
    if (!ehPontoSeguro(x, y)) {
        printf("troque de coordenada\n");
        return 0;
    }

    // Fase 2: O ponto principal é seguro, então contamos os vizinhos distantes seguros.
    int vizinhos_seguros = 0;
    
    // Verifica os 4 vizinhos estratégicos
    if (ehPontoSeguro(x + 2, y)) {
        vizinhos_seguros++;
    }
    if (ehPontoSeguro(x - 2, y)) {
        vizinhos_seguros++;
    }
    if (ehPontoSeguro(x, y + 2)) {
        vizinhos_seguros++;
    }
    if (ehPontoSeguro(x, y - 2)) {
        vizinhos_seguros++;
    }

    // Fase 3: Veredito Final com base na contagem de vizinhos
    if (vizinhos_seguros >= 4) { // 4 pontos seguros
        printf("seguro\n");
    } else if (vizinhos_seguros >= 2) { // 2 ou 3 pontos seguros
        printf("relativamente seguro\n");
    } else { // 0 ou 1 ponto seguro
        printf("inseguro\n");
    }

    return 0;
}