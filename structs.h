#ifndef structs_h
#define structs_h

#include <stdlib.h>
#include <stdio.h>

#define MAX_CHAR 500

typedef struct atleta
{
    int id;
    char nome[MAX_CHAR];
    char sobreNome[MAX_CHAR];
    char paisOrigem[MAX_CHAR];
    char modalidade[MAX_CHAR];
    char equipe[MAX_CHAR];
}atleta;

typedef struct equipe
{
    int id;
    char nome[MAX_CHAR];
}equipe;


typedef struct voluntario
{
    int id;
    char nome[MAX_CHAR];
    char sobreNome[MAX_CHAR];
    char cargo[MAX_CHAR];
}voluntario;


typedef struct funcionario
{
    int id;
    char nome[MAX_CHAR];
    char sobreNome[MAX_CHAR];
    char cargo[MAX_CHAR];
    char funcao[MAX_CHAR];
}funcionario;

#endif