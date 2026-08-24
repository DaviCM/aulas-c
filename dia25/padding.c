#include <stdio.h>

/* a especificação permite que o compilador adicione
   bytes de padding entre structs, então não é claro
   o que sizeof(struct) irá retornar. por isso, às
   vezes a soma dos tamanhos dos elementos da struct
   não será exatamente o tamanho da struct.
*/

struct bottle {
    unsigned id;
    double size;
    char *material;
    char *color;
};


int main(void) {
    struct bottle generic = {
        .id = 1,
        .size = 450.00,
        .material = "PETG",
        .color = "Azul",
    };

    printf("Tamanho de uma struct bottle: %zu\n", sizeof(struct bottle));
    printf("Tamanho da struct generic: %zu\n", sizeof(generic));

    int struct_sum = sizeof(generic.id) + sizeof(generic.size) 
    + sizeof(generic.material) + sizeof(generic.color);
    printf("Soma dos tamanhos dos campos de generic: %d\n", struct_sum);

    int data_sum = sizeof(unsigned) + sizeof(double) + sizeof(char*) + sizeof(char*);
    printf("Soma dos tamanhos dos tipos de dados: %d\n", data_sum);
    
    return 0;
}

/* nessa máquina, o resultado foi:

   Tamanho de uma struct bottle: 32
   Tamanho da struct generic: 32
   Soma dos tamanhos dos campos de generic: 28
   Soma dos tamanhos dos tipos de dados: 28

   ou seja: o tamanho de uma struct é maior do que a soma dos tamanhos de seus tipos de dados.
   então o compilador está adicionando bytes de padding entre uma struct e outra na memória.
*/