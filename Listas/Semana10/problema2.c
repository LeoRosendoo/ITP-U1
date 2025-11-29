#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Busca todas as ocorrências de um valor em um vetor.
 * @param v Ponteiro para o início do vetor de inteiros.
 * @param n Tamanho do vetor v.
 * @param valor O valor inteiro a ser buscado.
 * @param qtd Ponteiro para um inteiro onde a quantidade de ocorrências será armazenada.
 * @return int* Ponteiro para um novo vetor (alocado dinamicamente) contendo os
 * índices onde 'valor' foi encontrado, ou NULL se nenhuma ocorrência
 * for encontrada ou se a alocação falhar.
 */
int* buscaNoVetor(int* v, int n, int valor, int* qtd) {
    int contagem = 0;
    // Primeira passagem: contar quantas ocorrências existem
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            contagem++;
        }
    }

    // Se nenhuma ocorrência foi encontrada
    if (contagem == 0) {
        *qtd = 0;
        return NULL;
    }

    // Aloca dinamicamente o vetor de índices
    int* indices = (int*)malloc(contagem * sizeof(int));
    if (indices == NULL) {
        printf("Erro: Falha na alocacao de memoria para os indices.\n");
        *qtd = 0; // Indica falha
        return NULL;
    }

    // Segunda passagem: preencher o vetor de índices
    int indice_atual = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            indices[indice_atual] = i;
            indice_atual++;
        }
    }

    // Armazena a quantidade de ocorrências no endereço apontado por qtd
    *qtd = contagem;
    return indices;
}

/**
 * @brief Lê um vetor de inteiros, busca por um valor e imprime os índices das ocorrências.
 * Utiliza alocação dinâmica e uma função auxiliar para realizar a busca.
 */
int main() {
    int n;
    printf("Digite o tamanho do vetor:\n");
    fflush(stdout);
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    // Aloca o vetor principal
    int* vetor = (int*)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro: Falha na alocacao de memoria para o vetor principal.\n");
        return 1;
    }

    printf("Digite os %d elementos do vetor (separados por espaco):\n", n);
    fflush(stdout);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int valor_busca;
    printf("Digite o valor a ser buscado:\n");
    fflush(stdout);
    scanf("%d", &valor_busca);

    int quantidade_ocorrencias = 0;
    int* indices_encontrados = buscaNoVetor(vetor, n, valor_busca, &quantidade_ocorrencias);

    // Imprime o resultado
    if (indices_encontrados == NULL) {
        printf("Nenhuma ocorrencia\n");
    } else {
        printf("Quantidade de ocorrencias: %d\n", quantidade_ocorrencias);
        printf("Indices: ");
        for (int i = 0; i < quantidade_ocorrencias; i++) {
            printf("%d ", indices_encontrados[i]);
        }
        printf("\n");
        // Libera a memória alocada para o vetor de índices
        free(indices_encontrados);
    }

    // Libera a memória alocada para o vetor principal
    free(vetor);

    return 0;
}