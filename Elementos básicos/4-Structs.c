#include <stdio.h>
#include <stdlib.h>

//Define a estrutura, portanto o que compõe o tipo data de nascimento
typedef struct
{
    int dia;
    int mes;
    int ano;
}DataNas;

typedef struct 
{
    char nome[20];
    int idade;
    float peso, altura;
    DataNas nascimento;
    
}Pessoa;


int main()
{
    //cria uma variavel do tipo pessoa
    Pessoa p1;
    printf("Digite o nome: ");
   fgets(p1.nome, 20, stdin);
    printf("\nDigite a idade: ");
    scanf("%d", &p1.idade);
    printf("\nDigite o peso: ");
    scanf("%f", &p1.peso);
    printf("\nDigite a altura: ");
    scanf("%f", &p1.altura);
    printf("\nDigite a data de nascimento: ");
    scanf("%d%d%d", &p1.nascimento.dia, &p1.nascimento.mes, &p1.nascimento.ano);

    printf("\tNome: %s\n\tIdade: %d\n\tPeso: %.2f\n\tAltura: %.2f\n\tData de Nascimento: %d/%d/%d", p1.nome, p1.idade, p1.peso, p1.altura, p1.nascimento.dia, p1.nascimento.mes, p1.nascimento.ano);
}