#include <stdio.h>

int main(void) {
    // ISSO VAI QUEBRAR TUDO SE EXECUTADO
    
    int *pointer_random = NULL;

    printf("Esse é pointer_random: %p \n", pointer_random);
    printf("Um int tem tamanho: %zu bytes \n", sizeof(int));
    printf("O tamanho de nosso pointer é: %zu bytes \n", sizeof pointer_random);
    printf("E o valor NULL do dereference dele tem tamanho: %zu bytes \n", sizeof *pointer_random);

    *pointer_random = 42;
    printf("Deu ruim? esse é pointer_random agora: %p \n", pointer_random);
    return 0;
}

/* esse operador null indica que um ponteiro ainda não foi inicializado
mas dereferenciar um ponteiro não inicializado e instanciar outro valor é uma má ideia. */

// minha primeira segmentation fault! VAMO!     