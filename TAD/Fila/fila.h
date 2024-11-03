#ifndef FILA_H
#define FILA_H

typedef struct Cliente
{
    char nome[50];
    int senha;
    char pedido[50];
    
}Cliente;

typedef struct No
{
    Cliente cliente;
    No *proximo;

}No;

typedef struct Fila
{
    No *inicio;
    No *fim;
    int qtd_pessoas;

}Fila;

Cliente preencheCliente(Cliente cliente, int qtd_pessoas);

void imprimeCliente(Cliente cliente);

void criaFila(Fila *fila);

void insereNaFila(Fila *fila);

void removeDaFila(Fila *fila);

void imprimeFila(Fila *fila);



#endif