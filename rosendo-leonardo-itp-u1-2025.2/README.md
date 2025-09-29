Introdução a Técnicas de Programação

- Aluno: Leonardo Rosendo Faustino
- Matrícula: 20250027331
- Período: 2025.2


Projeto: Simulação e Análise de Sinais Neurais Sintéticos

Descrição: 
	Este projeto consiste em um programa em Linguagem C que simula um sinal neural contínuo, similar a um eletroencefalograma (EEG). O programa gera autonomamente uma série de dados temporais e os classifica em tempo real em três estados distintos ("Atividade Normal", "Alerta Máximo", "Repouso Profundo"), aplicando os conceitos da Unidade I.

Repositório: 

Vídeo de Demonstração: https://youtu.be/PmgS2MRG2dM

Funcionalidades Implementadas:
- Geração de sinal sintético contínuo.
- Classificação do sinal em 3 estados com base em limiares.
- Registro de todo o histórico da simulação em um vetor.
- Exibição do estado da simulação em tempo real com referência temporal.

Conceitos da U1 Aplicados:
- Estruturas condicionais: Utilizadas para classificar o sinal e para garantir que os valores permanecessem dentro dos limites.
- Estruturas de repetição: O laço "for" foi o motor central da simulação, garantindo a execução de 100 pulsos.
- Vetores: O vetor "historicoDeSinais" foi usado para armazenar todos os 100 pontos de dados gerados, servindo como a memória da simulação.

- Funções: O código foi modularizado em 4 funções especialistas ("interpretarSinal", "executarPulsoSimulacao", "exibirEstadoSimulacao", "exibirResumoHistorico") para aumentar a legibilidade e a manutenção, com a "main" atuando como orquestradora.


