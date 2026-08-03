#include <stdio.h>

int main(void) {
    /* outra keyword para o compilador monitorar o endereço de memória, mas essa
       é muito próximo do hardware. ela diz que uma variável pode ter seu valor
       alterado na memória repentinamente, e o compilador deve verifica-la a todo
       momento para evitar caching, race conditions e outros fatores prejudiciais.

       resumidamente, é uma forma de evitar que o compilador tente otimizar uma
       seção crítica do código, quando não se tem certeza de que a memória está
       segura.
    */
    volatile unsigned ram = 0xFFFF;
    return 0;
}