#include <stdio.h>

// Função que imprime N números inteiros
void imprimeNumeros(int N) {
    for (int i = 0; i < N; i++) {
        printf("%d\n", i);
    }
}

int main() {
   
    int n;
    printf("Digite a quantidade de números que deseja imprimir: ");
    scanf("%d", &n);
    
    imprimeNumeros(n);

    return 0;
}