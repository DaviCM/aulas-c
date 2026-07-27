#include <stdio.h>

int main(void) {
    // C aceita outras formas de representar números, que não decimal:

    // decimal comum
    int dec = 90;
    printf("decimal: %d\n", dec); // formatador %d


    // 0x: número hexadecimal (base 16, 1 dígito = grupos de 4 binários)
    int hex = 0x5a;
    printf("hexadecimal: %x\n", hex); // formatador %x 
    

    // 0: número octal (base 8, 1 dígito = grupos de 3 binários)
    int oct = 0132;
    printf("octal: %o\n", oct); // formatador %o


    // o novo c23 introduziu constantes binárias à implementação:
    int bin = 0b1011010;
    printf("binário: %.8b\n", bin); // formatador %b, formatado para 8 caracteres de precisão.


    /* outra coisa: é possível especificar o tamanho alocado para uma variável em sua declaração
     * por meio de caracteres específicos: l para long, u para unsigned 
     * em uppercase ou lowercase e em qualquer ordem, desde que ll para long long esteja junto.
    */

    unsigned int ui = 42u;
    long int li = 42l;
    long long lli = 42ll;
    unsigned long uli = 42ul;

    return 0;
}


/* Para converter entre bases é muito simples: pegar cada dígito e multiplicar pela base nova
 * seguindo o padrão binário de exponenciação: da direita para esquerda, aumentando o expoente em 1
 * 
 * exemplo com octal:
 * 0132
 * == 1 x 8² + 3 x 8¹ + 2 x 8⁰
 * == 64 + 24 + 2
 * == decimal 90
 * 
 * 
 * exemplo com hexadecimal:
 * 0x5a
 * == 5 x 16¹ + a(10) x 16⁰
 * == 80 + 10
 * == decimal 90
 * 
 * 
 * exemplo com binário:
 * 0b1011010
 * == 1 x 2⁶ + 0 x 2⁵ + 1 x 2⁴ + 1 x 2³ + 0 x 2² + 1 x 2¹ + 0 x 2⁰
 * == 64 + 16 + 8 + 2
 * == decimal 90
 * 
 * 
 * exemplo com decimal:
 * 122
 * == 1 x 10² + 2 x 10¹ + 2 x 10⁰
 * == 100 + 20 + 2
 * == decimal 122
 * 
 * tudo que é multiplicado por 0 pode ser ignorado, e os números são multiplicados de forma posicional.
 * 
*/