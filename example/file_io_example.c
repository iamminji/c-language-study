// https://www.programiz.com/c-programming/c-file-input-output

#include <stdio.h>
#include <stdlib.h>

void write_to_text_file() {
    int num;
    FILE *fptr;

    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("../tester/test_text.txt", "w");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    fclose(fptr);
}

void read_from_text_file() {
    int num;
    FILE *fptr;

    if ((fptr = fopen("../tester/test_text.txt", "r")) == NULL) {
        printf("Error! opening file");

        // Program exist if the file pointer returns NULL
        exit(1);
    }

    fscanf(fptr, "%d", &num);

    printf("Value of n=%d\n", num);
    fclose(fptr);
}

struct threeNum {
    int n1, n2, n3;
};

void write_to_binary_file() {

    int n;
    struct threeNum num;
    FILE *fptr;

    if ((fptr = fopen("../tester/test_bin.txt", "wb")) == NULL) {
        printf("Error! opening file!");
        exit(1);
    }

    for (n = 1; n < 5; ++n) {
        num.n1 = n;
        num.n2 = 5 * n;
        num.n3 = 5 * n + 1;

        // fwrite(addressData, sizeData, numbersData, pointerToFile);
        fwrite(&num, sizeof(struct threeNum), 1, fptr);
    }
    fclose(fptr);
}

void read_from_binary_file() {
    int n;
    struct threeNum num;
    FILE *fptr;

    if ((fptr = fopen("../tester/test_bin.txt", "rb")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    for (n = 1; n < 5; ++n) {
        // fread(addressData, sizeData, numbersData, pointerToFile);
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2:%d\tn3: %d\n", num.n1, num.n2, num.n3);
    }

    fclose(fptr);
}

void fseek_example() {
    int n;
    struct threeNum num;
    FILE *fptr;

    if ((fptr = fopen("../tester/test_bin.txt", "rb")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    // fseek(FILE * stream, long int offset, int whence);
    fseek(fptr, -sizeof(struct threeNum), SEEK_END);

    for (n = 1; n < 5; ++n) {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2:%d\tn3: %d\n", num.n1, num.n2, num.n3);
        fseek(fptr, -2*sizeof(struct threeNum), SEEK_CUR);
    }
    fclose(fptr);

}

int main() {
    fseek_example();
    return 0;
}