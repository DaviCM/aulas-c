#include <stdio.h>
#include <stdbool.h>

int main(void) { 
    /* com stdbool, podemos converter ints para bool diretamente,
       apenas convertendo com o sinal de =.
       obviamente, se convertemos um 0, o resultado será false. 
       caso contrário, será true.
    */

    bool is_true = true;
    int num = 42;
    int zr = 0;

    printf("Esse é nosso bool: %d\n", is_true);

    is_true = num;
    printf("Bool se ele for igualado a 42: %d\n", is_true);

    is_true = zr;
    printf("Bool se ele for igualado a 0: %d\n", is_true);

    /* é possível converter entre tipos inteiros, tanto unsigned quanto signed.
       se um valor unsigned maior for convertido para um tipo unsigned e não couber,
       ele será "avançado" passando do limite e retornando a 0, onde caberá.

       se um tipo signed maior for convertido para um tipo signed e não couber,
       o resultado será dependente da implementação. provavelmente, no entanto,
       o que acontecerá será relacionado com o twos complement, a forma com a qual
       signeds lidam com valores, com o bit mais indicativo sinalizando o sinal.
       logo, o número provavelmente terá todos os seus valores invertidos, tendo
       apenas o bit mais à esquerda represntando 1, que configura o menor número
       negativo possível.
    */

    printf("\n");

    double flt = 9.87;
    printf("aqui temos um double: %.2f\n", flt);

    int intflt = flt;
    printf("E aqui temos o mesmo número, mas convertido para int: %d\n", intflt);
    // a parte decimal será descartada com prejuízo, sem arredondamento.
    // o resultado esperado é 9, ele apenas pega a parte inteira.

    printf("\n"); 

    /* caso um float cuja parte inteira não cabe no respectivo tipo int que está sendo
       convertido não caiba nele, o comportamento é indefinido. logo, não vamos fazer isso.
    */

    // conversões assim são feitas da forma esperada, com o descarte do decimal por último:
    int x = 5.5 * 3;
    printf("5.5 * 3 (16.5), parte decimal excluída: %d\n", x);

    // e assim também, sem parte decimal do float para representar:
    float y = 4 * 12;
    printf("Um float sem parte decimal: %.2f\n", y);

    /* Às vezes o compilador faz promoções de tipo implícitas
       quando a inicialização é por meio de uma operação, já que
       o valor máximo do tipo pode não ser suficiente para aguentar o resultado.
     * se o valor for muito grande, pode até ser convertido para unsigned.
    */

    printf("\n");

    // esses chars, se operações forem feitas com eles utilizando ints, serão convertidos para int.
    char let = 'i', nmc = 78;
    printf("forma char: %c %c\n", let, nmc);
    printf("forma int: %d %d\n", let, nmc);
    printf("Aqui os dois foram somados +5, então o compilador os converteu para int antes: %c %c\n", let + 5, nmc + 5);
    printf("Mas, mesmo assim, ainda podemos mostrar na forma char!\n");

    return 0;
}