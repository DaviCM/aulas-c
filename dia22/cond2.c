#include <stdio.h>

/* da mesma forma, é possível ter um if comum, independente da definição,
   do macro, que precisa retornar "1", true, para que seja incluído na 
   compilação.

   não substitui um if tradicional porque se refere à compilação e não ao
   runtime, portanto não identifica condições mutáveis, apenas estados
   binários que podem ou não ser verdade na compilação, geralmente estados
   de outros macros.
*/

#define SEIS 6

int main(void) {
    #if SEIS == 6
        printf("Descobri hoje que seis == 6.\n");
    #elif SEIS == 7
        printf("Que? Eu acho que estamos errados.");
    #else
        printf("De qualquer forma isso seria bem estranho.");
    #endif

    printf("Seis: %d\n", SEIS);

    #undef SEIS
    printf("Derrubamos a definição de seis com undef.\n");

    return 0;
}

/* nesse caso o compilador verá apenas o primeiro printf, porque a condicional
   pode produzir apenas uma resposta binária no tempo de compilação.
   essa condicional não existirá no código após a compilação, e não equivale
   a um if-else if-else comum, a começar que depende de um macro.
*/

/* obs:
   a keyword para o compilador "defined" é sinônimo do "def" em #ifdef, #ifndef e etc.
   assim, esses são todos sinônimos, mas trocando #ifdef por #if:

   #ifdef
   #if defined

   #ifndef
   #if !defined // o operador ! continua funcionando, bem como todos os demais operadores lógicos.

   #elifdef
   #elif defined

   #elifndef
   #elif !defined

   simplesmente semântica.
*/