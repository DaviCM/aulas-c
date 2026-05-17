#include <stdio.h>

// Mesmo sem retornar nada, como as array colapsam para ponteiros
// E ponteiros são endereços de memória na stack
// O valor da array é acessado mesmo no escopo da função
// E é acessível também na main!

void arrayTimes2(int *array) {
    for (int count = 0; count < 6; count++) {
        array[count] = array[count] * 2;
    };
}


int main(void) {
    int array1[6] = {11, 12, 13, 14, 15, 16};
    
    for (int count = 0; count < 6; count++) {
        printf("array1[%d] = %d \n", count, array1[count]);
    };

    printf("\n");
    arrayTimes2(array1);

    for (int count = 0; count < 6; count++) {
        printf("array1[%d] = %d \n", count, array1[count]);
    };

    // Os valores mudaram, porque o endereço de memória onde arrayTimes2 está é o mesmo!
    return 0;
}