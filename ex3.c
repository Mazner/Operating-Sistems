#include <stdio.h>
#include <stdlib.h>

#define FILHOS 5
#define VET_SIZE 10
#define SEARCH_FOR 63

int *cria_vetor_aleatorio(int size) // Função que cria um vetor com valores aleatórios
{
    int *vetor = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        vetor[i] = rand() % 100 + 1;
    }
    return vetor;
}

void imprime_vetor(int size, int *vetor) // Função que imprime o vetor
{
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%d", vetor[i]);
        }
        else
        {
            printf("%d - ", vetor[i]);
        }
    }
}

int main()
{
    int *vetor_a = cria_vetor_aleatorio(20);

    imprime_vetor(VET_SIZE, vetor_a);

    int quantidade = VET_SIZE / FILHOS;
    int resto = VET_SIZE % FILHOS;

    /*Criar funções:
    Incialização dos filhos;
    Buscar elementos, escolher por onde começar etc
    */
    return 0;
}