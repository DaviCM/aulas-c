#include <stdio.h>
#include <stdlib.h>

// obs: realloc trabalha byte por byte!

int main(void) {
    int *ints;
    ints = calloc(10, sizeof(*ints));
    for (int count = 0; count < 10; count++) {
        *(ints + count) = 5 * count;
    };

    printf("\n");

    int *testptr = realloc(ints, 20 * sizeof(*ints));
    if (testptr == NULL) {
        printf("Ocorreu um erro na realocação de memória.");
        return 1;
    };

    ints = testptr;
    for (int count = 10; count < 20; count++) {
        *(ints + count) = 10 * count;
    };

    for (int count = 0; count < 20; count++) {
        printf("%d ", ints[count]);
        printf("%p\n", (void *)(ints + count));
    };

    free(ints);
    return 0;
}