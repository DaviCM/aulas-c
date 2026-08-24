#include <stdio.h>

/* desde que uma struct seja o primeiro campo de outra, um sistema de "herança"
   é possível.

   isso porque: um ponteiro para uma struct é um ponteiro para o primeiro
   byte de seu primeiro elemento.

   se esse primeiro byte for outra struct, ele poderá a acessar imediatamente
   via ->, arrow operator

   similar à ideia de herança.
*/

struct bloco {
    int id;
    char letra;
};

struct sala {
    struct bloco bloco;
    int num;
    int maquinas;
};


void print_bloco(struct bloco *bloco) {
    printf("Bloco: %c, ID: %d\n", bloco->letra, bloco->id);
}


void print_sala(struct sala *sala) {
    printf("Sala: %c-%d, Máquinas: %d\n", sala->bloco.id, sala->num, sala->maquinas);
}


int main(void) {
    // podemos, então, acessar uma struct "pai" ao criar um ponteiro para a filha.
    struct sala f04 = {
        .bloco = {
            .id = 1,
            .letra = 'F',
        },
        .num = 4,
        .maquinas = 32,
    };

    /* mesmo que seja um ponteiro para a struct sala e não bloco,
       como o ponteiro aponta para o primeiro elemento da struct e esse é 
       do tipo "struct bloco" o resultado é o mesmo!    
    */
    print_bloco(&f04);
    print_sala(&f04);

    return 0;
}