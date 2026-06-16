#include <stdio.h>
#include <string.h>

void write_binary_string(void) {
    FILE *fp;
    char *ola = "Olá, meus queridos amigos!";

    fp = fopen("./dia10/bin_3.bin", "wb");
    
    // fwrite(ola, sizeof(ola), 1, fp);
    fwrite(ola, strlen(ola), 1, fp);

    // Descobri o comportamento: um sizeof(ola) para ola sendo char* irá retornar o tamanho do ponteiro, não da array inteira alocada;
    // por que ela não foi alocada, apenas o tamanho do ponteiro foi.
    // na memória fica armazenado apenas o ponteiro, e a leitura sequencial acontece só quando a string é acessada.
    fclose(fp);
}


void read_binary_string(void) {
    FILE *fp;
    char buffer;

    fp = fopen("./dia10/bin_3.bin", "rb");
    
    // Lembrete: fread() retorna zero quando chega ao EOF.
    while (fread(&buffer, sizeof(char), 1, fp) != 0) {
        printf("%c", buffer);
    };
    printf("\n");
    
    fclose(fp);
}


int main(void) {
    write_binary_string();
    read_binary_string();
    return 0;
}


/* Fato curioso: quando eu chamo write_binary_string() com a string na forma de ponteiro, ele não escreve a string toda.
 * Suspeito que tenha a ver com o fato de ponteiros ocuparem espaço de memória protegido, então geram algum conflito
 * na hora de serem escritos no arquivo.
 */

// não era isso, mas foi um bom palpite.