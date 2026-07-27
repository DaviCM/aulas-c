#include <stdio.h>

/* Outra coisa que acontece: nem sempre o compilador considera a variável do exato tipo declarado.
 * Ele sempre tentará armazenar ints no tipo que ocupa a menor memória possível, começando por 
 * signed int comum. Após isso ele tentará unsigned int e todos os longs em versão signed, depois unsigned.
 * 
 * Claro que, se o número tiver o descritor u no final, só unsigned serão tentados. se tiver l, a partir de long
 * e etc. Ele sempre tentará fazer o número caber no menor número de bytes possível, em resumo, começando por 
 * sizeof(int) na implementação.
 * 
 * Para floats é diferente: devido à maior precisão, o padrão é double ao invés de float normal. Float é forçável
 * apenas com o descritor f ao final.
 * Floats geralmente têm apenas 4 bytes, com double tendo 8 bytes e long double 16.
*/

int main(void) {
    printf("sizeof float: %zu\n", sizeof(float)); // 4
    printf("sizeof double: %zu\n", sizeof(double)); // 8
    printf("sizeof long double: %zu\n", sizeof(long double)); // 16

    // então, esses dois são a mesma coisa, pois o compilador faz o cast para double por padrão:
    float f1 = 4.22;
    double f2 = 4.28;

    // ambos serão double, pois não foi especificado o sufixo f para garantir que f1 é um float.

    printf("\n");

    /* há também uma forma comum de representação de números de ponto flutuante, 
     * a notação científica, na forma do sufixo e que separa mantissa e expoente:
    */
    float f3 = 4.23e-5; // 4.23 x 10⁻⁵
    printf("notação: %e\n", f3); // notação científica: %e
    printf("decimal: %f\n", f3);

    /* mas não necessáriamente a regra de 1 < x < 10 da notação científica tem que se aplicar aqui;
     * a parte inteira antes do ponto pode ser maior, e será tratado da mesma forma
    */
    double f4 = 314.159e+2; 
    
    // será tratado normalmente, e mostrado em notação científica correta no print
    // no caso: 3.14159e+4
    printf("31415.9 em notação: %e\n", f4);

    // claro, os especificadores de tipo f e l para float e long podem ser utilizados com notação científica.


    return 0;
}