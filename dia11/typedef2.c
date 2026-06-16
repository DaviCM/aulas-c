#include <stdio.h>

// Isso é uma struct anônima: com typedef podemos declarar uma struct sem dar a ela imediatamente um nome!
typedef struct {
    int id;
    char *nome;
    float balanco;
    char *criado_em;
} user;


void structs(void) {
    // então isso aqui é permitido: usamos o "tipo" que criamos com o typedef
    user user1 = {
        .id = 4,
        .nome = "Roger",
        .balanco = 4.55,
        .criado_em = "23/07/2039",
    };

    // já isso aqui levanta um erro, porque nós nunca declaramos struct user:
    /* struct user user1 = {
        .id = 5,
    }; 
    */
    printf("id: %d \n", user1.id);
    printf("nome: %s \n", user1.nome);
    printf("balanço: %f \n", user1.balanco);
    printf("criado_em: %s \n", user1.criado_em);
    printf("\n");
}

// também podemos usar typedef como um alias para tipos que vamos precisar trocar no futuro:
typedef long long verylong;
// se um dia eu precisar que eles sejam apenas long ao invés de long long, vai ser fácil.

void ints(void) {
    verylong x = 45346;
    printf("%lld \n", x);
    printf("%zu \n", sizeof(verylong));
    printf("%zu \n", sizeof(long long));
    printf("\n");
}


// e também tem como criar um tipo que é um ponteiro:
typedef int* intptr;
// apesar de que não é muito recomendado, pode te dar alguns contratempos.

void ptrs(void) {
    int y = 15;
    intptr to_y = &y;
    
    printf("%p \n", (void*)to_y);
    printf("%d \n", *to_y);
    printf("\n");
}

// a sintaxe é estranha, mas tem como utilizar typedef para criar um alias para uma array específica:
typedef float quatrofloats[4];
// a declaração do tipo não vai explicitar que isso é uma array, no entanto.

void array(void) {
    quatrofloats a = {9.2312, 4.543252, 94.42, 5.121321};

    for (int count = 0; count < 4; count++) {
        printf("%f \n", a[count]);
    };
    printf("\n");
}


int main(void) {
    structs();
    ints();
    ptrs();
    array();
    return 0;
}

/* lembrete: o melhor é seguir com lower_snake_case em C. É o padrão
 * K&R, é o que o Beej usa no guia e é o padrão geral, incluindo
 * o kernel Linux. Manter ele provavelmente é boa ideia.
 */