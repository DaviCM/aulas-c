#include <stdio.h>

void sumptr(void) {
    int arr[] = {4, 5, 12, 14, 15, 19};
    int *parr;

    parr = &arr[0];
    // Fazendo o cast para void* apenas para visualizar os endereços.
    printf("endereço do 1o elemento: %p\n", (void*)parr);
    printf("elemento 1: %d\n", *parr);

    printf("\n");

    parr += 1;
    printf("endereço do 2o elemento: %p\n", (void*)parr);
    printf("elemento 2: %d\n", *parr);
}


void forptr(void) {
    int arr[6] = {1, 2, [3] = 5, 7, 11};
    int *parr;

    parr = arr;
    for (int count = 0; count < 6; count++){
        printf("elemento no.%d: %d\n", (count + 1), *(parr + count));
    };
}


int main(void) {
    sumptr();
    printf("\n");
    forptr();
    return 0;
}

/* explicação: C sabe o tamanho de um int na memória e identifica um ponteiro para um int,
 * então ele pula o tamanho exato de bytes na memória para ir ao próximo int.
 * nessa máquina, serão 8 bytes.
 * 
 * logo: 
 * 1 == valor de 1 x o tamanho do tipo de dado na memória, 2 == valor de 2 x tamanho do tipo etc.
 */

 // ele sabe que tem que pular sizeof(int) bytes porque é um ponteiro para um int.