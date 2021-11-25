#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "equipe.c"
#include "atleta.c"
#include "voluntario.c"
#include "funcionario.c"
#include "menuus.c"
#include "logi_menu.h"
#include "medalhas.h"
#include "relatorios.c"
#include "login.c"
#include "menu.c"

int main(){

    if (primeiroAcesso() == 1)
    {
        menu();
    }

    system("pause");
   return 0;
}