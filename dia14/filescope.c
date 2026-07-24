#include <stdio.h>

// há também o escopo de arquivo, que é global e vive durante toda a execução:
int n1 = 68;

// ele poderá ser acessível em qualquer função declarada após ele, e seu valor será visível em todas
// o ponteiro é o mesmo, então todas as alterações apontam para o mesmo valor!

void plus(void) {
    n1 += 50;
    printf("%d\n", n1);
}

void minus(void) {
    n1 -= 10;
    printf("%d\n", n1);
}

void times(void) {
    n1 *= 2;
    printf("%d\n", n1);
}

int main(void) {
    printf("%d\n", n1);
    plus();
    minus();
    times();

    // o valor alterado é visível em todas!
    return 0;
}

/* lembrete: isso não se mistura com o escopo de função, para as variáveis-parâmetro
 * passadas como atributos. para elas, uma cópia do valor passado com o nome atribuído
 * é utilizada, a menos que seja passada na forma de ponteiro, e não alteram o valor
 * inicial.
*/