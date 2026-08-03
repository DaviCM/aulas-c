#include <stdio.h>
#include "declar.h" // incluindo os conteúdos do arquivo declar (a variável cnt)

/* em dia19/declar.c, eu declarei uma variável: int cnt = 55;
   e ela, a princípio pertence apenas àquele arquivo.
   
   entretanto, com a keyword extern no arquivo de destino, eu consigo
   acessar essa variável.
   
   isso não funcionaria caso cnt tivesse sido declarada em declar.c
   como static, ela estaria disponível apenas no arquivo.

   extern já é o padrão para funções!
*/


int main(void) {
    // essa variável foi instanciada em declar.h, não aqui!
    extern int cnt;

    // mesmo que ela nunca tenha sido instanciada aqui, seu valor aparece.
    printf("Acessando uma variável de outro arqivo: %d\n", cnt);

    cnt = 70;
    printf("Ainda a mesma cnt de declar.h, porém alterada: %d\n", cnt);

    return 0;
}