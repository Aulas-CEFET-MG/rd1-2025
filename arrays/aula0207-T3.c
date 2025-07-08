#include <stdio.h>

int main(){

    //int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int mA[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};

    for (int lin = 0; lin < 3; lin++)
    {
        for(int col = 0; col < 3; col++)
        {
            printf("%d ", mA[lin][col]);
        }
        printf("\n");
    }
    
    /*
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    */

    return 0;
}