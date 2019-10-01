#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double time1, timedif;

void insertion_sort(int num[1000000], int tam)
{
    int j, i, aux;
    for (int i = 1; i < tam; i++)
    {
        aux = num[i];
        j = i - 1;

        while ((j >= 0) && (num[j] > aux))
        {
            num[j + 1] = num[j];
            j--;
            cont++;
        }
        cont++;
        num[j + 1] = aux;
    }
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
                insertion_sort(array, elementos); //Função
                timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;




                 for (a = 0; a < 10; a++)
                 {
                     printf("\n%d\n", array[a]);
                 }

                printf("\n--------------------------\nTeste:%d\n--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\n",i+1, timedif);
            }
            return 0;
        }
