#include <stdio.h>

int main(void) {
    int numero; // um int!
    int *to_numero; // um ponteiro para um int, leva para o endereço de memória onde há um inteiro

    to_numero = &numero; // o ponteiro agora guarda o valor do int que declaramos
    
    // aqui o C vai usar "sobrecarga de operador", então é pra prestar atenção

    numero = 42;
    *to_numero = 39;

    printf("Nosso valor final é: %d \n", numero);
    return 0;
}

/* 
na declaração, * define o tipo int*, um ponteiro para um int
nós igualamos esse ponteiro ao endereço de memória de uma variável int. Ele agora "referencia" numero
Depois, nós atribuímos um valor à variável
E depois usamos o indirection operator para "desreferenciar" o ponteiro
Ou seja: utilizamos ele para acessar o valor do endereço de memória que o ponteiro guardava.
Nesse caso o valor é o valor de numero, então nós alteramos ele diretamente.
 */

// Estamos dizendo ao C para usar o valor na memória que o ponteiro está apontando, não o ponteiro em si.