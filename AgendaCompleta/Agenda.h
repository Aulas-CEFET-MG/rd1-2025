#ifndef AGENDA_H
#define AGENDA_H

// --- CONSTANTES ---
#define ARQUIVO_DB "agenda.tsv"
#define TAM_NOME 50
#define TAM_TEL 15

// --- ESTRUTURA ---
typedef struct {
    char nome[TAM_NOME];
    int ddd;
    char telefone[TAM_TEL];
} Contato;

// --- PROTÓTIPOS (Assinaturas das funções) ---

// Utilitários
void limparBuffer();
void lerString(char *buffer, int tamanho);

// Gerenciamento de Memória e Arquivo
void carregarArquivo(Contato **agenda, int *qtd, int *capacidade);
void salvarArquivo(Contato *agenda, int qtd);
void redimensionarAgenda(Contato **agenda, int *capacidade);

// CRUD (Create, Read, Update, Delete)
void adicionarContato(Contato **agenda, int *qtd, int *capacidade);
void listarContatos(Contato *agenda, int qtd);
void buscarPorNome(Contato *agenda, int qtd);
void buscarPorDDD(Contato *agenda, int qtd);
void atualizarContato(Contato *agenda, int qtd);
void removerContato(Contato **agenda, int *qtd);

#endif // Fim do AGENDA_H