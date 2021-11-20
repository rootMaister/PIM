#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "logi_menu.h"
#include "medalhas.h"

int main(){
    int opcao;
    int peg = 1;
    setlocale(LC_ALL, "Portuguese");
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
            case 9:
                printf("sair");//sair
                peg = 0;
                break;
            default:
                printf("digite um n?mero v?lido");
        }
        printf("\n");
        //system("pause");
    }while(peg);



   return 0;
}
