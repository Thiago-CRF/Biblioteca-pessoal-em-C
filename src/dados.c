#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"
#include "dados.h"

#define BUFFER_LINHA 500
#define BUFFER_STRING 256

int carregar_livros(No** head_livros){
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "r");

    if(!arquivo){
        printf("\n# 'ERRO' ao abrir o arquivo #\n");
        return -1;
    }

    char linha[BUFFER_LINHA];
    int cont = 0;

    char titulo_temp[BUFFER_STRING], autor_temp[BUFFER_STRING];
    int ano_temp, pag_tot_temp, pag_lidas_temp, status_temp;

    while(fgets(linha, BUFFER_LINHA, arquivo) != NULL){
        
        //verifica se a linha lida não é maior que o buffer de 500 caracteres, e a descarta ela se for
        int len = strlen(linha);
        if(len>0 && linha[len-1] != '\n' && !feof(arquivo)){
            printf("\n# 'AVISO' Linha %d muito longa, ignorada", cont+1);
            int c;
            while((c = fgetc(arquivo)) != '\n' && c != EOF);
            continue;
        }

        // ve qual o indice onde \n está e coloca o \0 no lugar
        linha[strcspn(linha, "\n")] = '\0';

        if(strlen(linha) == 0)// pula se houver linhas vazias
            continue;

        int verifica = sscanf(linha, "%199[^|]|%199[^|]|%d|%d|%d|%d",
                            titulo_temp, autor_temp, &ano_temp, 
                            &pag_tot_temp, &pag_lidas_temp, &status_temp);

        // verifica se todos os campos foram lidos, e ignora se não foram
        if(verifica != 6){
            printf("\n# 'AVISO' Linha %d corrompida, ignorada", cont+1);
            continue;
        }

        // verifica se o valor do status é válido
        if(status_temp<0 || status_temp>2){
            printf("\n# 'AVISO' Linha %d com status invalido, ignorada", cont+1);
            continue;
        }

        No* novo = (No*)malloc(sizeof(No));

        novo->livro.titulo = (char*)malloc((strlen(titulo_temp)+1) * sizeof(char));
        // aloca memoria para o titulo, verifica se foi alocado e copia o titulo para a alocação
        if(!novo->livro.titulo){
            printf("\n# 'ERRO' Falha ao alocar memória para o titulo\n");
            free(novo);
            continue;
        }
        strcpy(novo->livro.titulo, titulo_temp);

        novo->livro.autor = (char*)malloc((strlen(autor_temp)+1) * sizeof(char));
        // aloca memoria para o autor, verifica se foi alocado e copia o titulo para a alocação
        if(!novo->livro.autor){
            printf("\n# 'ERRO' Falha ao alocar memória para o autor\n");
            free(novo);
            continue;
        }
        strcpy(novo->livro.autor, autor_temp);

        //preenche as outras variaveis da struct
        novo->livro.ano = ano_temp;
        novo->livro.paginas_tot = pag_tot_temp;
        novo->livro.paginas_lidas = pag_lidas_temp;
        novo->livro.status = (StatusLivro)status_temp;

        // organização de ordem da lista, adicionando no fim da lista encadeada
        novo->prox = NULL;

        if(*head_livros == NULL){
            cont++;
            *head_livros = novo;
            continue;
        }

        No* atual = *head_livros;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;

        cont++;
    }

    fclose(arquivo);
    return cont;
}

int salvar_livro(const Livro *livro){
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "a");

    if(!arquivo){
        printf("\n# 'ERRO' ao abrir o arquivo #\n");
        return -1;
    }

    fprintf(arquivo, "%s|%s|%d|%d|%d|%d\n",
            livro->titulo, livro->autor, livro->ano,
            livro->paginas_tot, livro->paginas_lidas, livro->status);

    fclose(arquivo);
    return 0;
}

int reescrever_livros(const No* head_livros){   // tirar o const pois ele não reescreve caso seja o primeiro livro da lista
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "w");

    if(!arquivo){
        printf("\n# 'ERRO' ao abrir o arquivo #\n");
        return -1;
    }

    const No* aux = head_livros;
    while(aux){
        fprintf(arquivo, "%s|%s|%d|%d|%d|%d\n",
            aux->livro.titulo, aux->livro.autor, aux->livro.ano,
            aux->livro.paginas_tot, aux->livro.paginas_lidas,
            aux->livro.status);
        aux = aux->prox;
    }

    fclose(arquivo);
    return 0;
}