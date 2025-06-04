#include <stdio.h> // aqui tem outro comentario
//Esta é a biblioteca padraõ do C

/* Nossa, como eu gosto de comentários no código!!!!

:)

*/

int main() {
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    
    // Cálculo das expressões
    printf("a * b / c = %d\n", a * b / c);
    printf("a * b %% c + 1 = %d\n", a * b % c + 1);
    printf("++a * b - c-- = %d\n", (++a * b - c--)); // a incrementado antes da operação e c decrementado depois
    printf("7 - - b * ++d = %d\n", 7 - - b * ++d); // d incrementado antes da operação
    printf("a / b / c = %d\n", a / b / c);
    printf("7 + c * --d / e = %d\n", 7 + c * --d / e); // d decrementado antes da operação
    printf("2 * a %% - b + c + 1 = %d\n", 2 * a % - b + c + 1);
    printf("39 / - ++e - + 29 %% c = %d\n", 39 / - ++e - + 29 % c); // e incrementado antes da operação
    printf("7 - + ++a %% (3 + b) = %d\n", 7 - + ++a % (3 + b)); // a incrementado antes da operação

    return 0;
}