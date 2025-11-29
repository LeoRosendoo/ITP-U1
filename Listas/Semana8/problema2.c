#include <stdio.h>

typedef struct {
    int chuva;
    int mes_indice; 
} MesChuva;

int main() {
    MesChuva dados_chuva[12];
    const char* nomes_meses[12] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    printf("Digite a quantidade de chuva para cada mes (Jan a Dez, separados por espaco):\n");
    fflush(stdout);
    for (int i = 0; i < 12; i++) {
        scanf("%d", &dados_chuva[i].chuva);
        dados_chuva[i].mes_indice = i;
    }

    // Ordena usando Bubble Sort (decrescente)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11 - i; j++) {
            if (dados_chuva[j].chuva < dados_chuva[j + 1].chuva) {
                MesChuva temp = dados_chuva[j];
                dados_chuva[j] = dados_chuva[j + 1];
                dados_chuva[j + 1] = temp;
            }
        }
    }

    // Imprime o ranking ordenado
    for (int i = 0; i < 12; i++) {
        printf("%s %d\n", nomes_meses[dados_chuva[i].mes_indice], dados_chuva[i].chuva);
    }

    return 0;
}