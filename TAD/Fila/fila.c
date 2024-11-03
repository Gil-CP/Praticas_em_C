#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Cliente preencheCliente(int qtd_pessoas)
{
    Cliente cliente;

    cliente.senha = qtd_pessoas + 1;
    printf("\nNome: ");
    getchar();
    fgets(cliente.nome, 50, stdin);
    getchar();
    printf("\nQual o pedido?");
    fgets(cliente.pedido, 50, stdin);

    return cliente;
}

void imprimeCliente(Cliente cliente)
{
    printf("\n\t\tNome: %s\t\tPedido: %s\t\tSenha: %d", cliente.nome, cliente.pedido, cliente.senha);
}

void criaFila(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
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
        if(fila->inicio == NULL)
        {
            novo->cliente = preencheCliente(fila->qtd_pessoas);
            novo->proximo = NULL;
            fila->inicio = novo;
            fila->fim = novo;
        }
        else
        {
            
        }
    }
}

void removeDaFila(Fila *fila);

void imprimeFila(Fila *fila);
