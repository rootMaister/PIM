#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


typedef struct DMA{
    int dia;
    int mes;
    int ano;
}data;


int inner_menu_agendar_treino()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                 AGENDAMENTO DE TREINO       \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - AGENDAR TREINO          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR TREINO           |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                   |   \n");
    printf("          --------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            agendarTreino();
        break;

        case 2:
            mostraTreino();
        break;

        case 9:
            logi_menu_cad();
        break;

        case 10:
            printf("sair");
            abort();
        default:
        printf("Escolha uma opcao valida selecionando um numero acima: ");
    }
}


int agendarTreino()
{

    printf("---AGENDAMENTO DE TREINOS---\n");

   
    FILE *pont_arq;

    pont_arq = fopen("banco/treino.txt", "a+");

    //if(get_size("banco/treino.txt") == 0){
    //    printf("Erro na abertura do arquivo!");
    //    return 1;
    //}

    data data;

    printf("Digite a data de agendamento do treino (DD/MM/AA): ");

    fflush(stdin);
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
    


    int treinoHorario, localTreino;

        printf("Escolha a opção pros horarios disponiveis: \n");
        printf("[1] 6:00\n");
        printf("[2] 8:00\n");
        printf("[3] 10:00\n");
        printf("[4] 12:00\n");
        printf("[5] 14:00\n");
        printf("[6] 16:00\n");
        scanf("%d", &treinoHorario);

        char horarioTreino[MAX_CHAR];
        char *pt_horarioTreino = horarioTreino;

        printf("%s \n", pt_horarioTreino);
        switch (treinoHorario)
        {

            case 1:
                pt_horarioTreino = "6:00";
            break;
            case 2:
                pt_horarioTreino = "8:00";
            break;
            case 3:
                pt_horarioTreino = "10:00";
            break;
            case 4:
                pt_horarioTreino = "12:00";
            break;
            case 5:
                pt_horarioTreino = "14:00";
            break;
            case 6:
                pt_horarioTreino = "16:00";
            break;

            default:
            break;
            
        }

        

    
        printf("Escolha a opção do local de treinamento: \n");
        printf("[1]Arena 01 \n");
        printf("[2]Arena 02 \n");
        printf("[3]Arena 03 \n");
        printf("[4]Arena 04 \n");
        printf("[5]Arena 05 \n");
        printf("[6]Arena 06 \n");
        scanf("%d", &localTreino);

        char treinoLocal[MAX_CHAR];
        char *pt_treinoLocal = treinoLocal;

        switch (localTreino)
        {
            case 1:
            pt_treinoLocal = " Arena 01";

            break;
        
            case 2:
            pt_treinoLocal = " Arena 02";

            break;
            case 3:
            pt_treinoLocal = " Arena 03";

            break;
            case 4:
            pt_treinoLocal = " Arena 04";

            break;
            case 5:
            pt_treinoLocal = " Arena 05";

            break;
            case 6:
            pt_treinoLocal = " Arena 06";

            break;

        default:
            break;
        }
        

        

        char *destinarioTreino[60];

        printf("Digite o nome do atleta/equipe para o qual a reserva será feita: ");
        fflush(stdin);
        fgets(destinarioTreino, MAX_CHAR, stdin);
        strtok(destinarioTreino, "\n");
        
        fprintf(pont_arq, "%d %d %d %s %s %s \n", data.dia, data.mes, data.ano, destinarioTreino, pt_treinoLocal, pt_horarioTreino);

        fclose(pont_arq);

        printf("Treinamento agendado com sucesso!");

    return 1;
}


int mostraTreino(){
    
    system("cls");
    char *pt_Local[MAX_CHAR];

    FILE *bancoLocal;

    bancoLocal = fopen("banco/treino.txt", "r");

    if (get_size("banco/treino.txt") == 0)
    {
        printf("Nao existem treinos cadastrados ainda! Por favor cadastre um.\n");
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