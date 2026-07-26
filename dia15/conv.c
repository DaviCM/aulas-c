#include <stdio.h>
#include <float.h>

int main(void) {
    /* A questão é: para a conversão de volta entre o resultado decimal (base 10)
     * e o resultado guardado na forma de float (base 2), quantos dígitos precisam
     * ser preservados, do mantissa, para que o número tenha seu expoente reconstruído?
     * 
     * a resposta: há macros para dizer quantos dígitos, no máximo, são garantidos:
     * FLT_DECIMAL_DIG para float, DBL_DECIMAL_DIG para double e LDBL_DECIMAL_DIG para long double.
     * 
     * além disso, há DECIMAL_DIG que mapeia para o limite mais alto (LDBL).
     * 
    */
    
    printf("dígitos com precisão garantida pelo double: %d\n", DBL_DIG);
    printf("dígitos decimais que podem ser convertidos para double: %d\n", DBL_DECIMAL_DIG);

    double d1 = 0.12345678912345; // 15 dígitos significativos
    double d2 = 0.000000000000006; // 1 dígito significativo no 16o mantissa

    // em teoria, somar esses dois causa erro, a precisão não é garantida apesar de a constante ser.
    printf("d1 é exatamente: %.17f\n", d1); // formatado para o número de casas decimais (não float) garantidas
    printf("d2 é exatamente: %.17f\n", d2);

    printf("soma: %.17f\n", d1 + d2); // erro de precisão, deveria acabar em 45600.

    // porém esse número ainda é inferior ao número de casas decimais disponíveis,
    // então mesmo imprecisos em soma, serão precisos em constante:
    double d3 = d1 + d2;
    printf("d3 é exatamente: %.17f\n", d3);

    // mas não tente expandir ele, não dá certo.
    double d4 = 0.00000000000000001;
    printf("soma imprecisa (18a posição): %.18f\n", d3 + d4); // deveria terminar em 56000.
    return 0;
}

/* moral da história: existem limites diferentes para precisão em ponto flutuante e em decimais;
 * mas ambos, após esse limite, apresentam comportamento não padronizado e não garantido.
 * o limite para decimais é maior que o limite para floats.
 * 
 * d3, por exemplo, foi convertido para decimal e depois novamente para float,
 * então seguiu DBL_DECIMAL_DIG para manter-se preciso.
*/