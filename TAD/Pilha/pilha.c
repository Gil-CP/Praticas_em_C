#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pessoa preenchePessoa()
{
    Pessoa pessoa;

    printf("\nDigite o nome: ");
    getchar();
    fgets(pessoa.nome, 50, stdin);
    printf("Digite a idade:");
    scanf("%d", &pessoa.idade);

    return pessoa;
}

void imprimePessoa(Pessoa pessoa)
{
    printf("\n\tNome: %s\tIdade: %d\n",pessoa.nome, pessoa.idade );
}

int menu()
{
    int op;
    printf("\n************************************************************");
    printf("\n\tSelecione uma opcao:\n\t\t1- Empilha dados\n\t\t2- Desempilha dados\n\t\t3- Imprime pilha\n\t\t4- Finaliza o programa");
    printf("\n************************************************************\n");
    scanf("%d", &op);

    return op;

}

void criaPilha(Pilha *pilha)
{
    pilha->topo = NULL;
    printf("\nSeja bem vindo(a) ao programa pilha!");
}

void empilha(Pilha *pilha)
{
    No *novo = calloc(1, sizeof(No));

    if(novo == NULL)
    {
        printf("\nFalha na alocação de memória!");
    }
    else
    {
        novo->pessoa = preenchePessoa();
        novo->proximo = pilha->topo;
        pilha->topo = novo;
    }
}

void desempilhar(Pilha *pilha)
{
    if(pilha->topo == NULL)
    {
        printf("\nNão ha itens a serem desempilhados!");
    }
    else
    {
        No *aux =  pilha->topo;

        imprimePessoa(aux->pessoa);
        pilha->topo = aux->proximo;
        free(aux);
    }
}

void imprimePilha(Pilha *pilha)
{
    printf("\n************************************************************");
    if(pilha->topo == NULL)
    {
        printf("\nA pilha está vazia!");
    }
    else
    {
        No *aux = pilha->topo;

        while(aux != NULL)
        {
            imprimePessoa(aux->pessoa);
            aux = aux->proximo;
        }
    }
    printf("\n************************************************************\n");
}