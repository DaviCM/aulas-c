#include <stdio.h>

int main(void) {
    /* 
    Declarando diretamente apenas alguns valores da matriz, assim como podemos fazer em arrays unidimensionais;
    
    Aqui nós não passamos chaves para cada linha, apenas passamos os valores diretamente dentro de um só
    conjunto de chaves.
    */
    int matrix[3][3] = {
        [0][0] = 1, 
        [1][1] = 2, 
        [2][2] = 3,
    };

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("(%d, %d) = %d \n", row, col, matrix[row][col]);
        };
    };

    return 0;
}