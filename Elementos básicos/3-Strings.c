#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    //String -> vetor de caracteres
    //Declarando uma string
    char palavra[10];

    //scanf -> utilização insegura (estouro de memória)
    //scanf("%s", palavra);
    
    //corrigingo o problema do scanf
    //scanf("%6[^\n]", palavra);
    
    //fgets(onde será salvo, quantidade máxima de caracteres, entrada padrão)
    fgets(palavra, 10, stdin); //stdin -> entrada padrão (normalmente o teclado)
    
    
    
    printf("Palavra: %s", palavra);

    return 0;

}