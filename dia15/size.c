#include <stdio.h>
#include <limits.h>

int main(void) {
    /* existem variações de int com tamanhos diferentes, em bytes, que dependem
     * do compilador, da plataforma e de definições específicas. Porém, em geral:
     * short - mínimo de 2 bytes
     * int - mínimo de 2 bytes
     * long - mínimo de 4 bytes
     * long long - mínimo de 8 bytes
     * 
     * todos podem existir em versão signed e unsigned, com a mesma regra de signed possuírem metade - 1 valores como positivos mantida.
     * short, long e long long podem ser chamados com ou sem a keyword "int";
    */

    short int s1;
    short s2;
    unsigned short s3;
    long long ll1;

    // para chars: é possível determinar se o padrão para chars no sistema é signed ou unsigned
    // se os macros de <limits.h> CHAR_MAX e UCHAR_MAX forem iguais, será unsigned.
    printf("CHAR_MAX = UCHAR_MAX: ");
    printf(CHAR_MAX == UCHAR_MAX? "true (unsigned)\n" : "false (signed)\n");

    // é relevante saber se chars são signed ou não, pois isso mudará a forma com a qual caracteres fora do padrão ASCII inicial
    // serão tratadas, pois os index após 127 poderão ou não ser acessados. Será necessário mudar o encoding em algumas situações.

    /* Nesse caso o padrão de char é signed, pois CHAR_MAX é menor que UCHAR_MAX.
     * Caso os macros fossem iguais e o máximo para char fosse UCHAR_MAX, seria impossível
     * existirem signed chars, porque seu limite é obrigatóriamente metade de unsigned -1.
    */
    return 0;
}