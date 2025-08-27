#include <stdio.h>
#include <string.h>

int main(){

    //TAD - Tipos Abstratos de Dados

    typedef struct{
        int dia;
        int mes;
        int ano;
    }Data;

    Data hoje;

    hoje.dia = 27;
    hoje.mes = 8;
    hoje.ano = 2025;

    printf("%d/%d/%d", hoje.dia, hoje.mes,hoje.ano);

    typedef struct{
        int matricula;
        char nome[30];
        char curso[30];
    }Aluno;

    Aluno a1;

    a1.matricula = 1;
    strcpy(a1.nome,"Gabriel");
    strcpy(a1.curso,"Tec Redes");

    //COMANDO PRINTF PARA MOSTRAR OS DADOS
    printf("--- Ficha do Aluno ---\n");
    printf("Matricula: %d\n", a1.matricula);
    printf("Nome: %s\n", a1.nome);
    printf("Sobrenome: %s\n", a1.curso);

    Aluno alunos[5] = {};

}