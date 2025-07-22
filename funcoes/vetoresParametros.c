#include <stdio.h>
//Forma não recomendada abaixo :(
void imprimeVetor_V2(int vetor[10]){
    for(int i = 0; i<10; i++)
        printf("%d ", vetor[i]);
}

//Forma mais reutilizável -- good idea! :)
void imprimeVetor_V1(int vetor[], int tamanho){
    for(int i = 0; i<tamanho; i++)
        printf("%d ", vetor[i]);
}
//Faça uma função para retornar o maior valor de um vetor 
//de N posições

int main(){
    
    int vet[] = {1,3,9,2,5};
    
    printf("\n\n\n");
    imprimeVetor_V1(vet, 5);
    
    printf("\n\n\n");
    imprimeVetor_V2(vet);

    return 0;
}