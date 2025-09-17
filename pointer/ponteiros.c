#include <stdio.h>

int main() {

int a = 10;
int *pointerA;
int *pointerB;

printf("Variavel A: %d\n", a);

printf("Endereco de A %d\n", &a);

pointerA = &a;

printf("Ponteiro de A %d\n", pointerA);

printf("Ponteiro de A %d\n", *pointerA);



pointerB = 6422292;

printf("Ponteiro de B %d\n", pointerB);

printf("PointerB %d\n", *pointerB);

























    
    /*
    // Declara uma variável inteira 'idade' e a inicializa com o valor 30.
    int idade = 30;

    // Declara um ponteiro para um inteiro chamado 'ponteiro_idade'.
    // Um ponteiro é uma variável que armazena um endereço de memória.
    int *ponteiro_idade;

    // --- Exemplo 1: Apontando para uma variável e acessando seu valor ---

    printf("--- Exemplo 1 ---\n");

    // O operador '&' (endereço de) obtém o endereço de memória da variável 'idade'.
    // Atribuímos esse endereço ao nosso ponteiro.
    // Agora, 'ponteiro_idade' aponta para 'idade'.
    ponteiro_idade = &idade;

    printf("Valor da variável 'idade': %d\n", idade);
    printf("Endereço de memória de 'idade': %p\n", &idade);
    printf("Valor da variável 'ponteiro_idade' (é o endereço para onde aponta): %p\n", ponteiro_idade);

    // O operador '*' (derreferência) acessa o valor que está no endereço de memória
    // para o qual o ponteiro aponta.
    printf("Valor apontado por 'ponteiro_idade': %d\n\n", *ponteiro_idade);


    // --- Exemplo 2: Modificando o valor de uma variável através de um ponteiro ---

    printf("--- Exemplo 2 ---\n");
    printf("Valor original de 'idade': %d\n", idade);

    // Usando o operador de derreferência '*', podemos alterar o valor da variável original.
    *ponteiro_idade = 35; // O mesmo que fazer 'idade = 35;'

    printf("Novo valor de 'idade' após modificação via ponteiro: %d\n\n", idade);


    // --- Exemplo 3: Ponteiros e Arrays ---

    printf("--- Exemplo 3 ---\n");
    int numeros[3] = {10, 20, 30};

    // O nome de um array em C é, essencialmente, um ponteiro para o seu primeiro elemento.
    int *ponteiro_numeros = numeros; // Não precisa do '&' para arrays

    printf("O primeiro elemento do array é: %d\n", *ponteiro_numeros);

    // Aritmética de ponteiros: podemos "avançar" o ponteiro para o próximo elemento.
    ponteiro_numeros++; // Move o ponteiro para a próxima posição do array (endereço de numeros[1])

    printf("O segundo elemento do array, acessado com ponteiro incrementado, é: %d\n\n", *ponteiro_numeros);


    // --- Exemplo 4: Ponteiro NULO (NULL) ---

    printf("--- Exemplo 4 ---\n");
    // É uma boa prática inicializar ponteiros como NULL se eles não apontam para nada ainda.
    // NULL é um valor especial que significa "nenhum endereço".
    int *ponteiro_seguro = NULL;

    printf("O valor de 'ponteiro_seguro' é: %p\n", ponteiro_seguro);
    // Tentar derreferenciar um ponteiro NULL causaria um erro (segmentation fault).
    // if (ponteiro_seguro != NULL) {
    //    printf("%d", *ponteiro_seguro);
    // }

    */
    return 0;
}