#ifndef login_c
#define login_c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "renderImg.c"
#define qtd_cad 200

char *nome[qtd_cad] [qtd_cad];
char *senha[qtd_cad] [qtd_cad];
char *cpf[qtd_cad] [qtd_cad];
char *confirmaSenha[qtd_cad] [qtd_cad];

int nivelPermissao = 0;
int sessao = 0;

typedef struct login
{
    char nome[qtd_cad];
    char senha[qtd_cad];
    char cpf[qtd_cad];
    int permissao;
    
}login;



int cad_administrador(){
    int permissao, senhaConfirmada = 0;

    FILE *listaUsuarios = fopen("lista-cadastro.txt", "r");

    static int linha;
    system("cls");

    if (listaUsuarios == NULL && sessao == 0)
    {
        printf("Seja bem vindo ao Sistema de Gerenciamento Olimpiadas 2024!\n");
        printf("Para o seu primeiro acesso, cadastre um nome e uma senha.\n");
    }
    printf("\n");
    printf("CADASTRO DE USUÁRIO\n");
    fflush(stdin);
    printf("Nome de usuário:");
    fflush(stdin);
    scanf("%s", &nome[linha]);
    fflush(stdin);
    //RECEBER SENHA.
    printf("Senha:");
    scanf("%s", &senha[linha]);
    fflush(stdin);
    printf("Confirme a senha: ");
    scanf("%s", &confirmaSenha[linha]);
    
    do
    {
        if ( strcmp(senha[linha], confirmaSenha[linha] ) == 0)
        {   
            printf("Tudo certo para o seu acesso, %s!", nome[linha]);
            if (sessao == 0)
            {
                printf("Utilize nome e senha para fazer o seu primeiro login! \n");
                system("pause");
            }
            
            senhaConfirmada = 1;
        }
        else
        {
            printf("As senha não batem! Tente novamente por favor. \n");
            printf("Senha:");
            scanf("%s", &senha[linha]);
            fflush(stdin);
            printf("Confirmar senha: ");
            scanf("%s", &confirmaSenha[linha]);
            fflush(stdin);
        }
        
    } while (senhaConfirmada == 0);
    

    //RECEBER PERMISSÃO.
    if (listaUsuarios == NULL)
    {   
        //Se o arquivo não existir, ou for nullo, o primeiro cadastro sempre será com permissão de Admnistrador automaticamente;
        permissao = 1;
        fflush(stdin);
        fclose(listaUsuarios);
    }
    else
    {
        system("cls");
        printf("1 - Admnistrador\n");
        printf("2 - Staff\n");
        printf("3 - Voluntario\n");
        printf("Escolha uma permissão para esse usuário: ");
        
        scanf("%d", &permissao);
        fflush(stdin);
        fclose(listaUsuarios);
    }
    
    FILE *listaCadastro;
    listaCadastro = fopen("banco/lista-cadastro.txt", "a");
    
    fprintf(listaCadastro, "%s %s %d\n", nome[linha], senha[linha], permissao);

    fclose(listaCadastro); 

    if (sessao == 0)
    {
        if (LOGIN_Admin() == 1)
        {
            return 1;
        }
    }   
}

int opcao;

int LOGIN_Admin()
{
    int verificaFimPermissao = 0;

    char nomeVerificacao[30], senhaVerificacao[20];

    FILE *logo_olimpiadas = fopen("logo-olimpiadas.txt", "r");

    //renderImg(logo_olimpiadas);

    system("cls");
    login login;

    static int linha;
    printf("LOGIN\n");
    printf("Nome:");
    fflush(stdin);
    scanf("%s", &nome[linha]);
    printf("senha:");
    scanf("%s", &senha[linha]);
    fflush(stdin);
    
    FILE *listaCadastro;
    listaCadastro = fopen("banco/lista-cadastro.txt", "r");

    while(1){
        fscanf(listaCadastro, "%s %s %i", &login.nome, &login.senha, &login.permissao);
        if (strcmp(nome[linha], login.nome) == 0 && strcmp(senha[linha], login.senha) == 0)
        {
            verificaFimPermissao = 1;
            break;
        }
        else
        {
            verificaFimPermissao = 0;
            break;
        }

        if(feof(listaCadastro) != 0){
            break;
        }
    }
    
    if (verificaFimPermissao == 0)
    {
        printf("acesso negado! Por favor tente novamente\n");
        system("pause");
        
        
        if (LOGIN_Admin() == 0)
        {   
            //Retorna para o primeiro acesso;
            return 0;
        }
        else
        {
            //Retorna para o primeiro acesso;
            return 1;
        }
        
    }

    if (verificaFimPermissao == 1)
    {
        printf("acesso permitido! \n");

        nivelPermissao = login.permissao;
        //Retorna para o primeiro acesso;
        return 1;
    }

    system("pause");
    
    fclose(listaCadastro);
}

int primeiroAcesso()
{
        int qtd_administrador = 0;
        setlocale(LC_ALL, "Portuguese"); //Habilita a acentuação para o português

        FILE *listaCadastro;
            listaCadastro = fopen("banco/lista-cadastro.txt", "r");

                if(listaCadastro == NULL)
                {
                    if (cad_administrador(qtd_administrador++) == 1)
                    {   
                        //Retorna para main
                        //Caso seja falso (igual a 0) ele desce pro 'Else'
                        sessao = 1;
                        return 1;
                    }
                    
                }
                else
                {   
                    if(LOGIN_Admin() == 1){
                        //Retorna para main
                        sessao = 1;
                        return 1;
                    }
                }

                fclose(listaCadastro);
        return 0;
}
#endif