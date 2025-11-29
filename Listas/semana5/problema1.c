#include <stdio.h>

/**
 * @brief Imprime um horário em formato 24h ou 12h (AM/PM).
 * @param horas As horas totais (podem ser > 23).
 * @param minutos Os minutos totais (podem ser > 59).
 * @param formato O formato de saída (0 para 24h, 1 para 12h).
 */
void imprimirHorario(int horas, int minutos, int formato) {
    // Normaliza os minutos e horas
    horas += minutos / 60;
    minutos = minutos % 60;
    horas = horas % 24;

    if (formato == 0) { // Formato 24h
        printf("%02d:%02d\n", horas, minutos);
    } else { // Formato 12h
        int hora_12h = horas;
        const char* periodo = "AM"; // Usando const char*

        if (horas == 0) {
            hora_12h = 12; // 00:xx é 12:xx AM
        } else if (horas == 12) {
            periodo = "PM"; // 12:xx é 12:xx PM
        } else if (horas > 12) {
            hora_12h = horas - 12;
            periodo = "PM"; // Horas > 12 são PM
        }
        
        printf("%02d:%02d %s\n", hora_12h, minutos, periodo);
    }
}

/**
 * @brief Calcula e exibe os horários de rondas policiais.
 * Lê um horário inicial e um formato de exibição. Em seguida, calcula
 * e exibe 5 horários de ronda com base em acréscimos predefinidos.
 */
int main() {
    int h_inicial, m_inicial, formato;

    printf("Digite a hora inicial, minuto inicial e o formato (0 para 24h, 1 para 12h): ");
    scanf("%d %d %d", &h_inicial, &m_inicial, &formato);

    // A primeira impressão é o próprio horário inicial.
    imprimirHorario(h_inicial, m_inicial, formato);
    // Acréscimos em relação ao horário da primeira ronda.
    imprimirHorario(h_inicial + 1, m_inicial, formato);
    imprimirHorario(h_inicial + 2, m_inicial + 10, formato);
    imprimirHorario(h_inicial + 4, m_inicial + 40, formato);
    imprimirHorario(h_inicial + 12, m_inicial + 5, formato);
    
    return 0;
}