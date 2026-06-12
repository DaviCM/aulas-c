#include <stdio.h>

void write_binary(void) {
    FILE *fp;
    fp = fopen("./dia10/bin_2.bin", "wb");
    
    // Dois números escritos em forma de hex: 0x42 e 0x78
    // São, respectivamente, 66 e 120
    unsigned short nums;
    nums = 0x4278;

    // Tem que ser um ponteiro para o que deve ser escrito
    fwrite(&nums, sizeof(nums), 1, fp);

    fclose(fp);
}


void read_binary(void) {
    FILE *fp;
    fp = fopen("./dia10/bin_2.bin", "rb");

    char buffer[1024];

    while (fread(buffer, sizeof(unsigned short), 1, fp) != 0) {
        printf("%d \n", buffer);
    };

    fclose(fp);
}


int main(void) {
    write_binary();
    read_binary();
    return 0;
}

