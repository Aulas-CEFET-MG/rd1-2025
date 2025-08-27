#include <stdio.h>
#include <string.h>

int main(){

    //TAD - Tipo Abstrato de Dados
    typedef struct{
        int dia;
        int mes;
        int ano;
    }Data;

    typedef struct{
        int matricula;
        char nome[20];
        char sobrenome[20];
    }Aluno;

    Data d1;
    Aluno marcucci;
    // Vetor de Alunos
    Aluno alunos[5] = {};

    d1.dia = 27;
    d1.mes = 8;
    d1.ano = 2025;

    marcucci.matricula = 1;
    strcpy(marcucci.nome, "Gabriel");
    strcpy(marcucci.sobrenome, "Marcucci");
    

      //COMANDO PRINTF PARA MOSTRAR OS DADOS
    printf("--- Data de Hoje :) ---\n");
    printf("Dia: %d\n", d1.dia);
    printf("Mes: %d\n", d1.mes);
    printf("Ano: %d\n", d1.ano);

      //COMANDO PRINTF PARA MOSTRAR OS DADOS
    printf("--- Ficha do Aluno ---\n");
    printf("ID: %d\n", marcucci.matricula);
    printf("Nome: %s\n", marcucci.nome);
    printf("Sobrenome: %s\n", marcucci.sobrenome);

}