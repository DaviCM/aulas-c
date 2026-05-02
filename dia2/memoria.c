#include <stdio.h>
#include <stdlib.h>

void memoria(void) {
    char* ola = malloc(4); /* malloc: memory allocation
    aloca um número x de bytes para o endereço de memória da variável */

    ola[0] = 'O';
    ola[1] = 'l';
    ola[2] = 'a'; // Aspas simples indicam um caractere, aspas duplas indicam um ponteiro para o tipo char
    ola[3] = '\0'; // Toda string termina implicitamente com esse caractere
    printf("Essa é nossa string: \"%s\" \n", ola);
    printf("Aqui é onde nossa string está: %p \n", &ola);

    free(ola); // Liberando o espaço de memória que alocamos para olá.
    printf("Agora nossa string é: \"%s\". Sumiu! \n", ola);
};


int main(void) {
    memoria();
    return 0;
};
