#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structs.h"
#include "logi_menu.h"

int inner_menu_funcionario()
{
    int op = 0, stay = 1;

    system("cls");
    printf("          ---------------------------------  \n");
    printf("                  OLIMPIADAS 2024            \n");
    printf("          ---------------------------------  \n");
    printf("                  FUNCIONARIO          \n");
    printf("          ---------------------------------  \n");
    printf("           | 1 - CADASTRAR FUNCIONÁRIOS        |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 2 - LISTAR FUNCIONÁRIOS          |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 9 - VOLTAR                  |   \n");
    printf("           |-----------------------------|   \n");
    printf("           | 10 - SAIR                    |   \n");
    printf("          ---------------------------------  \n");

    scanf("%i", &op);
    switch (op)
    {
        case 1:
            cadastroFuncionario();
        break;

        case 2:
            listarFuncionario();
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

int buscaIdFuncionario()
{
    funcionario funcionarios;

    funcionarios.id = 0;

    FILE *bancoFuncionario;
    bancoFuncionario = fopen("banco/banco-funcionarios.txt", "a+");

    while(!feof(bancoFuncionario))
    {
        fscanf(bancoFuncionario, "%i %s %s %s \n", &funcionarios.id, &funcionarios.nome, &funcionarios.sobreNome, fgets(funcionarios.cargo, MAX_CHAR, bancoFuncionario));
        strtok(funcionarios.cargo, "\n");
    }

    fclose(bancoFuncionario);
    return funcionarios.id;
    inner_menu_funcionario();
}

void cadastroFuncionario(){
    system("cls");

    funcionario funcionarios[MAX_CHAR];

    int op, i, contaId = 0;

    FILE *bancoFuncionarios;

    bancoFuncionarios = fopen("banco/banco-funcionarios.txt", "a+");
    contaId = buscaIdFuncionario();
    
    for(i = 0; i < MAX_CHAR; i++){

        system("cls");
        printf("Nome: ");
        scanf("%s", &funcionarios[i].nome);

        printf("Sobrenome: ");
        scanf("%s", &funcionarios[i].sobreNome);
        fflush(stdin);

        printf("Cargo do funcionario: ");
        fflush(stdin);
        fgets(funcionarios[i].cargo, MAX_CHAR, stdin);
        strtok(funcionarios[i].cargo, "\n");

        funcionarios[i].id = contaId+1+i;

        fprintf(bancoFuncionarios, "%i %s %s %s \n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].sobreNome, funcionarios[i].cargo);

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
    fclose(bancoFuncionarios);
    inner_menu_funcionario();  
}

void listarFuncionario(){

    system("cls");
    
    voluntario funcionarios;

    FILE *bancoFuncionarios;

    bancoFuncionarios = fopen("banco/banco-funcionarios.txt", "r");
    while(fgets(funcionarios.nome, MAX_CHAR, bancoFuncionarios))
    {
        strtok(funcionarios.nome, "\n");
        printf("%s \n", funcionarios.nome);
    }

    if (!feof(bancoFuncionarios))
    {
        system("pause");
    }
   
    system("pause");
    fclose(bancoFuncionarios);
    inner_menu_funcionario();
}





