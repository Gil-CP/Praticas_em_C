#ifndef LISTA_H
#define LISTA_H

typedef struct 
{
    long int matricula;
    float nota;
    char nome[50];

}Aluno;

typedef struct No
{
    Aluno aluno;
    struct No *proximo;
}No;

typedef struct
{
    No *inicio;

}Lista;

int menu();

Aluno preencheAluno();

void imprimeAluno(Aluno aluno);

void insereNoInicio(Lista *lista);

void insereNoFinal(Lista *lista);

void insereNoMeio(Lista *lista, long int referencia);

void imprimeLista(Lista *lista);

void buscaAluno(Lista *lista, long int matricula);

void removeAluno(Lista *list);

#endif