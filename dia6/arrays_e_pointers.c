#include <stdio.h>

// Em C, arrays em muitos contextos são transformadas em ponteiros para o primeiro endereço da array
// Por exemplo, quando são passadas como argumentos em funções com parâmetros do tipo array.

void times2(float *array, int len);

void times3(float array[], int len);

void times4(float array[5], int len);

int main(void) {
    float array1[5] = {1.23, 5.92, 2.46, 6.24, 8.01};
    float *toArray1;

    // um ponteiro para o primeiro elemento de uma array é muito comum
    // tão comum que existe um atalho para isso no C:

    toArray1 = &array1[0];
    toArray1 = array1;

    // eles são a mesma coisa!

    printf("Ponteiro para o primeiro elemento da array: %p \n", (void*)toArray1);
    printf("Valor no. 1 da array: %f \n", *toArray1);
    // lembrando: o compilador precisa que um %p seja um pointer void.

    times2(array1, 5);
    printf("\n");
    times3(array1, 5);
    printf("\n");
    times4(array1, 5);
}


void times2(float *array, int len) {
    for (int count = 0; count < len; count++) {
        printf("%f \n", array[count] * 2);
    };
}


void times3(float array[], int len) {
    for (int count = 0; count < len; count++) {
        printf("%f \n", array[count] * 3);
    };
}


void times4(float array[5], int len) {
    for (int count = 0; count < len; count++) {
        printf("%f \n", array[count] * 4);
    };
}

// Essas três são essencialmente a mesma coisa, mas com o parâmetro array em forma de argumento;
// array;
// e array com tamanho fixo.

// a notação de ponteiro é a mais popular.
