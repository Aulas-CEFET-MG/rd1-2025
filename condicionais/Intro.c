#include <stdio.h>

int main() {
    int x;
    
    printf("Digite a quantidade de cópias: ");
    scanf("%d", &x);
    
    if (x <= 2) {
        printf("%.2f\n", x * 0.10);
    } else if (x > 2 && x <= 10) {
        printf("%.2f\n", x * 0.08);
    } else if (x > 10 && x <= 100) {
        printf("%.2f\n", x * 0.06);
    } else {
        printf("%.2f\n", x * 0.04);
    }

    return 0;
}