#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Agenda.h" // Inclui nossa própria interface

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char *buffer, int tamanho) {
    fgets(buffer, tamanho, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

void redimensionarAgenda(Contato **agenda, int *capacidade) {
    int novaCapacidade = (*capacidade == 0) ? 10 : (*capacidade * 2);
    Contato *temp = realloc(*agenda, novaCapacidade * sizeof(Contato));
    
    if (temp == NULL) {
        printf("Erro critico: Falha ao alocar memoria!\n");
        exit(1);
    }
    
    *agenda = temp;
    *capacidade = novaCapacidade;
}

void adicionarContato(Contato **agenda, int *qtd, int *capacidade) {
    if (*qtd == *capacidade) {
        redimensionarAgenda(agenda, capacidade);
    }

    printf("\n--- Novo Contato ---\n");
    printf("Nome: ");
    lerString((*agenda)[*qtd].nome, TAM_NOME);

    printf("DDD (apenas numeros): ");
    scanf("%d", &(*agenda)[*qtd].ddd);
    limparBuffer();

    printf("Telefone: ");
    lerString((*agenda)[*qtd].telefone, TAM_TEL);

    (*qtd)++;
    printf("Contato adicionado com sucesso!\n");

    // --- Persistência Imediata ---
    salvarArquivo(*agenda, *qtd);
    printf("(Dados salvos no arquivo automaticamente)\n");
}

void listarContatos(Contato *agenda, int qtd) {
    if (qtd == 0) {
        printf("\nAgenda vazia.\n");
        return;
    }

    printf("\n%-30s | %-4s | %-15s\n", "NOME", "DDD", "TELEFONE");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("%-30s | %-4d | %-15s\n", agenda[i].nome, agenda[i].ddd, agenda[i].telefone);
    }
}

void buscarPorNome(Contato *agenda, int qtd) {
    char termo[TAM_NOME];
    int encontrou = 0;

    printf("Digite parte do nome: ");
    lerString(termo, TAM_NOME);

    printf("\nResultados da busca:\n");
    for (int i = 0; i < qtd; i++) {
        if (strstr(agenda[i].nome, termo) != NULL) {
            printf("[%d] %s - (%d) %s\n", i, agenda[i].nome, agenda[i].ddd, agenda[i].telefone);
            encontrou = 1;
        }
    }

    if (!encontrou) printf("Nenhum contato encontrado.\n");
}

void buscarPorDDD(Contato *agenda, int qtd) {
    int dddBusca;
    int encontrou = 0;

    printf("Digite o DDD para listar: ");
    scanf("%d", &dddBusca);
    limparBuffer();

    printf("\nContatos do DDD %d:\n", dddBusca);
    for (int i = 0; i < qtd; i++) {
        if (agenda[i].ddd == dddBusca) {
            printf("[%d] %s - %s\n", i, agenda[i].nome, agenda[i].telefone);
            encontrou = 1;
        }
    }

    if (!encontrou) printf("Nenhum contato neste DDD.\n");
}

void atualizarContato(Contato *agenda, int qtd) {
    int indice;
    buscarPorNome(agenda, qtd); 

    printf("\nDigite o indice para editar (-1 para cancelar): ");
    scanf("%d", &indice);
    limparBuffer();

    if (indice >= 0 && indice < qtd) {
        printf("Editando: %s\n", agenda[indice].nome);
        
        printf("Novo Nome (Enter mantem atual): ");
        char temp[TAM_NOME];
        lerString(temp, TAM_NOME);
        if(strlen(temp) > 0) strcpy(agenda[indice].nome, temp);

        printf("Novo DDD (0 mantem atual): ");
        int novoDDD;
        scanf("%d", &novoDDD);
        limparBuffer();
        if(novoDDD != 0) agenda[indice].ddd = novoDDD;

        printf("Novo Telefone (Enter mantem atual): ");
        lerString(temp, TAM_TEL);
        if(strlen(temp) > 0) strcpy(agenda[indice].telefone, temp);

        printf("Atualizado com sucesso!\n");

        // --- Persistência Imediata ---
        salvarArquivo(agenda, qtd); 
        printf("(Alteracao salva no arquivo)\n");
    }
}

void removerContato(Contato **agenda, int *qtd) {
    int indice;
    buscarPorNome(*agenda, *qtd); 

    printf("\nDigite o indice para remover (-1 para cancelar): ");
    scanf("%d", &indice);
    limparBuffer();

    if (indice >= 0 && indice < *qtd) {
        for (int i = indice; i < *qtd - 1; i++) {
            (*agenda)[i] = (*agenda)[i + 1];
        }
        (*qtd)--;
        printf("Removido com sucesso!\n");
    }

    // --- Persistência Imediata ---
        salvarArquivo(*agenda, *qtd);
        printf("(Remocao salva no arquivo)\n");
}

void salvarArquivo(Contato *agenda, int qtd) {
    FILE *arquivo = fopen(ARQUIVO_DB, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para gravacao!\n");
        return;
    }
    for (int i = 0; i < qtd; i++) {
        fprintf(arquivo, "%s\t%d\t%s\n", agenda[i].nome, agenda[i].ddd, agenda[i].telefone);
    }
    fclose(arquivo);
}

void carregarArquivo(Contato **agenda, int *qtd, int *capacidade) {
    FILE *arquivo = fopen(ARQUIVO_DB, "r");
    if (arquivo == NULL) return;

    Contato temp;
    while (fscanf(arquivo, " %49[^\t]\t%d\t%14[^\n]", temp.nome, &temp.ddd, temp.telefone) == 3) {
        if (*qtd == *capacidade) {
            redimensionarAgenda(agenda, capacidade);
        }
        (*agenda)[*qtd] = temp;
        (*qtd)++;
    }
    fclose(arquivo);
}