#include <stdio.h>
#include <stdbool.h> // Booleanos não existem por padrão no C puro, mas o módulo stdbool os adiciona.
// Em C23, o tipo bool passou a existir nativamente no C; com valores true e false

void bools(void) {
    bool isActive = true;

    if (isActive == 1) {
        printf("Deu bão \n");
    }
    else {
        printf("Num deu bom não \n");
    };
};

int main(void) {
    bools();

    int integer = 3;
    float floating_point = 3.14;
    char* string = "Olá, meu amigo"; // o tipo string não existe no C!

    printf("%i é um int, %f é um float \n", integer, floating_point); // Códigos %s indicam o tipo da variável que queremos mostrar
    printf("E \"%s\" é uma string, ou um ponteiro para um char! \n", string);
    return 0;
};

// Comentários de linha

/*
Comentários
multi
linha
*/
