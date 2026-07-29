#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* strtol() e suas irmãs possuem outra caraterística:
       o uso de ponteiros para ponteiros.
       As funções inteiras, que suportam também hex e octal, recebem três argumentos:

       - ponteiro para o início da string

       - ponteiro para o endereço (ponteiro) do final da string, 
         onde o NUL terminator será guardado

       - base do número.

       As de ponto flutuante, por não suportarem hex e octal, não recebem base.
    */
    
    char *longlit = "1893243";

    // será passado, na forma de um ponteiro para ponteiro, 
    // para armazenar o primeiro caractere após a leitura.
    // é um tratamento de erros, pois permite ver se parte da string não foi convertida;
    char *endptr;

    long lit;

    lit = strtol(longlit, &endptr, 10);
    printf("String convertida para long: %ld\n", lit);
    printf("A string foi formatada até esse byte: %c\n", *endptr);
    printf("Correspondente a esse int: %d\n", *endptr);
    printf("Disclaimer: ASCII 0 == \\0\n");

    return 0;
}