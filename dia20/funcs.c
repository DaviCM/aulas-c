#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


void print_str(char *dst, char *str) {
    sprintf(dst, "%s", str);
} 


void *memcpy_rw(void *dst, void *src, int size) {
    char *memdst = dst, *memsrc = src;

    while (size--) {
        // lembrete: irá primeiro dereferenciar e igualar, só apenas (post-increment) somar.
        *memdst++ = *memsrc++;
    };

    return memdst;
}


int randint() {
    srand(time(NULL));
    
    // macro SHRT_MAX, na verdade, é 32768!
    return rand() % SHRT_MAX;
}

// funções randômicas cuja única função é serem referenciadas na main.c
// teremos de compilar os arquivos juntos, para eles serem linkados.