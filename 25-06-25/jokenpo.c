#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    int jogador, computador;

    // Inicializa o gerador de números aleatórios uma única vez
    srand(time(NULL));

    while(jogador != 4) {
        printf("Escolha uma opção:\n");
        printf("1 - Pedra\n");
        printf("2 - Papel\n");
        printf("3 - Tesoura\n");
        printf("4 - Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &jogador);

        if (jogador == 4) {
            printf("Até a próxima!\n");
            break;
        }

        if (jogador < 1 || jogador > 4) {
            printf("Opção inválida! Tente novamente.\n\n");
            continue;
        }

        computador = rand() % 3 + 1;

        printf("Computador escolheu: ");
        if (computador == 1) printf("Pedra\n");
        else if (computador == 2) printf("Papel\n");
        else printf("Tesoura\n");

        if (jogador == computador) {
            printf("Empate!\n");
        } else if ((jogador == 1 && computador == 3) ||
                   (jogador == 2 && computador == 1) ||
                   (jogador == 3 && computador == 2)) {
            printf("Você venceu!\n");
        } else {
            printf("Você perdeu!\n");
        }

        printf("\n");

    };

    return 0;
}