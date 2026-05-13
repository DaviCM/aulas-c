#include <stdio.h>
#include <stdlib.h>

void arrayNuances(void) {
    // Uma array não pode receber diretamente mais valores do que o tamanho ao qual foi alocada, mas pode receber menos!
    int ints[6] = {5, 7, 9, 11}; // Os outros elementos sempre serão zero. Prova disso:
    for (int i = 0; i < 6; i++) {
        printf("%d \n", ints[i]);
        // Irá retornar 5 7 9 11 0 0 
    };

    // Também dá para inicializar todos os valores para 0:
    float cemFloats[100] = {0};
    printf("\n");

    // E dá para interromper a inicialização ao passar um index diretamente:
    long algunsInts[7] = {0, 2, 4, 6, [5]=10, 11};
    // o valor que está entre 6 ([3]) e 10 ([5]) será automaticamente zerado.
    for (int i = 0; i < 7; i++) {
        printf("%ld \n", algunsInts[i]);
    };
}


int main(void) {
    arrayNuances();

    float floatList[4] = {3.14, 4.33333, 7.0, 8.93}; // Declarando uma array e passando os elementos diretamente. No C, se utilizam chaves.
    
    for (int i = 0; i < (sizeof floatList / sizeof(float)); i++) {
        // .2 consegue formatar o valor para duas casas decimais, e f porque é um float. Assim como no python.
        printf("O elemento no. %d da lista é: %.2f \n", i + 1, floatList[i]); 
    };

    return 0;
}