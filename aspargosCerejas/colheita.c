#include <stdio.h>
#include <stdlib.h> // Para a função abs() que calcula o valor absoluto

// Define um tamanho máximo para todos os vetores usados no programa
#define MAX_VETOR 100

// --- Protótipos das Funções ---
// Declarar as funções aqui informa ao compilador sobre sua existência
// antes de serem efetivamente usadas na 'main'.

void imprimir_vetor(int vetor[], int tamanho);
long calcular_essencia_dos_aspargos(int vetor_aspargos[], int tamanho);
void imprimir_relatorio_completo(int vetor_aspargos_inicial[], int tamanho_inicial, int cerejas);


// --- Função Principal ---
// O ponto de entrada de qualquer programa em C.
int main() {
    // Dados da colheita de hoje
    int aspargos_iniciais[] = {1, 2, 4, 5};
    
    // Em C, precisamos calcular o tamanho do vetor manualmente.
    // O operador sizeof() retorna o tamanho em bytes. Dividindo o tamanho total
    // do vetor pelo tamanho de um único elemento, obtemos a quantidade de elementos.
    int tamanho_inicial = sizeof(aspargos_iniciais) / sizeof(aspargos_iniciais[0]);
    
    int cerejas_colhidas = 10;

    // Inicia o processo e imprime o relatório
    printf("--- Relatório da Colheita da Fazenda Cascata ---\n");
    imprimir_relatorio_completo(aspargos_iniciais, tamanho_inicial, cerejas_colhidas);

    return 0; // Retorna 0 para indicar que o programa executou com sucesso.
}


// --- Implementação das Funções ---

void imprimir_vetor(int vetor[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        // Adiciona uma vírgula e espaço depois de cada elemento, exceto o último.
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

long calcular_essencia_dos_aspargos(int vetor_aspargos[], int tamanho) {
   
    long soma_quadrados_impares = 0;
    long soma_quadrados_pares = 0;

    for (int i = 0; i < tamanho; i++) {
        int elemento = vetor_aspargos[i];
        long quadrado = elemento * elemento;

        // Verifica se o número é par usando o operador módulo (resto da divisão)
        if (elemento % 2 == 0) {
            soma_quadrados_pares += quadrado;
        } else {
            soma_quadrados_impares += quadrado;
        }
    }

    return soma_quadrados_impares - soma_quadrados_pares;
}

void imprimir_relatorio_completo(int vetor_aspargos_inicial[], int tamanho_inicial, int cerejas) {
    // 1. Imprime o vetor inicial
    printf("> Vetor de Aspargos Inicial: ");
    imprimir_vetor(vetor_aspargos_inicial, tamanho_inicial);

    // 2. Calcula e imprime a essência inicial
    long essencia_inicial = calcular_essencia_dos_aspargos(vetor_aspargos_inicial, tamanho_inicial);
    printf("> Essência Inicial Calculada: %ld\n", essencia_inicial);

    // 3. Define o tamanho do novo vetor e verifica se é válido
    int novo_tamanho = abs(essencia_inicial);

    // Verificação de segurança: garante que o novo tamanho não exceda a memória alocada.
    if (novo_tamanho > MAX_VETOR) {
        printf("ERRO: A essência (%ld) é muito grande e excede a capacidade do vetor (%d)!\n", essencia_inicial, MAX_VETOR);
        return; // Encerra a função prematuramente se houver erro.
    }

    // 4. Cria e preenche o novo vetor
    int novo_vetor[MAX_VETOR]; // Declara o vetor com o tamanho máximo
    for (int i = 0; i < novo_tamanho; i++) {
        // Preenche as posições 'reais' do vetor com o valor da essência
        novo_vetor[i] = essencia_inicial;
    }

    // Imprime o novo vetor
    printf("> Novo Vetor de Aspargos Gerado: ");
    imprimir_vetor(novo_vetor, novo_tamanho);
    
    // 5. Calcula a essência refinada a partir do novo vetor
    long essencia_refinada = calcular_essencia_dos_aspargos(novo_vetor, novo_tamanho);
    printf("> Essência Refinada: %ld\n", essencia_refinada);

    // 6. Calcula o resultado final do ritual
    long resultado_final = essencia_refinada * cerejas;
    printf("> Resultado Final do Ritual (x%d cerejas): %ld\n", cerejas, resultado_final);
}