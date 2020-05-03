/**
@file main.c
Módulo principal do jogo Rastros.
*/
#include "dados.h"
#include "interface.h"
#include "logica.h"

int main () {
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}
