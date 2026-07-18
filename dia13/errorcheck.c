#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // malloc() retorna o ponteiro com a memória alocada ou NULL se ocorrer um problema na alocação.
    // o que é NULL é o ponteiro, o endereço de memória, não o valor ao qual ele se refere.
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        printf("Ocorreu um erro na alocação de memória.");
        return 1;
    };
    
    *p = 25;

    // ou:
    int *q;
    if ((q = malloc(sizeof(int) * 5)) == NULL) {
        printf("Ocorreu um erro na alocação de memória de 5 ints");
        return 1;
    };

    // uma array com 10 ints, acessível via notação de array ou de ponteiro.
    int *r = malloc(sizeof(int) * 10);
    for (int count = 0; count < 10; count++) {
        *(r + count) = 5 * count;
        printf("%d\n", r[count]);
    };

    free(p);
    free(q);
    free(r);

    return 0;
}