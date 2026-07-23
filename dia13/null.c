#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    /* é possível fazer realloc sem nenhum ponteiro prévio, "realocando" apenas
     * para o ponteiro que é retornado pela função.
     * o resultado é o exato mesmo de um malloc(), e o caso de uso é puramente
     * em situações de alocação em loop.
    */ 

    int count = 1;
    int *point = NULL;
    int *spare;
    
    for (; count < 10; count++) {
        spare = realloc(point, (sizeof(int) * count));
        if (spare == NULL) {
            free(point);
            return 1;
        };

        point = spare;
        *(point + (count - 1)) = count;

        printf("count: %d\n", count);

        printf("array: ");
        for (int pos = 0; pos < count; pos++) {
            printf("%d ", *(point + pos));
        };
        printf("\n");

        printf("tamanho do buffer: %zu\n\n", (sizeof(*point) * count));
    };

    spare = realloc(point, count);
    if (spare == NULL) {
        free(point);
        return 1;
    };

    point = spare;
    printf("\n%p\n", (void *)point);

    free(point);
    return 0;
}

/* a gente não precisa de um caso especial para o primeiro malloc(), podemos simplesmente alocar
 * para um ponteiro que era nulo no início. facilita a vida.
 */