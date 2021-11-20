#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "equipe.c"
#include "atleta.c"
#include "voluntario.c"
#include "funcionario.c"

void menu();

//Atletas
void cadastroAtleta();
void listarAtleta();
void cadastroEquipe();

//Equipes
void cadastroEquipe();
void listarEquipes();
int buscaIdEquipe();

void main(){
    menu();
}

void menu(){

    setlocale(LC_ALL, "Portuguese");

    int opcao, op;

    do
        {
        system("cls");

        printf("1 - Cadastrar Atleta\n");
        printf("2 - Listar Atletas\n");
        printf("3 - Listar Equipes\n");
        printf("4 - Cadastrar Equipes\n");
        printf("5 - Cadastrar Voluntarios\n");
        printf("6 - Listar Voluntarios\n");

        printf("0 - Sair\n");

        scanf("%d", &op);
        getchar();

        switch(op)
        {

            case 1:
                cadastroAtleta();
            break;

            case 2:
                listarAtleta();
            break;

            case 3:
                listarEquipes();
            break;

            case 4:
                cadastroEquipes();
            break;

            case 5:
                cadastroVoluntario();
            break;

            case 6:
                listarVoluntario();
            break;

            case 7:
                cadastroFuncionario();
            break;

            case 8:
                listarFuncionario();
            break;

        }
    } while (op != 0);
}