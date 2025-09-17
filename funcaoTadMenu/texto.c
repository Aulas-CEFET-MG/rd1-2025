#include <stdio.h>
#include <string.h> // Biblioteca para manipulação de strings (strcpy, strcmp)

// Complete a definição da estrutura
typedef struct {

    char titulo[50];
    char ________________[30];
    int ____________________; 

} Jogo;

// Complete a função para exibir os dados de um único jogo
________   ___________________(Jogo j) { // Escolha um nome para a função

    printf("\n------------------------\n");
    printf("  Titulo: %s\n",    _______________);
    printf("  Genero: %s\n",    _______________);
    printf("  Ano: %d\n",       _______________ );
    printf("------------------------\n");

}

// Complete a função para buscar e exibir jogos de um gênero específico
void buscar_por_genero(Jogo biblioteca[], int tamanho, const char* genero_busca) {

    printf("\n>>> Buscando jogos do genero: %s <<<\n", genero_busca);
    int encontrou = 0;

    for (int i = 0; _______________; i++) { // Complete a condição do laço 'for'

        // Complete a condição do 'if' para comparar o gênero do jogo atual
        // com o gênero que está sendo buscado (genero_busca)
        if (strcmp(______________________________, genero_busca) == 0) {
        
            ____________________(biblioteca[i]); // Chame a função da Questão 2 aqui
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("\nNenhum jogo encontrado para este genero.\n");
    }
}

int main() {
    // Cria um vetor para armazenar 3 jogos
    Jogo minha_biblioteca[3];
    
    // --- Inicializa os dados do Jogo 1 ---
    strcpy(minha_biblioteca[0].titulo, "The Witcher 3");
    strcpy(minha_biblioteca[0].genero, "RPG");
    __________________________________ = 2015; // Complete a atribuição do ano

    // --- Inicializa os dados do Jogo 2 ---
    strcpy(minha_biblioteca[1].titulo, "Stardew Valley");
    strcpy(minha_biblioteca[1].genero, "Simulacao");
    minha_biblioteca[1].ano_lancamento = 2016;

    // --- Inicializa os dados do Jogo 3 ---
    strcpy(minha_biblioteca[2].titulo, "Cyberpunk 2077");
    _________________________________________________; // Complete a cópia do gênero "RPG"
    minha_biblioteca[2].ano_lancamento = 2020;


    // Agora, chame a função da Questão 3 para buscar todos os jogos do gênero "RPG"
    // Passe o vetor, seu tamanho e a string "RPG" como argumentos.
    ____________________________________________________________;
    
    return 0;
}

