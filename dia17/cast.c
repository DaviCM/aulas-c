#include <stdio.h>
#include <stdlib.h>

int compare(const void *e1, const void *e2) {
    // casting de e1 e e2 para (int *)
    if (*((const int *)e1) < *((const int *)e2)) {
        return -1;
    }
    else if (*((const int *)e1) > *((const int *)e2)) {
        return 1;
    }
    else {
        return 0;
    };
}

// mas é a exata mesma coisa disso aqui, que é definitivamente mais legível:
int compare2(const void *e1, const void *e2) {
    const int *i1 = e1; // const é necessário para garantir ao compilador que o valor não muda
    const int *i2 = e2;

    if (*i1 < *i2) {
        return -1;
    }
    else if (*i1 > *i2) {
        return 1;
    }
    else {
        return 0;
    };
}

/* tecnicamente, compare() deve retornar negativo se *e1 < *e2, positivo se *e1 > *e2 e 0 se *e1 == *e2
    então, pode ser escrito dessa forma bem limpa:
    return *e1 - *e2;

    se *e1 < *e2, será negativo. se *e1 > *e2, positivo. se *e1 == *e2, 0.
*/


int main(void) {
    /* essa é uma prática relativamente comum: casting de tipos para variáveis
       serve para evitar avisos do compilador e termos certeza de que as variáveis 
       possuem os tipos que esperamos delas, antes de operações, visualizações
       ou apenas para poder operar de forma diferente.
    */

    // exemplo:
    int a = 20;
    long b;

    /* é pronunciado: fazendo o cast de a para long
       assim temos certeza de que a variável possui o tipo que é esperado.
       esse caso é desnecessário, o compilador faria a promoção de a para long
       automaticamente.
    */

    b = (long)a + 50;
    printf("long: %ld\n\n", b);

    /* uma forma comum de casting é com (void *), pois muitas vezes eles são
       o tipo de ponteiro necessário para a situação, já que muitos tipos são aceitáveis
       exemplo na função compare()! 
    */
    int arr[8] = {33, 1, 64, 98, 11, 3, 83, 42};

    for (int c = 0; c < 8; c++) {
        printf("%d ", *(arr + c));
    };
    printf("\n");

    qsort(arr, 8, sizeof(int), compare);

    for (int c = 0; c < 8; c++) {
        printf("%d ", *(arr + c));
    };
    printf("\n");

    return 0;
}

/* resumo: não é preciso ter receio de usar casts, mas se você chegou
   ao ponto de precisar deles, provavelmente há métodos melhores por aí.
*/