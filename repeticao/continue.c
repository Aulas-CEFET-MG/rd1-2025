#include <stdio.h>

int main(){
/*
    for(int i = 0; i<= 100; i++){
        if(i%2 == 1)
            continue;
            //break;
        printf("%2d\n", i);
    }
    printf("FIM\n");
*/
    for(int i = 0; i<5; i++)
        for(int j = 0; j<5; j++){
            printf("%d e %d\n", i, j);
        }
    return 0;
}