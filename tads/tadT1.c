#include <stdio.h>
#include <string.h> // para o strcpy

int main(){

    //TAD - Tipos Abstratos de Dados
    typedef struct{
        int ml;
        char sabor[20];
        char aspargos;
    }Toddy;

    Toddy jojo;

    jojo.ml = 250;
    strcpy(jojo.sabor,"Chocolate");
    jojo.aspargos = 'c';

    printf("%d\n", jojo.ml);
    printf("%s\n", jojo.sabor);
    printf("%c\n", jojo.aspargos);

    Toddy vetToddy[5];


    return 0;
}