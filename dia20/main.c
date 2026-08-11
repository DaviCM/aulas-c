#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// imports do mesmo diretório usam aspas ao invés dos sinais de maior e menor que.
#include "funcs.h" 

/* literalmente irá incluir tudo o que está no arquivo, no caso os protótipos, ao 
   código-fonte do arquivo em que include é chamado.
*/

int main(void) {
    char *tst = "Oi, eu sou uma string!";
    char *recv = malloc(strlen(tst));
    char tst_copy[50];

    print_str(recv, tst);

    printf("resultado de print_str(): \"%s\"\n", recv);

    memcpy_rw(tst_copy, tst, strlen(tst));
    printf("string copiada por memcpy_rw(): \"%s\"\n", tst_copy);

    printf("número aleatório vindo de randint(): %d\n", randint());

    free(recv);
    return 0;
}

/* não poderei usar a makefile aqui, o comando de compilação precisa ser direto.
   pois a makefile não está preparada para lidar com múltiplos inputs.

   será:
   gcc ./dia20/funcs.c ./dia20/main.c -o ./bin/dia20/main -Wall -Wextra -Wpedantic -std=c23
*/