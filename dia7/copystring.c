#include <stdio.h>

int main(void) {
    // Não dá pra copiar a string apenas com o operador =, porque isso apenas referencia a string no ponteiro
    // lembrando: para editar a string, temos que inicializar ela com notação array para ter uma cópia local.
    // se inicializarmos como pointer ela irá para memória protegida.
    char ola[] = "Olá, meu chapa";
    printf("%s \n", ola);
    
    // Posso acessar essa com notação de array!
    char *to_ola;
    to_ola = ola;
    to_ola[0] = 'A';
    printf("String modificada: \"%s\" \n", to_ola);

    printf("A string original também mudou: \"%s\" \n", ola);
    printf("Deu ruim, ein \n");
    
    return 0;
}


