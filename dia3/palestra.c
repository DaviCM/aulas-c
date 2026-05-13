#include <stdio.h>
#include <stdlib.h>

/* Em geral, na computação, tipos de dados que ocupam mais de um byte, ou mais de um endereço de memória, têm
seus bytes que o compõem em ordem. Isso é a "ordem dos bytes", em inglês endianess.
Computadores podem ser big-endian (bytes em ordem com o mais significativo primeiro);
little-endian (bytes em ordem com o mais significativo ao final);
ou nenhuma organização em particular, com bytes dispersos. Acima disso, talvez eles nem
sejam alocados em sequência na memória. */

// Uma variável guarda um dado de um tipo específico, expresso na forma de bytes e armazenado na memória.
// Um ponteiro é simplesmente uma variável que guarda o endereço onde esse dado está.

// Ou seja: se temos um dado na memória, ele está em um endereço. O ponteiro é simplesmente uma variável que guarda esse endereço.
// Ela não guarda o dado, mas nos diz onde ele está.
// Será útil em chamadas de função.
// endereço de memória == ponteiro

void ptrs(void) {
  int num = 42;
  printf("O valor de nosso número é: %d \n", num);
  printf("E na memória ele está em: %p \n", &num);
  printf("E esse é um ponteiro para ele: %p \n", (void*)&num); // assim que se faz conversão de tipo no c, (tipo)var.
                                                               // estamos convertendo esse ponteiro para um ponteiro void
                                                               // ele é um "tipo sem tipo", então aceita qualquer quantidade de bytes.
}

int main (void) {
    ptrs();
    return 0;
}
