#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"
#include "menu.h"
#include "dados.h"

/* opções em ordem:
    adicionar livro
    remover livro
    exibir a lista de livros
    exibir informações de um livro
    editar progresso de leitura
    */

    // limpa a tela se for windows e se for outro sistema 
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() { // pausar execução para esperar a pessoa ver a cada escolha
    printf("\n# Pressione ENTER para continuar... #\n");
    limpa_buffer();
    getchar();
}

void menu(No **head_livros, int qtd){
    int opcao;

    if(qtd == -1)
        printf("\n# 'ERRO' ao carregar os livros # \n");
     else 
        if(qtd>1) 
            printf("\n# %d livros carregados com sucesso #\n", qtd);
         else 
            if(qtd == 1)
                printf("\n# 1 livro carregado com sucesso #\n");
            

    do{
        printf("\n#### BIBLIOTECA PESSOAL ####\n");

        printf("    [1] Adicionar livro\n");
        printf("    [2] Remover livro\n");
        printf("    [3] Listar livros de forma simples\n");
        printf("    [4] Listar livros com detalhes\n");
        printf("    [5] Listar livros por status\n");
        printf("    [6] Exibir informacoes de um livro\n");
        printf("    [7] Editar progresso de leitura\n");
        printf("    [0] Sair\n\n");
        
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                adicionar_livro(head_livros);
                pausar();
                break;
            case 2:
                remover_livro(head_livros);
                pausar();
                break;
            case 3:
                listar_livros(*head_livros);
                pausar();
                break;
            case 4:
                listar_detalhado(*head_livros);
                pausar();
                break;
            case 5:
                listar_por_status(*head_livros);
                pausar();
                break;
            case 6:
                mostrar_livro(*head_livros);
                pausar();
                break;
            case 7:
                editar_progresso(*head_livros);
                pausar();
                break;
            case 0:
                printf("\n# Sistema encerrado #\n");
                pausar();
                break;
            default:
                printf("\n# Opcao invalida, selecione uma opcao valida do menu #\n");
                pausar();     
        }
    limpar_tela();
    } while(opcao != 0);
}