#include <stdio.h>

/* compilação condicional: #ifdef, #ifndef, #endif

   em termos simples, o código será compilado apenas caso
   uma condição envolvendo um macro seja satisfeita, sendo:

   - #ifdef: if defined, código entre a condicional e o endif
   só executa caso algum arquivo tenha definido um macro com '
   esse nome;

   - #fndef: if not defined, código entre a condicional e o 
   endif só compila caso o macro não tenha sido definido em 
   snenhum lugar;

   esses macros são resolvidos na compilação, não se tornam
   if-statements no código final. se a diretiva estiver
   presente, o código apenas será adicionado à compilação.

   há também condicional: #elifdef, #elifndef, #else.
   as duas primeiras são features do c23.
   basicamente estendem a compilação condicional, podendo depender de vários marcos ou de nenhum.
*/

#define BOM_DIA

int main(void) {
    printf("Oi, amigos!\n");

    #ifdef BOM_DIA
        printf("Um BOM_DIA foi definido para todos nós!\n");
    #endif

    // nunca será executado porque BOA_NOITE não está definido.
    #ifdef BOA_NOITE
        printf("BOA_NOITE para você também!\n");
    #else
        printf("É, esqueceram do BOA_NOITE.\n");
    #endif

    // será executado justamente porque BOA_TARDE não está definido.
    #ifndef BOA_TARDE
        printf("Esqueceram de me dar BOA_TARDE.\n");
    #elifdef BOA_TARDE
        printf("Estamos preparados para BOA_TARDE");
    #endif

    return 0;
}