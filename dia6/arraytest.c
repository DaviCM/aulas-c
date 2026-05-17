#include <stdio.h>

int main(void) {
    int matrix[4][4] = {
        {10, 11, 12, 13}, 
        {20, 21, 22, 23}, 
        {30, 31, 32, 33}, 
        {40, 41, 42, 43},
    };

    for (int row = 0; row < 4; row++) {
        printf("%p \n", (void*)matrix[row]);
        printf("%d \n", *matrix[row]);
    };

    return 0;
}


// Printa o endereço de memória do elemento no. 1 de cada coluna!
// E como a array é um ponteiro para o endereço do elemento no.1, a gente pode usar dereference
// para receber esse valor!

// array não é um tipo em C, é apenas semântica com tipos estáticos e ponteiros.