#include <stdio.h>

int main(){

    double peso;
    double altura;
    double imc;

    printf("Digite sua altura (em metros): \n");
    scanf("%lf", &altura);

    printf("Digite o seu peso (em kg):\n");
    scanf("%lf", &peso);

    imc = peso/(altura*altura);
    
    if(imc <= 18.49){
        printf("Abaixo do Peso!\n");
        printf("oioioi\n\n");
    }else if(imc <= 24.99)
        printf("Peso Normal!\n\n");
    else if(imc <= 29.99)
        printf("Acima do Peso!\n\n");
    else
        printf("Obesidade!\n\n");

    return 0;
}