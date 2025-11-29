#include <stdio.h>

int main() {
    int n; 
    
    printf("Digite o numero de pilotos (1 a 20):\n");
    fflush(stdout);
    scanf("%d", &n);

    // Validação básica
     if (n < 1 || n > 20) {
        printf("Numero de pilotos invalido.\n");
        return 1;
    }

    int largada[n];
    int chegada[n];
    int pos_largada[n + 1]; 
    int pos_chegada[n + 1]; 

    printf("Digite a ordem de largada (numeros dos pilotos de 1 a %d, separados por espaco):\n", n);
    fflush(stdout);
    for (int i = 0; i < n; i++) {
        scanf("%d", &largada[i]);
         if (largada[i] < 1 || largada[i] > n) { // Validação piloto existe
            printf("Piloto invalido na largada.\n"); return 1;
        }
        pos_largada[largada[i]] = i + 1; 
    }

    printf("Digite a ordem de chegada (numeros dos pilotos de 1 a %d, separados por espaco):\n", n);
    fflush(stdout);
    for (int i = 0; i < n; i++) {
        scanf("%d", &chegada[i]);
         if (chegada[i] < 1 || chegada[i] > n) { // Validação piloto existe
             printf("Piloto invalido na chegada.\n"); return 1;
        }
        pos_chegada[chegada[i]] = i + 1; 
    }

    int maior_ganho = 0;
    int piloto_vencedor = -1;
    int empate = 0;

    for (int piloto = 1; piloto <= n; piloto++) {
        int ganho = pos_largada[piloto] - pos_chegada[piloto];

        if (ganho > maior_ganho) {
            maior_ganho = ganho;
            piloto_vencedor = piloto;
            empate = 0; 
        } else if (ganho == maior_ganho && ganho > 0) {
             // Se já havia um vencedor com o mesmo ganho, marca empate
             if (piloto_vencedor != -1) {
                 empate = 1;
             }
             // Se não havia vencedor ainda (maior_ganho era 0), este é o primeiro
             // Mas se outro piloto também tiver ganho 0, será empate no final
        }
    }
    
    // Caso especial: Ninguém ganhou posições (maior_ganho == 0)
    if (maior_ganho == 0) {
        empate = 1; // Força empate se ninguém ganhou nada
    }


    if (piloto_vencedor != -1 && !empate) {
        printf("%d\n", piloto_vencedor);
    } else {
        printf("empate\n");
    }

    return 0;
}