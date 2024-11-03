#ifndef PILHA_H
#define PILHA_H

typedef struct Pessoa
{
    char nome[50];
    int idade;

}Pessoa;

typedef struct No
{
    Pessoa pessoa;
    struct No *proximo;

}No;

typedef struct Pilha
{
    No *topo;

}Pilha;

Pessoa preenchePessoa();

void imprimePessoa();

int menu();

void criaPilha(Pilha *pilha);

void empilha(Pilha *pilha);

void desempilhar(Pilha *pilha);

void imprimePilha(Pilha *pilha);
#endif