#include <stdio.h>

int main()
{

    int vet[10] = {};
    int TAM = 10;
    int numerosLidos = 0;
    

    while (numerosLidos != TAM)
    {
        int insere = 1;
        int numero;
        printf("Digite o %d numero: \n", numerosLidos + 1);
        scanf("%d", &numero);

        for (int i = 0; i < TAM; i++)
        {
            if (vet[i] == numero)
            {
                printf("Número já registrado. Digite outro...");
                insere = 0;
                break;
            }
        }

        if (insere == 1)
        {
            vet[numerosLidos] = numero;
            numerosLidos++;
        }
    }

    printf("\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vet[i]);
    }
}