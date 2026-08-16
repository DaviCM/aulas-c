#include <stdio.h>

/* também é possível definir com #define um macro que recebe uma quantidade
   variável de argumentos, para quaisquer motivações,
   isso é feito com os operadores reticências (ellipses ...), e o macro
   __VA_ARGS__.

   nesse caso o macro reconhece as variáveis passadas e, para os variáveis,
   apenas os separa com vírgula.
   mas mesmo assim os valores são distintos, e, como são susbstituídos na
   compilação, reutilizáveis.
*/

#define EVAL_PRINT(a, b, c, ...) ((a) * (b) + (a) + (b) + (0.25) * (c)), __VA_ARGS__

int main(void) {
    printf("Resultado dessa sintaxe estranha:\n");
    printf("%f %s %c %d\n", EVAL_PRINT(8, 4, 5.25, "Random", 'R', 3));

    return 0;
}