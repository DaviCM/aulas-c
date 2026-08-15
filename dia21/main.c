#include <stdio.h>
#include <stdlib.h>

/* hora de deixar o int main(void) de lado.

   é o seguinte: C fornece um método para interação entre o programa
   e o ambiente onde ele é executado, nesse caso o shell. essa inte-
   ração é feita por meio de argumento passados junto com o executável,
   da mesma forma que um ls com o argumento -a lista informações adi
   cionais.

   para isso, podemos capturar os parâmetros e receber a contagem deles,
   por meio de dois parâmetros na main que, na execução, recebem os ar-
   gumentos.
*/

// o primeiro é int: arg count, o segundo é arg vectors, uma array de char *.
// ou pointer to pointer, na maioria dos casos.
int main(int argc, char *argv[]) {
    printf("no de argumentos passados na execução: %d\n", argc);
    printf("nome do executável: %s\n", argv[0]);

    printf("\n");

    long total;

    for (int count = 0; count < argc; count++) {
        char *rest;
        long arg = strtol(*(argv + count), &rest, 10);

        printf("tentando converter o argumento %d para long: %ld\n", count, arg);
        printf("Parte do argumento que não pôde ser convertida: %s\n", rest);
        printf("\n");

        total += arg;
    };

    printf("soma de todos os argumentos: %ld\n", total);

    return 0;
}

/* OBS: argv[argc] sempre apontará para NULL. útil para saber que chegamos ao fim
   da lista de argumentos.

   OBS:
   - apesar de ser raro, às vezes *argv não aponta para o nome do executável.

   - da mesma forma, é possível (mas extremamente improvável) que uma imple-
    mentação de c não trate **argv como um ponteiro para os argumentos pas-
    ados.

   - as strings de argv podem ser modificadas, mas os seus tamanhos são al-
    ocados apenas para o limite que precisam. Portanto, substituí-las por
    algo maior não é boa ideia. 
*/