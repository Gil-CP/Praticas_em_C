#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(int *linhas, int *colunas);

int main()
{
    //Variáveis e funções auxiliares
    int linhas, colunas;
    menu(&linhas, &colunas);
    srand(time(NULL));


    //Declaração de matrizes (semelhante a vetores)
    int m1[][2] = {1, 2, 3, 4,}; //Define uma matriz com 2 colunas e uma quantidade variável de linhas
    int m2[3][3];

    //Criação de matriz exemplo
    int matriz[linhas][colunas];

    //Percorrendo e preenchendo uma matriz
    for (int l = 0; l < linhas; l++)
    {
        for (int c = 0; c < colunas; c++)
        {
            matriz[l][c] = rand()%100;
        }
        
    }

    //Imprimindo resultado de matrizes
    for (int l = 0; l < linhas; l++)
    {
        for (int c = 0; c < colunas; c++)
        {
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }
    
    return 0;
}
void menu(int *linhas, int *colunas)
{
    printf("Informe a quantidade de linhas: \n");
    scanf("%d", linhas);
    printf("Informe a quantidade de colunas: \n");
    scanf("%d", colunas);
}