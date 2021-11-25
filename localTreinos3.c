#ifndef localtreinos_c
#define localtreinos_c
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"

int inner_menu_local_treino()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2042            \n");
    printf("          ---------------------------------  \n");
    printf("                 AGENDAR TREINOS             \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - AGENDAR TREINO          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR TREINOS          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |   \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadLocal();
        break;

        case 2:
            mostraLocal();
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

void cadLocal(){
    
    system("cls");
    char cidade[MAX_CHAR];
    char bairro[MAX_CHAR];
    char estadio[MAX_CHAR];

    FILE *arquivo;

    arquivo = fopen("banco/banco-locaisTreinos.txt", "r");
    if (get_size("banco/banco-locaisTreinos.txt") == 0)
    {
        arquivo = fopen("banco/banco-locaisTreinos.txt", "a+");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        fprintf(arquivo, "            ESTADIO                  BAIRRO                CIDADE                       \n");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        fclose(arquivo);
    }

    printf("Digite o nome da Cidade-sede onde ocorrerá os jogos: ");
    fflush(stdin);
    fgets(cidade, MAX_CHAR, stdin);
    strtok(cidade, "\n");



    printf("Digite o nome do bairro correspondente: ");
    fflush(stdin);
    fgets(bairro, MAX_CHAR, stdin);
    strtok(bairro, "\n");

    printf("Digite o nome do estadio onde ocorrerá os jogos: ");
    fflush(stdin);
    fgets(estadio, MAX_CHAR, stdin);
    strtok(estadio, "\n");

    arquivo = fopen("banco/banco-locaisTreinos.txt", "a+");
    fprintf(arquivo, "%-30s %-30s %-30s \n", estadio, bairro, cidade);
    fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
    fclose(arquivo);

    //inner_menu_calendario();
}

void mostraLocal(){
    
    system("cls");
    char *pt_Local[MAX_CHAR];

    FILE *bancoLocal;

    bancoLocal = fopen("banco/banco-locaisTreinos.txt", "r");

    if (get_size("banco/banco-locaisTreinos.txt") == 0)
    {
        printf("Nao existem locais cadastrados ainda! Por favor cadastre um.\n");
        system("pause");
    }
    else
    {
        while (fgets(pt_Local, MAX_CHAR, bancoLocal))
        {
            strtok(pt_Local, "\n");
            printf("%s \n", pt_Local);
        }

        if (!feof(bancoLocal))
        {
            system("pause");
        }

    }

    system("pause");
    fclose(bancoLocal);
    return 1;
}

#endif