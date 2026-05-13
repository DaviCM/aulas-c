#include <stdio.h>

int main(void) {
    // Também é possível declarar matrizes em arrays C, na forma row-first.
    // Isso significa que a primeira determinação é do número de linhas, e a segunda do número de colunas.

    int matrix[3][3] = {
        {7, 8, 9},
        {4, 5, 6},
        {1, 2, 3},
    };

    // importante lembrar: a validação é < 3, então não executará em rows = 3; rodará em rows = 0, 1 e 2. 
    for (int rows = 0; rows < 3; rows++) {
        for (int cols = 0; cols < 3; cols++) {
            printf("(%d, %d) = %d \n", rows, cols, matrix[rows][cols]);
        };
    };

    return 0;
}