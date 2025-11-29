#include <stdio.h>

/**
 * @brief Compara as respostas de um aluno com um gabarito do ENEM.
 * O programa lê o número de questões, o gabarito oficial e as respostas
 * do aluno, armazenando-os em vetores. Em seguida, compara os dois
 * vetores e conta o número de acertos.
 */
int main() {
    int n; // Número de questões

    printf("Digite o numero de questoes (1 a 20): ");
    scanf("%d", &n);

    // Declara os vetores APÓS 'n' ter sido lido
    int gabarito[n];
    int respostas_aluno[n];
    int acertos = 0;

    printf("Digite as %d respostas do gabarito (sem espacos): ", n);
    // O espaço antes de "%1d" é crucial para consumir o '\n' anterior
    for (int i = 0; i < n; i++) {
        scanf(" %1d", &gabarito[i]);
    }

    printf("Digite as %d respostas do aluno (sem espacos): ", n);
    // O espaço aqui também previne erros caso haja mais whitespace
    for (int i = 0; i < n; i++) {
        scanf(" %1d", &respostas_aluno[i]);
    }

    // Compara as respostas e conta os acertos
    for (int i = 0; i < n; i++) {
        if (gabarito[i] == respostas_aluno[i]) {
            acertos++;
        }
    }

    // Exibe o resultado com a formatação correta para o plural
    if (acertos == 1) {
        printf("%d acerto\n", acertos);
    } else {
        printf("%d acertos\n", acertos);
    }

    return 0;
}