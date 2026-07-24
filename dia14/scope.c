#include <stdio.h>

int main(void) {
    /* Em C, o escopo (brackets) delimita o campo onde uma variável será reconhecida. 
     * Isso significa que variáveis criadas dentro de if, for, while ou até blocos separados não serão visíveis, 
     * e resultarão em erros do compilador se forem chamadas fora do escopo.
     * Além disso, obviamente, todas as variáveis devem ser inicializadas antes de serem chamadas.
     * 
     * lembrete:
     * uma variável vive num escopo enquanto esse escopo existir.
    */

    // ex:
    int n1 = 15;
    {
        int n2 = 23;
    };
    printf("%d\n", n1);
    // printf("%d\n", n2) // ilegal, n2 não existe nesse escopo.

    int n2 = 29;
    printf("%d %d\n\n", n1, n2); // perfeitamente legal!




    /* outra questão de escopo: precedência
     * se existirem duas variáveis com o mesmo nome em escopos diferentes, a que está no escopo mais interno será a considerada.
     * isso se chama "esconder" a variável, ela esconde (e ignora) o valor no escopo externo enquanto o interno está em execução.
    */

    // ex:
    float fl1 = 3.00;
    for (float fl1 = 2.00; fl1 < 3.14; fl1 *= 1.165) {
        // valor inicial será 2.00, devido ao escopo de declaração do for loop ser mais interno.
        printf("%.2f\n", fl1); 
    };
    // aqui o valor exibido será 3.00, pois o escopo interno foi encerrado e as variáveis também.
    printf("\n%.2f\n\n", fl1); 




    /* outra questão com for loops: 
    * é possível esconder a variável declarada na formulação do loop, e o resultado é curioso:
    */
   
   // ex:
    for (int n3 = 0; n3 < 5; n3++) {
        int n3 = 67;
        printf("%d\n", n3);
    };

    /* sim: ele printa 67 cinco vezes. A razão é que o escopo da declaração do for loop é mais externo que o escopo de dentro do loop,
     * então o valor que n3 representa nas iterações é escondido pelo valor que ele representa dentro do loop,
     * mas ele ainda existe e é usado no escopo mais externo, é inafetado pelo interno.
    */

   return 0;
}

// sim: é possível segmentar blocos sem nenhuma expressão anterior, e eles criam um escopo próprio.

