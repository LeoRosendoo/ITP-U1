#include <stdio.h>

int main() {
    float p_venda, q_custo, melhor_razao = 0.0;
    int melhor_x = 0, melhor_y = 0;

    printf("Digite o preco de venda p: ");
    scanf("%f", &p_venda);
    printf("Digite o preco de producao q: ");
    scanf("%f", &q_custo);

    // x = leva, y = paga. x > y. x <= 10
    for (int x = 2; x <= 10; x++) {
        for (int y = 1; y < x; y++) {
            // Lucro = (venda) - (custo)
            float lucro = (y * p_venda) - (x * q_custo);
            if (lucro >= 0) {
                float razao_atual = (float)x / y;
                if (razao_atual > melhor_razao) {
                    melhor_razao = razao_atual;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }

    if (melhor_x > 0) {
        printf("A melhor promocao eh: leve %d pague %d\n", melhor_x, melhor_y);
    } else {
        printf("Nenhuma promocao viavel encontrada sem prejuizo.\n");
    }
    return 0;
}