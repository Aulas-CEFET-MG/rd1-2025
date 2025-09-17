#include <stdio.h>
#include <string.h>

typedef struct
{
    char modelo[60];
    int nPassageiros;
    char tipoVoo; // I ou N
    int minutosVoo;
} Aeronave;

Aeronave registrarAeronave()
{
    char modelo[60];
    int nPassageiros;
    char tipoVoo; // I ou N
    int minutosVoo;
    Aeronave aviao;

    // Limpa o buffer antes de fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o modelo da Aeronave:\n");
    fgets(modelo, sizeof(modelo), stdin);
    modelo[strcspn(modelo, "\n")] = '\0'; // Remove o \n


    printf("Digite a capacidade de passageiros da aeronave:\n");
    scanf("%d", &nPassageiros);

    // Limpa novamente
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Digite o Tipo de Voo realizado pela aeronave.\n I - Para Internacional\n N - para Nacional\n");
    scanf("%c", &tipoVoo);

    printf("Digite o tempo (em minutos) de voo da Aeronave:\n");
    scanf("%d", &minutosVoo);

    strcpy(aviao.modelo, modelo);
    aviao.nPassageiros = nPassageiros;
    aviao.tipoVoo = tipoVoo;
    aviao.minutosVoo = minutosVoo;

    return aviao;
}

void listarAeronaves(Aeronave aeronaves[], int numeroAeronaves)
{
    printf("Modelo \t\t| Num. de Passageiros \t| Tipo de Voo \t| Tempo de Voo\n");
    printf("-------------------------------------------------------------\n");
        
    for (int i = 0; i < numeroAeronaves; i++)
    {
        //if(strcmp(aeronaves[i].modelo, ""))
        if(aeronaves[i].nPassageiros == 0)
            break;

        printf("%s \t| %d \t\t\t| %c \t| %d \n", aeronaves[i].modelo, aeronaves[i].nPassageiros, aeronaves[i].tipoVoo, aeronaves[i].minutosVoo);
        printf("-------------------------------------------------------------\n");
    }
    printf("\n-------------------------------------------------------------\n");
}

void imprimirMenu()
{
    printf("\n================== MENU =================\n");
    printf("|  1 - Registrar Aeronave               |\n");
    printf("|  2 - Registrar Tempo de Voo           |\n");
    printf("|  3 - Listar Aeronaves                 |\n");
    printf("|  4 - Exibir Ranking por Tempo de Voo  |\n");
    printf("|  5 - Sair                             |\n");
    printf("=========================================\n");
    printf("Escolha uma opcao: ");
}

Aeronave* inicializarVetorAeronaves(int maxAeronaves){

    Aeronave *vetor = malloc(maxAeronaves*sizeof(Aeronave));
    if(vetor == NULL){
        printf("Erro ao Alocar memoria.");
        return NULL;
    }

    for(int i = 0; i < maxAeronaves; i++){
        strcpy(vetor[i].modelo, "");
        vetor[i].nPassageiros = 0;
        vetor[i].tipoVoo = 'O';
        vetor[i].minutosVoo = 0;
    }

    return vetor;

}

void registrarTempodeVoo(Aeronave aeronaves[], int totalCadastradas){

    char nomeAeronave[50];
    // Limpa o buffer antes de fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Digite o modelo da Aeronave que deseja atualizar o tempo de voo: ");
    fgets(nomeAeronave, sizeof(nomeAeronave), stdin);
    nomeAeronave[strcspn(nomeAeronave, "\n")] = '\0'; // Remove o \n

    for(int i = 0; i < totalCadastradas; i++){
        if(strcmp(aeronaves[i].modelo, nomeAeronave) == 0){
            printf("Digite o tempo de voo (em minutos) atualizado: ");
            scanf("%d", &aeronaves[i].minutosVoo);
        }
        else{
            printf("Aeronave não localizada!");
        }
    }
}

void exibirRankingPorTempo(Aeronave aeronaves[], int totalCadastradas){
    for(int i = 0; i < totalCadastradas-1; i++){
        for(int j = i+1; j < totalCadastradas; j++){
            if(aeronaves[j].minutosVoo > aeronaves[i].minutosVoo){
                Aeronave temp = aeronaves[i];
                aeronaves[i] = aeronaves[j];
                aeronaves[j] = temp;
            }
        }
    }

    printf("============= Ranking por Tempo de Voo ==============\n");
    for(int i = 0; i < totalCadastradas; i++){
        printf("%s \t| %d \t\t\t| %c \t| %d \n", aeronaves[i].modelo, aeronaves[i].nPassageiros, aeronaves[i].tipoVoo, aeronaves[i].minutosVoo);
    }
    printf("=====================================================\n");

}

int main()
{

    int MAX_AVIOES;

    printf("Quantas Aeronaves deseja cadastrar? ");
    scanf("%d", &MAX_AVIOES);

    Aeronave *avioes = inicializarVetorAeronaves(MAX_AVIOES);
    int avioesCadastrados = 0;

    // Variavel para ler a opcao do usuario
    int opcao = 0;

    while (opcao != 5)
    {

        imprimirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                avioes[avioesCadastrados] = registrarAeronave();
                avioesCadastrados++;
                break;
            case 2:
                registrarTempodeVoo(avioes, avioesCadastrados);
                break;
            case 3:
                listarAeronaves(avioes, MAX_AVIOES);
                break;
            case 4:
                exibirRankingPorTempo(avioes, avioesCadastrados);
                break;
            case 5:
                printf("Ate logo :) ");
                break;

            default:
            break;
        }
    }

    

    

    listarAeronaves(avioes, avioesCadastrados);

    return 0;
}