#include <stdio.h>

void ex_1_1() {
    printf("hello, world\n");
}

void ex_1_2() {
//    printf("hello, world\c");
}

void ex_1_3() {
    /* print Fahrenheit-Celsius table
     * for fahr = 0, 20, ..., 300
     * floating-point version
     */

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int main(void) {
}