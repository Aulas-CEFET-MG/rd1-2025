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

    printf("Digite o modelo da Aeronave:\n");
    fgets(modelo, sizeof(modelo), stdin);

    printf("Digite a capacidade de passageiros da aeronave:\n");
    scanf("%d", &nPassageiros);

    // --- AQUI ESTÁ A SOLUÇÃO ---
    // Limpa o buffer de entrada removendo o '\n' e quaisquer outros caracteres restantes
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    // ----------------------------

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
    for (int i = 0; i < numeroAeronaves; i++)
    {
        printf("Modelo \t| Nº de Passageiros \t| Tipo de Voo \t| Tempo de Voo\n");
        printf("-------------------------------------------------------------\n");
        printf("%s \t| %d \t| %c \t| %d \n", aeronaves[i].modelo, aeronaves[i].nPassageiros, aeronaves[i].tipoVoo, aeronaves[i].minutosVoo);
        printf("-------------------------------------------------------------\n");
    }
}

int main()
{

    int MAX_AVIOES = 2;
    Aeronave avioes[MAX_AVIOES];

    int avioesCadastrados = 0;

    avioes[avioesCadastrados] = registrarAeronave();
    avioesCadastrados++;

    listarAeronaves(avioes, avioesCadastrados);

    return 0;
}