#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

int menu()
{
     int operacao;
     printf("\n\tSelecione uma opcao:\n\t\t1- Inserir na fila\n\t\t2- Remover da fila\n\t\t3- Imprimir fila\n\t\t4- Encerrar programa\n");
     scanf("%d", &operacao);

     return operacao;
}
Cliente preencheCliente()
{
     Cliente cliente;
     printf("\nDigite o nome: ");
     //fgets(cliente.nome, 50, stdin);
     scanf("%s", cliente.nome);

     for (int i = 0; i < sizeof(cliente.nome); i++)
     {
          if(cliente.nome[i] == '\n')
          {
               cliente.nome[i] = ' ';
          }
     }

     printf("\nDigite a idade: ");
     scanf("%d", &cliente.idade);

     return cliente;
}

void imprimeCliente(Cliente cliente)
{
     printf("\n\t\tNome: %s\n\t\tIdade: %d\n", cliente.nome, cliente.idade);
}

void criaFila(Fila *fila)
{
     fila->inicio = NULL;
     printf("\nFila criada!");
}

void insereNaFila(Fila *fila)
{
     printf("Porra de função");
     No *novo = calloc(1, sizeof(No));

     if(novo == NULL)
     {
          printf("\nFalha na alocacao de memoria!");
     }
     else
     {
          novo->cliente = preencheCliente();
          novo->proximo = NULL;

          if(fila->inicio == NULL)
          {
               fila->inicio = novo;
  
          }
          else
          {
               No *aux = fila->inicio;

               if(novo->cliente.idade < 60)
               {
                         while(aux->proximo != NULL)
                    {
                         aux = aux->proximo;
                    }
                    aux->proximo = novo;
               }
               else
               {
                    if(aux == fila->inicio && aux->cliente.idade < 60)
                    {
                         novo->proximo = fila->inicio;
                         fila->inicio = novo;
                    }
                    else
                    {
                         while((aux->proximo->cliente.idade > 60) && aux->proximo != NULL)
                         {
                              aux = aux->proximo;
                         }
                         novo->proximo = aux->proximo;
                         aux->proximo = novo;

                    }
               }

          }
     }
}

void removeDaFila(Fila *fila)
{
     if(fila->inicio == NULL)
     {
          printf("\nNao ha itens a serem removidos!");
     }
     else
     {
          No *aux = fila->inicio;
          imprimeCliente(aux->cliente);

          fila->inicio = aux->proximo;

          free(aux);
     }
}

void imprimeFila(Fila *fila)
{
     if(fila->inicio == NULL)
     {
          printf("\nA fila esta vazia!");
     }
     else
     {
          No *aux = fila->inicio;

          while(aux != NULL)
          {
               imprimeCliente(aux->cliente);
               aux = aux->proximo;
          }
     }
}