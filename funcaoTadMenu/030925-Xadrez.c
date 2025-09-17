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

typedef struct{
    char nome[50];
    int pontos;
}Jogador;

void registrarPontosDaPartida(Partida partidasV[], int numDePartidas,
                              int pontosA, int pontosB, int partidaAtual)
{
    // Recebemos a partida começando em 1, mas o vetor inicia em zero...
    partidaAtual -= 1;

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
        if (partidasV[i].pontoA == -1 || partidasV[i].pontoB == -1)
            break;

        printf("\n------------- Partida %d -------------\n", i + 1);
        printf("- %s \t\t\t %d -\n", partidasV[i].jogadorA, partidasV[i].pontoA);
        printf("- %s \t\t\t %d -\n", partidasV[i].jogadorB, partidasV[i].pontoB);
        printf("-------------------------------------\n");
    }
}

void inicializarPartidas(Partida partidas[], int numeroDePartidas)
{

    for (int i = 0; i < numeroDePartidas; i++)
    {
        strcpy(partidas[i].jogadorA, "");
        strcpy(partidas[i].jogadorB, "");
        partidas[i].corA = ' ';
        partidas[i].corB = ' ';
        partidas[i].pontoA = -1;
        partidas[i].pontoB = -1;
    }
}

void imprimirMenu()
{
    printf("=====================================\n");
    printf("        JOGO DE XADREZ - MENU      \n");
    printf("=====================================\n");
    printf("1 - Registrar Partida\n");
    printf("2 - Registrar Pontos da Partida\n");
    printf("3 - Exibir Placar\n");
    printf("4 - Exibir Ranking\n");
    printf("5 - Sair\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
}

void registrarPartida(Partida partidasV[], int numDePartidas){

    int p = 0;
    printf("Digite a partida que deseja registrar. Note que voce deve escolher entre 1 e %d.", numDePartidas);
    scanf("%d", &p);
    //validar a partida selecionada pelo usuario.

    //Ler o nome dos jogadores e suas respectivas cores no jogo
    printf("Digite o nome do Jogador A: ");
    scanf("%s", &partidasV[p-1].jogadorA);

    printf("Digite o nome do Jogador B: ");
    scanf("%s", &partidasV[p-1].jogadorB);

    printf("Digite a cor do Jogador A: ");
    scanf(" %c", &partidasV[p-1].corA);

    printf("Digite a cor do Jogador B: ");
    scanf(" %c", &partidasV[p-1].corB);

}

void cadastrarJogador(Jogador jogadores, int maxJogador){

    //TODO...
    
}

void somaPontuacaoJogadores(Partida partidas[], int numDePartidas, Jogador jogadores[], int maxJogadores){

    // Avaliar se será necessário essas variáveis...
    int encontradoA, encontradoB;

    for (int i = 0; i < numDePartidas; i++)
    {
       encontradoA = 0;
       encontradoB = 0;

       for(int j = 0; j < maxJogadores; j++){

            if(strcpm(partidas[i].jogadorA, jogadores[j].nome) == 0){
                jogadores[j].pontos += partidas[i].pontoA;
                encontradoA = 1;
            }

            if(strcpm(partidas[i].jogadorB, jogadores[j].nome) == 0){
                jogadores[j].pontos += partidas[i].pontoB;
                encontradoB = 1;
            }                
       }
    }

}

void exibirRanking(Jogador jogadores[], int numJogadores) {
    // Ordenar por pontuação (simples bubble sort)
    for (int i = 0; i < numJogadores - 1; i++) {
        for (int j = i + 1; j < numJogadores; j++) {
            if (jogadores[j].pontos > jogadores[i].pontos) {
                Jogador temp = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = temp;
            }
        }
    }

    printf("\n=========== RANKING DE JOGADORES ===========\n");
    for (int i = 0; i < numJogadores; i++) {
        printf("%dº - %s: %d pontos\n", i + 1, jogadores[i].nome, jogadores[i].pontos);
    }
    printf("============================================\n\n");
}

void main()
{
    int NUM_PARTIDAS;

    printf("Digite o numero de partidas deste jogo: ");
    scanf("%d", &NUM_PARTIDAS);

    //cria o vetor com o numero de partidas 
    Partida partidas[NUM_PARTIDAS];

    //Inicializa o vetor de partidas com dados "zerados"
    inicializarPartidas(partidas, NUM_PARTIDAS);

    // Variável a ser manipulada no Menu de opções
    int opcao = -1;

    // Colocar todas as variáveis aqui
    int partidaAtual;
    int pontosA, pontosB;

    while (opcao != 5)
    {
        imprimirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                registrarPartida(partidas, NUM_PARTIDAS);
                break;
            case 2:
                printf("Digite a partida para registrar os pontos: Entre 1 e %d. ", NUM_PARTIDAS);
                scanf("%d", &partidaAtual);
                printf("Digite a pontuacao do Jogador A: ");
                scanf("%d", &pontosA);
                printf("Digite a pontuacao do Jogador B: ");
                scanf("%d", &pontosB);
                registrarPontosDaPartida(partidas, NUM_PARTIDAS, pontosA, pontosB, partidaAtual);
                break;
            case 3:
                imprimirPlacar(partidas, NUM_PARTIDAS);
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;

            default:
                printf("\nOpcao invalida. Digite a opcao correta.\n\n");
                
        }
    }

    /*
    inicializarPartidas(partidas, NUM_PARTIDAS);

    strcpy(partidas[0].jogadorA, "Mateus");
    strcpy(partidas[0].jogadorB, "Jean");
    partidas[0].corA = 'B';
    partidas[0].corB = 'P';

    registrarPontosDaPartida(partidas, NUM_PARTIDAS, 2, 0, 0);

    imprimirPlacar(partidas, NUM_PARTIDAS);
    */
}
