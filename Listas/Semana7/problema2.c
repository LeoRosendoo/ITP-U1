#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Valida uma string como placa de carro padrão brasileiro ou Mercosul.
 * O programa solicita uma placa, lê a string e verifica se seu formato 
 * corresponde a um dos dois padrões: LLL-AAAA (brasileiro) ou LLLALAA 
 * (Mercosul), onde L é uma letra maiúscula e A é um algarismo.
 */
int main() {
    char placa[11];
    
    printf("Digite a placa do carro para o sistema verificar a validade:\n");
    fflush(stdout); // Garante que a mensagem apareça

    scanf("%s", placa);

    int len = strlen(placa);
    int padrao_brasileiro = 0; // Inicia como falso
    int padrao_mercosul = 0;   // Inicia como falso

    // Verifica o padrão brasileiro: LLL-AAAA
    if (len == 8) {
        int valido = 1; // Flag de validação local
        for (int i = 0; i < 3; i++) {
            if (!isupper(placa[i])) valido = 0;
        }
        if (placa[3] != '-') valido = 0;
        for (int i = 4; i < 8; i++) {
            if (!isdigit(placa[i])) valido = 0;
        }
        if (valido) padrao_brasileiro = 1;
    }
    
    // Verifica o padrão Mercosul: LLLALAA
    if (len == 7) {
        int valido = 1; // Flag de validação local
        if (!isupper(placa[0])) valido = 0;
        if (!isupper(placa[1])) valido = 0;
        if (!isupper(placa[2])) valido = 0;
        if (!isupper(placa[3])) valido = 0;
        if (!isdigit(placa[4])) valido = 0;
        if (!isupper(placa[5])) valido = 0;
        if (!isdigit(placa[6])) valido = 0;
        
        // Correção na lógica de verificação Mercosul LLLALAA
        // O pdf mostra LLLALAA, porém o exemplo é QWE4K99, ou seja LLLA L AA
        // O pdf também mostra um exemplo inválido TTM9923, que seria LLLA AA A
        // Vou seguir o exemplo QWE4K99 que parece LLLA L AA
        if (len == 7) {
            padrao_mercosul = 1; // Assume que é válido e invalida se encontrar erro
            for(int i = 0; i < 3; i++) if(!isupper(placa[i])) padrao_mercosul = 0; // LLL
            if(!isdigit(placa[3])) padrao_mercosul = 0; // A
            if(!isupper(placa[4])) padrao_mercosul = 0; // L
            for(int i = 5; i < 7; i++) if(!isdigit(placa[i])) padrao_mercosul = 0; // AA
        }
    }


    // Emite o veredito
    if (padrao_brasileiro) {
        printf("brasileiro\n");
    } else if (padrao_mercosul) {
        printf("mercosul\n");
    } else {
        printf("invalido\n");
    }

    return 0;
}