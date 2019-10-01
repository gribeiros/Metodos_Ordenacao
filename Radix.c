#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double time1, timedif;

void radixsort(int vetor[], int tamanho)
{
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior/exp > 0)
    {
        int bucket[10] = { 0 };
        for (i = 0; i < tamanho; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanho - 1; i >= 0; i--)
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanho; i++)
            vetor[i] = b[i];
        exp *= 10;
    }

    free(b);
}


int main(void)
{
    int a, elementos = 10; //Troque para quantidade de elementos que vai ser ordenada
    int *array=(int*)malloc(elementos*sizeof(int));
    srand(time(NULL));
    for(int i=0; i<30; i++)
    {
        for (a = 0; a < elementos; a++)
        {
            array[a]=rand()%100;
        }

        time1 = (double)clock();
        time1 = time1 / CLOCKS_PER_SEC;
        radixsort(array, elementos); //Função
        timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;




        for (a = 0; a < 10; a++)
        {
            printf("\n%d\n", array[a]);
        }

        printf("\n--------------------------\nTeste:%d\n--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\n",i+1, timedif);
    }
    return 0;
}

