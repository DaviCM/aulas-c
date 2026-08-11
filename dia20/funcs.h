// funcs.h: um arquivo header!

/* arquivos header provém os protótipos para as funções declaradas nos arquivos-fonte,
   e apenas assim C consegue saber os parâmetros que a função recebe, para serem pas-
   sados como argumentos, seus nomes, tipos de retorno e afins.

   assim evitamos o erro de declaração implícita de função do compilador, que indica
   que fizemos besteira.
*/

// equivalente a escrever os protótipos no próprio arquivo, mas bem mais conveniente!

/* e isso é uma diretiva do preprocessador: ele vai saber que só um arquivo precisa 
   fazer #include, porque #include em sequência causam problemas com o compilador
   ou erros de dependências circulares, que são loops infinitos de importação.

   ifndef basicamente diz que, se BAR_H, o nome que demos para todo o arquivo,
   ainda não foi definido (então não foi incluido), devemos o fazer.

   se já tiver sido, absolutamente nada acontece.
*/

/* os protótipos em si só precisam ser linkados uma vez, o #include serve para o
   compilador interpretar corretamente os headers que cada arquivo precisa, para 
   executar corretamente seu código. 
*/ 

#ifndef BAR_H
#define BAR_H


void print_str(char *dst, char* str);

void *memcpy_rw(void *dst, void *src, int size);

int randint();

#endif