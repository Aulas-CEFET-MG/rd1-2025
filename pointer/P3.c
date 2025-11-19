#include <stdio.h>

int main(){

    int i = 3, j = 5;

    int *p = &i, *q = &j;
    printf("%d", p == &i);
    printf("%d",*p - *q);
    printf("%d",**&p);

    int quociente = 0;
    int resto = 0;

    calculaDivisao(10,3,&quociente, &resto);

    printf("\n\n%d .. %d", quociente, resto);

    return 0;
}

void calculaDivisao(int dividendo, int divisor, int *quociente, int *resto) {
    // Usa o ponteiro para escrever o resultado do quociente no endereço de 'q'
    *quociente = dividendo / divisor;
    
    // Usa o ponteiro para escrever o resultado do resto no endereço de 'r'
    *resto = dividendo % divisor;
}