#include <stdio.h>
#include <string.h> // existe uma header com funções relacionadas a strings!


int customStrlen(char* str) {
    int count;
    for (count = 0; str[count] != '\0'; count++) {
    }

    // mesma coisa:
    /*
    int count = 0;
    while (str[count] != '\0') {
        count++
    }
    */

    return count;
}


int main(void) {
    char *str1 = "Oi pessoal!";

    printf("Esse é o tamanho da string \"%s\": %zu \n", str1, strlen(str1));
    printf("E esse é o mesmo tamanho, mas eu que escrevi: %d \n", customStrlen(str1));
    return 0;
}