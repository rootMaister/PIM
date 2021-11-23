#ifndef structs_h
#define structs_h

#include <stdlib.h>
#include <stdio.h>

#define MAX_CHAR 400

int get_size(const char* file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}


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