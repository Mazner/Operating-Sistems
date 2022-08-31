#include <stdio.h>
#include <stdlib.h>

#define QTD_FILHOS 2
#define VET_SIZE 11
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
            printf("%d\n", vetor[i]);
        }
        else
        {
            printf("%d - ", vetor[i]);
        }
    }
}

int verifica_vetor(int x, int j, int quantidade,int numero_procurado,int* vetor)
{
    for (j = x; j < x + quantidade; j++)
    {
        if (vetor[j] == numero_procurado)
        {
            printf("O valor %d foi encontrado na posicao %d do vetor\n", numero_procurado, j);
            return 1;
        }
    }
}

int main()
{
    int *vetor = cria_vetor_aleatorio(20);

    imprime_vetor(VET_SIZE, vetor);

    int quantidade = VET_SIZE / QTD_FILHOS; // quantidade de elementos para cada filho
    int resto = VET_SIZE % QTD_FILHOS;      // Caso haja resto, ele terá de ser colocado em algum filho

    // int* teste = cria_vetor_aleatorio(QTD_FILHOS);

    // Declaração das variáveis

    pid_t pid, pid2;
    int status = 0;
    int searched_number = SEARCH_FOR;
    int i = 0, j = 0, x = 0;
    int controle_quantidade = 0;

    pid = getpid();

    for (i = 0; i < QTD_FILHOS & pid != 0; ++i) 
    {
        pid = fork();   //Cria o processo filho

        if (pid >= 0)   
        {
            if (pid == 0)
            {
                if (i < resto)  //dividindo as partes para os filhos
                {
                    controle_quantidade = quantidade + 1;
                }
                else
                {
                    controle_quantidade = quantidade;
                }

                if (i < resto)
                {
                    x = i * (quantidade);       //Calcula a posição de início
                }
                else
                {
                    x = i * controle_quantidade + resto; //Coloca o valor do resto no filho (caso tenha resto)
                }

                verifica_vetor(x, j, controle_quantidade, searched_number, vetor); //Cada filho verifica o vetor com suas respectivas instruções
                return 0;
            }
        }
        else
        {
            printf("ERRO NA CRIAÇÃO DO PROCESSO FILHO\n");
            return -1;
        }
    }

    // Verifica qual filho encontrou o valor procurado
    if (pid)
    {
        x = 0;

        do
        {
            pid2 = wait(&status);
            if (WEXITSTATUS(status) != 0)
            {
                printf("Olha so! O filho %d encontrou o valor, parabens!\n", pid2);
            }
            x++;
        } while (x < QTD_FILHOS);
    }

    return 0;
}