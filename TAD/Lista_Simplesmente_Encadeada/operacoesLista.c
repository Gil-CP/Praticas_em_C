#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int menu()
{
    int op;
    printf("\n\n\tSelecione uma opcao: \n\t\t1 - Inserir no inicio da lista\n\t\t2 - Iserir no final da lista\n\t\t3- Inserir no meio da lista\n\t\t4- Imprimir lista\n\t\t5- Busca aluno\n\t\t6- Remover aluno da lista\n\t\t7- Sair do programa\n");
    scanf("%d", &op);

    return op;
}

Aluno preencheAluno()
{
    Aluno aluno;

    printf("\nDigite a matricula: ");
    scanf(" %ld", &aluno.matricula);
    getchar();
    printf("\nDigite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    
    size_t len = strlen(aluno.nome);
    if(len >0 && aluno.nome[len - 1] == '\n')
    {
        aluno.nome[len-1] = '\0';
    }

    printf("\nDigite a nota A1: ");
    scanf("%f", &aluno.nota);
  
    return aluno;
}

void imprimeAluno(Aluno aluno)
{
    printf("\n\n\t\tMatricula: %ld\n\t\tNome: %s\n\t\tNota A1: %.2f", aluno.matricula, aluno.nome, aluno.nota);
}

void insereNoInicio(Lista *lista)
{
    No *novo = calloc(1, sizeof(No));

    if(novo == NULL)
    {
        printf("\nFalha na alocacao de memoria!!!");
    }
    else
    {
        novo->aluno = preencheAluno();

        if(lista == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;

        }
        else
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
    }
}

void insereNoFinal(Lista *lista)
{
    No *novo = calloc(1, sizeof(No));

    if(novo == NULL)
    {
        printf("\nA lista está vazia!");
    }
    else
    {
        novo->aluno = preencheAluno();
        novo->proximo = NULL;
        
        if(lista->inicio == NULL)
        {
            lista->inicio = novo;
        }
        else
        {
            No *aux = lista->inicio;

            while(aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
}

void insereNoMeio(Lista *lista, long int referencia)
{
    No *novo = calloc(1, sizeof(No));

    if(novo == NULL)
    {
        printf("\nFalha na alocacao de memoria!");
    }
    else
    {
        No *aux = lista->inicio;
        novo->aluno = preencheAluno();

        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        while(aux->proximo != NULL && aux->aluno.matricula != referencia)
        {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;

    }
}

void imprimeLista(Lista *lista)
{
    if(lista->inicio == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        No *aux = lista->inicio;

        while(aux != NULL)
        {
            imprimeAluno(aux->aluno);
            aux = aux->proximo;
        }

    }
}

void buscaAluno(Lista *lista, long int matricula)
{
    if(lista->inicio == NULL)
    {
        printf("\nA lista está vazia");
    }
    else
    {
        No *aux = lista->inicio;

        while(aux->proximo != NULL && aux->aluno.matricula != matricula)
        {
            aux = aux->proximo;
        }
        
        if(aux->proximo == NULL && aux->aluno.matricula != matricula)
        {
            printf("\nAluno nao esta na lista!");
        }
        else
        {
            imprimeAluno(aux->aluno);
        }
    }
}

void removeAluno(Lista *lista)
{
    if(lista->inicio == NULL)
    {
        printf("\nA lista estah vazia!");
    }
    else
    {
        long int matricula;
        printf("\nDigite a matricula do aluno a ser removido: ");
        scanf("%ld", &matricula);

        No *aux = lista->inicio;
        No *aux2 = NULL; 

        while(aux->proximo != NULL && aux->aluno.matricula != matricula)
        {
            aux2 = aux;
            aux = aux->proximo;
        }
        if(aux->proximo == NULL && aux->aluno.matricula != matricula)
        {
            printf("\nAluno nao estah na lista!");
        }
        else
        {
            imprimeAluno(aux->aluno);

            if(aux == lista->inicio)
            {
                lista->inicio = aux->proximo;
            }
            else if(aux->proximo == NULL && aux->aluno.matricula == matricula)
            {
                aux2->proximo = NULL;
            }
            else
            {
                aux2->proximo = aux->proximo;
            }
        }
    }
}