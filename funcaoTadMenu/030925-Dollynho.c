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

Dollynho registrarDolinho(){

    char nome[60];
    char sabor[60];
    int dano;
    int vida;
    char raridade;
    Dollynho dolly;

    printf("Digite o nome do seu amiguinho: \n");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite o sabor do seu dollynho:\n");
    fgets(sabor, sizeof(sabor), stdin);

    printf("Digite o nível de Dano do seu dollynho:\n");
    scanf("%d", &dano);

    printf("Digite o nível de Vida do seu dollynho:\n");
    scanf("%d", &vida);

    // --- AQUI ESTÁ A SOLUÇÃO ---
    // Limpa o buffer de entrada removendo o '\n' e quaisquer outros caracteres restantes
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    // ----------------------------

    printf("Digite o nível (A-Z) de Raridade do seu dollynho:\n");
    scanf("%c", &raridade);

    dolly.dano = dano;
    dolly.raridade = raridade;
    strcpy(dolly.sabor, sabor);
    strcpy(dolly.nome, nome);
    dolly.vida = vida;

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    return dolly;
}

void listarDollynhos(Dollynho amiguinhos[], int numeroDollynhos){

    for(int i = 0; i < numeroDollynhos; i++){
        printf("Nome: %s \t | Vida: %d\n", amiguinhos[i].nome, amiguinhos[i].vida);
        printf("Sabor: %s \t | Dano: %d\n", amiguinhos[i].sabor, amiguinhos[i].dano);
        printf("Raridade: %c\n", amiguinhos[i].raridade);
    }
}

int main(){

    int MAX_DOLLYNHOS = 2;
    Dollynho dollynhos[MAX_DOLLYNHOS];
    int dollynhosCadastrados = 0;

    dollynhos[dollynhosCadastrados] = registrarDolinho();
    dollynhosCadastrados++;

    listarDollynhos(dollynhos, dollynhosCadastrados);

    dollynhos[dollynhosCadastrados] = registrarDolinho();
    dollynhosCadastrados++;

    listarDollynhos(dollynhos, dollynhosCadastrados);


}