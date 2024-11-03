#include "pilha.c"

int main()
{
    int opcao = 0;
    Pilha pilha;
    criaPilha(&pilha);


    do
    {
        opcao = menu();

        switch(opcao)
        {
            case 1 :
                int qtd;
                printf("\nQuandos dados deseja empilhar?\n");
                scanf("%d", &qtd);
                for(int i = 0; i < qtd; i++)
                {
                    empilha(&pilha);
                }
                break;
            case 2 :
                desempilhar(&pilha);
                break;
            case 3 :
                imprimePilha(&pilha);
                break;
            case 4 :
                break;
            default :
                printf("\nOpcao invalida!");
        }
    }while(opcao != 4);


    return 0;
}