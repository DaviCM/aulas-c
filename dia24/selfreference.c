#include <stdio.h>
#include <stdlib.h>

struct player {
    int id;
    char *username;

    /* isso é um atributo de struct que é um ponteiro para uma struct
       do mesmo tipo!

       isso é possível porque, apesar de o compilador não saber como
       a struct inteira se comporta ainda, ele pode alocar memória para
       ponteiros; em geral eles têm tamanhos similares, então cast para 
       void* deles não trará problemas. 
    */
    struct player *next;
};


int main(void) {
    // e podemos, num for loop, alocar memória e valores para eles:
    struct player *head = malloc(sizeof(*head));
    struct player *current = head;

    for (int c = 0; c < 8; c++) {
        current->id = c + 1;
        current->username = "randplayer";

        if (c == 8) {
            current->next = NULL;
        }
        else {
            current->next = malloc(sizeof(*current));
            current = current->next;
        };
    };

    printf("Usuários \"randplayer\" cadastrados\n");
    for (; head->next != NULL; head = head->next) {
        printf("id: %d\n", head->id);
        printf("username: %s\n", head->username);
        printf("endereço atual: %p\n", (void*)head);
        printf("endereço do próximo: %p\n", (void*)head->next);
        
        printf("\n");
    };

    free(head->next);
    free(head);

    return 0;
}