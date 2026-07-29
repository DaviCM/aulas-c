#include <stdio.h>
#include <stdlib.h>

int main(void) {
   /* no parâmetro do ponteiro para ponteiro, que é utilizado como tratamento de erro, 
      se você passar NULL, um NULL ** Nesse caso, você não receberá informação do caractere
      em que a conversão de tipo parou.
   */ 

   // é possível converter entre bases! declaramos a string em outra base:
   char *convert = "101011011";
   unsigned long result;

   // strotoul: unsigned long
   result = strtoul(convert, NULL, 2);

   // os valores são representados em todas as bases, então podem ser impressos em todas
   printf("valor convertido (binário): %lb\n", result);
   printf("valor convertido (decimal): %lu\n", result);

   printf("\n");

   /* uma parte dessa char* não será lida, pois esses caracteres não existem em doubles.
      o caractere seguinte será armazenado no endereço de char* "remaining"
      e assim podemos ver onde a conversão parou.
   */

   char *cvtdbl = "24.45tbw";
   char *remaining;
   double newdbl;

   newdbl = strtod(cvtdbl, &remaining);

   printf("double convertido: %f\n", newdbl);
   printf("a string restante foi: \"%s\"\n", remaining);
   printf("a execução parou em: \"%c\"\n", *remaining); // dereference de um char* é um char

   // se nada der errado, o ponteiro endptr do strtol apontará para o NUL terminator.

   /* A razão de passarmos um ponteiro para ponteiro é armazenar o primeiro caractere
      remanescente da string, pois de outra forma nós não conseguiriamos ver.
      o dereference desse ponteiro é a string propriamente dita, e o dereference de um char*
      comum é apenas um char.
   */

   return 0;
}


