#include <stdio.h>

int main(void) {
    /* qualifiadores de tipo: significam que nós podemos dar descrições a mais
       para variáveis, para que o compilador as trate de forma específica ou
       otimize a geração do assembly.
    */

    // const: essa variável não pode ser modificada, jamais.
    // tentar modificar uma const resultará num compilador raivoso.
    const unsigned cnt = 6;
    printf("Valor constante: %u\n", cnt);

    // cnt = 7; // ERRO!

    // permitido, não modifica a variável.
    printf("valor constante + 10: %u\n", cnt + 10);

    /* const também pode aparecer em parâmetros de funções, o que significa
       que os argumentos passados não podem ser alterados dentro da função
       e nem convertidos para um tipo que não seja const.
    */

    const double fn = 45.2;

    // permitido, a conversão descarta a parte decimal mas o novo valor, como foi inicializado agora, é um novo const.
    const int in = fn;
    printf("double constante igualado a int constante: %.2f %.d\n", fn, in);

    printf("\n");

    int example = 55;
    // const com ponteiros é uma história complicada. há duas declarações possíveis:


    // significa que o valor apontado (dereference) é constante, mas o ponteiro pode ser alterado.
    const int *pt = &example;
    printf("pt: %p %d\n", (void*)pt, *pt);

    // completamente permitido, irá para o endereço de memória 4 bytes à frente.
    pt++;
    printf("pt[1]: %p %d\n", (void*)pt, *pt);
    
    pt--;
    printf("pt[0] inalterado, mesmo após pt ter aumentado e depois diminuído: %p %d\n", (void*)pt, *pt);

    // *pt = 56; // ERRO! o valor que ele dereferencia é constante.

    // isso funciona pois o valor guardado está e, *(pt + 0), pt[0], e permanece lá mesmo que o ponteiro avance. se dermos um --p, voltaremos a ve-lo.


    printf("\n");


    // significa que o ponteiro é constante, mas o valor pode ser alterado.
    int *const pt2 = &example;
    printf("pt2: %p %d\n", (void*)pt2, *pt2);

    // completamente permitido, dereferencia o ponteiro e altera o valor que ele aponta. O endereço segue.
    *pt2 = 57;

    printf("pt2 inalterado, mesmo com valor que aponta mudando: %p %d\n", (void*)pt2, *pt2);
    // pt2 = &in; // ERRO! o endereço de memória que esse ponteiro represnta não pode mudar.



    // e as declarações podem ser unidas:
    const int *const pt3 = &example;

    // aqui, nem o ponteiro e nem o valor que ele aponta podem ser alterados.
    // pt3 e *pt3 são constantes.

    return 0;
}