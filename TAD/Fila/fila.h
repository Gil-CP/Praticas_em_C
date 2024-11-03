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
    struct No *proximo;

}No;

typedef struct Fila
{
    No *inicio;
    //No *fim;
    int qtd_pessoas;

}Fila;

int menu();

Cliente preencheCliente (int qtd_pessoas);

void imprimeCliente(Cliente cliente);

void criaFila(Fila *fila);

void insereNaFila(Fila *fila);

void removeDaFila(Fila *fila);

void imprimeFila(Fila *fila);



#endif