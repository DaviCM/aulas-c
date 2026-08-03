#include <stdio.h>

/* o que acontece é o seguinte: a keyword "restrict", em c, é passada para
   garantir que, durante a execução, nenhum outro ponteiro tentará acessar
   o endereço de memória que um determinado ponteiro já está acessando.

   é utilizada para otimizações de compilador, pois ele não precisa assumir
   que outra tentativa de acessar esse endereço a não ser pelo ponteiro será feita.
*/

// essa keyword só pode ser utilizada após o asterisco, pois ela diz respeito ao ponteiro
// e não ao valor que ele está apontando.

// essa função aqui troca o valor de dois ponteiros entre si,
// e garante que jamais ambos apontam para o mesmo endereço;
void swap(int *restrict p1, int *restrict p2) {
    int tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main(void) {
    // sendo assim, podemos chamar desde que os ponteiros não iniciem apontando o mesmo lugar:
    int p1 = 20, p2 = 25;
    printf("p1: %d\n", p1);
    printf("p2: %d\n", p2);

    swap(&p1, &p2);

    // os valores entre eles estarão invertidos.
    printf("p1: %d\n", p1);
    printf("p2: %d\n", p2);

    printf("\n");
    int p3 = 40;

    // aqui o comportamento será indefinido
    printf("p3: %d\n", p3);
    swap(&p3, &p3); // AVISO: ambos os ponteiros apontam para o mesmo lugar;
    printf("p3: %d\n", p3);

    return 0;
}

/* NOTA: restrict possui escopo do bloco em que foi declarado. assim, se um parâmetro de função
   foi declarado como restrict, esse ponteiro será obrigatóriamente restrict apenas no escopo da
   função.

   NOTA 2: um ponteiro restrict, numa array, tornaria restrict apenas o exato endereço que ele está
   apontando no momento.

   assim, mesmo que exista:
   int *restrict arr = {5, 10, 15, 20, 25};

   outro ponteiro poderia, por exemplo, modificar *(arr + 3), porque o ponteiro no momento está apontando
   o primerio elemento, não o quarto.
*/

// a libc utiliza restrict em muitas chamadas de ponteiro, para garantir que apenas um ponteiro é a fonte
// dos dados passados à função. um exemplo é o char * em printf.