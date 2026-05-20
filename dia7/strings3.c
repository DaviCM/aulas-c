#include <stdio.h>
#include <string.h> // existe uma header com funções relacionadas a strings!

int main(void) {
    char *str1 = "Oi pessoal!";

    printf("Esse é o tamanho da string \"%s\": %zu \n", str1, strlen(str1));
    return 0;
}