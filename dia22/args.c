#include <stdio.h>

/* também é possível fazer #define de macros com argumentos, como se fossem declarações de funções.
   novamente: não substitui uma função e não é a prática mais adequada, mas em tempo de compilação
   e para funções rápidas é bastante visto no mundo de C.
*/

// um radiano são 180 / pi graus.
#define sqr(num) ((num) * (num))

int main(void) {
    printf("12²: %d\n", sqr(12));
    printf("9²: %d\n", sqr(9));

    // ERRO: a precedência matemática permanece, e não passamos nenhum tipo de correção.
    printf("(3 + 5)²: %d\n", sqr(3 + 5));

    /* o que acontece aqui é: 
        
       #define sqr(num) num * num

       3 + 5 foi passado como argumento, então fica:
       3 + 5 * 3 + 5.
       a precedência matemática, de tokenização, diz que multiplicação deve vir primeiro.
       então temos 3 + 15 + 5, que é 23.

       o correto: adicionar parênteses entre os termos.
       ficará:
       (3 + 5) * (3 + 5).
       e aí teremos o resultado correto.
    */

    // correto!
    printf("(3 + 5 * 3)² (18²): %d\n", sqr(3 + 5 * 3));

    
    /* mas o ideal é adicionar mais um nível de parênteses ao redor da expressão para garantir
       que o resultado não seja passado na metade para outras expressões.

       então: #define sqr(num) ((num) * (num))
    */  

    return 0;
}