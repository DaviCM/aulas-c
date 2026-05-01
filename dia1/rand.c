#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int aleatorio;

    do {
        aleatorio = (rand() % 100); // o módulo da divisão é um filtro para o limite máximo que o número pode ter
        printf("Random da vez: %d \n", aleatorio);
    } while (aleatorio != 55);

    printf("Nosso temido 55 chegou! \n");

    for (;;) {
    }; 
    // for loop infinito!
    return 0;
};
