#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[60];
    char sabor[60];
    int dano;
    int vida;
    char raridade;
} Dollynho;

Dollynho registrarDolinho()
{
    Dollynho dolly;
    char nome[60];
    char sabor[60];
    int dano, vida;
    char raridade;
    int c;

    // Limpa o buffer antes de fgets (caso venha de um scanf anterior)
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Digite o nome do seu amiguinho: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o \n

    printf("Digite o sabor do seu dollynho:\n");
    fgets(sabor, sizeof(sabor), stdin);
    sabor[strcspn(sabor, "\n")] = '\0'; // Remove o \n

    printf("Digite o nível de Dano do seu dollynho:\n");
    scanf("%d", &dano);

    printf("Digite o nível de Vida do seu dollynho:\n");
    scanf("%d", &vida);

    // Limpa o buffer antes de ler o caractere
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Digite o nível (A-Z) de Raridade do seu dollynho:\n");
    scanf("%c", &raridade);

    // Preenche a struct
    strcpy(dolly.nome, nome);
    strcpy(dolly.sabor, sabor);
    dolly.dano = dano;
    dolly.vida = vida;
    dolly.raridade = raridade;

    return dolly;
}

void listarDollynhos(Dollynho amiguinhos[], int numeroDollynhos)
{

    for (int i = 0; i < numeroDollynhos; i++)
    {
        printf("Nome: %s \t | Vida: %d\n", amiguinhos[i].nome, amiguinhos[i].vida);
        printf("Sabor: %s \t | Dano: %d\n", amiguinhos[i].sabor, amiguinhos[i].dano);
        printf("Raridade: %c\n\n", amiguinhos[i].raridade);
    }
}

void exibirMenuDollynho()
{
    printf("\n===================== MENU =====================\n");
    printf("= 1 - Registrar Dollynho                       =\n");
    printf("= 2 - Atualizar Nivel de Vida                  =\n");
    printf("= 3 - Listar Dollynhos                         =\n");
    printf("= 4 - Exibir Ranking de Dollynhos por Raridade =\n");
    printf("= 5 - Sair                                     =\n");
    printf("================================================\n");
    printf("Escolha uma opcao: ");
}

Dollynho *inicializarVetorDollynhos(int totalDollynhos)
{

    Dollynho *vetor = malloc(totalDollynhos * sizeof(Dollynho));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria!");
        return NULL;
    }

    for (int i = 0; i < totalDollynhos; i++)
    {
        vetor[i].dano = 0;
        strcpy(vetor[i].nome, "");
        vetor[i].raridade = 'O';
        strcpy(vetor[i].sabor, "");
        vetor[i].vida = 0;
    }

    return vetor;
}

void atualizarVidaDollynho(Dollynho dollynhos[], int totalDollynhos)
{

    char nome[50];

    int c;
    // Limpa o buffer antes de fgets (caso venha de um scanf anterior)
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Qual Dollynho (seu amiguinho) deseja atualizar o nivel de vida?");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o \n

    for (int i = 0; i < totalDollynhos; i++)
    {
        if (strcmp(dollynhos[i].nome, nome) == 0)
        {
            printf("Qual é o novo nivel de Vida do %s?", nome);
            scanf("%d", &dollynhos[i].vida);
        }
    }
}

void listarDollynhosPorRaridade(Dollynho dollynhos[], int totalDollynhos)
{

    for (int i = 0; i < totalDollynhos - 1; i++)
    {
        for (int j = i + 1; j < totalDollynhos; j++)
        {
            if (dollynhos[j].raridade > dollynhos[i].raridade)
            {
                Dollynho temp = dollynhos[i];
                dollynhos[i] = dollynhos[j];
                dollynhos[j] = temp;
            }
        }
    }

    printf("================ Ranking por Raridade ================");
    for (int i = 0; i < totalDollynhos; i++)
    {
        printf("%dº - %s | Raridade: %c | Vida: %d | Dano: %d | Sabor: %s\n\n",
               i + 1,
               dollynhos[i].nome,
               dollynhos[i].raridade,
               dollynhos[i].vida,
               dollynhos[i].dano,
               dollynhos[i].sabor);
    }
    printf("======================================================\n\n");
}

int main()
{

    int MAX_DOLLYNHOS;
    printf("Quantos Dollynhos (seus amiguinhos) voce deseja cadastrar? ");
    scanf("%d", &MAX_DOLLYNHOS);

    Dollynho *dollynhos = inicializarVetorDollynhos(MAX_DOLLYNHOS);
    int dollynhosCadastrados = 0;

    int opcao = 0;

    while (opcao != 5)
    {

        exibirMenuDollynho();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            dollynhos[dollynhosCadastrados] = registrarDolinho();
            dollynhosCadastrados++;
            break;
        case 2:
            atualizarVidaDollynho(dollynhos, dollynhosCadastrados);
            break;
        case 3:
            listarDollynhos(dollynhos, dollynhosCadastrados);
            break;
        case 4:
            listarDollynhosPorRaridade(dollynhos, dollynhosCadastrados);
            break;
        case 5:
            printf("See you soon :)");
            break;

        default:
            break;
        }
    }

}