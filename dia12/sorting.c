#include <stdio.h>
#include <stdlib.h>

/*
 * typedef struct {
 *    int id;
 *    char *nome;
 * } user;
 */

struct user {
    int id;
    char *nome;
};


int compare(const void *e1, const void *e2) {
    const struct user *s1 = e1, *s2 = e2;

    if (s1->id < s2->id) {
        return -1;
    }
    else if (s1->id > s2->id) {
        return 1;
    }
    else {
        return 0;
    };
}


int main(void) {
    struct user users[5] = {
        {.id = 6, .nome = "Davi"},
        {.id = 8, .nome = "Nunes Dev"},
        {.id = 1, .nome = "João Bahia"},
        {.id = 5, .nome = "Nikita Verstappen"},
        {.id = 2, .nome = "Gabriel"}
    };

    qsort(users, 5, sizeof(struct user), compare);

    for (int count = 0; count < 5; count++) {
        printf("usuário: %s\nid: %d\n\n", users[count].nome, users[count].id);
    };
    
    return 0;
}