#include <stdio.h>

void read_oi_chars(void) {
    FILE *ola = fopen("./dia9/oi.txt", "r");

    // Igualo o valor a fgetc antes e depois da iteração, para o valor ser atualizado!
    for (int c = fgetc(ola); c != EOF; c = fgetc(ola)) {
        printf("%c", c);
    };
    printf("\n");

    // a notação while é bem mais limpa:
    /*
    int c;
    while ((c = fgetc(ola)) != EOF) {
        printf("%c", c);
    };
    */
   fclose(ola);
}


// Agora vamos ler tudo de uma vez, que é muito mais simples!
void read_oi_string(void) {
    FILE *ola = fopen("./dia9/oi.txt", "r");
    char line[512]; 
    // evitando erro de overflow no buffer do fgets, quando ele lê uma linha.
    // o segundo parâmetro do fgets é um buffer, que precisa de espaço para armazenar todos os caracteres da linha.

    fgets(line, sizeof(line), ola);
    printf("%s \n", line);

    fclose(ola);
}


void read_pc_file(void) {
    FILE *pc = fopen("./dia9/pc.txt", "r");
    char line[512];
    int count = 1;
     
    // fgets() retornará null ao encontrar EOF!
    while (fgets(line, sizeof(line), pc) != NULL) {
        printf("%d: %s", count, line);
        count++;
    };
    printf("\n");
    fclose(pc);
}


int main(void) {
    read_oi_chars();
    read_oi_string();

    printf("\n");

    read_pc_file();
    return 0;
}