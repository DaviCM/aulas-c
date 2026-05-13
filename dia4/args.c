#include <stdio.h>

// o operador address-of, ou endereço-de, retorna o endereço na memória em que o primerio byte de uma variável está guardado.
// ele é: &

void somar(int *n) {
    ++*n; // pre-increment na dereferência do ponteiro, irá incrementar o valor cujo endereço o ponteiro aponta.
}


int main(void) {
    int num1 = 1;
    int *to_num1 = &num1;

    printf("Nosso endereço de memória é: %p \n", to_num1);
    printf("Nós começamos com: %d \n", num1);

    for (num1; num1 < 50 ;) {
        somar(to_num1);
        printf("O valor de num1 é: %d \n", num1);
        // chamamos a função, que espera um ponteiro, com nosso ponteiro que aponta para o endereço de memória de num1
        // isso significa que estamos alterando a variável sem jamais colocar o valor original no escopo da função!
    };
    return 0;
}

// podemos também passar o endereço de memória diretamente com o endereço-de, o retorno dele

/* em geral, se você quiser que uma função modifique um parâmetro que você passou como argumento no escopo global, 
você vai ter que fazer isso na forma de ponteiro com dereference. 
*/