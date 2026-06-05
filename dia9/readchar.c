#include <stdio.h>

int main(void) {
    // Essas duas funções compilam para a mesma coisa, pois o FILE * "stdout" passado ao fprintf é o caminho padrão do printf.

    printf("Hello, world do printf! \n");
    fprintf(stdout, "Hello world do fprintf! \n");

    FILE *ola;

    // o "r" significa read, iremos ler do arquivo. mesmo sendo apenas um char, passamos com aspas duplas porque o tipo é char *.
    ola = fopen("./dia9/oi.txt", "r");

    // fgetc: Pega exatamente um caractere do arquivo passado em FILE *, o primeiro que encontrar.
    // A função retorna o código do caractere em int, mas mostramos na tela como str.    
    printf("Lemos isso de oi.txt: \"%c\" \n", fgetc(ola));
    
    /*
    * além disso, podemos utilizar fgetc() em sequência para pegar todos os caracteres da página
    * existe um caractere implícito, com valor int, que indica o final da cadeia de texto do arquivo: 
    * ele é um macro do preprocessador C denominado EOF
    * (end of file)
    * por isso também fgetc() retorna int: EOF possui um valor maior do que o encoding de um char
    * então podemos comparar cada caractere com ele e, se nao acharmos, continuamos:
    */
    
    int letra;
    while ((letra = fgetc(ola)) != EOF) {
        printf("%c", letra);
    }

    // fgetc() irá ler todos os caracteres restantes, pois o primeiro já foi lido por ele anteriormente.
    fclose(ola);
    return 0;
}