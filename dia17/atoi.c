#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* É possível converter tipos de dados múltiplos para string 
       por meio das funções de print da stdlib sprintf() e snprintf()
       ambas recebem a string de destino antes do que deve ser formatado,
       com a diferença de que snprintf() exige um número máximo de bytes
       para escrever, prevenindo estouros de buffer
    */

    int num = 942;
    char *str = malloc(10);

    // irá incluir o null terminator automaticamente
    snprintf(str, 10, "%d", num); 
    printf("Esse é o número que formatamos para str: %s\n", str);


    // É possível também fazer a conversão inversa com funções da stdlib:
    /*
      famílias atoi() e strtol().
      a atoi (ascii to int) possui variantes para float, long e long long
      sem proteções contra estouro de buffer, e comportamento indefinido
      para uma string inválida passada.

      e a strtol (str to long) possui variantes signed e unsigned para int, 
      long e long long, além de float, double e long double.
    */

    double flt;
    char *flt_s = "9.54325";

    flt = atof(flt_s);
    printf("Convertido para float: %f\n", flt);

    // isso aqui vai dar muito ruim (comportamento indefinido):
    // é por isso que atoi() não é seguro, ela não possui erros ou NULL.
    long err = atol("opa");
    printf("\nOlha como deu ruim: %ld\n", err); //ld: formatador para long

    free(str);
    return 0;
}