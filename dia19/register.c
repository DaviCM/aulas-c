#include <stdio.h>

int main(void) {
    /* a keyword "register" significa que a variável deve ser colocada
       em algum lugar, pelo compilador, em que possa ser acessível
       o mais rápido possível, sempre que necessário.

       novamente uma keyword mais útil em compiladores para embarcados,
       e o compilador não obrigatóriamente precisa seguir. ainda assim,
       é útil ocasionalmente.
    */

    // essa variável será colocada onde pode ser prontamente acessada!
    register int fast = 15;
    for (int c = 0; c < 10; c++) {
        printf("%d\n", fast++);
    };

    // no entanto, tanta velocidade tem um custo:
    // int *p = &fast; // ERRO! não será possível acessar essa variável via pointer. 0

    register int hex[] = {0x16, 0x17, 0x18, 0x19, 0x1a};
    // int *pk = (hex + 3); // ERRO! Não é possível acessar elementos de uma array register.


    /* você pode declarar um ponteiro como restrict e const, com o efeito
       
    */
    return 0;
}
