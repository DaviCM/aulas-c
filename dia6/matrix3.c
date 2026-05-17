#include <stdio.h>

// em matrizes, arrays multidimensionais, é necessário passar as dimensões em forma de array, não ponteiro
// o C precisa saber disso para manipular corretamente a matriz.

// a primeira dimensão pode até ser implícita, mas o número de dimensões e o no. de elementos das demais
// têm que ser explícitos.
// também são valores válidos:
// int matrix[][3]
// int (*matrix)[3]

// o ponteiro sempre é para o primeiro elemento da primeira dimensão!

void matrixTimes2(int matrix[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            matrix[row][col] *= 2;
        };
    };
}


int main(void) {
    int matrix[3][3] = {
        {7, 8, 9}, 
        {4, 5, 6}, 
        {1, 2, 3},
    };

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("(%d, %d) = %d \n", row, col, matrix[row][col]);
        };
    };

    printf("\n");
    matrixTimes2(matrix);

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("(%d, %d) = %d \n", row, col, matrix[row][col]);
        };
    };

    return 0;
}