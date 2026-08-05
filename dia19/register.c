#include <stdio.h>

int main(void) {
    /* a keyword "register" significa que a variável deve ser colocada
       em algum lugar, pelo compilador, em que possa ser acessível
       o mais rápido possível, sempre que necessário.

       originalmente esse lugar seriam as registradoras de memória do cpu,
       mas hoje em dia esse comportamento não é garantido.

       novamente uma keyword mais útil em compiladores para embarcados,
       e o compilador não obrigatóriamente precisa seguir. ainda assim,
       é útil ocasionalmente.
    */

    // essa variável será colocada onde pode ser prontamente acessada!
    register int fast = 15;
    for (int c = 0; c < 10; c++) {
        printf("%d\n", fast++);
    };

    printf("\n");

    // no entanto, tanta velocidade tem um custo:
    // int *p = &fast; // ERRO! não será possível acessar essa variável via pointer.

    // numa array register, todos os seus elementos estão "protegidos" contra dereferencing
    // e também contra seus valores sendo referenciados em outros ponteiros.
    register int hex[] = {0x16, 0x17, 0x18, 0x19, 0x1a};

    // isso aqui é apenas um aviso, mas não é recomendado fazer isso.
    int pk = hex[3];

    // ERRO! Não é possível acessar elementos de uma array register por notação de ponteiro.
    // int pk = *(hex + 3); 

    printf("elemento de uma array register: %#x\n", pk);
    printf("a especificação permite, mas não recomenda.\n");

    return 0;
}

/* você pode declarar um ponteiro como register e const, com o efeito de evitar
   que uma função altere o valor ao qual esse ponteiro está apontando por engano.
   const em variáveis impede que o valor mude, mas ele ainda pode ter seu endereço
   pego e depois instanciado em outro ponteiro.

   com const, não só o valor não muda como o valor jamais poderá ser acessado 
   via ponteiro sem avisos.

   arrays register, como não podem ser referenciadas na forma de ponteiro, são
   largamente inúteis: geralmente elas decaem para ponteiro, e assim
   não podem ser usadas.
*/