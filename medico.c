#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logi_menu.h"
#include "structs.h"

int inner_menu_medico()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                 MEDIDAS                     \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR MEDICOS       |     \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR MEDICOS          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadMedicos();
        break;

        case 2:
            listarMedicos();
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

void cadMedicos()
{

    char nome[100];
    char equipe[100];

    FILE *arquivo;

    printf("Digite o nome do medico: ");
    fflush(stdin);
    fgets(nome, 100, stdin);
    strtok(nome, "\n");

    printf("Digite a equipe:");
    fflush(stdin);
    fgets(equipe, MAX_CHAR, stdin);
    strtok(equipe, "\n");

    arquivo = fopen("banco/banco-medicos.txt", "a+");
    fprintf(arquivo, "----------------------------------------------------------\n");
    fprintf(arquivo, "%s %s \n", nome, equipe);
    fclose(arquivo);

    inner_menu_medico();
}

void listarMedicos(){

    system("cls");

    char *pt_medicos[MAX_CHAR];

    FILE *bancoMedicos;

    bancoMedicos = fopen("banco/banco-medicos.txt", "r");

    if (bancoMedicos == NULL)
    {
        printf("Não existem equipes cadastradas ainda! Por favor cadastre equipes em Cadastro de Equipes.\n");
        system("pause");
    }
    else
    {
        while (fgets(pt_medicos, MAX_CHAR, bancoMedicos))
        {
            strtok(pt_medicos, "\n");
            printf("%s \n", pt_medicos);
        }

        if (!feof(bancoMedicos))
        {
            system("pause");
        }
        
    }
    
    system("pause");
    fclose(bancoMedicos);
    return 1;
}