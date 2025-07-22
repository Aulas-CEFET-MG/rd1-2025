#include <stdio.h>

double lerNota(int aluno){
    double nota;
    printf("Digite a nota do %d aluno:", aluno);
    nota = scanf("%lf", &nota);
    return nota;
}

void imprime(int n){
    for(int i = 0; i < n; i++){
        printf("%d ", i+1);
    }
}

int soma(int numero1,int numero2){
    return numero1 + numero2;
}

double quadradoNumero(double numero){
    return numero*numero;
}


int main(){
       
    #define MAX_ALUNOS 10 
    const int MAX = 3;

    int notasAlunos[MAX_ALUNOS] = {};

    printf("\n\n");

    imprime(200);

    int valorSoma = soma(10,30);
    printf("\n\nResultado da Soma: %d", valorSoma);

    printf("\n\nQuadrado: %lf ", quadradoNumero(128));

    for(int i = 0; i < MAX_ALUNOS; i++){
        notasAlunos[i] = lerNota(i+1);
    }

    printf("\n");

    return 0;
    
}