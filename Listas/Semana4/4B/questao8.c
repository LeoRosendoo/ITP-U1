#include <stdio.h>

int main() {
    float preco1, preco2, orcamento;
    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%f", &preco1);
    printf("Digite o preco do segundo fornecedor: ");
    scanf("%f", &preco2);
    printf("Digite a quantia disponivel: ");
    scanf("%f", &orcamento);

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            float custo_total = (i * preco1) + (j * preco2);
            if (custo_total <= orcamento) {
                printf("Comprando %d do primeiro e %d do segundo resta: %.2f\n", i, j, orcamento - custo_total);
            }
        }
    }
    return 0;
}