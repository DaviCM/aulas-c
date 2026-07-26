#include <stdio.h>

int main(void) {
    /* Existem diversos tipos derivados dos três primitivos em C: int, float e char;
     * Esses tipos representam informações sobre seu tamanho, precisão e outros fatores;
     *
     * Para ints, por exemplo, há números que podem ter sinal positivo e negativo (signed);
     * e números que podem ser apenas positivos, sem sinal (unsigned).
     * Isso é devido aos números "signed" dedicarem o seu bit mais significativo
     * para registrar o sinal, em código binário.
    */

    // signed: int padrão, que pode ser chamado pelo alias e admite sinais positivos e negativos.
    int n1;
    signed int n2;
    signed n3;

    // unsigned: não aceita sinais negativos.
    unsigned int n4;
    unsigned n5;

    // o limite do unsigned é o dobro + 1 do limite do signed, mesmo que ambos sejam números muito grandes.

    // sobre chars: no fundo, eles são ints pequenos que ocupam apenas um byte de espaço:
    char c = 'B';
    printf("char para int: %c, %d\n", c, c); // B, 66

    /* Compiladores podem ou não atribuir sinais para caracteres específicos em arquiteturas específicas,
     * a depender do caractere, do compilador e de outras nuances num char não especificado;
     * mas se for especificado, será certo de que ele possui ou não o sinal.
     * logo, chars também podem ser:
     */
    signed char c2;
    unsigned char c3;

    printf("\n");

    // então é possível fazer operações com chars, pois os caracteres na verdade são inteiros que representam um caractere;
    // no encoding utilizado pelo sistema e pelo compilador.

    char d = 68;
    char e = 50;
    char a = 'C';

    printf("ints: %d %d %d\n", d, e, a);
    printf("chars: %c %c %c\n", d, e, a);
    printf("int + char (int): %d\n", e + a);
    printf("int + char (char): %c\n", e + a);

    // para o alfabeto, geralmente são utilizados os caracteres maiúsculos e minúsculos da tabela ascii.
    return 0;
}

// obs: hoje em dia é quase certo que um byte possui 8 bits, mas nem sempre foi assim na computação.