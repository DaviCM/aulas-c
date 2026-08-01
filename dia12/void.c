#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A grande diferença entre arrays e pointers é que você pode apontar um ponteiro
 * para outro endereço de memória qualquer, e com arrays você não pode igualar a array inteira a outra coisa,
 * apenas elementos dela. para copiar uma array em um espaço de memória diferente do original,
 * que seria acessado por meio de um ponteiro, é necessário usar memcpy() da string.h
 */


/* um void* é um pointer normal, mas não sabemos o tipo dele.
 * assim, a matemática de ponteiros não funciona, porque não sabemos o tipo de dado que ele está apontando
 * e assim, não sabemos seu tamanho.
 * 
 * no entanto, um void* pode ser convertido para um ponteiro de qualquer tipo, 
 * pode apontar para um endereço em que qualquer tipo de variável esteja armazenado.
 */

// lembrete: um char* sempre é um byte!

int main(void) {
    // void pointers:

    char *src = "Opa, bão?";
    char dest[50];

    memcpy(dest, src, 10);
    printf("Essa é a str copiada: \"%s\"\n", dest);
    return 0;
}

// memcpy funciona byte por byte, ela não sabe o tamanho dos tipos de dados como ponteiros
// em pointer aritmethics.