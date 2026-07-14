#include <stdio.h>

/* memcpy() funciona byte por byte, e nós vimos que um byte sempre é o tamanho de um char;
 * portanto, para copiar memória nós apenas precisamos transformar cada elemento em um char*
 * e percorrer o número de elementos da array.
 */

 // lembrete: para igualar ponteiros, podemos apenas usar =. igualar um ponteiro ao endereço de memória de um ponteiro
 // é um "pointer to pointer".

void *memcpy_rw(void *dest, void *src, int elements) {
    char *cdest = dest, *csrc = src;

    for (;elements > 0; elements--) {
        *cdest++ = *csrc++;
    };

    return dest;
}

/* poderia também ser uma forma bem engenhosa:
 * while (elements--) {
 * }
 * 
 * assim, quando elements chegasse a 0 (while (0)), isso seria uma condição nula e o loop quebraria.
 */ 


int main(void) {
    float arr[] = {3.12, 3.35, 3.54, 3.14, 3.15, 2.16};
    float arrcpy[50];

    memcpy_rw(arrcpy, arr, (sizeof(float) * 6));
    *(arr + 2) = 5.6; // arr[2] = 5.6
    // assim a gente consegue notar que são endereços de memória diferentes.

    printf("array original\n");
    for (int count = 0; count < 6; count++) {
        printf("%.2f ", arr[count]);
    };

    printf("\n\n");

    printf("array copiada\n");
    for (int count = 0; count < 6; count++) {
        printf("%.2f ", arrcpy[count]);
    };

    printf("\n");
    return 0;
}