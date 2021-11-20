#ifndef menu_c
#define menu_c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "menuus.c"
#include "login.c"
#include "localTreinos.c"
#include "agendarTreino.c"

int menu(){

    int opcao;
    int peg = 1;
    setlocale(LC_ALL, "");
    do {
        menu_main();
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                peg = logi_menu_con();
                break;

            case 2:
                peg = logi_menu_cad();
                break;

            case 3:
                peg = logi_menu_ger();
                break;

            case 4:
                peg = inner_menu_agendar_treino();
                break;

            case 11:
                printf("sair");
                peg = 0;
                break;

            default:
                printf("digite um número válido");
        }
        printf("\n");
    }while(peg);
   return 0;
}

#endif