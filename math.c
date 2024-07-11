#include<stdio.h>
#include "math.h"

int main() {
    int a = 10, b = 5;

    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %d\n", a, b, sub(a, b));
    printf("Product: %d * %d = %d\n", a, b, product(a, b));
    printf("Division: %d / %d = %.2f\n", a, b, division(a, b));

    return 0;
}
