#include <stdio.h>
#include <math.h>

/* podemos criar macros #define com quantos argumentos quisermos,
   dando nomes específicos para cada um deles.

   
   por exemplo, podemos criar um para determinar a fórmula quadrática:
   ou dois, devido ao +- da raiz de delta.
*/

// lemnbrete: para definir com #define, não utilizamos o sinal de igualdade.
#define QUADRATIC_PLUS(a, b, c) (((-b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a))) 
#define QUADRATIC_MINUS(a, b, c) (((-b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))  

int main(void) {
    printf("Raízes de 2x² + 5x + 2:\n");
    printf("x1: %f\n", QUADRATIC_PLUS(2, 5, 2));
    printf("x2: %f\n", QUADRATIC_MINUS(2, 5, 2));
    
    return 0;
}

// claro que, com a biblioteca-padrão, apenas resultados reais serão retornados.