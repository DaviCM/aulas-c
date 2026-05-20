#include <stdio.h>

// strings são como arrays no C: não são tipos, apenas semântica com ponteiros
// que se aproveitam da leitura sequencial de memória.

int main(void) {
    char a = 'a'; // aspas simples == apenas um caractere.

    char *str1 = "Bom dia a todos! \n";
    char *str2 = "Um sorvete entre aspas é um \"sorvete\" \n";
    // backslash, ou barra ao contrário (\) é o caractere 'escape', que indica que o caractere seguinte
    // deve ser interpretado literalmente.

    // Na verdade, um char* e uma array são bem semelhantes
    // ambos são ponteiros para o primeiro caractere da cadeia de elementos.

    printf("%c \n", a);
    printf("%s", str1);
    printf("%s", str2);

    // Também podemos passar strings como arrays da forma correta e da forma preguiçosa:
    char str3[13] = "Olá, mundo!";
    char str4[] = "Olá mundo, novamente!"; // O compilador instancia o tamanho automaticamente.

    // lembrete: strings sempre tem um caractere implícito \0, que indica seu fim. quando instanciando-a 
    // em forma de array, nós temos que passar dois endereços extra para esse código.

    printf("%s \n", str3);
    printf("%s \n", str4);
    
    return 0;
}