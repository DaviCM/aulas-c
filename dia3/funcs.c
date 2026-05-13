#include <stdio.h>
#include <stdlib.h> // vou pegar a função rand() e a constante RAND_MAX

// Protótipo de função declarada depois da main, para ela saber que essa função existe no sistema
float umFloatAleatorio(void);

// Em uma função, isso é um parâmetro: int target
int somarUm(int target) {
    return ++target;
}


int main(void) {
    for (int count = 1;;count++) {
        int num;
        printf("Escreva um número para somar 1: ");
        scanf("%d", &num);
    
        /* E aqui estamos passando um argumento.
        Os argumentos não são os parâmetros, mas o valor deles é copiado para o parâmetros */
        printf("O resultado, por incrível que pareça, é: %d \n", somarUm(num));
        printf("Essa é a iteração: %d \n \n", count);

        printf("Chamando uma função declarada via protótipo: %f \n", umFloatAleatorio());
    };
    return 0;
}

/* Curiosidade: a main() sempre retorna 0 como sinal para código bem sucedido, 
por isso ela tem que ser uma função int e não void */


float umFloatAleatorio(void) {
    /* (float)rand() pega o int aleatório e converte para float
    RAND_MAX é o valor máximo que rand() Pode retornar se não utilizarmos módulo para dividir
    Esse valor é o maior int32 sem sinal (unsigned) possível */
    return (float)rand() / RAND_MAX; 
}

