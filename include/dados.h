#ifndef DADOS_H
#define DADOS_H

#define ARQUIVO_LIVROS "livros.txt"

/* vai carregar todos os livros para a lista encadeada,
a função retorna a quantidade de livros que foram carregados e -1 caso dê qualquer erro*/
int carregar_livros(No **head_livros);

/* adiciona um livro a última linha do arquivo .txt, recebendo uma variável Livro com todos os dados
retorna 0 pra sucesso e -1 pra erro */
int salvar_livro(const Livro *livro); // usado só pra adicionar novos livros

/* reescreve todo o .txt com a lista de livros recebido. usado apenas para quando excluir um livro ou editar progresso
retorna 0 pra sucesso e -1 pra erro */
int reescrever_livros(const No *head_livros);

#endif