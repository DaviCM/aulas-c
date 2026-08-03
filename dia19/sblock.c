#include <stdio.h>

int count(void) {
    /* em escopo de bloco, como uma função, static significa que uma variável não deve
       ser dealocada quando seu escopo termina, ela continua na memória e ainda pode
       ser manipulada. ela vive enquanto o programa estiver em execução.

       portanto, só é inicializada uma vez, e por padrão é inicializada para 0.
       toda vez que uma static em escopo de bloco for chamada, o mesmo valor será
       acessado ao invés de inicializar outro.
    */

    static int cnt;
    return cnt += 1;
}


// agora, em escopo de arquivo o comportamento de static é diferente.

/* já sabemos que variáveis em escopo de arquivo, por padrão, são
   acessíveis em todas as chamadas de função ao longo do arquivo. ao
   invés disso, static no escopo de arquivo significa que essa variável
   não é visível fora do escopo desse arquivo, útil em #includes.

   quase que uma "global", mas específica do arquivo presente.
*/

// essa variável não seria visível caso incluíssemos esse arquivo em outro lugar.
static float e = 2.71;


int main(void) {
    /* especificadores de classe de armazenamento
    
       informam ao compilador como tratar variáveis específicas, geralmente
       tendo a ver com o escopo no qual se encontram.
    */

    // auto: singifica que a variável tem duração automática, 
    // vive no escopo em que foi criada e morre ao fim dele.
    auto int n1 = 15;


    /* static: essa keyword tem dois sentidos, a depende do escopo: pode ser
       um bloco ou o escopo do arquivo, que é global, e significa coisas
       distintas.
    */

    for (int c = 0; c < 6; c++) {
        printf("static int cnt (iteração %d): %d\n", c, count());
    };

    return 0;
}