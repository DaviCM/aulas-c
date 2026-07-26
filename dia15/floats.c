#include <stdio.h>
#include <float.h>

int main(void) {
    // Floats também podem ser extendidos, mas para isso é preciso compreender como eles são armazenados.

    /* Todo float possui:
     * um sinal, 
     * um valor que serve como base para a exponenciação, como em notação científica com o 10. Em computação binária, é geralmente 2;
     * um expoente positivo ou negativo para a base, gerado por meio de biased representation em que 127 é um zero-de-fato;
     * os números significativos, que formam a parte decimal também chamada de mantissa;
     * e a precisão dos dígitos, que define quantos bytes devem ser reservados a ela.
     * de acordo com a especificação do C.
    */

    // é possível ver qual é nosso radix, a base para a exponenciação:
    printf("radix: %d\n", FLT_RADIX);

    // E existem três tipos, com precisão que é *2 a cada um deles:
    float f1;

    double d1;

    // não tem ligação com long ints, representa precisão e não apenas tamanho.
    long double ld1;

    printf("dígitos do mantissa com precisão garantida: %d\n", FLT_DIG);
    
    f1 = 0.123456f; // f no final garante que o número será tratado como float e não double
    printf("%.8f\n", f1);
     
    f1 = 0.123456789f;
    printf("%.9f\n", f1); // imprecisão, a partir do sétimo dígito.



    /* esses dígitos são significativos porque fazem parte do mantissa e são diferentes de 0. Assim:
     * esse número possui apenas quatro dígitos significativos, porque os 0 quando aparecem ao início não são.
    */
    float f3 = 0.000001122f;
    f1 = 0.15834f;
    
    // isso aqui irá gerar imprecisão, porque agora haverá 9 dígitos significativos.
    printf("%.10f\n", f1 + f3);

    return 0;
}

// moral da história: até FLT_DIG dígitos, o float será mostrado com precisão. Acima disso, é impossível ter certeza.