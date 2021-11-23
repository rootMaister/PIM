#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"


int inner_menu_calendario()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  CALENDARIO                    \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR DATA          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR CALENDÁRIO       |    \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            guardaData();
        break;

        case 2:
            mostraData();
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

void guardaData(){
    
    system("cls");
    char data[MAX_CHAR];
    char prova[MAX_CHAR];
    char horario[MAX_CHAR];
    char liga[MAX_CHAR];

    FILE *arquivo;

    arquivo = fopen("banco/calendario.txt", "r");
    if (get_size("banco/calendario.txt") == 0)
    {
        arquivo = fopen("banco/calendario.txt", "a+");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        fprintf(arquivo, "   DATA               PROVA                     HORARIO   LIGA                          \n");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        fclose(arquivo);
    }

    printf("Digite a data [DD/MM/AAAA]: ");
    fflush(stdin);
    fgets(data, MAX_CHAR, stdin);
    strtok(data, "\n");

    printf("Digite a prova: ");
    fflush(stdin);
    fgets(prova, MAX_CHAR, stdin);
    strtok(prova, "\n");

    printf("Digite o horario [00:00]: ");
    fflush(stdin);
    fgets(horario, MAX_CHAR, stdin);
    strtok(horario, "\n");

    printf("Digite a liga: ");
    fflush(stdin);
    fgets(liga, MAX_CHAR, stdin);
    strtok(liga, "\n");

    arquivo = fopen("banco/calendario.txt", "a+");
    fprintf(arquivo, "%-12s %-35s %-6s %-35s\n", data, prova, horario, liga);
    fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
    fclose(arquivo);

    //inner_menu_calendario();
}

void mostraData(){
    
    system("cls");
    char *pt_calendario[MAX_CHAR];

    FILE *bancoCalendario;

    bancoCalendario = fopen("banco/calendario.txt", "r");

    if (get_size("banco/calendario.txt") == 0)
    {
        printf("NÃ£o existem datas cadastradas ainda! Por favor cadastre uma.\n");
        system("pause");
    }
    else
    {
        while (fgets(pt_calendario, MAX_CHAR, bancoCalendario))
        {
            strtok(pt_calendario, "\n");
            printf("%s \n", pt_calendario);
        }

        if (!feof(bancoCalendario))
        {
            system("pause");
        }

    }

    
    system("pause");
    fclose(bancoCalendario);
    return 1;
}