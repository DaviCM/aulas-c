#include <stdio.h>

struct Product {
    int id;
    char *name;
    float price;
    int quantity;
    int sales;
};

// Uma struct pode ser um parâmetro, e será acessível na função assim;
// Mas como uma cópia dela é criada, não veremos mudança ao verificar o preço no lugar onde chamamos.
void set_price(struct Product to_set, int new_price) {
    to_set.price = new_price;
};

// Parâmetro aqui é um ponteiro para a struct. As alterações feitas nele serão refletidas no lugar onde chamamos.
void set_quantity(struct Product *to_set, int new_quantity) {
    // É preciso usar os parênteses nesse caso, para o dereference funcionar com a struct apenas e não tentar com 'to_set.quantity'.
    (*to_set).quantity = new_quantity;
};

void set_sales(struct Product *to_set, int new_sales) {
    // Agora vamos usar a versão mais idiomática do C
    // Arrow operator!
    to_set->sales = new_sales;

    // Mesma coisa dos parênteses, mas faz o dereference da struct automaticamente.
    // Tecnicamente é a forma correta quando temos struct*.
}


int main(void) {
    struct Product teclado = {
        .id=1,
        .name="55 teclas Multialaser",
    };

    set_price(teclado, 299.99);
    set_quantity(&teclado, 25);
    set_sales(&teclado, 99999);

    printf("id: %d \n", teclado.id);
    printf("nome: \"%s\" \n", teclado.name);
    printf("valor: R$%.2f \n", teclado.price); // Não vai aparecer no chamador, pois o valor alterado foi o da cópia.
    printf("quantidade em estoque: %d \n", teclado.quantity);
    printf("total de vendas: %d \n", teclado.sales);

    struct Product mouse;
    // Copiar uma struct não é como copiar uma string, podemos usar apenas o = para atribuir valor.
    mouse = teclado;
    
    return 0;
}


/* OBS

Cópias em C são sempre shallow-copy.
Shallow-copy é quando os ponteiros são simplesmente copiados, sem que o compilador crie o dado ao qual eles apontam novamente e crie outro ponteiro.
Isso seria uma deep-copy.
Sendo assim, os ponteiros são apenas copiados. um ponteiro em 'mouse' e um em 'teclado' guardariam o mesmo endereço de memória.
*/