#include <stdio.h>
#include <string.h>

void copyPointer(void) {
    // Não dá pra copiar a string apenas com o operador =, porque isso apenas referencia a string no ponteiro
    // lembrando: para editar a string, temos que inicializar ela com notação array para ter uma cópia local.
    // se inicializarmos como pointer ela irá para memória protegida.
    char ola[] = "Olá, meu chapa";
    printf("%s \n", ola);
    
    // Posso acessar essa com notação de array!
    char *to_ola;
    to_ola = ola; // ambos são pointers de qualquer forma, então compila
    to_ola[0] = 'A';
    printf("String modificada: \"%s\" \n", to_ola);

    printf("A string original também mudou: \"%s\" \n", ola);
    printf("Deu ruim, ein \n");
}


void copyString(void) {
    char ola[] = "Olá mais uma vez!";
    /* Instanciando o tamanho da array com o resultado da função que retorna o tamanho da string original
    Assim temos certeza de eficiência de memória! */
    char to_ola[((int) strlen(ola)) + 1]; // strlen() + 1 é o tamanho recomendado pelo manual.

    strcpy(to_ola, ola);
    printf("String original: \"%s\" \n", ola);
    printf("Cópia da string: \"%s\" \n", to_ola);

    to_ola[0] = 'A';
    printf("A cópia da string mudou: \"%s\" \n", to_ola);
    printf("Mas a original permanece igual: \"%s\" \n", ola);
}


int main(void) {
    copyPointer();
    printf("\n");
    copyString();
    return 0;
}


