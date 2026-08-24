#include <stdio.h>
#include <stddef.h>

/* é possível descobrir o número de bytes deoffset que separam os campos da struct,
   por meio do operador offsetof() disponível em stddef.h.

   o funcionamento é o exato mesmo de sizeof(), retornando size_t,
   com a diferença de que recebe dois parâmetros: a struct e os membro específico
   para ser analisado.

   assim podemos inclusive descobrir se bytes de padding estão sendo usados,
   pois os offsets denunciariam a posição de cada dado.
*/

struct sala {
    int numero;
    char bloco;
    int maquinas;
    char *professor;
};


int main(void) {
    struct sala f04 = {
        .numero = 4,
        .bloco = 'F',
        .maquinas = 32,
        .professor = "Karython",
    };

    printf("Tamanho da struct: %zu\n", sizeof(struct sala));
    printf("Bytes de offset em número: %zu\n", offsetof(struct sala, numero));
    printf("Bytes de offset em bloco: %zu\n", offsetof(struct sala, bloco));
    printf("Bytes de offset em máquinas: %zu\n", offsetof(struct sala, maquinas));
    printf("Bytes de offset em professor: %zu\n", offsetof(struct sala, professor));

    printf("\n");

    int data_size = sizeof(f04.numero) + sizeof(f04.bloco)
    + sizeof(f04.maquinas) + sizeof(f04.professor);
    printf("Soma dos tamanhos dos dados: %d\n", data_size);

    return 0;
}

/* resultado:

   Tamanho da struct: 24
   Bytes de offset em número: 0
   Bytes de offset em bloco: 4
   Bytes de offset em máquinas: 8
   Bytes de offset em professor: 16

   ou seja: entre cada campo da struct existem quatro bytes, pois há intervalos de quatro em quatro
   entre o início da struct e os endereços dos campos específicos.
*/