#ifndef LIVROS_H
#define LIVROS_H

typedef enum {
    NAO_LIDO,
    LENDO,
    LIDO
} StatusLivro;

typedef struct {
    char *titulo, *autor;
    int ano, paginas_tot, paginas_lidas; 
    StatusLivro status;
} Livro;

typedef struct No {
    Livro livro;
    struct No *prox;
} No;

/* adiciona um livro no começo da lista, fazendo o mais recente ser a cabeça*/

// funções dos livros
void adicionar_livro(No **head_livros); /* OK Adiciona um livro, pedindo que digite   
o titulo, autor, ano, paginas totais, paginas lidas, e status(se leu, ou nao ou esta lendo)*/

void remover_livro(No **head_livros); /* fala pra digitar o numero do livro que 
quer remover, e lista todos os livros registrados, dando numeros crescentes de 1 até o ultimo livro
OBS: recebe **head_livros porque se precisar remover o primeiro da lista ele precisa modificar a cabeça*/

int listar_livros(const No *head_livros);/* OK apenas lista os livros, e da um numero de 1
até o ultimo livro
*/
void listar_por_status(const No *head_livros, StatusLivro status);/* lista os livros começando
pelos lidos, depois pelos lendo e então não lidos, formatando para ficar separado e facil de entender*/

void editar_progresso(No *head_livros);/* OK Lista os livros pra perguntar qual quer editar o progresso
e depois pede pra digitar o novo progresso atualizado*/

void mostrar_livro(const No *head_livros);/* OK Lista os livros pra perguntar qual quer exibir, e depois
pergunta qual o numero do livro pra exibir e exibe todas as informações do livro escolhido */

void liberar_lista(No **head_livros);/* OK libera toda a memória da lista, excluindo toda a lista, deixando
apenas o endereço da cabeça, que apontará para NULL*/

#endif