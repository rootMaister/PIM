#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"

#define LISTAEQP 500

char nomeEquipamento [LISTAEQP] [50];
char modalidadeEquipamento [LISTAEQP] [50];

void cad_equipamento();
void listar_equipamento();
int op;

int inner_menu_equipamento()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  EQUIPAMENTOS                    \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR EQUIPAMENTOS        |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR EQUIPAMENTOS          |    \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                    |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cad_equipamento();
        break;

        case 2:
            listar_equipamento();
        break;

        case 9:
            logi_menu_cad();
        break;

        case 10:
            printf("sair");
            abort();
        default:
        printf("Escolha uma opção valida selecionando um número acima: ");
    }
}

void cad_equipamento(){
    static int linha;
    do{
        fflush(stdin);
        printf("\nDIGITE O NOME DO EQUIPAMENTO :");
        fgets(nomeEquipamento[linha], 90, stdin);
        strtok(nomeEquipamento[linha], "\n");
        fflush(stdin);
        printf("\nDIGITE A MODALIDADE DO EQUIPAMENTO:");
        fgets(modalidadeEquipamento[linha], 90, stdin);
        strtok(modalidadeEquipamento[linha], "\n");
        fflush(stdin);


        FILE *listaEquipamento;
        listaEquipamento = fopen("banco/banco-equipamento.txt", "a");

        fprintf(listaEquipamento, "%s %s\n", nomeEquipamento[linha], modalidadeEquipamento[linha]);

        fclose(listaEquipamento);
        printf("Digite 1 Para continuar adicionando ou 0 para sair\n");
        scanf("%d", &op);
        linha++;
    }while(op == 1);
}

void listar_equipamento()
{
    system("cls");
    char pt_Equipamento[LISTAEQP];

    FILE *listaEquipamento;
    listaEquipamento = fopen("banco/banco-equipamento.txt", "r");

    if (listaEquipamento == NULL){
        printf("Nenhum Equipamento Cadastrado! Por Favor cadastre algum Equipamento em Cadastro de Equipamento.\n");
    }
    else
    {
        while(fgets(pt_Equipamento, LISTAEQP, listaEquipamento)){
            strtok(pt_Equipamento, "\n");
            printf("%s\n", pt_Equipamento);
        }
    }
    system("pause");
    fclose(listaEquipamento);
}