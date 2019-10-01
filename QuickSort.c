#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double time1, timedif;

void quick_sort(int a[100000], int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    time1 = (double)clock();
    time1 = time1 / CLOCKS_PER_SEC;

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            cont++;
        }
    }

    if (j > left)
    {
        quick_sort(a, left, j);
    }
    if (i < right)
    {
        quick_sort(a, i, right);
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
        quick_sort(array, 0,elementos); //Função
        timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;




        for (a = 0; a < 10; a++)
        {
            printf("\n%d\n", array[a]);
        }

        printf("\n--------------------------\nTeste:%d\n--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\n",i+1, timedif);
    }
    return 0;
}
