#include <stdio.h>

int main(void) {
    int arr[] = {12, 23, 34, 45, 56};
    int *arr3 = &arr[3];

    printf("%d\n",(arr[3] == *arr3));
    printf("%d\n", arr[3]);

    printf("%d\n",(arr[3] == *(arr + 3)));
    printf("%d\n", *arr3);

    printf("%d\n", *arr);

    return 0;
}

/* logo:
 * x[y] == *(x + y), em que x é um ponteiro/array e y é um int.
 * pois esse 'y' será interpretado como o número de elementos com x valor que devem ser pulados
 * na memória, pois arrays são apenas ponteiros indicando endereços de memória.
 */

// a notação de ponteiro e de array funcionará em ambos.

/* a[4] pode ser acessado com *(a + 4), e *b pode ser acessado como b[0].
 * ^ porque se trata de um ponteiro para o primeiro elemento!
 * 
 */