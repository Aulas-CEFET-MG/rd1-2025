#include <stdio.h>

int main() {

    int numeros[] = {10, 20, 30};
    int *p;
    int resultado;

    printf("Valor de p: %d\n", p);
    p++;
    printf("Valor após chamar p++: %d\n", p);

    // --- Teste 1: (*p)++ ---
    // Incrementa o VALOR para o qual p aponta.
    p = numeros; // Reseta: p aponta para o 10.
    (*p)++;      // O valor 10 se torna 11.
    printf("(*p)++ -> O valor original virou: %d\n", numeros[0]); // Imprime 11
    
    // Reseta o valor do vetor para o próximo teste
    numeros[0] = 10;

    // --- Teste 2: *p++ (pós-fixado) ---
    // 1º: Pega o valor de onde p está (10).
    // 2º: DEPOIS, avança o ponteiro para o próximo elemento (20).
    p = numeros; // Reseta: p aponta para o 10.
    resultado = *p++; 
    printf("*p++   -> Valor pego: %d, Ponteiro agora aponta para: %d\n", resultado, *p); // Imprime 10, 20

    // --- Teste 3: *++p (pré-fixado) ---
    // 1º: PRIMEIRO, avança o ponteiro para o próximo elemento (20).
    // 2º: Pega o valor de onde o ponteiro chegou (20).
    p = numeros; // Reseta: p aponta para o 10.
    resultado = *++p;
    printf("*++p   -> Valor pego: %d, Ponteiro agora aponta para: %d\n", resultado, *p); // Imprime 20, 20

 
    // O ponteiro 'p' começa apontando para o primeiro elemento (10)
    p = numeros;

    printf("O ponteiro 'p' aponta para o valor: %d\n\n", *p);
    // Agora, executamos a expressão e guardamos o valor retornado
    int valor_acessado = *(p++);

    printf("1. O valor acessado e guardado é: %d\n", valor_acessado);
    printf("2. O ponteiro 'p' foi movido e agora aponta para: %d\n", *p);

    return 0;
}