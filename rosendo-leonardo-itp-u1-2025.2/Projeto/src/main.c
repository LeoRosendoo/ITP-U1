#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//================================================================================
// PARÂMETROS GLOBAIS DA SIMULAÇÃO
//================================================================================
#define NUMERO_DE_PULSOS 100
#define SINAL_INICIAL 50
#define MAX_VARIACAO 5
#define PASSO_DE_TEMPO 0.1
#define LIMIAR_ALERTA 85
#define LIMIAR_REPOUSO 20

//================================================================================
// DECLARAÇÃO DAS FUNÇÕES
//================================================================================

/**
 * @brief Interpreta um valor de sinal e retorna a string do estado cognitivo.
 * @param sinal O valor inteiro do sinal a ser analisado.
 * @return const char* Ponteiro para a string que descreve o estado.
 */
const char* interpretarSinal(int sinal);

/**
 * @brief Calcula o próximo valor do sinal com base no valor anterior.
 * Aplica uma variação "aleatória" e garante que o valor permaneça nos limites.
 * @param sinalAnterior O valor do sinal no pulso anterior.
 * @return int O novo valor do sinal após a variação.
 */
int executarPulsoSimulacao(int sinalAnterior);

/**
 * @brief Imprime o estado atual da simulação de forma formatada.
 * @param pulso O número do pulso atual (iteração).
 * @param tempo O tempo decorrido simulado em segundos.
 * @param sinal O valor do sinal no pulso atual.
 * @param estado A string que descreve o estado cognitivo interpretado.
 */
void exibirEstadoSimulacao(int pulso, double tempo, int sinal, const char* estado);

/**
 * @brief Imprime um resumo do histórico de sinais armazenado no vetor.
 * Exibe os primeiros e os últimos valores para demonstrar o uso do vetor.
 * @param historico O vetor (array) contendo o histórico de sinais.
 * @param tamanho O tamanho total do vetor de histórico.
 */
void exibirResumoHistorico(int historico[], int tamanho);


//================================================================================
// FUNÇÃO PRINCIPAL
//================================================================================
int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Declaração do vetor para armazenar o histórico de dados da simulação
    int historicoDeSinais[NUMERO_DE_PULSOS];

    // Variáveis de estado da simulação
    int sinalAtual = SINAL_INICIAL;
    double tempoSimulado = 0.0;

    printf("--- INICIO DA SIMULACAO: Eletroencefalograma Artificial ---\n");
    printf("----------------------------------------------------------------\n");

    // Loop principal da simulação
    for (int i = 0; i < NUMERO_DE_PULSOS; i++) {
        sinalAtual = executarPulsoSimulacao(sinalAtual);
        const char* estadoAtual = interpretarSinal(sinalAtual);
        
        // Armazena o sinal gerado no vetor de histórico
        historicoDeSinais[i] = sinalAtual;

        exibirEstadoSimulacao(i + 1, tempoSimulado, sinalAtual, estadoAtual);

        tempoSimulado += PASSO_DE_TEMPO;
    }

    printf("----------------------------------------------------------------\n");
    printf("--- FIM DA SIMULACAO ---\n");

    // Exibe o resumo para comprovar o uso do vetor
    exibirResumoHistorico(historicoDeSinais, NUMERO_DE_PULSOS);

    return 0;
}

//================================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES
//================================================================================

const char* interpretarSinal(int sinal) {
    if (sinal > LIMIAR_ALERTA) {
        return "ALERTA MAXIMO";
    } else if (sinal < LIMIAR_REPOUSO) {
        return "REPOUSO PROFUNDO";
    } else {
        return "ATIVIDADE NORMAL";
    }
}

int executarPulsoSimulacao(int sinalAnterior) {
    // Gera uma variação aleatória no intervalo [-MAX_VARIACAO, +MAX_VARIACAO]
    int variacao = (rand() % (2 * MAX_VARIACAO + 1)) - MAX_VARIACAO;
    int novoSinal = sinalAnterior + variacao;

    // Assegura que o novo sinal permaneça dentro do intervalo [0, 100]
    if (novoSinal > 100) {
        novoSinal = 100;
    } else if (novoSinal < 0) {
        novoSinal = 0;
    }
    return novoSinal;
}

void exibirEstadoSimulacao(int pulso, double tempo, int sinal, const char* estado) {
    printf("Tempo: %.1fs | Pulso #%d: Sinal = %d | Estado: %s\n", tempo, pulso, sinal, estado);
}

void exibirResumoHistorico(int historico[], int tamanho) {
    printf("\n--- RESUMO DO HISTORICO DE SINAIS (VETOR) ---\n");
    printf("Primeiros 5 sinais: %d, %d, %d, %d, %d\n", 
           historico[0], historico[1], historico[2], historico[3], historico[4]);
    printf("Ultimos 5 sinais: %d, %d, %d, %d, %d\n", 
           historico[tamanho-5], historico[tamanho-4], historico[tamanho-3], historico[tamanho-2], historico[tamanho-1]);
    printf("---------------------------------------------\n");
}
