#include <stdio.h>
#include <string.h>

/**
 * @brief Simula uma verificação em um campo minado unidimensional.
 * O programa solicita e lê uma string que representa o campo e um índice a ser
 * verificado. Se a posição contiver uma bomba ('x'), imprime "bum!".
 * Caso contrário, conta e imprime o número de bombas nas posições
 * adjacentes (esquerda e direita).
 */
int main() {
    char campo[21]; 
    int indice;

    // Arauto anuncia a ordem
    printf("Digite o campo minado (ex: ..xx..x) e o indice a verificar (ex: 1):\n");
    fflush(stdout); // Garante que a mensagem apareça
    
    scanf("%s %d", campo, &indice);

    if (indice < 0 || indice >= strlen(campo)) {
        printf("Indice invalido!\n");
        return 1;
    }

    if (campo[indice] == 'x') {
        printf("bum!\n");
    } else {
        int bombas_adjacentes = 0;
        int len = strlen(campo);

        if (indice > 0 && campo[indice - 1] == 'x') {
            bombas_adjacentes++;
        }

        if (indice < len - 1 && campo[indice + 1] == 'x') {
            bombas_adjacentes++;
        }

        printf("%d\n", bombas_adjacentes);
    }

    return 0;
}