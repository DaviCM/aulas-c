#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Podemos também, para não declarar um tamanho finito de caracteres
   para um campo char* em uma struct, utilizar a abordagem moderna 
   para alocar dinâmicamente a string/array, utilizando malloc() e tendo cer-
   teza de que a array é o último campo da struct.
*/

// aqui, o campo name normalmente terá seu tamanho delimitado pela primeira 
// string que for alocada nele.
struct shoe {
    double price;
    int size;
    char name[];
};

struct shoe *allocate_shoe(char *name) {
    /* estamos alocando, além do tamanho padrão que a struct ocuparia,
       bits extra ao fim para a string. como a string é o último campo,
       virá por último na memória.

       possibilitará por isso a escrita além de sizeof(struct shoe), já 
       que colocamos bytes extra justamente para isso.
    */
    size_t name_len = strlen(name);
    struct shoe *newshoe = malloc((sizeof(*newshoe)) + name_len);

    memcpy(newshoe->name, name, name_len);

    /* agora, a string name está alocada até além do tamanho da struct,
       é um overflow controlado de memória.

       agora, mesmo com os padding bytes que a especificação permite para
       structs, temos certeza de que não leremos além do alocado para a
       string.

       esse comportamento é padrão e descrito pela especificação c!
    */

    return newshoe;
}


int main(void) {
    struct shoe *adidas = allocate_shoe("Adizero");
    adidas->price = 399.99;
    adidas->size = 42;

    printf("Preço do tênis: %.2f\n", adidas->price);
    printf("Tamanho do tênis: %d\n", adidas->size);
    printf("Nome do tênis: %s\n", adidas->name);

    free(adidas);
    printf("\n");

    adidas = allocate_shoe("Air Jordan");
    adidas->price = 399.99;
    adidas->size = 42;

    printf("Novo preço do tênis: %.2f\n", adidas->price);
    printf("Novo tamanho do tênis: %d\n", adidas->size);
    printf("Novo nome do tênis: %s\n", adidas->name);

    return 0;
}