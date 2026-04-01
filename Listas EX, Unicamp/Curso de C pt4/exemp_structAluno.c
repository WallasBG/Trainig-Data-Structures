#include <stdio.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    char nome[50];
    data nascimento;
    float nota;
}dados_aluno;

int main(){
    dados_aluno aluno_1;
    strcpy(aluno_1.nome, "CJ");
    aluno_1.nota = 9.9;
    aluno_1.nascimento.dia = 1;
    aluno_1.nascimento.mes = 4;
    aluno_1.nascimento.ano = 1974;

    printf("Nome: %s\n", aluno_1.nome);
    printf("Born: %02d/%02d/%d\n", aluno_1.nascimento.dia, aluno_1.nascimento.mes, 
    aluno_1.nascimento.ano);
    printf("Nota: %.2f\n", aluno_1.nota);

    return 0;
}