Introdução a Técnicas de Programação
Aluno: Leonardo Rosendo Faustino
Matrícula: 20250027331
Período: 2025.2
Projeto: Sistema de Monitoramento e Análise Híbrida de Sinais Neurais (EEG)

Descrição

Este projeto é o resultado final da disciplina, consolidando o desenvolvimento realizado ao longo das Unidades 1 e 2. O software evoluiu de um simples simulador para um sistema híbrido robusto capaz de operar em dois modos distintos:

Simulação (Legado U1): Geração de sinais sintéticos controlados baseados em caminhada aleatória.

Dados Reais (Expansão U2): Carregamento e processamento de arquivos de EEG reais (contendo mais de 600.000 pontos de dados), utilizando alocação dinâmica para lidar com grandes volumes.

O sistema final aplica filtros digitais (Média Móvel) para suavização e algoritmos de análise de tendência para prever estados críticos antes que eles ocorram.

Repositório

https://github.com/LeoRosendoo/ITP-U1/tree/main/rosendo-leonardo-itp-2025.2

Vídeos de Demonstração

Unidade 1 (Gerador Sintético): https://youtu.be/PmgS2MRG2dM

Unidade 2 (Análise Híbrida e EEG Real): https://www.youtube.com/watch?v=GwC5lLFA4Wk

Funcionalidades Implementadas

Unidade 1

Geração de Sinal Sintético: Simulação de um sinal neural contínuo.

Classificação em Tempo Real: Categorização do sinal em 3 estados ("Normal", "Alerta", "Repouso") com base em limiares fixos.

Histórico Estático: Registro dos últimos 100 pontos em um vetor de tamanho fixo.

Unidade 2

Leitura de Arquivos Reais: Capacidade de ler e processar arquivos .csv de EEG com volume arbitrário de dados.

Gerenciamento Dinâmico de Memória: Uso de malloc e realloc para armazenar vetores de tamanho desconhecido (ex: 600k pontos).

Filtro de Suavização: Algoritmo de Média Móvel para reduzir ruídos do sinal original.

Oráculo de Tendências: Análise preditiva baseada na derivada do sinal, detectando subidas ou descidas bruscas em tempo real.

Amostragem Inteligente: Visualização sincronizada de amostras aleatórias contíguas para comparação entre sinal bruto e tratado.

Conceitos Aplicados

Da Unidade 1

Estruturas Condicionais: if/else e switch para lógica de estados e menus.

Estruturas de Repetição: Laços for simples para percorrer vetores fixos.

Modularização Básica: Divisão do código em funções especialistas.

Da Unidade 2

Alocação Dinâmica: Fundamental para carregar os 600.000 pontos do EEG, superando as limitações da memória stack. Toda memória é liberada com free.

Ponteiros: Utilizados extensivamente para manipular vetores dinâmicos e passagem por referência.

Strings e Arquivos: Uso de stdio.h e string.h para processar o arquivo CSV.

Estruturas de Repetição Aninhadas: Aplicadas na função de Média Móvel (um laço para o sinal, outro para a janela).

Estrutura do Projeto Final

O código (main.c) integra todas as funcionalidades:

carregarDadosEEG: Leitura e alocação dinâmica.

gerarDadosSinteticos: Lógica da U1 adaptada para memória dinâmica.

calcularMediaMovel: Processamento matemático (Laços Aninhados).

analisarTendencia: Lógica de decisão e previsão.

analisarEExibirDados: Interface de saída unificada.