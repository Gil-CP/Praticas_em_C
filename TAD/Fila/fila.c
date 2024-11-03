#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Cliente preencheCliente(int qtd_pessoas)
{
    Cliente cliente;

    getchar();
    cliente.senha = qtd_pessoas + 1;
    printf("\nNome: ");
    fgets(cliente.nome,50, stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = 0;

    printf("Qual o pedido? ");
    fgets(cliente.pedido, 50, stdin);
    cliente.pedido[strcspn(cliente.pedido, "\n")] = 0;
    return cliente;

}
void imprimeCliente(Cliente cliente)
{
    printf("\n\t\tNome: %s\n\t\tPedido: %s\n\t\tSenha: %d\n", cliente.nome, cliente.pedido, cliente.senha);
}

void criaFila(Fila *fila)
{
    printf("\nSeja bem vindo ao restaurante xpto!");
    fila->inicio = NULL;
    //fila->fim = NULL;
    fila->qtd_pessoas = 0;

}

void insereNaFila(Fila *fila)
{
    No *novo = calloc(1, sizeof(No));
    if(novo == NULL)
    {
        printf("\nFalha na alocação de memória!");
    }
    else
    {
        novo->cliente = preencheCliente(fila->qtd_pessoas);
        novo->proximo = NULL;

        if(fila->inicio == NULL)
        {
            fila->inicio = novo;
        }
        else
        {
            No *aux = fila->inicio;

            while(aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            
            aux->proximo = novo;
            
        }
        fila->qtd_pessoas++; 
        
    }
}
int menu()
{
    int opcao;
    printf("\n\tSelecione uma opcao:\n\t\t1- Insere clientes na fila\n\t\t2- Remove clientes da fila\n\t\t3- Exibe todos os clientes da fila\n\t\t4- Finaliza o programa\n");
    scanf("%d", &opcao);

    return opcao;
}
void removeDaFila(Fila *fila)
{
    if(fila->inicio == NULL)
    {
        printf("\nNao ha clientes na fila!");
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
