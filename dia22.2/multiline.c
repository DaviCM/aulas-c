#include <stdio.h>
#include <math.h>

/* também podem existir macros multilinha, indicados por uma barra invertida
   (\) em cada uma das linhas pertencentes ao macro.

   como código c normal pode estar no macro, em teoria é possível programar
   assim. prática bem sem sentido e possívelmente nociva, no entanto.
*/

#define EXPONENTIAL(start, end, exponent) \
double current = start; \
\
while (current <= end) { \
    double result = pow(current, exponent); \
    printf("%.0f^%.0f = %.0f\n", current, exponent, result); \
    \
    current++; \
}

// a última linha não precisa da barra invertida.

int main(void) {
    EXPONENTIAL(2.0, 9.0, 3.0);    
    return 0;
}

/* observação muito interessante:
   lvalues e rvalues em C.

   lvalue (left-side value):
   qualquer valor que pode ser acessado, que está armazenada em um lugar.
   esses valores podem ser manipulados matemáticamente e assignados para
   outras variáveis, por exemplo.

   até mesmo variáveis register são lvalues, pois sua característica é
   não possuir uma forma de apontar para ela com &. ela detém todas as outras
   características de variáveis comuns.



   rvalue (right-side value):
   qualquer valor que pode inicializar uma variável, contando números literais.
   rvalues são perigosos em macros porque podem acabar sendo tratados como lvalues
   dentro do código, como por exemplo:

   #define increment(a) a++

   se no código for chamado 2, o valor será substituido por 2++. como 2 é um literal
   e não vive na memória do sistema, não é um valor que pode ser incrementado como um
   lvalue; portanto o código não compila.
*/