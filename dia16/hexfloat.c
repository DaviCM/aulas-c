#include <stdio.h>

/* C suporta, por mais confusas que possam ser, 
 * constantes de ponto flutuante em forma hexadecimal.
 *
 * sua estrutura é a seguinte:
 * float, double ou long;
 * 0x;
 * mantissa na forma hexadecimal;
 * indicador de expoente p;
 * e o valor do expoente, que virá na forma de uma potência de base 2 e não 10.
 * 
 * a construção final será algo como:
*/

int main(void) {
    double hexfloat = 0xb.14p+3;

    /* esse valor terá um 11 (b),
     * 1 x 16⁻¹ e 4 x 16⁻², tudo multiplicado por 2³, que é 8.
     * resultará em um decimal que, como todos os gerados por esse método,
     * é divisível por 5.
    */

    printf("notação científica hex: %a\n", hexfloat);
    printf("número na forma decimal: %f\n", hexfloat);

    return 0;
}

/* lembrete: números de ponto flutuante, na sua parte posterior á vírgula,
 * atuam com os expoentes negativos da base, inverso à parte inteira.
 * sendo assim, como o primeiro dígito antes da vírgula é ^0, o primeiro depois é ^-1.
 * exemplo em base 10 seria:
 * 10.15 =
 * 1 x 10¹ + 0 x 10⁰ + 1 x 10⁻¹ + 5 x 10⁻²,
 * 
 * para os expoentes negativos, é a mesma coisa de:
 * 1 x (1/10)¹ e 5 x (1/10)², com a base invertida.
 * 
 * princípio matemático da inversão de base em expoentes negativos
*/