#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void chapter_1_1() {
    printf("hello, world\n");
}

void chapter_1_2() {
    int fahr, celsius;
    int lower, upper, step;

    // lower limit of temperature table
    lower = 0;
    // upper limit
    upper = 300;
    // step size
    step = 20;

    fahr = lower;

    while (fahr <= upper) {
        celsius = 5 * (fahr - 30) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void chapter_1_3() {
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}

void chapter_1_4() {
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}

void chapter_1_5_1() {
    int c;
    c = getchar();
    // ctrl+D
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

void chapter_1_5_2() {
    // count characters in input; 1st version
    long nc;
    nc = 0;

    while (getchar() != EOF) {
        ++nc;
    }
    printf("%ld\n", nc);
}

void chapter_1_5_3() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') { ++nl; }
        printf("%d\n", nl);
    }
}


/*
int main() {
//    chapter_1_1();
//    chapter_1_2();
//    chapter_1_3();
//    chapter_1_4();
//    chapter_1_5_1();
//    chapter_1_5_2();
    chapter_1_5_3();
}
 */


