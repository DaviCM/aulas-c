#include <stdio.h>

/* ALVO: ASSERT(x < 20, Mensagem de erro customizada)
   deve mostrar arquivo e linha do erro.
*/


/* Podemos utilizar a compilação condicional para 
   habilitar assert apenas se necessário. se um macro
   for inicializado como zero, ele é avaliado como um
   valor falso em c; assim como 0 em loops e ifs.
*/
#define ASSERT_ENABLED 1
#if ASSERT_ENABLED

#define ASSERT(condition, detail) \
if (!(condition)) { \
    fprintf(stderr, "Assert em \"%s\" falhou na linha: %d\n", __FILE__, __LINE__); \
    fprintf(stderr, "%s, %s\n", #condition, detail); \
\
    return 1; \
}

#else
#define ASSERT(condition, detail)
#endif

// outra diretiva: #error.
// Irá falhar a compilação imediatamente se for acionada, basicamente.
#ifndef ASSERT_ENABLED
#error Eu imaginei que, de qualquer forma, ASSERT estaria definido.
#endif


int main(void) {
    int numb = 75;
    ASSERT((numb < 50), "O valor numb precisa ser menor que 50.");

    return 0;
}