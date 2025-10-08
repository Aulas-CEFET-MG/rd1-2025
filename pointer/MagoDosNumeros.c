#include <stdio.h>

// Função para calcular o fatorial de um número
long long int calcular_fatorial(int n) {

    if (n < 0) return -1; // Fatorial não definido para negativos
    if (n == 0) return 1;
    long long int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// A função principal da atividade
void mago_dos_numeros(int ________, int ________) {
    printf("--- Dentro da MÁGICA ---\n");
    printf("Valores recebidos (via ponteiro): %d e %d\n", ________, ________);

    // 1. Implementar a TROCA dos valores aqui
    
    // 2. Calcular o QUADRADO e substituir o valor original
    
    // 3. Calcular o FATORIAL e substituir o valor original

    printf("Valores ao final da mágica: %d e %d\n", *ptr_a, *ptr_b);
    printf("------------------------\n\n");
}

int main() {
    int numero1 = 4;
    int numero2 = 5;

    printf("Valores ANTES da mágica: numero1 = %d, numero2 = %d\n\n", numero1, numero2);

    // Chama a função passando os ENDEREÇOS das variáveis
    mago_dos_numeros(_________, _________);

    printf("Valores DEPOIS da mágica: numero1 = %d, numero2 = %d\n", numero1, numero2);

    return 0;
}
