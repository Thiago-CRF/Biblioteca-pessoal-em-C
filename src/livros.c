#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"

char *ler_string(){
    char buffer[256]; //buffer para leitura antes da alocação dinamica

    while(fgets(buffer, sizeof(buffer), stdin) == NULL){ // le a string e se não digitar nada, diz que é invalido e repete
        printf("\nTitulo invaldio, digite novamente: ");
    }

    size_t tam = strlen(buffer);
    if (tam > 0 && buffer[tam-1] == '\n'){  // tira o \n do fgets e coloca o novo final \0, atualizando tamanho
        buffer[tam-1] = '\0';
        tam--;
    }

    char *str = (char*)malloc((tam+1) * sizeof(char)); // aloca a memória incluindo o tamanho para o \0  de final

    if(str == NULL){
        printf("ERRO: Falha de alocacao de memoria\n");
        return NULL;
    }

    strcpy(str, buffer); // copia a string do buffer para a memória alocada

    return str;
}

void adicionar_livro(No **head_livros){
    //aloca memoria para o novo nó
    No *novo = (No*)malloc(sizeof(No));

    printf("\n--- Adicionar novo livro ---\n");

    // le o titulo com a função ler string, e retorna caso de erro de alocação de memoria
        printf("Digite o titulo do livro: ");
    novo->livro.titulo = ler_string();
    if(novo->livro.titulo == NULL){
        free(novo);
        return;
    }

    // le o autor com a função ler string, e retorna caso de erro de alocação de memoria
        printf("\nDigite o nome do autor: ");
    novo->livro.autor = ler_string();
    if(novo->livro.autor == NULL){
        free(novo);
        return;
    }

    printf("\nDigite o ano de publicacao"); //pega o ano de publicação do livro
    scanf("%d", &novo->livro.ano);

    printf("\nDigite o total de paginas"); // pega o numero total de paginas do livro
    scanf("%d", &novo->livro.paginas_tot);

    /* fiz um escopo dessa parte para a variavel status só existir aqui
    pergunta qual o status de leitura do livro, voltando caso o que foi digitado seja uma opção invalida, depois atualiza o
    status do livro. utilizando que o typedef do C determina cada tipo como 0, 1, 2... em ordem, e uso o "escopo" (StatusLivro) para ler assim*/
     { int status;
    do{
        printf("\nDigite a opcao do status de leitura:");
        printf("0-Nao lido; 1-Lendo/Iniciado; 2-Lido\n");
        scanf("%d", &status);
        if(status >=0 && status <=2){
            printf("\nOpcao invalida, escolha novamente\n");
        }
    } while(status >=0 && status <=2);
    novo->livro.status = (StatusLivro)status;
     }

    // define as paginas lidas como as totais caso o status seja lido, e como 0 caso o status seja não lido, e pergunta quantas paginas leu caso o status seja lendo
    if(novo->livro.status == LIDO){
        novo->livro.paginas_lidas = novo->livro.paginas_tot;
    } else 
        if(novo->livro.status == NAO_LIDO){
            novo->livro.paginas_lidas = 0;
        } else {
        printf("\nDigite a quantidade de paginas lidas: ");
        scanf("%d", &novo->livro.paginas_lidas);
    }

    while(getchar() != '\n'); // limpa o buffer do scanf

    novo->prox = *head_livros;
    *head_livros = novo;

        printf("\n# Livro registrado com sucesso #\n");
}

void listar_livros(const No *head_livros){ //apenas lista um cada livro por id de ordem, titulo e autor com um ponteiro auxiliar
    printf("\n");
    
    No *aux = head_livros;
    for(aux; aux != NULL; aux = aux->prox){
        int i = 1;
        printf("%d: %s de %s \n",i ,aux->livro.titulo, aux->livro.autor);
    }
}
