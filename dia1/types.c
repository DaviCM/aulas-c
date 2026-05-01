#include <stdio.h>

// Duas expressões diferentes
int insig1 = 5; int insig2 = 943;


void nums(void) {
    int x = 10;
    int y = 0; 
    y += x > 5? 10: 27; // ternário, igual ao do JS
    printf("%d \n", y);
};


void increment(void) {
    int x = 10;
    int y = 0; 

    y++;
    y--;
    // Operadores post-increment e post-decrement: Avaliam a expressão, como um for-loop ou um if, e apenas depois somam ou subtraem o valor.

    --y;
    ++y;
    // Operadores pre-increment e pre-decrement: Somam ou subtraem primeiro, depois avaliam a expressão.

    // Ex:
    int num1 = 20;
    int num2 = 15 + num1++; // Irá somar, e só depois adicionar 1 a num2
    printf("%d %d \n", num1, num2);

    // O oposto também acontece:
    int num3 = 15;
    int num4 = 5 + ++num3;
    printf("%d %d \n", num3, num4); // Adiciona primeiro, só depois faz a operação
}


// Operadores booleanos:
// && and
// || or
// ! not


void forloop(void) {
    // For loop, super simples
    for (int num = 1; num < 15; num++) { // A operação irá se repetir enquanto a condição passada no segundo parâmetro for verdade
        printf("Estamos na iteração: %d \n", num);
    };
    printf("%s \n", "Acabou o Guaraná Antárctica");
};

int main(void) {
    nums();
    increment();
    forloop();
    return 0;
};

