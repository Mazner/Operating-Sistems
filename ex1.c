/*
Faça um programa que crie uma hierarquia de processos com
N níveis (1 + 2 + 4 + 8 + … + 2N-1) processos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 3 // níveis de processos

int main()
{
    int process_ids[SIZE]; // vetor de id de processos

    for (int i = 0; i < SIZE; i++) // Laço itera o tamanho pré-definido
    {
        process_ids[i] = fork(); // O vetor na posição i recebe o id retornado
    }
    sleep(5);
    return 0;
}
