#include <stdio.h>

/*
 * Agora chamaremos as funções de leitura e escrita binárias: respectivamente fwrite() e fread()
 *
 * Ambas recebem quatro parâmetros, então elas possuem quatro argumentos:
 * ponteiro para os dados que devem ser escritos (geralmente em forma de array), 
 * tamanho de cada elemento do conjunto de dados, 
 * número de dados,
 * stream de destino.
 * 
 * Tomar cuidado com decay to pointer aqui!
 */

void write_binary(void) {
    FILE *bin;
    unsigned char bytes[7] = {15, 23, 111, 112, 113, 42, 12};

    // Para manipular arquivos binários nós apenas adicionamos "b" ao modo, então o modo write (w)
    // se torna write binary (wb).
    bin = fopen("./dia10/bin_file.bin", "wb");

    fwrite(bytes, sizeof(unsigned char), 7, bin);
    fclose(bin);
}


void read_binary(void) {
    // fread funciona da mesma maneira, mas retornará o número de caracteres lidos ou 0 em caso de EOF.
    // Logo, pode ser tratada no loop: enquanto o valor for maior que 0, ele estará lendo.

    FILE *bin;
    unsigned char output;

    // rb == read binary!
    bin = fopen("./dia10/bin_file.bin", "rb");

    while (fread(&output, sizeof(unsigned char), 1, bin) > 0) {
        printf("%d \n", output);
    };

    fclose(bin);
}


int main(void) {
    write_binary();
    read_binary();
    return 0;
}

// NÃO ESQUECER:
// decay to pointer não acontece aqui, o escopo é o mesmo e não uma chamada de função. fwrite e fread 
// pedem o conjunto de um dos dados do conjunto, não de todos. Logo, sizeof(bytes) e sizeof(unsigned char) são diferentes.
// um pega o tamanho total = 1 * 7, 7 bytes por caractere. o outro pega apenas um byte, então cada dado deve ter apenas um.