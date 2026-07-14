#include <stdio.h>

int main(void) {
    int arr[] = {1, 3, 5, 7, 11, 13, 17};

    for(int *p = &arr[0], count = 0; *p != 17; p++, count++) {
        printf("Notação de array\n");
        printf("valor: %d\n", arr[count]);
        printf("posição: %d\n", count);

        printf("\n");

        printf("Notação de ponteiro\n");
        printf("valor: %d\n", *p);
        printf("posição: %ld\n", p - arr);

        printf("\n");
    }
    
    return 0;
}