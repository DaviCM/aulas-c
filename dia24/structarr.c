#include <stdio.h>

/* se passarmos uma variável aqui, o que acontece é:
   
   - o macro é resolvido no código;
   - o texto incluso, que é o nome da variável, é "char * ficado"
     pelo operador #; 

   - essa string é substituida no código, pois a chamada do macro é substituida por seu valor.
*/
#define GET_NAME(var) #var

#define HM_SIZE 8

struct pair {
    char *key;
    int value;
};

struct hashmap {
    struct pair elements[HM_SIZE];
};


int main(void) {
    //também é possível inicializar uma array de structs que é parâmetro de outra struct.
    struct hashmap hm = {
        .elements = {

            // podemos utilizar o índice da array, que referencia uma struct, para inicializar os campos dela.
            [0].key = "Tom",
            [0].value = 15,

            // ou, inicializando uma struct da forma convencional, mas por meio do elemento na array:
            [1] = {.key="Bob", .value=21},
            [3] = {.key="Davi", .value=255},
            [5] = {.key = "Maho", .value=52},
        },
    };

    printf("Pares chave-valor da struct %s: \n", GET_NAME(hm));
    for (int c = 0; c < HM_SIZE; c++) {
        printf("{ %s : %d }\n", hm.elements[c].key, hm.elements[c].value);
    };

    return 0;
}