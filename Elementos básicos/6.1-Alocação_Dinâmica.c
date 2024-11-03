#include <stdlib.h>
#include <stdio.h>

//Alocação dinâmica de matrizes

int main()
{
    //Necessário a utilização de ponteiros para ponteiros
    int **matriz;
    int qtd_linhas, qtd_colunas;

    printf("Digite a quantidade de linhas e colunas da matriz: \n");
    scanf("%d %d", &qtd_linhas, &qtd_colunas);

    //Aloca/ determina a quantidade de linhas
    matriz = calloc(qtd_linhas, sizeof(int *));
    if(matriz == NULL)
    {
        printf("Erro!\n");
    }
    else
    {
        for(int i = 0; i < qtd_linhas; i++)
        {
            matriz[i] = calloc(qtd_colunas, sizeof(int));
            
            if(matriz[i] == NULL)
            {   
                printf("Erro de alocação!");
            }
            
        }

        for(int i = 0; i < qtd_linhas; i++)
        {
            printf("Linha[%d] -> ", i);

            for(int j = 0; j < qtd_colunas; j++)
            {
                //Aritmética de ponteiros com matrizes
                printf("%d ", *(*(matriz + i) + j));
            }
            printf("\n");
        }

    }

    for(int i = 0; i <qtd_linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

}