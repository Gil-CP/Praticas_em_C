#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu();

int main()
{
    //Formas de declarar um vetor
    int v1[5];
    char v2[] = {'a','b','c'};
    float v3[4] = {1.2,2.3}; //Os demais endereços de memória serão preenchidos com 0
    int vet[3] = {0}; //Cria um vetor de tamanho 3 e inicializa com 0

    //Define o tamanho do vetor e cria um vetor do tamanho definido
    int tam;
    tam = menu();
    int vetor[tam];

    //Preenchendo o vetor com valores aleatorios
    //A função srand define a seed da função rand
    //A função time passa a informação da hora da máquina
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
    {
        //Função rand gera números a partir de uma seed
        vetor[i] = rand()%50;
        //%50 limita os números de 0 a 50
    }
    //Imprimindo vetor
    printf("Vetor: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d, ", vetor[i]);
    }
    
    
    return 0;
}
int menu()
{
    int tam;
    printf("Qual o tamanho do seu vetor?\n");
    scanf("%d", &tam);

    return tam;
}
