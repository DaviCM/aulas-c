#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// outra função de alocação de memória: calloc
/* o objetivo de calloc é alocar explicitamente para arrays, e ela tem uma característica importante:
 * como em malloc() + memset(), ela inicializa toda a memória alocada para 0;
 * como uma array em c, se você não definir todos os valores.
*/

// estrutura do memset: memset(início do conjunto de dados, valor desejado, n de bytes a modificar)
// será modificado partindo do endereço provido como início do conjunto de dados.

int main(void) {
    int *arr = calloc(8, sizeof(int));
    for (int c = 0; c < 6; c++) {
        *(arr + c) = 3 * c;
    };

    int *arr2 = malloc(sizeof(int) * 8);
    memset(arr2, 0, (8 * sizeof(int)));
    for (int c = 0; c < 6; c++) {
        *(arr2 + c) = 4 * c;
    };


    // 8 == sizeof(arr) / sizeof(int);
    for (int c = 0; c < 8; c++) {
        printf("%d ", arr[c]);
    };

    printf("\n");

    for (int c = 0; c < 8; c++) {
        printf("%d ", arr2[c]);
    };

    printf("\n");
    free(arr);
    free(arr2);
    return 0;
}

// se utilizássemos apenas o malloc(), os valores não seriam inicializados para nada. na verdade,
// existiria apenas lixo no lugar de qualquer coisa útil, em geral números randômicos.