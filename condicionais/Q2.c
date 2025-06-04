/* ===== Questão 2 ======
Implemente um programa que receba o peso e a altura de uma pessoa e retorne o seu IMC. 
O IMC é calculado da seguinte forma: IMC = 𝑃𝑒𝑠𝑜/(𝐴𝑙𝑡𝑢𝑟𝑎^2). 
O programa deverá utilizar o IMC calculado para informar o status do IMC da pessoa. 
É importante lembrar que o peso é em Kg e a altura em metros

Abaixo de 18,49 = Abaixo do peso 
Entre 18,5 e 24,99 = Peso normal 
Entre 25 e 29,99 = Acima do peso 
Acima de 30 = Obesidade 
*/

#include <stdio.h>

int main(){

    double imc;
    double peso;
    double altura;

    printf("Digite o peso da pessoa: \n");
    scanf("%lf",&peso);

    printf("Digite a altura da pessoa: \n");
    scanf("%lf",&altura);

    imc = peso/(altura*altura);

    if(imc <= 18.49){
        printf("Abaixo do Peso!");
    }else if(imc <= 24.99){
        printf("Peso Normal!");
    }else if(imc <= 29.99){
        printf("Acima do peso!");
    }else{
        printf("Obesidade!");
    }
    return 0;

}