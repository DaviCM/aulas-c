#include <stdio.h>
#include <threads.h>

int main(void) {
    static thread_local int n1 = 42;
    printf("essa variável será copiada em todas as threads, caso esse sistema rode multithread algum dia");
    printf("%d\n", n1);

    /* thread_local é exatamente isso: uma variável específica para código multithread,
       que é copiada automaticamente para todas as threads rodando o código, evitando
       race conditions e problemas para entrar na seção crítica, falhas comuns de có-
       digo multithread;

       obrigatório utilizar junto com extern ou static, no último caso significando que ela
       não será automaticamente desalocada quando o escopo acabar (static em um bloco, não
       no escopo de arquivo).
    */

    return 0;
}