#include <stdio.h>

void getSizes(void) {
    // sizeof retorna o valor em bytes que uma variável ou tipo ocupa no sistema
    // esse operador retorna um valor do tipo side_t, um int utilizado no C para 
    // armazenar resultado de algumas contagens
    int jaca = 32;
    float minion = 42.543;
    char a = 'c';

    printf("Essa int ocupa: %zu bytes \n", sizeof jaca);
    printf("Essa int ocupa: %zu bytes \n", sizeof(int)); // parênteses são obrigatórios entre tipos de dados e operadores
    printf("Esse float ocupa: %zu bytes \n", sizeof minion);
    printf("Esse char ocupa: %zu bytes \n", sizeof a);
    printf("Isso aqui é um double, por algum motivo: %zu bytes \n", sizeof 3.14159);
    // para cada tipo de dado em c, existe um formatador % para o imprimir na tela
};


void doWhile(void) {
    // isso é um while loop:
    int manga = 31;
    while (manga < 40) {
        printf("Estamos no while \n");
        manga += 1;
    };

    // e isso é um do-while loop:
    int melancia = 50;
    do {
        printf("Estamos no do-while \n");
        melancia += 1;
    } while (melancia < 50);
    // um bloco do-while sempre irá executar ao menos uma vez, pois ele executa antes de avaliar a expressão
};

int main(void) {
    getSizes();
    doWhile();
    return 0;
};

