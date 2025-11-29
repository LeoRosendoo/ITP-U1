#include <stdio.h>

/**
 * @brief Simula uma partida de Pedra, Papel e Tesoura.
 * O programa lê a jogada de dois jogadores (P, A, T) e
 * determina o vencedor com base nas regras clássicas do jogo.
 */
int main() {
    char jogador1, jogador2;

    printf("Jogador 1, digite sua jogada (P-Pedra, A-Papel, T-Tesoura): ");
    scanf(" %c", &jogador1);

    printf("Jogador 2, digite sua jogada (P-Pedra, A-Papel, T-Tesoura): ");
    scanf(" %c", &jogador2);

    if (jogador1 == jogador2) {
        printf("Resultado: Empate!\n");
    } else if ((jogador1 == 'P' && jogador2 == 'T') ||
               (jogador1 == 'T' && jogador2 == 'A') ||
               (jogador1 == 'A' && jogador2 == 'P')) {
        printf("Resultado: Jogador 1 venceu!\n");
    } else {
        printf("Resultado: Jogador 2 venceu!\n");
    }

    return 0;
}