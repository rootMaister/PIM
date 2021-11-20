#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"


int inner_menu_alojamento()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  ALOJAMENTO                    \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR ALOJAMENTO        |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR ALOJAMENTO         |    \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                    |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadAlojamento();
        break;

        case 2:
            mostraAlojamento();
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

void cadAlojamento(){
    
    system("cls");
    char nome[MAX_CHAR];
    char setor[MAX_CHAR];
    char andar[MAX_CHAR];
    char quarto[MAX_CHAR];

    FILE *arquivo;

    arquivo = fopen("banco/banco-alojamento.txt", "r");
    if (arquivo == NULL)
    {
        arquivo = fopen("banco/banco-alojamento.txt", "a+");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        fprintf(arquivo, "   ATLETA                       SETOR     ANDAR         QUARTO                          \n");
        fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
        fclose(arquivo);
    }

    printf("Digite o setor[setor 1, B]: ");
    fflush(stdin);
    fgets(setor, MAX_CHAR, stdin);
    strtok(setor, "\n");

    printf("Digite o andar[primeiro andar]: ");
    fflush(stdin);
    fgets(andar, MAX_CHAR, stdin);
    strtok(andar, "\n");

    printf("Digite o número do quarto: ");
    fflush(stdin);
    fgets(quarto, MAX_CHAR, stdin);
    strtok(quarto, "\n");

    printf("Digite o nome do atleta: ");
    fflush(stdin);
    fgets(nome, MAX_CHAR, stdin);
    strtok(nome, "\n");

    arquivo = fopen("banco/banco-alojamento.txt", "a+");
    fprintf(arquivo, "%-30s %-10s %-13s %-6s\n", nome, setor, andar, quarto);
    fprintf(arquivo, "----------------------------------------------------------------------------------------\n");
    fclose(arquivo);

    //inner_menu_calendario();
}

void mostraAlojamento(){
    
    system("cls");
    char *pt_alojamento[MAX_CHAR];

    FILE *bancoAlojamento;

    bancoAlojamento = fopen("banco/banco-alojamento.txt", "r");

    if (bancoAlojamento == NULL)
    {
        printf("NÃ£o existem alojamentos cadastrados ainda! Por favor cadastre um.\n");
        system("pause");
    }
    else
    {
        while (fgets(pt_alojamento, MAX_CHAR, bancoAlojamento))
        {
            strtok(pt_alojamento, "\n");
            printf("%s \n", pt_alojamento);
        }

        if (!feof(bancoAlojamento))
        {
            system("pause");
        }

    }

    system("pause");
    fclose(bancoAlojamento);
    return 1;
}
