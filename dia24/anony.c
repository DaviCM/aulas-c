#include <stdio.h>

/* Podemos declarar uma struct anônima fora de um typedef, 
   e criar variáveis com esse tipo;
   afinal, uma struct customizada é um tipo novo na memória.
*/
struct {
    char *brand;
    int memory;
    double filled;
} hdd, ssd, nvme;

/* o uso mais comum continua sendo via typedef, para podermos
   utilizar a estrutura sem a palavra "struct" antes, referen-
   ciando apeanas seu nome customizado.
*/

typedef struct {
    char *brand;
    int memory;
    double filled;
} drive;

int main(void) {
    // mesmo com struct sem nome, a variável declarada para esse tipo funciona.
    nvme.memory = 256;

    // não é preciso e nem permitido, nesse caso, escrever "struct drive".
    drive sandisk = {
        .brand = "SanDisk",
        .memory = 32,
        .filled = 12,
    };

    /* para ser legalizado escrever struct drive, a estrutura deveria ser declarada como:
       struct drive ...
       ou typedef struct drive ...
    */

    return 0;
}