#include <stdio.h>

/* não podemos passar uma array para uma função e tentar pegar o tamanho dela,
pois o compilador interpreta passar uma array como um pointer para o primeiro
caractere. Assim, tentar manipular vai retornar o tamanho desse pointer.
*/

void arraySize(int array[8]) {
    printf("** FALSO ** \n");
    printf("Esse é o tamanho de um int: %zu bytes \n", sizeof(int));
    printf("Esse é o tamanho de um ponteiro para um int: %zu bytes \n", sizeof(int*));
    printf("Esse é o tamanho da array: %zu bytes \n", sizeof array); // até o compilador sabe, ele levanta um warning!
    printf("E esse é o real número de elementos: %d \n", (sizeof array / sizeof(int)));
}

/* se eu tentar um dereference com sizeof *array, ele vai me retornar simplesmente o tamanho do primeiro elemento,
já que o compilador interpreta array[] como um ponteiro para o primeiro elemento*/

int main(void) {
    int arrayTeste[8];
    printf("** VERDADEIRO ** \n");
    printf("Esse é o real tamanho da array: %zu bytes \n", sizeof arrayTeste);
    printf("E esse é o número de elementos: %d \n", (sizeof arrayTeste / sizeof(int)));
    printf("\n");
    arraySize(arrayTeste);

    printf("\n");
    printf("** BONUS ** \n");
    printf("Dá pra saber o tamanho na memória de uma array sem declarar ela! \n");

    int num;
    printf("Insira o n de elementos int da array para sabermos quanto espaço ela ocupa: ");
    scanf("%d", &num);
    printf("Uma array de %d ints ocupa: %zu bytes de espaço! \n", num, sizeof(int[num]));
    return 0;
}