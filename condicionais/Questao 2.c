#include <stdio.h>

int main(){

    /*Abaixo de 18,49 = Abaixo do peso 
    Entre 18,5 e 24,99 = Peso normal 
    Entre 25 e 29,99 = Acima do peso 
    Acima de 30 = Obesidade 
    */

    float peso;
    float altura;
    float imc;

    printf("Digite o seu peso:\n");
    scanf("%f", &peso);

    printf("Digite o sua altura:\n");
    scanf("%f", &altura);

    imc = peso/(altura*altura);

    if(imc <= 18.49)
        printf("Abaixo do Peso!");
    else if(imc <= 24.99)
        printf("peso Normal!");
    else if(imc <= 29.99)
        printf("Acima do Peso!");
    else
        printf("Obesidade\n\n");


    return 0;
}