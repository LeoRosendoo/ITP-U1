#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Aloca dinamicamente um vetor de 'n' inteiros.
 * @param n O número de elementos do vetor.
 * @return Ponteiro para o vetor alocado, ou NULL se falhar.
 */
int* alocarVetor(int n) {
    // Aloca a memória
    int *vetor = (int *)malloc(n * sizeof(int));
    
    // Verifica se a alocação de memória falhou
    if (vetor == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        // Retorna NULL para que a função main possa tratar o erro
    }
    
    return vetor;
}

/**
 * @brief Soma dois vetores de mesmo tamanho, elemento a elemento.
 * @param u O primeiro vetor.
 * @param v O segundo vetor.
 * @param n O tamanho (dimensão) dos vetores.
 * @return Ponteiro para um novo vetor contendo a soma, ou NULL se falhar.
 */
int* somaVetores(int *u, int *v, int n) {
    // Aloca um novo vetor 'w' para armazenar o resultado
    int *w = alocarVetor(n);
    
    // Se a alocação de 'w' falhar, retorna NULL
    if (w == NULL) {
        return NULL;
    }

    // Itera por todos os elementos, calculando a soma
    for (int i = 0; i < n; i++) {
        w[i] = u[i] + v[i];
    }
    
    // Retorna o ponteiro para o novo vetor 'w' com o resultado
    return w;
}

int main() {
    int *u, *v, *w; // Ponteiros para os vetores u, v, e o resultado w
    int n1, n2;
    int i; // Variável auxiliar para os loops

    // 1. ler do usuário um inteiro n1 e um inteiro n2
    scanf("%d %d", &n1, &n2);

    // 2. verificar se n1 != n2
    if (n1 != n2) {
        printf("dimensoes incompatives\n");
        return 1; // Termina o programa com código de erro
    } 
    
    // Se n1 == n2, o código continua
    
    // 3. alocar dinamicamente os vetores u e v
    u = alocarVetor(n1);
    v = alocarVetor(n2); // n2 é igual a n1, mas seguimos a instrução

    // Verificar se a alocação de u ou v falhou
    if (u == NULL || v == NULL) {
        free(u); // Libera o que quer que tenha sido alocado
        free(v);
        return 1; // Termina com erro
    }

    // 4. ler n1 inteiros para u
    for (i = 0; i < n1; i++) {
        scanf("%d", &u[i]);
    }

    // 5. ler n2 inteiros para v
    for (i = 0; i < n2; i++) {
        scanf("%d", &v[i]);
    }

    // 6. chamar a função somaVetores
    w = somaVetores(u, v, n1); // Passa n1 (que é igual a n2)

    // Verificar se a alocação de 'w' dentro da função falhou
    if (w == NULL) {
        free(u);
        free(v);
        return 1; // Termina com erro
    }

    // 7. escrever na tela o vetor resultante
    for (i = 0; i < n1; i++) {
        // Imprime cada número com um espaço, conforme o exemplo "7 -4 6"
        printf("%d ", w[i]); 
    }
    printf("\n"); // Adiciona uma quebra de linha no final

    // 8. Liberar TODA a memória alocada antes de sair
    free(u);
    free(v);
    free(w);

    return 0; // Indica que o programa terminou com sucesso
}