#include <stdio.h>
#include <string.h>

typedef struct
{
    char jogadorA[50];
    char jogadorB[50];
    int pontoA;
    int pontoB;
    char corA;
    char corB;
} Partida;

void registrarPontosDaPartida(Partida partidasV[], int numDePartidas,
                              int pontosA, int pontosB, int partidaAtual)
{
    if (partidaAtual >= numDePartidas)
    {
        printf("Numero da Partida excede o numero de partidas do campeonato.");
        return NULL;
    }
    partidasV[partidaAtual].pontoA = pontosA;
    partidasV[partidaAtual].pontoB = pontosB;
}

void imprimirPlacar(Partida partidasV[], int numDePartidas)
{
    for (int i = 0; i < numDePartidas; i++)
    {
        if(partidasV[i].pontoA == -1 && partidasV[i].pontoB == -1)
            break;

        printf("\n------------- Partida %d -------------\n", i + 1);
        printf("- %s \t\t\t %d -\n", partidasV[i].jogadorA, partidasV[i].pontoA);
        printf("- %s \t\t\t %d -\n", partidasV[i].jogadorB, partidasV[i].pontoB);
        printf("-------------------------------------\n");
    }
}

void inicializarPartidas(Partida partidas[], int numeroDePartidas){
    
    for (int i = 0; i < numeroDePartidas; i++){
        strcpy(partidas[i].jogadorA,"");
        strcpy(partidas[i].jogadorB,"");
        partidas[i].corA = ' ';
        partidas[i].corB = ' ';
        partidas[i].pontoA = -1;
        partidas[i].pontoB = -1;
    }
}

void main()
{

    int NUM_PARTIDAS = 2;
    Partida partidas[NUM_PARTIDAS];

    inicializarPartidas(partidas, NUM_PARTIDAS);

    strcpy(partidas[0].jogadorA, "Mateus");
    strcpy(partidas[0].jogadorB, "Jean");
    partidas[0].corA = 'B';
    partidas[0].corB = 'P';

    registrarPontosDaPartida(partidas, NUM_PARTIDAS, 2, 0, 0);

    imprimirPlacar(partidas, NUM_PARTIDAS);
    
}