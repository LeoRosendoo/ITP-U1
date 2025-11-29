#include <stdio.h>
#include <math.h> // Para a função sqrt()

/**
 * @brief Resolve equações de segundo grau (ax^2 + bx + c = 0).
 * O programa lê os coeficientes a, b e c, calcula o discriminante (Delta),
 * e determina as raízes da equação com base no valor de Delta.
 */
int main() {
    float a, b, c, delta, x1, x2;

    printf("Digite os coeficientes a, b e c da equacao (ax^2 + bx + c = 0): ");
    scanf("%f %f %f", &a, &b, &c);

    // Verifica se é uma equação do segundo grau
    if (a == 0) {
        printf("Nao e uma equacao do segundo grau, pois 'a' e zero.\n");
        return 1;
    }

    // Calcula o discriminante (Delta)
    delta = (b * b) - (4 * a * c);

    printf("Delta: %.2f\n", delta);

    // Determina as raízes com base em Delta
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("A equacao possui duas raizes reais distintas: x1 = %.2f e x2 = %.2f\n", x1, x2);
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("A equacao possui uma raiz real: x = %.2f\n", x1);
    } else {
        printf("A equacao nao possui raizes reais.\n");
    }

    return 0;
}