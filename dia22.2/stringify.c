#include <stdio.h>

/* é possível fazer conversão direta para string de um conjunto __VA_ARGS__
   por meio do operador #, que converte os valores separados por vírgula
   gerados pelo macro em um char* alocado na memória em tempo de compilação.

   o resultado é que tudo será passado como uma string só. a partir daí essa
   será uma string normal que poderá ser acessada e manipulada com notação de array.

   lembrete: argumentos de tamanho variável passados em um campo marcado ...
   são opcionais.
*/

#define STRING(...) #__VA_ARGS__

/* se passarmos uma variável nomeada como parâmetro para um operador # em um define,
   a resposta não será o valor em string, mas o nome da variável!
*/
#define NAME_AND_VALUE(x) printf("%s = %d\n", #x, x)

/* e se passarmos dois hashs seguidos, ##, os valores serão concatenados em um único
   resultado. Como um __VA_ARGS__ com # antes e ..., mas podendo especificar o número de
   elementos e não transformando o valor em uma char*.

   valores de qualquer tipo podem ser concatenados, eles serão unidos e tratados como um 
   valor só.
*/
#define CONCAT(e1, e2) e1 ## e2


int main(void) {
    char result[50];
    sprintf(result, STRING(3, 1, 3, 6, "while true", 7.25, 1a, 0xfa));

    printf("%s\n", result);

    int a = 20;
    NAME_AND_VALUE(a);

    printf("%d\n", CONCAT(40, 45));
    
    return 0;
}