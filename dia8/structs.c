#include <stdio.h>

// Structs em C são como objetos em linguagens OOP, mas sem a possibilidade de declaração de métodos específicos para elas.
// Basicamente são schemas, com atributos que salvam dados.
struct User {
    int id;
    char* username;
    char* password;
    float balance;
    float *to_balance;
};


int main(void) {
    // Iniciando uma struct passando os valores manualmente. não é a forma mais elegante.
    // Mas utiliza o dot operator, como em objetos de outras linguagens.
    struct User davi;
    davi.id = 1;
    davi.username = "davicm";
    davi.password = "algumhash";
    davi.balance = 999.99;
    davi.to_balance = &davi.balance;

    // Inicializando uma struct da forma correta: passando os valores diretamente. Aqui eles devem estar em ordem.
    // Não dá pra fazer isso em uma struct já inicializada, tem que acontecer na inicialização.
    struct User davai = {
        2, 
        "davaicm", 
        "algumhash", 
        2999.99, 
        &davai.balance,
    };

    // Aqui passamos os valores dos atributos por seus nomes. não existe 'self', então fazemos isso apenas com .nome-do-atributo.
    // Os valores não inicializados serão zero, e os não numéricos aparecerão como null por padrão.
    // Porque não há nada na memória instanciado para eles.
    struct User davis = {
        .id=3,
        .username="daviscm",
        .balance=0,
    };

    printf("Davi \n");
    printf("id: %d \n", davi.id);
    printf("username: %s \n", davi.username);
    printf("senha: %s \n", davi.password);
    printf("saldo: %f \n", davi.balance);
    printf("ptr para o saldo: %p \n", (void*)davi.to_balance);

    printf("\n");

    printf("Davai \n");
    printf("id: %d \n", davai.id);
    printf("username: %s \n", davai.username);
    printf("senha: %s \n", davai.password);
    printf("saldo: %f \n", davai.balance);
    printf("ptr para o saldo: %p \n", (void*)davai.to_balance);

    printf("\n");

    printf("Davis \n");
    printf("id: %d \n", davis.id);
    printf("username: %s \n", davis.username);
    printf("senha: %s \n", davis.password);
    printf("saldo: %f \n", davis.balance);
    printf("ptr para o saldo: %p \n", (void*)davis.to_balance);

    return 0;
}