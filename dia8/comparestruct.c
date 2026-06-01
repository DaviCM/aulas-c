#include <stdio.h>
#include <string.h>

// não posso inicializar uma char *array[] sem passar o número de elementos; doideira!
struct dev {
    char *nome;
    char *linguagens[5];
    float loucura;
    int commits;
};


int main(void) {
    // Inicialização comum de struct.
    struct dev davi = {
        .nome = "Davi",
        .linguagens = {"Python", "C", "JavaScript", "Cobol", "Vibe Coding"},
        .loucura = 3.14,
        .commits = 999,
    };

    printf("nome: %s \n", davi.nome);
    printf("linguagens: ");
    
    for (int count = 0; count < 5; count++) {
        printf("%s, ", davi.linguagens[count]);
    };

    printf("\n");
    printf("nível de loucura: %f \n", davi.loucura);
    printf("commits: %d \n", davi.commits);

    // Setando todos os valores da struct para zero, seria útil para checar igualdade.
    memset(&davi, 0, sizeof(davi));
    printf("\n");

    printf("nome: %s \n", davi.nome);
    printf("linguagens: ");
    
    for (int count = 0; count < 5; count++) {
        printf("%s, ", davi.linguagens[count]);
    };

    printf("\n");
    printf("nível de loucura: %f \n", davi.loucura);
    printf("commits: %d \n", davi.commits);
    return 0;
}