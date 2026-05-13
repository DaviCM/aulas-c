#include <stdio.h>

int main(void) {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num); /* Especifica o tipo que queremos receber e o endereço onde devemos guarda-lo
    mas não vai quebrar se a gente inserir um valor de outro tipo, na verdade */
    switch (num) {
        case 5:
            printf("Número do Vettel e do Schumacher");
            break; /* Break tem que ser usado para sair da estutura switch-case, caso contrário ele retorna os demais resultados
            Se chama fall-through, e é um desastre */

        case 6:
            printf("Número do Rosberg \n");
            break;
        
        case 7:
            printf("Número do Kimi Raikkonen \n");
            break;
        
        case 12:
            printf("AAAAYYYYRTOOOON SENNA DO BRASIL \n");
            break;

        case 33:
            printf("Número do Max Verstappen \n");
            break;

        case 44:
            printf("Número do Hamilton \n");
            break;

        default:
            printf("Achamos um %d, ou algo que não é um int \n", num);
            break;
    };
    return 0;
}
