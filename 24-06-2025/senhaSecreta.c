#include <stdio.h>

int main() {
    int senha;

    // Solicita a senha ao usuário
    printf("Digite a senha: ");
    scanf("%d", &senha);

    // Extrai os dígitos da senha
    int d1 = senha / 1000;         // Primeiro dígito
    int d2 = (senha / 100) % 10;   // Segundo dígito
    int d3 = (senha / 10) % 10;    // Terceiro dígito
    int d4 = senha % 10;           // Quarto dígito

    // Verifica as condições da senha
    if (senha >= 1000 && senha <= 9999) { // Regra 1: Senha entre 1000 e 9999
        if (d1 % 2 == 0) { // Regra 2: Primeiro dígito par
            if (d4 % 2 != 0) { // Regra 3: Último dígito ímpar
                if (d2 + d3 > 10) { // Regra 4: Soma do segundo e terceiro dígitos maior que 10
                    printf("Senha: Válida\n");
                } else {
                    printf("Senha: Inválida\n");
                }
            } else {
                printf("Senha: Inválida\n");
            }
        } else {
            printf("Senha: Inválida\n");
        }
    } else {
        printf("Senha: Inválida\n");
    }

    return 0;
}