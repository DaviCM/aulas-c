#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    /* em C, é permitido omitir o return apenas na main, e é uma forma
       perfeitamente válida de se sair de um programa.

       o 0, retorno de sucesso, é um macro da stdlib (EXIT_SUCCESS) 
       que indica a saída de um programa sem nenhum erro levantado.
    */

    printf("se tudo der certo: %d\n", EXIT_SUCCESS);
    printf("se algo der ruim: %d\n", EXIT_FAILURE);

    // e podemos usar isso na aplicação: podemos pedir exatamente dois parâmetros
    // (argc == 3):
    if (argc != 3) {
        printf("ERRO! no de parâmetros inválido.\n");
        printf("Uso: multiplicar x y\n");

        return 1;
    };
    
    printf("\n");

    int x = strtol(argv[1], NULL, 10), y = strtol(argv[2], NULL, 10);
    printf("resultado da multiplicação: %d\n", x * y);

    return 0;
}

// echo $? para verificar o último código de erro da aplicação.