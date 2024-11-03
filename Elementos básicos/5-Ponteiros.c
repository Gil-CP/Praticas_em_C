//Ponteiro -> variável que armazena (aponta) o endereço de memória de outra variável do mesmo tipo

#include <stdio.h>
#define TAM 5

typedef struct 
{
    int dia, mes, ano;
}Data;

int main()
{
    int vetor[TAM];
    int variavel = 5;
    printf("Variavel: %d\n", variavel);

    //Declara um ponteiro do tipo inteiro, ou seja, cria uma variável que armazena o endereço de memória de um tipo inteiro
    int *ponteiro;
    //Passa o endereço de uma variável
    ponteiro = &variavel;
    //Operador * indica que o que deve ser manipulado é o conteúdo do ponteiro, portanto a variável que ele aponta
    *ponteiro = 20;
    printf("Variável atualizada: %d\n\n", variavel);

    printf("------------------------------------------------------------------------------------------------------------\n");

    //Demonstrando a o operador '*'
    //Para imprimir um endereço de memória é necessário a utilização da mascara p
    printf("Endereco da variave: %p\n", &variavel);
    printf("Conteúdo do ponteiro: %p\nConteúdo variavel apontada pelo ponteiro: %d\n\n", ponteiro, *ponteiro);

    //Aritmética de ponteiro os operadores "+" ou "-" quando utilizados com um ponteiro indicam o próximo ou o endereço de memória anterior
    
    printf("------------------------------------------------------------------------------------------------------------\n");

    //Manipulando um vetor utilizando aritmética de ponteiros
    for(int i = 0; i <  TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            *(vetor + i) = i;
        }

        printf("Posicao %d -> %d\n", i, *(vetor + i));
    }

    printf("------------------------------------------------------------------------------------------------------------\n");
    //Detalhe ao utilizar uma estrutura que está sendo apontada por um ponteiro, então deverá ser utilizado o operador '->' no lugar do operador '.'
    Data data;
    Data *ponteiroData;

    ponteiroData = &data;

    ponteiroData->dia = 20;
    ponteiroData->mes = 10;
    ponteiroData->ano = 2024;

    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);


    return 0;
}