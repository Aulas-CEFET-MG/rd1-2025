#include <stdio.h>

int main(){
/* 3) Tendo como dado de entrada a altura (h) de uma pessoa, 
    construa um algoritmo que calcule seu peso ideal, 
    utilizando as seguintes fórmulas:
     - Para homens: (72.7*h) – 58
     - Para mulheres: (62.1*h) - 44.7.
*/

    float altura;
    char genero;
    double pesoIdeal;

    printf("Digite a sua altura:\n");
    scanf("%f", &altura);

    printf("Digite seu genero: H - Homem ou M - Mulher: \n");
    scanf(" %c", &genero);

    switch (genero){
    case 'H':
        pesoIdeal = (72.7*altura) - 58;
        break;
    case 'M':
        pesoIdeal = (62.1*altura) - 44.7;
        break;
    default:
        printf("Genero inválido. Digite H para Homem e M para Mulher!");
        return 0; 
        // para não exibir a mensagem com o peso, a gnt sai da aplicação
    }

    printf("O seu peso ideal é de %lf kg.", pesoIdeal);

    return 0;

}