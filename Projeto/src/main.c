#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <float.h>

// --- Parâmetros ---
#define NUMERO_DE_PULSOS_SINTETICOS 100
#define SINAL_INICIAL_BASE 50.0
#define MAX_VARIACAO_BASE 5.0
#define TAMANHO_INICIAL_EEG 1000
#define TAMANHO_LINHA_EEG 100
#define NOME_ARQUIVO_EEG "dados_eeg.csv"
#define TAMANHO_AMOSTRA_EXIBIR 100

//================================================================================
// DECLARAÇÕES DAS FUNÇÕES
//================================================================================

double* carregarDadosEEG(const char* nomeArquivo, int* numPontos, double* minVal, double* maxVal);
double* gerarDadosSinteticos(int* numPontos, int escalar, double minTarget, double maxTarget);
void analisarEExibirDados(double* dados, int numPontos, const char* tipoDados, int indiceInicial);
double* calcularMediaMovel(double* dados, int numPontos, int tamanhoJanela);

/**
 * @brief Analisa tendências e faz previsões baseadas na derivada do sinal.
 * REQUISITO U2: Lógica de decisão baseada em histórico (previsão e recomendação da U1).
 */
void analisarTendencia(double* dados, int numPontos, int indiceInicial, double minTotal, double maxTotal);


//================================================================================
// FUNÇÃO PRINCIPAL
//================================================================================
int main() {
    srand(time(NULL));

    int escolha;
    double* dadosProcessar = NULL;
    int numeroDePontos = 0;
    const char* tipoDados = "";
    double minEEG = 0.0, maxEEG = 0.0;
    
    // Variáveis para controlar os limites da análise
    double minAnalise = 0.0, maxAnalise = 100.0; 

    printf("Escolha a fonte dos dados:\n");
    printf("1. Gerar dados sinteticos (faixa 0-100)\n");
    printf("2. Gerar dados sinteticos (escalado para faixa EEG)\n");
    printf("3. Carregar dados do arquivo EEG (%s)\n", NOME_ARQUIVO_EEG);
    printf("Opcao: ");
    fflush(stdout);
    scanf("%d", &escolha);

    // Pré-carregamento
    if (escolha == 2 || escolha == 3) {
        printf("Carregando dados do arquivo EEG para obter faixa e/ou processar...\n");
        fflush(stdout);
        dadosProcessar = carregarDadosEEG(NOME_ARQUIVO_EEG, &numeroDePontos, &minEEG, &maxEEG);
        
        if (dadosProcessar == NULL) {
             printf("Falha ao carregar dados EEG. Nao e possivel continuar.\n");
             return 1;
        }
        
        if (escolha == 3) {
             tipoDados = "EEG Real";
             printf("Faixa de dados EEG: min=%.6f, max=%.6f\n", minEEG, maxEEG);
             minAnalise = minEEG;
             maxAnalise = maxEEG;
        }
    }

    // Lógica de Geração
    switch (escolha) {
        case 1:
            printf("Gerando dados sinteticos (0-100)...\n");
            fflush(stdout);
            free(dadosProcessar);
            dadosProcessar = gerarDadosSinteticos(&numeroDePontos, 0, 0, 0);
            tipoDados = "Sinteticos (0-100)";
            minAnalise = 0.0;
            maxAnalise = 100.0;
            break;
        case 2:
             if (maxEEG <= minEEG) {
                 printf("Erro: Faixa do EEG invalida para escalar.\n");
                 free(dadosProcessar);
                 return 1;
             }
            printf("Gerando dados sinteticos (escalado para [%.6f, %.6f])...\n", minEEG, maxEEG);
            fflush(stdout);
            free(dadosProcessar); 
            dadosProcessar = gerarDadosSinteticos(&numeroDePontos, 1, minEEG, maxEEG);
            tipoDados = "Sinteticos (Escalados)";
            minAnalise = minEEG;
            maxAnalise = maxEEG;
            break;
        case 3:
            break;
        default:
            printf("Opcao invalida.\n");
            free(dadosProcessar);
            return 1;
    }

    // Processamento Final
    if (dadosProcessar != NULL && numeroDePontos > 0) {
        
        // Sorteio do índice para sincronizar visualizações
        int indiceParaExibir = 0;
        if (numeroDePontos > TAMANHO_AMOSTRA_EXIBIR) {
            int maxIndice = numeroDePontos - TAMANHO_AMOSTRA_EXIBIR;
            indiceParaExibir = rand() % (maxIndice + 1);
        }

        // 1. Exibe Original
        analisarEExibirDados(dadosProcessar, numeroDePontos, tipoDados, indiceParaExibir);

        // 2. Suavização (Média Móvel)
        printf("\n>>> Aplicando Filtro de Media Movel (Janela = 5)...\n");
        fflush(stdout);
        double* dadosSuavizados = calcularMediaMovel(dadosProcessar, numeroDePontos, 5);
        
        if (dadosSuavizados != NULL) {
            char tituloSuavizado[100];
            sprintf(tituloSuavizado, "%s - SUAVIZADO", tipoDados);
            analisarEExibirDados(dadosSuavizados, numeroDePontos, tituloSuavizado, indiceParaExibir);

            // ---------------------------------------------------------
            // 3. APLICAÇÃO DA ANÁLISE DE TENDÊNCIA E PREVISÃO
            // ---------------------------------------------------------
            analisarTendencia(dadosSuavizados, numeroDePontos, indiceParaExibir, minAnalise, maxAnalise);
            // ---------------------------------------------------------

            free(dadosSuavizados);
        }

        printf("Liberando memoria original...\n");
        fflush(stdout);
        free(dadosProcessar);
        printf("Memoria liberada.\n");
    } else {
        printf("Falha ao obter os dados.\n");
    }

    return 0;
}


//================================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES
//================================================================================

double* carregarDadosEEG(const char* nomeArquivo, int* numPontos, double* minVal, double* maxVal) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) { perror("Erro ao abrir o arquivo"); *numPontos = 0; return NULL; }

    double* dados = NULL;
    int capacidade = TAMANHO_INICIAL_EEG;
    int contador = 0;
    char linha[TAMANHO_LINHA_EEG];
    *minVal = DBL_MAX; *maxVal = -DBL_MAX;

    dados = (double*)malloc(capacidade * sizeof(double));
    if (dados == NULL) return NULL;

    while (fgets(linha, TAMANHO_LINHA_EEG, arquivo) != NULL) {
        if (contador >= capacidade) {
             capacidade *= 2;
             double* temp = (double*)realloc(dados, capacidade * sizeof(double));
             if (temp == NULL) { free(dados); fclose(arquivo); return NULL; }
             dados = temp;
        }
        double valorAtual = atof(linha);
        dados[contador] = valorAtual;
        if (valorAtual < *minVal) *minVal = valorAtual;
        if (valorAtual > *maxVal) *maxVal = valorAtual;
        contador++;
    }
    fclose(arquivo);
    *numPontos = contador;
    double* temp = (double*)realloc(dados, contador * sizeof(double));
    if (temp != NULL) dados = temp;
    return dados;
}

double* gerarDadosSinteticos(int* numPontos, int escalar, double minTarget, double maxTarget) {
    *numPontos = NUMERO_DE_PULSOS_SINTETICOS;
    double* dados = (double*)malloc((*numPontos) * sizeof(double));
    if (dados == NULL) return NULL;
    double sinalBase = SINAL_INICIAL_BASE;
    for (int i = 0; i < *numPontos; i++) {
        double variacao = ((double)rand() / RAND_MAX) * (2 * MAX_VARIACAO_BASE) - MAX_VARIACAO_BASE;
        sinalBase += variacao;
        if (sinalBase > 100.0) sinalBase = 100.0; else if (sinalBase < 0.0) sinalBase = 0.0;
        if (escalar && (maxTarget > minTarget)) {
            dados[i] = minTarget + (sinalBase / 100.0) * (maxTarget - minTarget);
        } else { dados[i] = sinalBase; }
    }
    return dados;
}

void analisarEExibirDados(double* dados, int numPontos, const char* tipoDados, int indiceInicial) {
    if (dados == NULL || numPontos <= 0) return;
    printf("\n--- Analise dos Dados (%s) ---\n", tipoDados);
    printf("Numero total de pontos: %d\n", numPontos);
    int fimExibicao = indiceInicial + TAMANHO_AMOSTRA_EXIBIR;
    if (fimExibicao > numPontos) fimExibicao = numPontos;
    if (indiceInicial < 0) indiceInicial = 0;
    printf("Exibindo amostra de %d pontos (indices %d a %d):\n", fimExibicao - indiceInicial, indiceInicial, fimExibicao - 1);
    for (int i = indiceInicial; i < fimExibicao; i++) {
        printf("%.4f ", dados[i]); 
        if ((i - indiceInicial + 1) % 10 == 0) printf("\n");
    }
    if ((fimExibicao - indiceInicial) % 10 != 0) printf("\n"); 
    printf("----------------------------------\n");
}

double* calcularMediaMovel(double* dados, int numPontos, int tamanhoJanela) {
    if (dados == NULL || numPontos <= 0) return NULL;
    double* dadosSuavizados = (double*)malloc(numPontos * sizeof(double));
    if (dadosSuavizados == NULL) return NULL;
    for (int i = 0; i < numPontos; i++) {
        double soma = 0.0;
        int pontosContados = 0;
        for (int j = 0; j < tamanhoJanela; j++) {
            int indiceAtual = i - j;
            if (indiceAtual >= 0) {
                soma += dados[indiceAtual];
                pontosContados++;
            }
        }
        dadosSuavizados[i] = soma / pontosContados;
    }
    return dadosSuavizados;
}

// --- analisarTendencia (Com Alta e Baixa) ---
void analisarTendencia(double* dados, int numPontos, int indiceInicial, double minTotal, double maxTotal) {
    printf("\n>>> ORACULO DE TENDENCIAS (Amostra) <<<\n");
    
    // Definição Dinâmica dos Limiares
    double amplitude = maxTotal - minTotal;
    double limiarAlerta = minTotal + (amplitude * 0.70); // 70% do range
    double limiarRepouso = minTotal + (amplitude * 0.30); // 30% do range
    
    // Define um limiar de variação brusca (1% da amplitude total)
    double limiarVariacao = amplitude * 0.01; 
    
    printf("Limiar Repouso (< %.2f) | Limiar Alerta (> %.2f)\n", limiarRepouso, limiarAlerta);

    int fimExibicao = indiceInicial + TAMANHO_AMOSTRA_EXIBIR;
    if (fimExibicao > numPontos) fimExibicao = numPontos;

    for (int i = indiceInicial; i < fimExibicao; i++) {
        double valorAtual = dados[i];
        double valorAnterior = (i > 0) ? dados[i-1] : valorAtual;
        double derivada = valorAtual - valorAnterior; // Taxa de variação (+ sobe, - desce)
        
        // Classificação de Estado Estático
        char* estado = "NORMAL";
        if (valorAtual > limiarAlerta) estado = "ALERTA";
        else if (valorAtual < limiarRepouso) estado = "REPOUSO";

        // Lógica de Previsão e Impressão Prioritária
        int eventoReportado = 0;

        // 1. Verifica Subida Rápida (Tendência de Alta)
        if (derivada > limiarVariacao) {
            printf("[%d] %.4f -> TENDENCIA DE ALTA (Subindo %.4f)! Estado: %s\n", i, valorAtual, derivada, estado);
            eventoReportado = 1;
        }
        // 2. Verifica Descida Rápida (Tendência de Baixa)
        else if (derivada < -limiarVariacao) {
            printf("[%d] %.4f -> TENDENCIA DE BAIXA (Caindo %.4f)! Estado: %s\n", i, valorAtual, derivada, estado);
            eventoReportado = 1;
        }

        // 3. Se não houve tendência brusca, mostra apenas se for estado crítico (Alerta ou Repouso)
        if (!eventoReportado && strcmp(estado, "NORMAL") != 0) {
             printf("[%d] %.4f -> Estado: %s\n", i, valorAtual, estado);
        }
    }
    printf("----------------------------------\n");
}