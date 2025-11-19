#include <stdio.h>
#include <stdlib.h> // Para exit()

/**
 * @brief Salva a lista de produtos em modo TEXTO, um por linha.
 * @param prods O array de produtos.
 * @param num_prods O número de produtos no array.
 */
void salvar_modo_texto(char prods[5][30], int num_prods) {
    printf("Salvando em modo TEXTO (produtos.txt)...\n");

    // 1. Abrir em modo "w" (write/escrita de texto)
    FILE *fp = fopen("produtos.txt", "w");
    if (fp == NULL) {
        perror("Erro ao abrir produtos.txt");
        exit(1); // Aborta o programa se não conseguir criar o arquivo
    }

    // 2. Iterar e escrever cada string formatada
    for (int i = 0; i < num_prods; i++) {
        // Usa fprintf para salvar a string seguida de um pula-linha
        fprintf(fp, "%s\n", prods[i]);
    }

    // 3. Fechar o arquivo
    fclose(fp);
    printf("Arquivo 'produtos.txt' salvo com sucesso!\n\n");
}

/**
 * @brief Salva a lista de produtos em modo BINÁRIO.
 * @param prods O array de produtos.
 * @param num_prods O número de produtos no array.
 */
void salvar_modo_binario(char prods[5][30], int num_prods) {
    printf("Salvando em modo BINARIO (produtos.dat)...\n");

    // 1. Abrir em modo "wb" (write/escrita binária)
    FILE *fp = fopen("produtos.dat", "wb");
    if (fp == NULL) {
        perror("Erro ao abrir produtos.dat");
        exit(1);
    }

    // 2. Escrever o bloco de memória INTEIRO de uma vez.
    //    Origem: O array 'prods'
    //    Tamanho do bloco: O tamanho total do array (5 * 30 bytes)
    //    Quantidade de blocos: 1
    fwrite(prods, sizeof(char[5][30]), 1, fp);

    // 3. Fechar o arquivo
    fclose(fp);
    printf("Arquivo 'produtos.dat' salvo com sucesso!\n\n");
}

int main() {
    // Definindo o array com 5 nomes de produtos
    char produtos[5][30] = {
        "Mouse Gamer",
        "Teclado Mecanico",
        "Monitor Ultrawide",
        "SSD 1TB",
        "Headset 7.1"
    };
    
    int num_prods = 5;

    // Executando as duas formas de salvamento
    salvar_modo_texto(produtos, num_prods);
    salvar_modo_binario(produtos, num_prods);

    // --- Verificação Final (Conforme o enunciado) ---
    printf("--- Verificacao Final ---\n");
    printf("1. Abra 'produtos.txt' no Bloco de Notas ou outro editor de texto.\n");
    printf("   (Voce vera os nomes perfeitamente legiveis).\n");
    printf("\n");
    printf("2. Tente abrir 'produtos.dat' no mesmo editor de texto.\n");
    printf("   (Voce vera dados 'estranhos' ou ilegiveis).\n");

    return 0;
}