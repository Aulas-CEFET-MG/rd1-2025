#include <stdio.h>

int main(){

    int numeroCopias;

    printf("Digite o numero de copias");
    scanf("%d", &numeroCopias);

    if(numeroCopias <= 2)
        printf("O valor é R$ %.2f", numeroCopias*0.1);
    else if(numeroCopias <= 10)
        printf("O valor é R$ %.2f", numeroCopias*0.08);
    else if(numeroCopias <= 100)
        printf("O valor é R$ %.2f", numeroCopias*0.06);
    else
        printf("O valor é R$ %.2f", numeroCopias*0.04);

    return 0;

}
