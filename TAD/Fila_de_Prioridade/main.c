#include "operacoes.c"

int main()
{
     int opcao;
     Fila fila;
     criaFila(&fila);

     do
     {
          opcao = menu();

          switch(opcao)
          {
               case 1:
                    insereNaFila(&fila);
                    break;
               case 2:
                    removeDaFila(&fila);
                    break;
               case 3:
                    imprimeFila(&fila);
                    break;
               case 4:
                    break;
               default:
                    printf("\nOpcao invalida!");
                    break;
          }
     }while(opcao != 4);
}