#include <stdio.h>

/* existem alguns parâmetros para um #embed, todos bem objetivos:
    if_empty(), que recebe os valores para substituir no resultado
    caso o #embed esteja chamando um arquivo sem bytes escritos,

   limit(), que recebe o limite de valores que podem ser lidos.

   prefix(), que recebe valores para colocar como prepend (ao início)
   aos bytes lidos. será ignorada se o arquivo estiver vazio.

   suffix(), que recebe valores para colocar como append (ao fim)
   aos bytes lidos. será ignorada se o arquivo estiver vazio.
   
   e um check para verificar se um arquivo pode receber embed:
   __has_embed(), que recebe filename.
   este verifica se o arquivo existe, se seu tamanho é inteiro e se
   os parâmetros limit(), prefix() e suffix() podem ser aplicados nele.

   __has_embed() pode ser utilizado com a diretiva #if do prepreocessador,
   pois condiciona a compilação para os casos em que o valor binário
   está disponível e os em que não está.

   __has_embed() também pode responder se algum dos parâmetros-padrão, 
   assim como outros que não fazem parte de stdc, estão disponíveis.
   o uso seria:
   #if __has_embed("caminho/do/arquivo" suffix(5)),

   ou pode ser utilizado com o arquivo-fonte para sempre resultar em 
   um valor positivo:
   #if __has_embed(__FILE__ suffix(5))
*/


int main(void) {
    
    return 0;
}