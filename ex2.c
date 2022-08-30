/*
Faça um programa que receba um comando Linux como parâmetro e execute como um filho do
processo. O processo pai deve aguardar o término da execução do comando.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t process_id; // definindo o pid

    char *linux_command = "ls"; // Comando linux que será executado (no caso o ls)
    char *args[] = {"ls",
                    "-l",
                    NULL}; // Vetor de argumentos
    process_id = fork();   // Criação do processo filho

    switch (process_id) // Switch para a verificação do processo filho
                        // Utilizamos o switch para testar contra o if
    {
    case 0:
        execvp(linux_command, args); // Executa o comando (ls com os argumentos ls, -l, null)
        break;

    default:
        wait(NULL); // Código para aguardar a finalização do filho
        break;
    }
    printf("Finalizado");

    sleep(10);

    return 0;
}
