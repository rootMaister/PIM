#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "structs.h"

equipe equipes[MAX_CHAR];

int inner_menu_equipe()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  EQUIPES          \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR EQUIPES       |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR EQUIPES          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |   \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadastroEquipes();
        break;

        case 2:
            listarEquipes();
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

int buscaIdEquipe(){

    atleta equipes;

    equipes.id = 0;

    FILE *bancoEquipes;
    
    bancoEquipes = fopen("banco/banco-equipes.txt", "a+");

    if (get_size("banco/banco-equipes.txt") == 0)
    {
        equipes.id = 0;
        fclose(bancoEquipes);
    }
    else
    {
        while(!feof(bancoEquipes)){
            fscanf(bancoEquipes, "%i %s", &equipes.id, fgets(equipes.nome, MAX_CHAR, bancoEquipes));
            strtok(equipes.nome, "\n");
        }
    }

    fclose(bancoEquipes);
    return equipes.id;
}

void cadastroEquipes(){
    system("cls");

    equipe equipe[MAX_CHAR];

    int op, i, contaId = 0;

    FILE *bancoEquipes;

    bancoEquipes = fopen("banco/banco-equipes.txt", "a");

    contaId = buscaIdEquipe();
    

    for(i = 0; i <= MAX_CHAR; i++){
        printf("Nome da Equipe: ");
        fflush(stdin);

        gets(equipe[i].nome);
        printf("%i \n", contaId);
        equipes[i].id = contaId+1+i;

        fprintf(bancoEquipes, "%i %s\n", equipes[i].id, equipe[i].nome);

        printf("Continuar?\n");
        printf("1 - continuar.");
        printf("0 - sair.");
        scanf("%i", &op);
        getchar();

        if (op == 0)
        {
            i = MAX_CHAR;
        };

    }

    fclose(bancoEquipes);

    listarEquipes();
    return 1;

}

void listarEquipes(){

    system("cls");

    equipe equipes;

    char** pt_equipes;

    FILE* bancoEquipes;

    bancoEquipes = fopen("banco/banco-equipes.txt", "r");

    if (get_size("banco/banco-equipes.txt") == 0)
    {
        printf("Não existem equipes cadastradas ainda! Por favor cadastre equipes em Cadastro de Equipes.\n");
        system("pause");
        cadastroEquipes();
    }
    else
    {
        while (fgets(equipes.nome, MAX_CHAR, bancoEquipes))
        {
            strtok(equipes.nome, "\n");
            printf("%s \n", equipes.nome);
        }

        if (!feof(bancoEquipes))
        {
            system("pause");
        }
    }
    
    system("pause");
    fclose(bancoEquipes);
    return 1;
}