#include <stdio.h>

int main(void) {
    /* com ponteiros para ponteiros, geralmente na forma de ponteiros para char*, 
       é necessário prestar atenção a quais níveis estão sendo demarcados como const.
    */

    char *rand = "Essa string não significa nada.";

    // seria um ponteiro para o primeiro elemento de uma array de strings.
    char **randp;
    randp++;
    (*randp)++;

    // o ponteiro para ponteiro é const, mas o ponteiro para string não.
    char **const randp2;
    // randp2++; // ERRO: tentando incrementar o ponteiro para ponteiro (const)
    (*randp2)++;

    // apenas o ponteiro para string é const, o ponteiro para ponteiro não;
    char *const *randp3;
    randp3++;
    // (*randp3)++; // ERRO: tentando ir ao próximo caractere da string, mas o char* é const.

    // o ponteiro para ponteiro e o ponteiro para string são const.
    char *const *const randp4;
    // randp3++; // ERRO
    // (*randp3)++; // ERRO

    return 0;
}