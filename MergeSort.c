#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double time1, timedif;

void merge(int *V, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *)malloc(tamanho * sizeof(int));
    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            V[k] = temp[j];
    }
}

void mergeSort(int *V, int inicio, int fim)
{
    int meio;
    time1 = (double)clock();
    time1 = time1 / CLOCKS_PER_SEC;
    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
    timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
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
        mergeSort(array,0, elementos); //Função
        timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;

       /* for (a = 0; a < 10; a++)
        {
            printf("\n%d\n", array[a]);
        }*/

        printf("\n--------------------------\nTeste:%d\n--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\n",i+1, timedif);
    }
    return 0;
}
