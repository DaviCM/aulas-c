#include <stdio.h>
#include <string.h>

/* dá para realizar uma subtração ou uma soma entre dois ponteiros, e ela é feita com o número de valores
 * do respectivo tipo de dado (então ints com 8 bytes, char com 1 byte etc) que existem entre esses dois ponteiros.
 * basicamente, é uma operação normal, e o compilador sabe o tamanho dos espaços que devem ser pulados.
 *  
 * logo, se 
 * 
 * int arr[15]
 * int* p1 = &arr[0];
 * int * p15 = &arr[15];
 * 
 * printf("%d", (p15 - p1));
 * 
 * printar isso irá resultar em 14, o número de ints que exister entre eles.
 */


int strlen_rw(char *str) {
    char *c = &str[0];

    while (*c != '\0') {
        c++;
    };

    return (c - str);
}


int main(void) {
    char saudacao[] = "Oi, amigos!";
    printf("Vamos ver o tamanho de: \"%s\"\n", saudacao);

    printf("Essa é a strlen custom: %d\n", strlen_rw(saudacao));
    printf("E essa é a strlen real: %zu\n", strlen(saudacao));
    return 0;
}

// isso só funciona dentro de uma única array ou str, não irá funcionar entre conjuntos de dados diferentes.

// já fiz duas strlen custom. hora de pensar em outra ideia.