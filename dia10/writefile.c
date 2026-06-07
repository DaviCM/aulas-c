#include <stdio.h>


void write_to_hello(void) {
    FILE *hello;
    float pi = 3.141592;

    // fopen no modo "w" para abrir o arquivo
    hello = fopen("./dia10/hello.txt", "w");
    
    fputc('A', hello);
    fputc('\n', hello);
    // fputs não precisa do buffer para armazenar a string, apenas a string que precisa ser escrita.
    fputs("Hello world do fputs! \n", hello);

    fprintf(hello, "Hello world, mas do fprintf! \n");

    fprintf(hello, "PI ≃ %f \n", pi);

    fputc('\n', hello);

    fclose(hello);
}


void read_of_hello(void) {
    FILE *hello2;
    hello2 = fopen("./dia10/hello.txt", "r");
    int count = 1;

    char read[1024];
    while (fgets(read, sizeof(read), hello2) != NULL) {
        printf("%d: %s", count, read);
        count++;
    };

    fclose(hello2);
}


int main(void) {
    write_to_hello();
    read_of_hello();
    return 0;
}