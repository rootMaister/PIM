#ifndef LOCAL_TREINO_C
#define LOCAL_TREINO_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logi_menu.h"
#include "structs.h"


int inner_menu_local_treino()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                 AGENDAR TREINOS             \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - AGENDAR TREINO        |     \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR TREINOS          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                    |  \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadastroLocalTreino();
        break;

        case 2:
            //listarEquipes();
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

void cadastroLocalTreino()
{
    FILE *pont_arq;

    pont_arq = fopen("banco/banco-locaisTreinos.txt", "a");

    if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    char *cidadeSede[50];

    printf("Digite o nome da Cidade-sede onde ocorrerá os jogos: ");
    fflush(stdin);
    fgets(cidadeSede , MAX_CHAR, stdin);
    //fprintf(pont_arq, "%s", cidadeSede);


    char *bairro[50];

    printf("Digite o nome do bairro correspondente: ");
    fflush(stdin);
    fgets( bairro , MAX_CHAR, stdin);
    //fprintf(pont_arq, "%s", bairro);


    char *estadio[50];

    printf("Digite o nome do estadio onde ocorrerá os jogos: ");
    fflush(stdin);
    fgets( estadio , MAX_CHAR, stdin);
    //fprintf(pont_arq, "%s", estadio);

    strtok(cidadeSede, "\n");
    strtok(bairro, "\n");
    strtok(estadio, "\n");
    fprintf(pont_arq, "%s %s %s \n", cidadeSede, bairro, estadio);

    fclose(pont_arq); 

}

#endif