#include <stdio.h>

/* Questão 3)
Na expressão float *pont; qual elemento é do tipo float?
a) A variável pont.
b) O endereço de pont.
c) A variável apontada por pont.
d) Nenhuma das anteriores.
*/

/*RESPOSTA

Na declaração float *pont; estamos dizendo que pont é um ponteiro para uma variável do tipo float. 
Ou seja, o conteúdo apontado por pont (a variável para a qual ele aponta) é do tipo float. 
O ponteiro em si (pont) é do tipo “ponteiro para float”, mas não é um float diretamente.
*/

/*Questão 4) 
Assumindo que o endereço da variável num foi atribuído ao ponteiro pnum, 
quais das seguintes expressões são verdadeiras?
a) num == &pnum
b) num == *pnum
c) pnum == *num
d) pnum == &num
*/

/* RESPOSTA (b) e (d)
- a) está incorreta porque num é o valor e &pnum é o endereço do ponteiro
- b) *pnum é o valor de num, então num == *pnum
- c) alternativa c está incorreta porque *num não faz sentido: num não é um ponteiro.
- d) Se o ponteiro pnum recebeu o endereço da variável num, então pnum aponta para o endereço de num
*/

/* Questão 5)
Qual instrução deve ser adicionada ao programa abaixo para que ele funcione corretamente?

main() {
    int j, *pj;
    *pj = 3;
}*/

/*RESPOSTA
É necessário inicializar o ponteiro pj com o endereço da variável j antes de usá-lo. 
A instrução correta a ser adicionada é: pj = &j;
*/

/*Questão 6)
Assumindo que o endereço da variável x foi atribuído ao ponteiro px, 
escreva uma expressão que não use x diretamente e que divida o valor de x por 5.
*/

/*RESPOSTA
*px = *px / 5;

Como px aponta para x, a expressão *px acessa o valor de x. 
Ao fazer *px = *px / 5; estamos modificando diretamente o valor de x sem usar o nome da variável. 
Essa é uma forma comum de manipular dados via ponteiros em C.
*/

/*Questão 7)
Qual será a saída do seguinte programa?
main() {
    int i = 5, *p = &i;
    printf("%u %d %d %d %d \n", p, *p+2, **&p, 3**p, **&p+4);
}
*/

/*RESPOSTA 
[ENDEREÇO] 7 5 15 9

- p: imprime o valor de p (o endereço de i). O formato %u mostra o endereço como um número inteiro sem sinal
- *p + 2: *p é o valor de i, que é 5. Então 5 + 2 = 7
- **&p: &p é o endereço de p, e *(&p) é p, então **&p é *p, que é i, ou seja, 5
- 3 * *p: *p é 5, então 3 * 5 = 15
- **&p + 4: novamente, **&p é 5, então 5 + 4 = 9

OBS: Saber que **&p equivale a *p é uma sacada importante. Os operadores de derreferência (*) e de "endereço de" (&) são inversos um do outro. 
Quando aparecem juntos, eles se anulam.
*/

/*Questão 8)
Considere a seguinte sequência de instruções em um programa C:
int *pti;
int i = 10;
pti = &i;
Qual das afirmativas abaixo é falsa?
a) pti armazena o endereço de i
b) *pti é igual a 10
c) Ao se executar *pti = 20;, i passará a ter o valor 20
d) Ao se alterar o valor de i, *pti será modificado
e) pti é igual a 10
*/

/*RESPOSTA (e)
a. pti é um ponteiro que armazena o endereço da variável i, não o valor dela.
b. *pti acessa o valor de i, então *pti == 10 é verdadeiro.
c. Se fizermos *pti = 20;, estamos alterando o valor de i via ponteiro — isso também é verdadeiro.
d. Se alterarmos diretamente i, como i = 30;, então *pti também refletirá esse novo valor — verdadeiro.
e. Dizer que pti == 10 é falso, porque pti guarda um endereço de memória, não o valor 10.
*/

/*Questão 9)
Faça uma única função que converte um valor em metros para: jardas; pés; e polegadas. 
Use a função no método main().
 Utilize o protótipo abaixo: void dist(float metros, float *jardas, float *pes, float *polegadas);
1 metro é igual a aproximadamente 1,094 jardas, 3,281 pés, e 39,3701 polegadas.
*/

/*RESPOSTA
// Função de conversão
void dist(float metros, float *jardas, float *pes, float *polegadas) {
    *jardas = metros * 1.094;
    *pes = metros * 3.281;
    *polegadas = metros * 39.3701;
}
int main() {
    float metros;
    float jardas, pes, polegadas;

    // Entrada do usuário
    printf("Digite o valor em metros: ");
    scanf("%f", &metros);

    // Chamada da função de conversão
    dist(metros, &jardas, &pes, &polegadas);

    // Exibição dos resultados
    printf("\n%.2f metros equivalem a:\n", metros);
    printf("→ %.2f jardas\n", jardas);
    printf("→ %.2f pés\n", pes);
    printf("→ %.2f polegadas\n", polegadas);

    return 0;
}
*/

/*Questão 10)
Crie	uma	função	que	receba	como	parâmetros	dois	vetores	de	inteiros: x1	e	x2 e	as	
suas	respectivas	quantidades	de	elementos:	n1	e	n2.	A	função	deverá	retornar	um	
ponteiro	para	um	terceiro	vetor,	x3,	alocado	dinamicamente,	contendo	a	
intersecção de	x1	e	x2 e	usar	o	ponteiro	qtd	para	retornar	o	tamanho	de	x3.
Sendo	x1	=	{1,	3,	5,	6,	7}	e	x2	=	{1,	3,	4,	6,	8},	x3	irá	conter	{1,	3,	6}.
Assinatura	da	função:
int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd);
*/

/*RESPOSTA

- A variável limite é usada para definir o tamanho máximo possível da interseção
- A verificação de duplicatas evita que o vetor x3 tenha elementos repetidos

#include <stdio.h>
#include <stdlib.h>

int* interseccao(int *x1, int *x2, int n1, int n2, int *qtd) {
    int limite;
    if (n1 < n2) {
        limite = n1;
    } else {
        limite = n2;
    }

    int *x3 = (int *)malloc(sizeof(int) * limite);
    int k = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (x1[i] == x2[j]) {
                // Verifica se já está em x3
                int repetido = 0;
                for (int m = 0; m < k; m++) {
                    if (x3[m] == x1[i]) {
                        repetido = 1;
                        break;
                    }
                }
                if (repetido == 0) {
                    x3[k] = x1[i];
                    k++;
                }
            }
        }
    }

    *qtd = k;
    return x3;
}
*/