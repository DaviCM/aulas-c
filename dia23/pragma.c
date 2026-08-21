#include <stdio.h>

/* a diretiva #pragma é curiosa: ela se revere à "pragmática".
   em teoria, é o estudo dos diferentes sentidos que o contexto
   traz para uma determinada diretiva.

   em c, isso significa que ela pode assumir vários papéis, de 
   acordo com o necessário, geralmente requisitada por uma do-
   cumentação, biblioteca ou pelo próprio padrão, quando precisa
   garantir que alguma coisa ocorre de uma forma bem específica.

   essas pragmas podem ser padrão ou não, e estão descritas em 
   diversas fontes. o compilador recebe a flag, caso as pragmas
   existam, sobre quais incluir.
*/


int main(void) {
    // uma pragma não-padrão: for loop em threads paralelas (openmp)
    #pragma omp parallel for
    for (int c = 0; c < 10; c++) {
        printf("eu estou rodando em threads paralelas!\n");
    };

    // precisa da flag -fopenmp para ser reconhecida. Não compilará com
    // a makefile que possuo no momento.

    /* uma pragma padrão: permitir que operações de ponto flutuante sejam
       tratadas como uma só ao invés de muitas pelo compilador, para evi-
       tar erros de arredondamento.
    */
   #pragma STDC FP_CONTRACT ON
    double n1 = 6.43432;
    double n2 = 5.13133;
    double n3 = 7.326354;

    // o compilador poderá tratar isso aqui como uma operação única, e isso
    // evita erros de arredondamento muito comuns em números de ponto flutuante.
    double n4 = (n1 * n2) + (n1 / n3) * 2 + 8.1;
    printf("double enorme: %f\n", n4);

    /* todas as pragmas padrão são full-caps, e começam com o nome da "fonte":
       STDC.
       após isso, trazem o nome da pragma e a diretiva para a ligar ou desligar,
       ON-OFF.
    */

    return 0;
}