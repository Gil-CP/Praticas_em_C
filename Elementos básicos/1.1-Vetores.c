#include "vetores.c"
#include <time.h>



int main()
{
    int tam, opcoes;
    tam = menuInicial();
    int vetor[tam];
    preencheVetor(vetor, tam);

    
    do
    {
        opcoes = menuOpcoes();
        switch (opcoes)
        {
            case 1:
                imprimeVetor(vetor, tam);
                break;
            case 2:
                ordenaVetor(vetor, tam);
                break;
            case 3:
                break;
        
        
        }
    }while(opcoes != 3);

    return 0;
}
