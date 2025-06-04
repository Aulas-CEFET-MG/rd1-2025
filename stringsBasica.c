#include <stdio.h>
#include <string.h> // Para strcpy e fgets

int main(void) {

  char nome[10];
  char nomeMaior[50]; // Para usar com fgets -- Buffer para até 49 caracteres + '\0'

  printf("Digite seu nome: ");
  scanf("%s", nome);
  printf("\nO nome armazenado foi: %s", nome);

  // Não funciona, uma vez que o vetor nome já foi declarado
  // E "TEste" é uma constante, logo não pode ser atribuída a uma variável
  //nome = "TEste";
  // Funciona, pois strcpy copia o conteúdo da constante para a string nome
  strcpy(nome, "Coisa"); 
  printf("\nO nome alterado para: %s", nome); 

  // --- AQUI ESTÁ A SOLUÇÃO ---
  // Limpa o buffer de entrada removendo o '\n' e quaisquer outros caracteres restantes
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  // ----------------------------

  printf("\nDigite seu nome completo: ");
  // Lê no máximo 49 caracteres do teclado (stdin)
  fgets(nomeMaior, sizeof(nomeMaior), stdin);
  printf("\nO nome completo armazenado foi: %s", nomeMaior);

  printf("\n\nDigite seu nome: ");
  scanf("%s", nome);
  printf("\nO nome armazenado foi: %s", nome);

  return 0;
}
