/* o C possui um preprocessador que é crucial no processo de compilação,
pois interpreta os marcos e definições fornecidas via # nos arquivos.

o primeiro deles é #include, geralmente utilizado com as headers. seu
papel é extremamente simples muito utilizado: ele inclui, literalmente,
o conteúdo do arquivo descrito no código fonte.
pode ser incluído por meio de <> para inclusões system-wide, presentes
na pasta /usr/include.
também pode ser incluída por meio de "", para arquivos locais.
*/

#include <stdio.h>

// Um macro: #define
// Identifica os caracteres passados como primeiro valor e substitui pelo segundo.
#define HELLO "Hello, world!\n"
#define NUM 4.24523453

/* não é a mesma coisa que declarar variáveis no código, substituir um por outro
   é má prática. O compilador não identifica os tipos de um define, apenas substitui
   exatamente os valores. se o valor for inválido, o compilador irá falhar.
*/

// Também é possível declarar um macro vazio:
#define NOTHING

// assim, se "NOTHING" for referenciado no código, será substituído por nada.

// É usado para criar labels para valores que com certeza serão os mesmos na compilação,
// diferentemente de variáveis const, que não podem ser casos num switch, por exemplo.

int main(void) {
    printf("%f: %s", HELLO, NUM);
    return 0;
}