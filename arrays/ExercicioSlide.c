#include <stdio.h>

int main() {
    int numeros[10];
    int i, maior, menor;
    int mat[3][4] = {};

    /*
    // Leitura dos 10 números
    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Posição [%d]: ", i);
        scanf("%d", &numeros[i]);
    }

    // Inicializa maior e menor com o primeiro valor
    maior = menor = numeros[0];

    // Impressão dos valores e identificação do maior/menor
    printf("\nValores digitados:\n");
    for (i = 0; i < 10; i++) {
        printf("Posição [%d] = %d\n", i, numeros[i]);

        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    // Exibição do maior e menor valor
    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    /*
    for (int i = 0; i < 3; i++) {           // percorre as linhas
        for (int j = 0; j < 4; j++) {       // percorre as colunas
            printf("%d ", mat[i][j]);   // acessa o elemento da linha i e coluna j
        }
        printf("\n");
    }
    */

    printf("%d  == Memory", (20*20*20*20*20*20*20*20) * sizeof(int));

    return 0;

}
