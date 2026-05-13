#include <stdio.h>

void arrays(void) {
    float floats[6]; /* Declaração de uma array funciona passando o número de elementos que ela tem.
    os elementos da array devem todos ter o mesmo tipo.
    isso não é o último índice. essa array tem 6 elementos, e como o índice começa em 0 ela termina em 5. */

    for (int c1 = 0; c1 < 6; c1++) { // lembre de inicializar a variável no for! vars inicializadas não necessariamente são 0.
        printf("Digite o valor no. %d: ", c1 + 1);
        scanf("%f", &floats[c1]);
    };

    printf("\n");
    for (int c2 = 0; c2 < 6; c2++) {
        printf("Esse é o valor no. %d de nossa array: %f \n", c2 + 1, floats[c2]);
    };

}


int main(void) {
    arrays();

    int array1[15];
    printf("\n");
    printf("Tamanho de uma array com 15 ints: %zu \n", sizeof array1);
    printf("Tamanho de um int: %zu \n", sizeof(int));
    printf("Número de elementos da array: %d \n", (sizeof array1 / sizeof(int)));
    return 0;
}


/* lembrete: isso não é python, a função scanf não retorna o que ela leu da stdin.
nós temos que passar para ela o endereço de memória onde queremos armazenar o que ela lê
e o valor de retorno dela é apenas um int que confirma operação bem sucedida.
*/