#include <stdio.h>
#include <stdlib.h>
#include "Agenda.h" // Importa o "manual de instruções" da agenda

int main() {
    Contato *agenda = NULL; 
    int qtd = 0;       
    int capacidade = 0; 
    int opcao;

    carregarArquivo(&agenda, &qtd, &capacidade);

    do {
        printf("\n=================================\n");
        printf("      AGENDA TELEFONICA (C)      \n");
        printf("=================================\n");
        printf("Contatos na memoria: %d\n", qtd);
        printf("---------------------------------\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Todos\n");
        printf("3. Buscar por Nome\n");
        printf("4. Buscar por DDD\n");
        printf("5. Atualizar Contato\n");
        printf("6. Remover Contato\n");
        printf("0. Sair e Salvar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer(); 

        switch(opcao) {
            case 1: adicionarContato(&agenda, &qtd, &capacidade); break;
            case 2: listarContatos(agenda, qtd); break;
            case 3: buscarPorNome(agenda, qtd); break;
            case 4: buscarPorDDD(agenda, qtd); break;
            case 5: atualizarContato(agenda, qtd); break;
            case 6: removerContato(&agenda, &qtd); break;
            case 0: 
                printf("Salvando dados e saindo...\n");
                salvarArquivo(agenda, qtd);
                if(agenda) free(agenda); 
                break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}