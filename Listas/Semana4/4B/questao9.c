#include <stdio.h>

int main() {
    float preco1, preco2, orcamento, menor_restante;
    int melhor_qtd1 = 0, melhor_qtd2 = 0;

    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%f", &preco1);
    printf("Digite o preco do segundo fornecedor: ");
    scanf("%f", &preco2);
    printf("Digite a quantia disponivel: ");
    scanf("%f", &orcamento);

    menor_restante = orcamento;

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            float custo_total = (i * preco1) + (j * preco2);
            if (custo_total <= orcamento) {
                float restante_atual = orcamento - custo_total;
                if (restante_atual < menor_restante) {
                    menor_restante = restante_atual;
                    melhor_qtd1 = i;
                    melhor_qtd2 = j;
                }
            }
        }
    }

    printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhor_qtd1, melhor_qtd2);
    return 0;
}