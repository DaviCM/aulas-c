#include <stdio.h>

/* diretiva embed do preprocessador: irá incluir no código o binário
   existente em um arquivo específico, todos os bytes que estão salvos
   nele.

   diretiva nova, do c23. o compilador com a flag mais moderna já
   reconhece a diretiva.

   cada elemento possui tamanho CHAR_BIT, ou o tamanho de um char, um byte,
   na memória. geralmente esse tamanho são 8 bits.
*/

int main(void) {
    FILE *fp = fopen("./dia23/arr.bin", "wb");

    unsigned char binary[5] = {0xa1, 0xa2, 0xa3, 0xa4, 0xa5};
    fwrite(binary, sizeof(unsigned char), 5, fp);
    fclose(fp);

    /* lembrete: sizeof(result), se estiver num escopo em qeu não foi
       decaído para ponteiro, retorna o número de bytes que a array 
       ocupa na memória, que é o número de elementos multiplicado pelo
       tamanho de cada um.
    */
    int result[] = {
        #embed "arr.bin"
    };

    for (unsigned count = 0; count < 5; count++) {
        printf("hex na posição %d: %x\n", count, *(result + count));
    };

    return 0;
}