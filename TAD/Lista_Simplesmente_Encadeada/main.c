#include "operacoesLista.c"

int main()
{
    int opcoes;
    long int matricula;

    Lista lista;
    lista.inicio = NULL;

    do
    {
        opcoes = menu();

        switch(opcoes)
        {
            case 1:
                insereNoInicio(&lista);
                break;
            case 2:
                insereNoFinal(&lista);
                break;
            case 3:
            {
                printf("\nInforme a matricula de referencia: ");
                scanf("%ld", &matricula);
                insereNoMeio(&lista, matricula);
                break;
            }
            case 4:
                imprimeLista(&lista);
                break;
            case 5:
            {
                printf("\nDigite a matricula a ser buscada: ");
                scanf("%ld", &matricula);
                buscaAluno(&lista, matricula);
                break;
            }
            case 6:
                removeAluno(&lista);
                break;
            case 7:
                break;
            default:
                printf("\nOpcao invalida!");
                break;
        }
    }while(opcoes != 7);
}