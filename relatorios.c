#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medalhas.h"

void escreveBanco(){

    system("cls");
    char nome[50];
    char pais[50];
    char medalha[10];

    FILE *arquivo;

    printf("Digite o nome do atleta:");
    fflush(stdin);
    fgets(nome, 50, stdin);

    printf("Digite a sigla do pais do atleta:");
    fflush(stdin);
    scanf("%s", &pais);

    if(pais[0] > 96){
        pais[0] = pais[0] - 32;
    }
    if(pais[1] > 96){
        pais[1] = pais[1] - 32;
    }

    printf("Digite a medalha:");
    fflush(stdin);
    scanf("%s", &medalha);

    if(medalha[0] < 96){
        medalha[0] = medalha[0] + 32;
    }


    arquivo = fopen("bancoMA.txt", "a+");
    fprintf(arquivo, "%-10s %-10s %s", medalha, pais, nome);
    fclose(arquivo);
}

void geraRelatorio(){

    system("cls");
    char linha[100];
    char nomeA[100];
    char extesao[5] = ".txt";
    int c = 0;

    printf("Digite o nome do relatorio: ");
    fflush(stdin);
    scanf("%s", &nomeA);

    strncat(nomeA, extesao, 10);

    FILE *arquivoMA;
    FILE *arquivoRE;

    arquivoMA = fopen("banco/bancoMA.txt", "r");

    if(arquivoMA == NULL){
        arquivoMA = fopen("banco/bancoMA.txt", "a+");
    }

    arquivoRE = fopen(nomeA, "w");

    while(1){
        fgets(linha, 100, arquivoMA);
        if(feof(arquivoMA) != 0){
            break;
        }
        fprintf(arquivoRE, " %-4d %s", c, linha);
        c++;
    }

    fclose(arquivoRE);
    fclose(arquivoMA);

}

void totalMedalha(){

    system("cls");
    char linha[100];
    char nomeA[100];
    char extesao[5] = ".txt";

    int totalOuro = 0;
    int totalPrata = 0;
    int totalBronze = 0;
    int totalSem = 0;

    printf("Digite o nome do relatorio: ");
    fflush(stdin);
    scanf("%s", &nomeA);

    strncat(nomeA, extesao, 10);

    FILE *arquivoMA;
    FILE *arquivoRE;

    arquivoMA = fopen("banco/bancoMA.txt", "r");

    if(arquivoMA == NULL){
        arquivoMA = fopen("banco/bancoMA.txt", "a+");
    }
    arquivoRE = fopen(nomeA, "w");

    while(1){
        fgets(linha, 100, arquivoMA);
        if(feof(arquivoMA) != 0){
            break;
        }
        if(linha[0] == 'o'){
            totalOuro++;
        } else if(linha[0] == 'p'){
            totalPrata++;
        } else if(linha[0] == 'b'){
            totalBronze++;
        } else {
            totalSem++;
        }
    }
    fprintf(arquivoRE, "TOTAL DE MEDALHAS\n");
    fprintf(arquivoRE, " %-4d Medalhas de Ouro\n", totalOuro);
    fprintf(arquivoRE, " %-4d Medalhas de Prata\n", totalPrata);
    fprintf(arquivoRE, " %-4d Medalhas de Bronze\n", totalBronze);
    fprintf(arquivoRE, " %-4d Medalhas SEM metal\n", totalSem);

    fclose(arquivoRE);
    fclose(arquivoMA);
}

void totalPaises(){
    system("cls");
    char nulo = '�';
    char linha[100];
    char nomeA[100];
    char extesao[5] = ".txt";

    printf("Digite o nome do relatorio: ");
    fflush(stdin);
    scanf("%s", &nomeA);

    strncat(nomeA, extesao, 10);

    struct Pais {
        char sigla[2];
        int medalhaOuro;
        int medalhaPrata;
        int medalhaBronze;
        int medalhaTotal;
    }Paises[220];

    FILE *arquivoMA;
    FILE *arquivoDI;
    FILE *arquivoRE;

    arquivoMA = fopen("banco/bancoMA.txt", "r");

    if(arquivoMA == NULL){
        arquivoMA = fopen("banco/bancoMA.txt", "a+");
    }
    for(int i = 0; i < 220; i++){
        Paises[i].sigla[0] = nulo;
        Paises[i].sigla[1] = nulo;
        Paises[i].medalhaTotal = 0;
    }
    while(1){
        fgets(linha, 100, arquivoMA);
        if(feof(arquivoMA) != 0){
            break;
        }
        int f = 0;
        while(f < 220){
            if(Paises[f].sigla[0] == nulo && Paises[f].sigla[1] == nulo || Paises[f].sigla[0] == linha[11] && Paises[f].sigla[1] == linha[12]){
                Paises[f].sigla[0] = linha[11];
                Paises[f].sigla[1] = linha[12];
                f = 221;
            }else {
                f++;
            }
        }
    }
    fclose(arquivoMA);

    int tamanhoPaises = 0;
    while(Paises[tamanhoPaises].sigla[0] != nulo && Paises[tamanhoPaises].sigla[1] != nulo){
        tamanhoPaises++;
    }

    arquivoDI = fopen("banco/bancoMA.txt", "r");
    if(arquivoDI == NULL){
        arquivoDI = fopen("banco/bancoMA.txt", "a+");
    }
    int contaLinha = 0;

    while(1){
        fgets(linha, 100, arquivoDI);
        if(feof(arquivoDI) != 0){
            break;
        }
        int contaPaises = 0;
        while(contaPaises <= tamanhoPaises){
            if(linha[11] == Paises[contaPaises].sigla[0] && linha[12] == Paises[contaPaises].sigla[1]){
                Paises[contaPaises].medalhaTotal++;
                contaPaises = tamanhoPaises + 1;
            }
            contaPaises++;
        }
        contaLinha++;
    }
    fclose(arquivoDI);

    arquivoRE = fopen(nomeA, "w");
    fprintf(arquivoRE, "TOTAL DE MEDALHAS POR PAIS\n");

    for(int i = 0; i < tamanhoPaises; i++){
        fprintf(arquivoRE, "  %c%c = %-3d\n", Paises[i].sigla[0], Paises[i].sigla[1], Paises[i].medalhaTotal);
        //printf("O pais %c%c tem %d medalhas\n", Paises[i].sigla[0], Paises[i].sigla[1], Paises[i].medalhaTotal);
    }
    fclose(arquivoRE);
}



