#include <stdio.h>

// Declarar strings na forma de ponteiros e na forma de arrays tem algumas diferenças.
// Declarar como ponteiro significa que não poderemos alterar seus elementos na execução
// Por causa do espaço de memória em que o compilador coloca ponteiros.



void stringManip(char *string) {
    printf("String: %s \n", string);
    string[0] = 'C';
    printf("String: %s \n", string);
}


int main(void) {
    // Mesmo declarando o char* com sintaxe de pointer, ele ainda pode ser acessado pelos métodos de array!
    char *str0 = "Bom dia de novo!";

    for (int count = 0; count < 16; count++) {
        printf("%c", str0[count]);
    };
    printf("\n");

    // Isso certamente pode causar crashes / segfaults!
    // Aqui causa uma segfault.
    // char *str1 = "Bom dia meu povo!";
    // stringManip(str1);

    // Mas isso aqui é de boa:
    char str2[] = "Bom dia de novo!";
    stringManip(str2);

    // Se instanciarmos a string como array, o compilador o colocará num espaço de memória manipulável.

    return 0;
}

// Ou seja: strings declaradas em notaçaõ de array não são string literals, mas cópias mutáveis de strings.
// String literals são imutáveis