#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    /* __pid_t pid = fork(); variáveis que começam com __ são identificadores reservados do sistema
    não devem ser chamados diretamente */
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("(filho) Olá mundo, eu sou um clone! \n");
        printf("(filho) Meu PID é: %d \n", getpid());
        printf("(filho) E esse é meu pai: %d \n", getppid());
    }
    else {
        printf("(pai) Eu não sou um clone! \n");
        printf("(pai) Meu PID é: %d \n", getpid());
        printf("(pai) E esse é meu pai: %d \n", getppid());
        printf("(pai) Meu pai é, na verdade, o shell! \n\n");
    };
};