#ifndef menuus_c
#define menuus_c
#include "logi_menu.h"
#include "atleta.c"
#include "login.c"
#include "localTreinos.c"
#include "medidas.c"
#include "medico.c"
#include "medalhas.h"
#include "equipamento.c"
#include "calendario.c"
#include "alojamento.c"

void menu_main(){
    system("cls");
    printf("\n");
    printf("OLIMPIADAS 2024\n");
    printf("\n");
    printf("ESCOLHA UMA OPÇÃO\n");
    printf("\n");
    printf("1 - RELATÓRIOS\n");
    printf("\n");
    printf("2 - CADASTROS E LISTAGENS\n");
    printf("\n");
    printf("3 - GERENCIAMENTO\n");
    printf("\n");
    printf("4 - AGENDAMENTO DE LOCAL PARA TREINOS\n");
    printf("\n");
    printf("11 - SAIR\n");
    printf("\n");
}

void menu_atleta(){
    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  ESCOLHA UMA OP??O          \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR ATLETA        |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR ATLETA          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 11 - SAIR                    |   \n");
    printf("          ---------------------------------  \n");
}

void menu_consulta(){
    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                     RELAT?RIOS              \n");
    printf("          ---------------------------------  \n");
    printf("                  ESCOLHA UMA OP??O          \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRO DE MEDALHAS POR ATLETA    |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - GERAR RELATORIO DE MEDALHAS   |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 3 - DISTRIBUIÇÃO TOTAL DE MEDALHAS  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 4 - DISTRIBUIÇÃO TOTAL DE MEDALHAS POR PAÍS    |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 5 - CALENDÁRIO OLÍMPICO     |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                    |   \n");
    printf("          ---------------------------------  \n");
    printf("           | 11 - SAIR                    |   \n");
    printf("          ---------------------------------  \n");
}

void menu_cadastro_menuu(){
    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                      CADASTROS E LISTAGENS              \n");
    printf("          ---------------------------------  \n");
    printf("                  ESCOLHA UMA OP??O          \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - ATLETAS   |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - EQUIPES   |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 3 - MODALIDADES OL?MPICAS   |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 4 - EQUIPAMENTOS       |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 5 - ALOJAMENTO DOS ATLETAS |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 6 - MÉDICOS E RESPECTIVAS EQUIPES     |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 7 - MEDIDAS DE PREVENÇÃO AO COVID 19    |   \n");
    printf("           |-----------------------------|   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - VOLTAR                 |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 11 - SAIR                   |   \n");
    printf("          ---------------------------------  \n");

}

void menu_gerenciamento(){
    system("cls");
    printf("\n");
    printf("OLIMPIADAS 2024\n");
    printf("\n");
    printf("GERENCIAMENTO\n");
    printf("\n");
    printf("ESCOLHA UMA OP??O\n");
    printf("\n");
    printf("1 - CADASTRO DE USUÁRIOS\n");
    printf("\n");
    printf("2 - CADASTRO DE FUNCIONÁRIOS\n");
    printf("\n");
    printf("3 - CADASTRO DE VOLUNTÁRIOS\n");
    printf("\n");
    printf("4 - CONTROLE DE CONTINGENTE\n");
    printf("\n");
    printf("10 - VOLTAR\n");
    printf("\n");
    printf("11 - SAIR\n");
    printf("\n");
}
int logi_menu_atle(){
    int escolha;
    int fica = 1;
    do{
        menu_atleta();
        scanf("%d", &escolha);
        getchar();
        switch(escolha){
            case 1:
                cadastroAtleta();
                break;
            case 2:
                listarAtleta();
                break;
            case 3:
                printf("calma");

                break;
            case 4:
                printf("sempre");

                break;
            case 5:
                printf("piora");

                break;
            case 10:
                printf("VOLTAR");
                fica = 0;
                return 1;
                break;
            case 11:
                printf("SAIR");
                fica = 0;
                return 0;
                break;
            default:
                printf("digite um n?mero v?lido");

        }
        printf("\n");
        //system("pause");

    }while(fica);

}

int logi_menu_ger(){
    int escolha;
    int fica = 1;
    do{
        menu_gerenciamento();
        scanf("%d", &escolha);
        getchar();
        switch(escolha){
            case 1:
                cad_administrador();
                break;

            case 2:
                inner_menu_funcionario();
                break;

            case 3:
                inner_menu_voluntario();
                break;

            case 10:
                printf("VOLTAR");
                fica = 0;
                return 1;
                break;

            case 11:
                printf("SAIR");
                fica = 0;
                return 0;
                break;

            default:
                printf("digite um n?mero v?lido");

        }
        printf("\n");
        //system("pause");

    }while(fica);


}


int logi_menu_con(){
    int escolha;
    int fica = 1;
    do{
        menu_consulta();
        scanf("%d", &escolha);
        getchar();
        switch(escolha){
            case 1:
                escreveBanco();
                break;
                
            case 2:
                geraRelatorio();
                break;

            case 3:
                totalMedalha();
                break;

            case 4:
                totalPaises();
                break;

            case 5:
                inner_menu_calendario();
                break;

            case 10:
                printf("VOLTAR");
                fica = 0;
                return 1;
                break;
            case 11:
                printf("SAIR");
                fica = 0;
                return 0;
                break;
            default:
                printf("digite um número válido");
        }
        printf("\n");
        //system("pause");

    }while(fica);

}

int logi_menu_cad(){
    int escolha;
    int fica = 1;
    do{
        menu_cadastro_menuu();
        scanf("%d", &escolha);
        getchar();
        switch(escolha){
            case 1:
                inner_menu_atleta();
                break;
            case 2:
                inner_menu_equipe();
                break;
            case 3:
                printf("MODALIDADES");
                break;
            case 4:
                inner_menu_equipamento();
                break;
            case 5:
                inner_menu_alojamento();
                break;
            case 6:
                inner_menu_medico();
                break;
            case 7:
                inner_menu_medidas();
                break;
            case 8:
                printf("VOLUNT?RIOS");
                break;
            case 9:
                printf("CONTROLE COVID-19");
                break;
            case 10:
                printf("VOLTAR");
                fica = 0;
                return 1;
                break;
            case 11:
                printf("SAIR");
                fica = 0;
                return 0;
                break;
            default:
                printf("digite um n?mero v?lido");
        }
        printf("\n");
        //system("pause");

    }while(fica);

}
#endif

