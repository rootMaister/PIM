#ifndef atleta_c
#define atleta_c
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"


int inner_menu_atleta()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  ATLETA                     \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR ATLETA        |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR ATLETA           |    \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadastroAtleta();
        break;

        case 2:
            listarAtleta();
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

int buscaIdAtleta(){

    atleta atletas;

    atletas.id = 0;

    int id;

    FILE *bancoAtleta;
    
    bancoAtleta = fopen("banco/banco-atletas.txt", "a+");

    if (get_size("banco/banco-atletas.txt") == 0)
    {
        atletas.id = 0;
        fclose(bancoAtleta);
    }
    else
    {
        while(!feof(bancoAtleta))
        {
            fscanf(bancoAtleta, "%i %s %s %s %s %s \n", &atletas.id, &atletas.nome, &atletas.sobreNome, &atletas.modalidade, &atletas.paisOrigem, fgets(atletas.equipe, MAX_CHAR, bancoAtleta));
            strtok(atletas.equipe, "\n");
        }
        fclose(bancoAtleta);
    }

    fclose(bancoAtleta);
    return atletas.id;
}

void cadastroAtleta(){

    system("cls");

    atleta atleta[MAX_CHAR], atletaCount;

    char **equipe[MAX_CHAR][MAX_CHAR];
    char **modalidade[MAX_CHAR][90];
    int *id[MAX_CHAR];
    int selecao;
    int selecaoModalidade = 0;

    char t_id[20] = "ID";
    char t_nome[20] = "NOME";
    char t_sobreNome[20] = "SOBRENOME";
    char t_pais[20] = "PAÍS";
    char t_equipe[20] = "EQUIPE";
    char t_modalidade[20] = "MODALIDADE";

    int op, i, j, k, contaId = 0;

    FILE *bancoAtletas, *bancoModalidade, *bancoEquipe;

    bancoAtletas = fopen("banco/banco-atletas.txt", "a+");
    bancoModalidade = fopen("banco/banco-modalidades.txt", "a+");
    bancoEquipe = fopen("banco/banco-equipes.txt", "r");



    if (get_size("banco/banco-atletas.txt") == 0)
    {
        fprintf(bancoAtletas, "%-5s %-20.20s %-20.20s %-20.20s %20.20s %-20.20s\n", t_id, t_nome, t_sobreNome, t_modalidade, t_pais, t_equipe);
    }
    
    contaId = buscaIdAtleta();

    for(i = 0; i <= MAX_CHAR; i ++){

        fflush(stdin);
        printf("Primeiro nome do Atleta: ");
        fgets(atleta[i].nome, 30, stdin);
        strtok(atleta[i].nome, "\n");
        //scanf("%s", &atleta[i].nome);

        printf("Sobrenome do Atleta: ");
        scanf("%s", &atleta[i].sobreNome);

        system("cls");
        listarModalidade();

         for (k = 0; k < MAX_CHAR; k++)
        {
            fgets(modalidade[k], MAX_CHAR, bancoModalidade);
        }

        printf("\n");
        printf("\n");
        printf("Selecione uma modalidade acima digitando o Id: ");
        fflush(stdin);
        scanf("%i", &selecaoModalidade);


        //fgets(atleta[i].modalidade, MAX_CHAR, stdin);
        //strtok(atleta[i].modalidade, "\n");
        fflush(stdin);

        system("cls");
        printf("Pa�s de origem do atleta: ");
        scanf("%s", &atleta[i].paisOrigem);

        fflush(stdin);

        system("cls");
        listarEquipes();

        int tamanhoLista = 0;
        

        for (j = 0; j < MAX_CHAR; j++)
        {
            fgets(equipe[j], MAX_CHAR, bancoEquipe);
        }

       
        
        printf("Selecione uma equipe acima digitando o id: ");
        fflush(stdin);
        scanf("%i", &selecao);

        fflush(stdin);
        printf("\n");
        printf("\n");
        printf("Equipe selecionada: %s\n", equipe[selecao-1]);
      

        
        fflush(stdin);

        atleta[i].id = contaId+1+i;
        printf("%-5i %-20.20s %-20.20s %-20.20s %20.20s %-20.20s\n", atleta[i].id, atleta[i].nome, atleta[i].sobreNome, modalidade[selecaoModalidade], atleta[i].paisOrigem, equipe[selecao-1]);
        system("pause");

        fflush(stdin);
        fprintf(bancoAtletas, "%-5i %-20.20s %-20.20s %-20.20s %20.20s %-20.20s\n", atleta[i].id, atleta[i].nome, atleta[i].sobreNome, modalidade[selecaoModalidade], atleta[i].paisOrigem, equipe[selecao-1]);

        //fprintf(bancoModalidade, "%s \n", atleta[i].modalidade);

        printf("\n");
        printf("\n");
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

    fclose(bancoAtletas);
    fclose(bancoModalidade);
    fclose(bancoEquipe);
    fflush(stdin);
}

void listarAtleta(){

    system("cls");

    char atletas[MAX_CHAR];

    FILE *bancoAtletas;

    bancoAtletas = fopen("banco/banco-atletas.txt", "r");

    if (get_size("banco/banco-atletas.txt") == 0)
    {
        printf("Não existem equipes cadastradas ainda! Por favor cadastre equipes em Cadastro de Equipes.\n");
        system("pause");
    }
    else
    {
        while (fgets(atletas, MAX_CHAR, bancoAtletas))
        {
            strtok(atletas, "\n");
            printf("%s \n", atletas);
        }
    }
    
    system("pause");
    fclose(bancoAtletas);
    return 1;
}
#endif