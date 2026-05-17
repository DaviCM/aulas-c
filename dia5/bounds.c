#include <stdio.h>

// diretiva do preprocessador que instancia o valor 42 como constante no 'nome' VERDADE
#define VERDADE 42
#define VETTEL 5

void halfDefined(void) {
    int driverNums[] = {VETTEL, VETTEL + 1, [VETTEL + 3]=11, 42}; // podemos deixar o número de elementos fixo ao indexa-los diretamente.
    for (long unsigned counter = 0; counter < (sizeof driverNums / sizeof(int)); counter++) {
        printf("%d ", driverNums[counter]);
    };
}


int main(void) {
    halfDefined();
    printf("\n");

    // em C, você pode tentar acessar endereços de memória de arrays não indexados. O comportamento é indefinido:
    int arrayTest[5] = {14, 15, 16, 17, 18};
    for (int c = 0; c < 10; c++) {
        printf("Int: %d \n", arrayTest[c]);
    };
    return 0;
}
