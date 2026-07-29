#include <stdio.h>

int main(void) {
    /* conversão inversa: número para char
       converter um valor numérico para seu correspondente 
       em forma de caractere, de acordo com o encoding.
    */

    printf("Esses são o mesmo caractere em forna int e char: %d %c\n", 5, '5');
    printf("Mas não são iguais, seu valor é diferente: %d %d\n", 5, '5');
    printf("A diferença é de 48, o código utf-8/ascii do 0.\n");

    /* sendo assim, é possível converter um char para seu valor inteiro;
       basta subtrair seu código por 48 ou '0', o código do 0, e o resultado será
       o valor original.
       vejamos:
       0   1   2   3   4   5   6   7   8   9
       48  49  50  51  52  53  54  55  56  57

       qualquer conversão funciona. 57 - 48 == 9.
    */

    // então:
    printf("%d == %c\n", 5, '5');
    printf("5 e ('5' - 48) são iguais: %d\n", (5 == '5' - 48));
    printf("5 e ('5' - '0') são iguais: %d\n", (5 == '5' - '0'));

    /* e, claro: o inverso também funciona: um int pode ser somado a '0';
       e o resultado será o caractere correspondente ao inteiro.

       logo:
       6 + '0' == 54

       e 54 é '6', o código utf-8 correspondente ao caractere.
    */

    return 0;
}

// lembrete: '' para char, "" para char *.