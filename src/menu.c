#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "livros.h"
#include "dados.h"

void menu(){
    Livro *livros = NULL;
    int quantidade = load_livros(&livros);

}