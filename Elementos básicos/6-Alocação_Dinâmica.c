#include <stdlib.h>
#include <stdio.h>

int main()
{
    /*Alocação dinâmica é preferivel em casos onde a demanda por memória é alta.
    Em geral o computador reserva mais memória dinâmica, ou seja, memória reservada em tempo de execução, que memória estática*/


    //Função malloc (memory alocation) -> aloca um espaço na memória. Se a alocação for mal sucedida retorna NULL, caso contrário retorna um endereço de memória
    int *espaco;

    espaco = malloc(sizeof(espaco)); //Recebe como parâmetro a quantidade em bytes que deve alocar

    if(espaco == NULL)
    {
        printf("Houve um erro na alocacao!\n");
    }
    else
    {
        *espaco = 5;
        printf("O conteudo da variavel criada (por malloc) eh: %d\n", *espaco);
    }
    /*Quando variável é alocada dinâmicamente o computador entende que a memória não deve ser liberada até que o programa seja finalizado ou que o programa indique que o espaço de memória não é mais necessário.
    A função que libera a memória alocada dinâmicamente é a função free*/

    free(espaco); //Recebe como parametro o ponteiro que indique o espaço de memória a ser desalocado

    printf("\n-------------------------------------------------------------------------------------------------\n");
    /*A função calloc, de modo semelhante a função calloc retorna um ponteiro para a nova região de memória em caso de sucesso e NULL em caso de falha.
    Além disso a função calloc limpa o endereço de memória antes de retornar o endereçodaafadfsaddahjkkl*/
    char *variavel;

    variavel = calloc(1, sizeof(variavel));//Possui dois parâmetros: 1° quantidade de elementos a serem alocados, 2° quantidade de bytes 

    if(variavel == NULL)
    {
        printf("Erro na alocação de memória calloc\n");
    }
    else
    {
        *variavel = 's';
        printf("O conteúdo da variavel criada por calloc eh: %c", *variavel);
    }

    free(variavel);

    printf("\n-------------------------------------------------------------------------------------------------\n");

    /*função realoc -> copia o conteúdo de um vetor para outra região de memória com o novo tamanho indicado dentro da função.
    Do mesmo modo que as demais funções vistas anteriormente a função realloc retorna um endereço de memória
    Observação: A função realoc funciona apenas para vetores alocados dinamicamente*/
    int *vetor;

    vetor = calloc(5, sizeof(vetor));

    if(vetor == NULL)
    {
        printf("Erro na alocação de memória\n");
    }
    else
    {
        for(int i = 0;i < 5; i++)
        {
            *(vetor + i) = i;
        }
        for(int i = 0; i < 5; i++)
        {
            printf("vetor[%d] -> %d\n", i, *(vetor + i));
        }
        
        printf("\n\n");
        vetor = realloc(vetor, 7); //O primeiro parametro diz respeito ao ponteiro de origem, o segundo parametro diz respeito ao novo tamanho do vetor

        for(int i = 0; i < 7; i++)
        {
            printf("vetor[%d] -> %d\n", i, *(vetor + i));
        }
    }
    
    return 0;
}