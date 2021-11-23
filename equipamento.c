#ifndef equipamento_c
#define equipamento_c
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"

char nomeEquipamento [MAX_CHAR] [50];
char modalidadeEquipamento [MAX_CHAR] [50];

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
    printf("           | 1 - CADASTRAR EQUIPAMENTOS  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR EQUIPAMENTOS     |    \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadastroEquipamento();
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

int buscaIdEquipamento(){

    char equipamento[MAX_CHAR];

    int idBusca = 0;

    FILE *bancoequipamento;
    
    bancoequipamento = fopen("banco/banco-equipamentos.txt", "a+");

    if (get_size("banco/banco-equipamentos.txt") == 0)
    {
        idBusca = 0;
        fclose(bancoequipamento);
    }
    else
    {
        while(!feof(bancoequipamento))
        {
            fscanf(bancoequipamento, "%i %s\n", &idBusca, fgets(equipamento, MAX_CHAR, bancoequipamento));
            strtok(equipamento, "\n");
        }
        fclose(bancoequipamento);
    }

    fclose(bancoequipamento);
    return idBusca;
}

void cadastroEquipamento(){

    system("cls");

    char equipamento[MAX_CHAR][MAX_CHAR];
    char modalidade[MAX_CHAR][MAX_CHAR];

    char t_id[20] = "ID";
    char t_equipamento[20] = "EQUIPAMENTO";
    char t_modalidade[20] = "MODALIDADE";

    int op, i, j, contaId = 0, id = 0;

    FILE *bancoequipamento;

    bancoequipamento = fopen("banco/banco-equipamentos.txt", "a+");

    if (get_size("banco/banco-equipamentos.txt") == 0)
    {
        fprintf(bancoequipamento, "%-5s %-20.20s %-20.20s\n", t_id, t_equipamento, t_modalidade);
    }
    
    contaId = buscaIdEquipamento();

    for(i = 0; i <= MAX_CHAR; i ++){

        fflush(stdin);
        printf("Nome do equipamento: ");
        fgets(equipamento[i], MAX_CHAR, stdin);
        strtok(equipamento[i], "\n");
        fflush(stdin);
        printf("Modalidade do equipamento: ");
        fgets(modalidade[i], MAX_CHAR, stdin);
        strtok(modalidade[i], "\n");

        fflush(stdin);

        id = contaId+1+i;

        fprintf(bancoequipamento, "%-5i %-20.20s %-20.20s\n", id, equipamento[i], modalidade[i]);

        printf("Continuar?\n");
        printf("1 - Continuar cadastrando.");
        printf("0 - Sair.");
        scanf("%i", &op);
        getchar();
        if (op == 0)
        {
            i = MAX_CHAR;
        };
        system("cls");
    }

    fclose(bancoequipamento);
    fflush(stdin);
}

void listar_equipamento()
{
    system("cls");
    char pt_Equipamento[MAX_CHAR];

    FILE *listaEquipamento;
    listaEquipamento = fopen("banco/banco-equipamentos.txt", "r");

    if (get_size("banco/banco-equipamentos.txt") == 0){
        printf("Nenhum Equipamento Cadastrado! Por Favor cadastre algum Equipamento em Cadastro de Equipamento.\n");
    }
    else
    {
        while(fgets(pt_Equipamento, MAX_CHAR, listaEquipamento)){
            strtok(pt_Equipamento, "\n");
            printf("%s\n", pt_Equipamento);
        }
    }
    system("pause");
    fclose(listaEquipamento);
}

#endif