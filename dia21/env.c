#include <stdio.h>
#include <stdlib.h>

/* é possível manipular as variáveis de ambiente por meio do C.

   ambiente se trata do ambiente de execução, que no nosso caso
   é o terminal. o bash (shell) clona-se quando o terminal o chama
   e depois troca o processo filho, seu clone, para o programa que
   executamos. seu resultado é retornado, após isso, ao stdout.
   
   o terminal pode adicionar suas próprias variáveis, valores no
   formato chave=valor que guardam informação sobre aplicativos,
   configurações do próprio terminal e informações do host.

   para acessar as variáveis, podemos utilizar três métodos:
   - a função getenv() da stdlib
   - o parâmetro char **envp da main, que captura todas as 
   env vars presentes no sistema.
   - chamando a variável extern **environ, que existe no 
   compilador e em unistd.h.

   para criar uma variável, setenv().
   para deletar uma variável, unsetenv().
*/

int main(void) {
    extern char **environ;

    char *host = getenv("HOSTNAME");
    printf("O nome do host (máquina) é: \"%s\"\n", host);

    char *shell = getenv("SHELL");
    printf("shell ativo no momento: \"%s\"\n", shell);

    // ! PERIGO: IRÁ SETAR A ENV VAR
    // parâmetros: chave, valor, overwrite
    /* overwrite, se for != 0, irá sobrescrever uma variável já de-
       clarada com o mesmo nome. se for == 0, não fará isso.
    */

    /*
    setenv("GIRLS", "PANZER", 1); // não faz parte do padrão C, e sim de POSIX.

    char *girls = getenv("GIRLS");
    printf("Agora a variável GIRLS existe: \"%s\"\n", girls);

    // destrói a variável de ambiente.
    unsetenv("GIRLS"); // não faz parte do padrão C, e sim de POSIX.
    */

    printf("\n");
    printf("Printando todas as env vars via **environ!\n\n");

    char **vars = environ;
    while (*vars != NULL) {
        printf("%s\n", *vars++);
    };

    return 0;
}

/* a diferença, para pegar env vars, é a seguinte:
   - getenv() é da implementação padrão do C.

   - **environ não é parte do padrão C, mas funciona em sistemas
   POSIX por ser parte do padrão.

   - **envp não é nem do padrão C e nem do padrão POSIX, mas é
   comum em sistemas Unix-like.
   
   o funcionamento é essencialmente o mesmo, com a diferença
   que getenv() é portátil e não exige que você itere sobre
   uma array com as env vars, como as outras duas opções.

   dentre todas, getenv().
   dentre as arrays, environ - é padrão.
*/