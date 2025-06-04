#include <stdio.h>

int main() {
    int x;
    float preco;

    printf("Digite a quantidade de cópias: ");
    scanf("%d", &x);

    switch (x) {
        case 0 ... 2:
            preco = 0.10;
            break;
        case 3 ... 10:
            preco = 0.08;
            break;
        case 11 ... 100:
            preco = 0.06;
            break;
        default:
            preco = 0.04;
            break;
    }

    printf("%.2f\n", x * preco);

    return 0;
}