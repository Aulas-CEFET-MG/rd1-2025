#include <stdio.h>

int main(){


    //int notasAlunos[12] = {1};

    //int notasAlunos[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int notasAlunos[12] = {};
    int nota;
    int matrizA[3][3] = {{3,4,5},
                         {6,7,8},
                         {9, 10, 11}};

    for (int lin = 0; lin < 3; lin++)
    {
        for(int col = 0; col < 3; col++){
            printf("%d ", matrizA[lin][col]);
        }
        printf("\n");
    }
    


    /*

    for (int i = 0; i < 12; i++)
    {
        printf("Digite a nota do %d Aluno: ", i+1);
        scanf("%d", &nota);
        notasAlunos[i] = nota;
    }

    printf("As notas dos alunos são: ");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", notasAlunos[i]);
    }
    */
    


    return 0;
}