#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"

int inner_menu_voluntario()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  VOLUNTARIOS          \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR VOLUNTARIOS        |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR VOLUNTARIOS          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                    |   \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            fflush(stdin);
            cadastroVoluntario();
        break;

        case 2:
            listarVoluntario();
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

int buscaIdVoluntario()
{
    voluntario voluntarios;

    voluntarios.id = 0;

    FILE *bancoVoluntario;

    bancoVoluntario = fopen("banco/banco-voluntarios.txt", "a+");

    if(bancoVoluntario == NULL){

        voluntarios.id = 0;
        fclose(bancoVoluntario);
    }
    else
    {
        while(!feof(bancoVoluntario))
        {
            fscanf(bancoVoluntario, "%i %s %s %s", &voluntarios.id, &voluntarios.nome, &voluntarios.sobreNome, fgets(voluntarios.cargo, MAX_CHAR, bancoVoluntario));
            strtok(voluntarios.cargo, "\n");
        }

        fclose(bancoVoluntario);
    }
    fclose(bancoVoluntario);
    return voluntarios.id;
    inner_menu_voluntario();
}

void cadastroVoluntario(){
    system("cls");

    voluntario voluntario[MAX_CHAR];

    int op, i, contaId = 0;

    FILE *bancoVoluntarios;

    bancoVoluntarios = fopen("banco/banco-voluntarios.txt", "a+");
    contaId = buscaIdVoluntario();
    
    for(i = 0; i < MAX_CHAR; i++){

        system("cls");
        printf("Nome: ");
        scanf("%s", &voluntario[i].nome);

        printf("Sobrenome: ");
        scanf("%s", &voluntario[i].sobreNome);
        fflush(stdin);

        printf("Cargo do voluntario: ");
        fflush(stdin);
        fgets(voluntario[i].cargo, MAX_CHAR, stdin);
        strtok(voluntario[i].cargo, "\n");

        voluntario[i].id = contaId+1+i;

        fprintf(bancoVoluntarios, "%i %s %s %s \n", voluntario[i].id, voluntario[i].nome, voluntario[i].sobreNome, voluntario[i].cargo);

        printf("Continuar?\n");
        printf("1 - continuar.");
        printf("0 - sair.");
        scanf("%i", &op);
        getchar();

        if (op == 0)
        {
            i = MAX_CHAR;
        }
    }
    fclose(bancoVoluntarios);
    inner_menu_voluntario();  
}

void listarVoluntario(){

    system("cls");
    
    voluntario voluntarios;

    FILE *bancoVoluntarios;

    bancoVoluntarios = fopen("banco/banco-voluntarios.txt", "r");

    printf("até aqui foi. \n");
    system("pause");
    while(fgets(voluntarios.nome, MAX_CHAR, bancoVoluntarios))
    {
        strtok(voluntarios.nome, "\n");
        printf("%s \n", voluntarios.nome);
    }

    if (!feof(bancoVoluntarios))
    {
        system("pause");
    }
   
    system("pause");
    fclose(bancoVoluntarios);
    inner_menu_voluntario();
    
}