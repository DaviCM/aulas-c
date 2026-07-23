#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dynamic_buffer(FILE *stream) {
    int count = 0;
    int size = 4;
    int c;
    char *buffer;
    char *spare;

    buffer = malloc(size);

    // tratamento de erro na alocação de memória, comum ao lidar com malloc() e realloc()
    if (buffer == NULL) {
        return NULL;
    };

    while ((c = fgetc(stream)), c != EOF && c != '\n') {

        /*
         * o espaço ocupado pelo caractere atual não pode 
         * ser menor que o tamanho do próximo + espaço para o \0
        */ 

        // - pois deve ser levado em consideração o próximo caractere e o null terminator (count e count + 1)
        if (count == size - 1) {
            size *= 2;

            spare = realloc(buffer, size);
            if (spare == NULL) {
                free(buffer);
                return NULL;
            };
            
            buffer = spare;
        };
        
        buffer[count] = c;
        count++;
    };
    
    // libera a memória se nenhum caractere tiver sido lido (não entrou no loop).
    if (count == 0 && c == EOF) {
        free(buffer);
        return NULL;
    };

    // aloca a memória com especificamente a contagem final de caracteres, que já leva em consideração o \0 
    // (post-increment após o último loop)
    spare = realloc(buffer, count);
    if (spare == NULL) {
        free(buffer);
        return NULL;
    };

    buffer = spare;
    buffer[count] = '\0';

    printf("count: %d\n", count);
    printf("size: %d\n", size);
    printf("strlen: %zu\n", strlen(buffer));
    
    return buffer;
}


int main(void) {
    FILE * stream = fopen("./dia13/verdade.txt", "r");
    
    char *str;
    while ((str = dynamic_buffer(stream)) != NULL) {
        printf("%s\n", str);
        printf("\n");

        /* a memória tem que ser livrada onde a função foi chamada, pois dynamic_buffer() está
         * retornando um ponteiro que foi alocado via malloc(),  
         * e essa memória não será automaticamente liberada.
        */
       
        free(str);
    };

    fclose(stream);
    return 0;
}

/* lembrete: existe um offset de um entre count e strlen, (off by one!)
 * pois count começa da posição 0 e strlen da posição 1,
 * então como ambos param no mesmo caractere, significa que:
 * count: 74 representa strlen: 75
 * 
 * e é por isso que buffer[count] = '\0' funciona, pois ele sempre estará em buffer[strlen + 1]
 * e o caractere imediatamente após strlen sempre é o \0 (null terminator).
 * 
 * a função strlen() não leva em consideração o null terminator.
 * 
*/