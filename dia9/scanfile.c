#include <stdio.h>

// Podemos fazer a mesma coisa do fprintf() com fscanf()
// Mas fscanf() tem um diferencial: Ela trata espaços como separadores de dados
// Assim, com um único fscanf() podemos pegar todos os dados sobre os tanques!
void scanfile(void) {
    FILE *tanques;
    tanques = fopen("./dia9/tanques.txt", "r");

    // Não alocar um tamanho na memória pode resultar no uso de uma variável não inicializada.
    char nome[1024];
    int canhao_mm;
    float peso;

    // fscanf() retornará EOF ao final do arquivo, e não NULL para uma string vazia como fgets()

    /*
    * Sintaxe: primeiro o arquivo FILE * a ser lido, após os tipos de dado separados pelo caractere espaçador,
    * no nosso caso espaço, e o endereço onde cada um deles deve ser salvo.
    */
    while (fscanf(tanques, "%s %d %f", nome, &canhao_mm, &peso) != EOF) {
        printf("Tanque: %s, Peso: %.2f T, Canhão: %d mm \n", nome, peso, canhao_mm);
    };

    fclose(tanques);
}


int main(void) {
    scanfile();
    return 0;
}