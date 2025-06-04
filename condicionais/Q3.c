/*
3) Tendo como dado de entrada a altura (h) de uma pessoa, 
construa um algoritmo que calcule seu peso ideal, 
utilizando as seguintes fórmulas:

     - Para homens: (72.7*h) – 58
     - Para mulheres: (62.1*h) - 44.7.

*/

#include <stdio.h>

int main(){

    char genero;
    float altura;

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite M se for Mulher e H se for Homem:\n");
    scanf(" %c", &genero);

    switch(genero){
        case 'M':
            printf("M - Seu peso ideal é %f\n", (62.1*altura) - 44.7);
            break;
        case 'H':
            printf("H - Seu peso ideal é %f\n", (72.7*altura) - 58);
            break;
        default:
            printf("Genero Inválido!");
            break;
    }

    return 0;

}