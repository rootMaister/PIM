#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logi_menu.h"
#include "structs.h"

int inner_menu_medidas()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                 MEDIDAS                     \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR MEDIDAS       |     \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR MEDIDAS          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                    |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            prevencaoCovid();
        break;

        case 2:
            listarPrevencao();
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

void prevencaoCovid(){

    char medida[500];

    FILE *arquivo;

    printf("Digite uma medida: ");
    fflush(stdin);
    fgets(medida, 500, stdin);

    arquivo = fopen("banco/medidas.txt", "a+");
    fprintf(arquivo, "----------------------------------------------------------\n");
    fprintf(arquivo, "%s", medida);
    fclose(arquivo);

    inner_menu_medidas();
}

void listarPrevencao()
{

    char prevencao[MAX_CHAR];
    FILE *arquivo;

    arquivo = fopen("banco/medidas.txt", "r");

    if(arquivo == NULL)
    {
        printf("Banco não existente. Por favor cadastre uma medida para poder listar. \n");
    }
    else
    {
        while(fgets(prevencao, 500, arquivo))
        {
            if (!feof(arquivo))
            {
                printf("%s", prevencao);
            }
        }
        system("pause");
    }   
    
    inner_menu_medidas();
}