#ifndef modalidade_c
#define modalidade_c
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"

int inner_menu_modalidade()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  MODALIDADE                     \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR MODALIDADE        |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR MODALIDADE           |    \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadastroModalidade();
        break;

        case 2:
            listarModalidade();
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

int buscaIdModalidade(){

    char modalidade[MAX_CHAR];

    int idBusca = 0;

    FILE *bancoModalidade;
    
    bancoModalidade = fopen("banco/banco-modalidades.txt", "a+");

    if (get_size("banco/banco-modalidades.txt") == 0)
    {
        idBusca = 0;
        fclose(bancoModalidade);
    }
    else
    {
        while(!feof(bancoModalidade))
        {
            fscanf(bancoModalidade, "%i %s\n", &idBusca, fgets(modalidade, MAX_CHAR, bancoModalidade));
            strtok(modalidade, "\n");
        }
        fclose(bancoModalidade);
    }

    fclose(bancoModalidade);
    return idBusca;
}

void cadastroModalidade(){

    system("cls");

    char modalidade[MAX_CHAR][MAX_CHAR];

    char t_id[20] = "ID";
    char t_modalidade[20] = "MODALIDADE";

    int op, i, j, contaId = 0, id = 0;

    FILE *bancoModalidade;

    bancoModalidade = fopen("banco/banco-modalidades.txt", "a+");

    if (get_size("banco/banco-modalidades.txt") == 0)
    {
        fprintf(bancoModalidade, "%-5s %-20.20s\n", t_id, t_modalidade);
    }
    
    contaId = buscaIdModalidade();

    for(i = 0; i <= MAX_CHAR; i ++){

        fflush(stdin);
        printf("Nome da modalidade: ");
        fgets(modalidade[i], MAX_CHAR, stdin);
        strtok(modalidade[i], "\n");

        fflush(stdin);

      
        id = contaId+1+i;

        fprintf(bancoModalidade, "%-5i %-20.20s\n", id, modalidade[i]);

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

    fclose(bancoModalidade);
    fflush(stdin);
}


void listarModalidade(){

    system("cls");

    char modalidade[MAX_CHAR];

    FILE *bancomodalidade;

    bancomodalidade = fopen("banco/banco-modalidades.txt", "r");

    if (get_size("banco/banco-modalidades.txt") == 0)
    {
        printf("Não existem equipes cadastradas ainda! Por favor cadastre equipes em Cadastro de Equipes.\n");
        system("pause");
    }
    else
    {
        while (fgets(modalidade, MAX_CHAR, bancomodalidade))
        {
            strtok(modalidade, "\n");
            printf("%s \n", modalidade);
        }
    }
    
    system("pause");
    fclose(bancomodalidade);
    return 1;
}
#endif