#include <stdio.h>

/* o padrão C possui vários macros-padrão que dão, em tempo de
   compilação, informação sobre o sistema, o compilador, o am-
   biente de execução, a função chamando o macro e várias outras
   informaçẽos que podem vir a ser convenientes.
*/

int main(void) {
    printf("__DATE__: data da compilação: %s\n", __DATE__);
    printf("__TIME__: horário da compilação: %s\n", __TIME__);
    printf("__FILE__: nome do arquivo binário: %s\n", __FILE__);
    printf("__LINE__: linha do código em que chamei esse macro: %d\n", __LINE__);
    printf("__func__: nome da função que chama o identificador: %s\n", __func__);
    printf("__STDC__: verificando se esse compilador está de acordo com o padrão C: %d\n", __STDC__);
    printf("__STDC_HOSTED__: Verificando se estamos num compilador \"hosted\": %d\n", __STDC_HOSTED__);
    printf("__STDC_VERSION__: versão do C usada na compilação: %ld\n", __STDC_VERSION__);

    return 0;
}

/* obs:
   um "c standard hosted" basicamente sigifica que estamos rodando num host, 
   um sistema que possui sistema operacional por trás. o contrário seria uma
   implementação standalone do C, que significa que você está rodando direta-
   mente sobre o hardware.

   esse macro garante a existência da libc padrão completa, o gateway main()
   para execução e que as headers esperadas para o ambiente estarão todas im-
   plementadas.



   obs²: __func__ não é um macro, ele é um valor variavel que diz o nome da 
   função em que ele está sendo chamado, em forma de string. mas seu uso
   é identico ao dos macros-padrão.
*/