#ifndef CABECALHO_H
#define CABECALHO_H

typedef struct Cliente
{
     char nome[50];
     int idade;
}Cliente;

typedef struct No
{
     Cliente cliente;
     struct No *proximo;
}No;

typedef struct Fila
{
     No *inicio;
}Fila;

int menu();

Cliente preencheCliente();

void imprimeCliente(Cliente cliente);

void criaFila(Fila *fila);

void insereNaFila(Fila *fila);

void removeDaFila(Fila *fila);

void imprimeFila(Fila *fila);
#endif