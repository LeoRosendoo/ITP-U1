#include <stdio.h>
#include <math.h>

/**
 * @brief Valida e classifica triângulos.
 * Lê três valores, verifica se podem formar um triângulo.
 * Em caso afirmativo, classifica-o quanto aos lados (equilátero, isósceles, escaleno)
 * e quanto aos ângulos (retângulo, acutângulo, obtusângulo).
 */
int main() {
    float l1, l2, l3;
    float a, b, c; // Para ordenação dos lados (a será o maior)

    printf("Digite os tres lados do triangulo: ");
    scanf("%f %f %f", &l1, &l2, &l3);

    // Condição de existência de um triângulo
    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1) {
        printf("Os lados formam um triangulo.\n");

        // Classificação quanto aos lados
        if (l1 == l2 && l2 == l3) {
            printf("Classificacao (lados): Equilatero\n");
        } else if (l1 == l2 || l1 == l3 || l2 == l3) {
            printf("Classificacao (lados): Isosceles\n");
        } else {
            printf("Classificacao (lados): Escaleno\n");
        }

        // Ordena os lados para facilitar a classificação de ângulo
        // 'a' será sempre o maior lado
        if (l1 >= l2 && l1 >= l3) { a = l1; b = l2; c = l3; }
        else if (l2 >= l1 && l2 >= l3) { a = l2; b = l1; c = l3; }
        else { a = l3; b = l1; c = l2; }

        // Classificação quanto aos ângulos
        // Usamos uma pequena tolerância (epsilon) para comparações de float
        float a2 = pow(a, 2);
        float b2_c2 = pow(b, 2) + pow(c, 2);
        float epsilon = 1e-6;

        if (fabs(a2 - b2_c2) < epsilon) {
            printf("Classificacao (angulos): Retangulo\n");
        } else if (a2 < b2_c2) {
            printf("Classificacao (angulos): Acutangulo\n");
        } else {
            printf("Classificacao (angulos): Obtusangulo\n");
        }

    } else {
        printf("Os lados NAO formam um triangulo.\n");
    }

    return 0;
}