#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dia, mes, ano;
}DataNas;

typedef struct
{
    char nome[50];
    int nota;
    DataNas nascimento;

}Aluno;

void imprimeListaAlunos(Aluno alunos);
Aluno registraAluno();

int main()
{
    int qtd_alunos, opcao;

    printf("Seja bem vindo usuário(a)!");
    printf("\nPara comecar digite a quantidade de alunos");
    scanf("%d", &qtd_alunos);
    
    Aluno alunos[qtd_alunos];
    // printf("Selecione uma opcao\n\t1- Preencher lista de alunos\n\t2- Exibir lista de alunos\n\t3- Sair do programa");
    // scanf("%d", &opcao);

  
    for(int i = 0; i < qtd_alunos; i++)
    {
        alunos[i] = registraAluno();
    }

    for(int i = 0; i < qtd_alunos; i++)
    {
        imprimeListaAlunos(alunos[i]);
    }

}

void imprimeListaAlunos(Aluno aluno)
{
    printf("\n\tNome do aluno: %s", aluno.nome);
    printf("\n\tNascimento aluno: %2d/%2d/%2d", aluno.nascimento.dia, aluno.nascimento.mes, aluno.nascimento.ano);
    printf("\n\tNota: %d", aluno.nota);

}
Aluno registraAluno()
{
    Aluno aluno;
    getchar();
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, 50, stdin);
    printf("Digite a data de nascimento do aluno: ");
    scanf("%d%d%d", &aluno.nascimento.dia, &aluno.nascimento.mes, &aluno.nascimento.ano);
    printf("Digite a nota do aluno: ");
    scanf("%d", &aluno.nota);

    return aluno;
}


    
