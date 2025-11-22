#ifndef DADOS_H
#define DADOS_H
#include "livros.h"

#define ARQUIVO_LIVROS "livros.txt"

/* vai carregar todos os livros para a memória e fazer isso uma vez só enquanto o programa executar,
e após as operações dar free na memória. E caso eu precise salvar um livro, dar free e depois carregar tudo 
de novo após ter salvo no .txt
a função retorna a quantidade de livros que foram carregados*/
int load_livros(No **head_livros);

/* adiciona um livro a última linha do arquivo .txt, recebendo uma variável Livro com todos os dados*/
void salvar_livro(const Livro *livros);

/* reescreve todo o .txt com o vetor livros recebido. usado apenas para quando excluir um livro*/
void reescrever_livros(const No *head_livros);

#endif