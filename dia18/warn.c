#include <stdio.h>

int main(void) {

    // isso aqui irá levantar a ira do compilador:
    const int c = 64;
    int *pt = &c;
    printf("const int puro: %d\n", c);

    /* erro: a declaração de constante será descartada, pois ele não pode garantir a constancia
       do valor caso seja manipulado pelo ponteiro.
    */

    /* o que acontece é: um tipo e um tipo como constante são tratados de forma diferente,
       porque o compilador tem que garantir que vars marcadas com const não sejam editadas
       sob nenhuma hipótese.

       assim, o compilador não deixa, pois sabe que int* podem ser incrementados no dereference.

       como o ponteiro aponta para o mesmo endereço da variável, dereferenciar ele irá alterar
       ambos os valores.
    */

    *pt = 48;
    printf("const int após ser dereferenciado num ponteiro: %d\n", c);
    
    // o comportamento é indefinido. não sabemos se o resultado será  48 ou 64.
    return 0;
}