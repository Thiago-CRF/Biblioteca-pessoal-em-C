#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "livros.h"
#include "dados.h"

void inicializar_lista(No **inicio){
    if(inicio == NULL){
        return;
    }
    *inicio = NULL;
}

int main(){
    No* head_lista;
    inicializar_lista(&head_lista);

    int cont = carregar_livros(&head_lista);

    menu(&head_lista, cont);

    liberar_lista(&head_lista);
    
    return 0;
}