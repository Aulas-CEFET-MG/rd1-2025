#include <stdio.h>

int main()
{

    /*3) Tendo como dado de entrada a altura (h) de uma pessoa,
    construa um algoritmo que calcule seu peso ideal,
    utilizando as seguintes fórmulas:

     - Para homens: (72.7*h) – 58
     - Para mulheres: (62.1*h) - 44.7.
*/

    double h;
    char genero;
    double pesoIdeal;

    printf("Digite a sua altura (em metros):\n");
    scanf("%lf", &h);

    printf("Digite seu genero: M - Masculino ou F - Feminino:\n");
    scanf(" %c", &genero);

    switch (genero){
        case 'M':
            pesoIdeal = (72.7 * h) - 58;
            break;

        case 'F':
            pesoIdeal = (62.1 * h) - 44.7;
            break;
            
        default:
            printf("Genero inválido. Digite M para Masculino ou F para Feminino!");
        break;
    }
    printf("O seu peso ideal é de %.2lf kg.", pesoIdeal);

    return 0;
}

int main(){

    int idade; 
    scanf("%d", &idade);
    printf("Sua idade é %d ", idade);

    if(idade == 18)
        printf("Maior de Idade!");
    else    
        printf("Menor de Idade!");

    
}