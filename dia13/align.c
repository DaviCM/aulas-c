#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // alocando 64 bytes num alinhamento de 8
    int *nt = aligned_alloc(8, 64);
    return 0;
}

/* também existe uma forma de alocar memória em um "alinhamento" específico, o que significa que:
 * um dado é guardado em um endereço de memória, ou ponteiro, que se localiza em uma posição de
 * valor múltiplo do tamanho desse tipo de dado.
 * 
 * ex:
 * digamos que nós temos uma variável int, e sizeof(int) é 8 bytes
 * então, para alocar um int num endereço de acesso rápido ele precisa ser colocado num endereço
 * com posição num múltiplo ou divisor de 8, como 2 ou 64;
 * 
 * isso em x86 é questão de otimização, mas em embarcados é determinante para o funcionamento do cpu
 * e um requisito de sua arquitetura.
 * 
 * então, você chama aligned_alloc() e passa o alinhamento e tamanho desejados.
 * 
 * o número de bytes alocados também precisa ser um múltiplo/divisor do alinhamento. 
*/

// obs: endereço de memória == valor guardado no ponteiro, geralmente aparece em forma hexadecimal.