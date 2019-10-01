#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double time1, timedif;

void bubble(int *v,int tam)
        {
            int i,j,temp,aux;
            if(tam)
                for(j=0; j<tam-1; j++)
                {
                    aux=0;
                    for(i=0; i<tam-1; i++)
                    {
                        if(v[i+1]<v[i])
                        {
                            temp=v[i];
                            v[i]=v[i+1];
                            v[i+1]=temp;
                            aux=1;
                        }
                    }
                    if(!aux)
                        break;
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
                bubble(array, elementos); //Função
                timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;




                 for (a = 0; a < 10; a++)
                 {
                     printf("\n%d\n", array[a]);
                 }

                printf("\n--------------------------\nTeste:%d\n--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\n",i+1, timedif);
            }
            return 0;
        }
