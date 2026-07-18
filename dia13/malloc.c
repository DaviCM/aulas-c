#include <stdio.h>
#include <stdlib.h>

/* conhecimento padrão de C: programadores dizem que variáveis automáticas, com alocação definida na inicialização dela,
 * a atribuição do valor, são colocadas na stack, e variáveis com memória alocada manualmente, no código, são colocadas
 * no heap. A especificação, no entanto, não requer isso.
*/


int main(void) {
    // alocando manualmente memória para um int
    int *num1 = malloc(sizeof(int));
    *num1 = 25;

    printf("num1: %d\n", *num1);
    free(num1);

    // valor aleatório: como a memória foi liberada mas o pointer ainda existe, qualquer valor que estiver lá no momento será o mostrado.
    printf("num1: %d\n", *num1); 
    return 0;
}


/* obs:
 * sizeof funciona com qualquer expressão que represente um valor.
 * int *p = malloc(sizeof(*p)); é perfeitamente válido, porque o compilador
 * sabe que *p é um int, pois p é um ponteiro para um int.
*/