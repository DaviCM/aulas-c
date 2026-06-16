#include <stdio.h>

// basicamente uma formad e criar aliases para tipos existentes, por questão de escopo ou organização.
typedef float loucura;

/* Algo comum é utilizar o typedef no escopo global, para todas as funções usufruirem do tipo.
 * Mas ele segue regras de scoping normais, como arrays e decay to pointer. Na função, continuará
 * sendo criada uma cópia do argumento passado à função.
 */


// Um uso normal é com structs, para não precisar digitar "struct" toda hora ao instanciar uma:
struct user {
    int id;
    char *nome;
    double balanco;
};

typedef struct user user;

typedef struct user2 {
    int id2;
    char *nome2;
    double balanco2;
} user2;
// mesma coisa, porém unindo as expressões de definição da struct e typedef numa só.

void structs(void) {
    struct user user1 = {
        .id = 5,
        .nome = "User Um",
        .balanco = 56.23,
    };

    user user2 = {
        .id = 7,
        .nome = "User Dois",
        .balanco = 21.12,
    };

    // é a mesma coisa, pois criamos um alias com typedef!
}


int main(void) {
    loucura pi = 3.14159;
    printf("%f \n", pi);
    structs();
    return 0;
}