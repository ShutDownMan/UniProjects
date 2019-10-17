#ifndef ARVOREBMAIS_H
#define ARVOREBMAIS_H
#ifndef ARVORE_H
#define ARVORE_H
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
#define ORDEM 5

//estrutura para o cabe�alho do arquivo
typedef struct cabecalho{

    int topo;
    int raiz;
    int livre;

}Cabecalho;

//estrutura que contem as informa��es dos livros
typedef struct livro{

    int codigo;
    char titulo[MAX];
    char autor[MAX];
    int quant_exemp;
}Livros;


//estrutura usado como dados satalites, para nao precisar carregar todas as informa��es
typedef struct dados{

    int codigo;
    int posicao;
}Dados;

//estrutura para o no da arvore
typedef struct arvore{

    Dados registro;
    int dir;
    int esq;
    int posicao;
}Arvore;

//estrutura para o cabe�alho da biblioteca, contendo o topo(tamanaho\ultima folha) e  posi��o livre
typedef struct cabecalhoBiblioteca{

    int topo;
    int livre;

}Cabecalho_bib;


//estrutura que contem um inteiro marcando o proximo no livre
typedef struct no_livre{

    int prox;

}NoLivre;

//estrutura que contem a proxima posi��o livre para um livro
typedef struct livro_livre{

    int prox;

}LivroLivre;

struct arvorebmais {
    Dados chave[ORDEM];  /// vetor de chaves
    int filho[ORDEM+1];    /// vetor para noh filho
    int pai[ORDEM];      /// vetor para noh pai
    int eh_folha;      /// folha
    int numChaves;     /// numero de chaves no noh
    int posicao;       /// posicao
};


typedef struct arvorebmais ArvoreBMAIS;

struct no{
    void *info;
    struct no* prox;
    struct no* ant;
};

typedef struct no No;

struct fila{
    int n;
    struct no* inicio;
    struct no* final;
};

typedef struct fila Fila;

void imprimeRegistro(FILE *registro, FILE *dados);

/**
 * @brief lerNome l� o nome do arquivo passado como parametro
 * @param argv
 * @return
 */
char *lerNome(const char *argv[]);

void leituraConsole(FILE *arquivo, FILE *dados);
/**
 * @brief escreveCabBib funcao que escreve o cabecalho do livro no arquivo binario
 * @param biblioteca_bin ponteiro para o arquivo binario
 * @param livro ponteiro para cabe�alho da biblioteca de livros
 */
void escreveCabBib(FILE* biblioteca_bin, Cabecalho_bib *livro);

/**
 * @brief criaCabBib cria o cabe�alho do livro no arquivo binario (biblioteca)
 * @param biblioteca_bin ponteiro para arquivo binario
 */
void criaCabBib(FILE* biblioteca_bin);

/**
 * @brief EscreveCabArv escreve o cabe�alho do no (raiz) no arquivo binario
 * @param arvore_bin ponteiro para o arquivo binario que contem a arvore binaria
 * @param arvore variavel do tipo cabe�alho, que contem o cabe�alho do arquivo binario
 */
void EscreveCabArv(FILE* arvore_bin, Cabecalho* arvore);

/**
 * @brief criaCabArv cria o cabe�alho para o arquivo binario das arvores
 * @param arvore_bin ponteiro para o arquivo binario que contem a arvore binaria
 */
void criaCabArv(FILE* arvore_bin);

/**
 * @brief obterLivros dado um arquivo binario que contem os livros e a posi��o desejada a fun��o vai para a posi��o passada e le o que tem nela
 * @param biblioteca_bin ponteiro para arquivo binario que contem os livros
 * @param posicao posi��o de onde deseja fazer a leitura do arquivo binario
 * @return retorna uma estrutura tipo ponteiro para Livros que contem as informa��es lidas na posi��o
 */
Livros* obterLivros(FILE* biblioteca_bin, int posicao);

/**
 * @brief lerNos faz a leitura do no da arvore contido no ponteiro para arquivo binario passado como parametro e na posi��o tamb�m passada como paramtro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura de arvore
 * @param posicao posi��o na qual deseja ser o n�
 * @return retorna as informa�oes contidas no n� lido
 */
ArvoreBMAIS* lerNos(FILE* arvore_bin, int posicao);

/**
 * @brief lerCabLivro le o cabe�alho do livro contido no arquivo binario
 * @param biblioteca_bin ponteiro para arquivo binario que contem os livros
 * @return retorna as informa�oes contidas no cabe�alho do livro armazenado no arquivo binario, do tipo cabecalho_bib
 */
Cabecalho_bib* lerCabLivro(FILE* biblioteca_bin);


/**
 * @brief lerCabArv obtem as informa��es contidas no cabe�alho da arvore armazenada no arquivo binario
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore
 * @return retorna as informa�oes contidas no cabe�alho, do tipo estrutura Cabe�alho
 */
Cabecalho* lerCabArv(FILE* arvore_bin);

/**
 * @brief inicializarBib aloca a memoria para contem livros e seta seus parametros como nulos
 * @return retorna a instancia de memoria alocada
 */
Livros* inicializarBib();

/**
 * @brief inicializarArv aloca memoria para uma estrutura de arvore e seta seus dados como nulos e livres
 * @return retorna uma estrutra de arvore instanciada na memoria
 */
Arvore* inicializarArv();

/**
 * @brief obterNoLivre obtem o no da posi��o passada como parametro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param posicao posi��o passada como parametro para verificar se o no esta livre
 * @return retorna o endere�o do n� livre
 */
NoLivre* obterNoLivre(FILE* arvore_bin, int posicao);

/**
 * @brief obterLivroLivre dada uma posi��o como parametro obtem o livro contido nela
 * @param biblioteca_bin ponteiro para arquivo que contem os livros
 * @param posicao posi��o do livro
 * @return retorna o livro
 */
LivroLivre* obterLivroLivre(FILE* biblioteca_bin, int posicao);

/**
 * @brief escreveBib escreve o livro no arquivo binario da biblioteca
 * @param biblioteca_bin ponteiro para arquivo binario que contem os livros
 * @param cabBib cabe�alho do arquivo que contem os livros
 * @param livro parametro onde vai ser escrito o livro
 * @return retorna a posi��o onde livro foi inserido
 */
int escreveBib(FILE* biblioteca_bin, Cabecalho_bib* cabBib, Livros *livro);

/**
 * @brief escreveArv escreve o no da estrutura de arvore binaria o arquivo binario que � contem
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutra da arvore
 * @param no n� da estrutura da arvore passada
 * @param arvore cabe�alho do arquivo contendo a arvore
 * @return retorna a posi��o onde n� foi inserido no arquivo
 */
int escreveArv(FILE* arvore_bin, ArvoreBMAIS* no, Cabecalho *arvore);

/**
 * @brief insere insere no arquivo binario da estrutura da arvore um n� contendo todas informa�oes do livro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore
 * @param codigo codigo do livro a ser inserido
 * @param posicao posi��o do livro no arquivo binario da biblioteca
 */
void insere(FILE* arvore_bin, int codigo, int posicao);

/**
 * @brief lerArquivo faz a leitura do arquivo inializado no programa
 * @param biblioteca_bin ponteiro para arquivo binario que contem a bliblioteca de livros
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutra para arvore binaria
 * @param linha_arq linha lida do arquivo de inicializa��o
 */
void lerArquivo( FILE* biblioteca_bin, FILE* arvore_bin, char *linha_arq);

/**
 * @brief imprimeArq imprime os dados dos livros
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 */
void imprimeArq(FILE* biblioteca_bin);
/**
 * @brief imprime_no imprime na console a estrutura arvore
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz no da arvore que ser� impresso
 */
void imprime_no(FILE* arvore_bin, Arvore* raiz);

/**
 * @brief imprimeArv obtem o cabe�alho da arvore e com a ajuda de uma fun��o auxiliar imprime a estrutura da arvore binaria
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 */
void imprimeArv(FILE* arvore_bin);

/**
 * @brief imprimir_livro imprime informa��es do livro na console
 * @param livro parametro que contem as informa�oes dos livros
 */
void imprimir_livro(Livros* livro);

/**
 * @brief imprimeInOrdem imprime a arvore inordem na console, do menor para o maior, usando seu codigo como requisito
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param raiz no que contem as informa��es dos livros
 * @param livro estrutura dos livro, que contem suas informa��es
 */
void imprimeInOrdem( FILE* arvore_bin, FILE* biblioteca_bin, Arvore* raiz, Livros* livro);

/**
 * @brief imprime_acervo imprime o acervo de livros armazenados no arquivo binario da biblioteca
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 */
void imprime_acervo(FILE* arvore_bin, FILE* biblioteca_bin);

/**
 * @brief escanear le uma informa��o do teclado, via console
 * @return retorna a informa��o obtida na console
 */
int escanear();

/**
 * @brief buscar fun��o para fazer a busca de determinada chave dada como parametro, fazendo a busca nos n�s da arvore, recursivamente
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param r parametro do tipo Arvore que contem as raizes dos nos
 * @param x chave buscada
 * @return
 */
Arvore* buscar(FILE* arvore_bin, Arvore* r, int x);

/**
 * @brief buscar_livro fun��o para buscar livro de acordo com seu c�digo pre inserido e imprime livro, se encontrado
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param procurado codigo do livro usado como chave para busca
 */
void buscar_livro(FILE* arvore_bin, FILE* biblioteca_bin, int procurado);

/**
 * @brief atualizaQuant fun��o que encontra chave pre inserida e edita a informa��o de quantidade de exemplares no livro que contem tal chave
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutra da arvore binaria
 * @param posicao posi��o na qual o usuario deseja atualizar numero de exemplares
 * @param nova_quant parametro que armazena a nova quantidade de exemplares do livro
 */
void atualizaQuant(FILE* biblioteca_bin, FILE* arvore_bin, int posicao);


/**
 * @brief divide auxilia na ordena��o dos livros, com o metodo de divis�o e conquista, faz a troca do elemento caso seja menor
 * @param vetor vetor de variaveis do tipo Livros que guarda um no (folha)
 * @param e lado esquerdo do vetor, inicializado como zero
 * @param d lado direito do vetor, a ultima posi�ao dele ou no caso a ultima posi��o da arvore
 * @return  retorna o vetor divido para ordena��o, com suas posi��es corrigidas,
 */
int divide(Livros* vetor[], int e, int d);

/**
 * @brief Quicksort metodo de ordena��o de vetor de divis�o e conquista, divide o vetor em duas partes e vai ordenando-as
 * @param vetor variavel do tipo Livro que contem a folha dele
 * @param e lado esquerdo do vetor, inicializado em 0
 * @param d lado direito do vetor, inicializado com o tamanho total dele
 */
void Quicksort(Livros* vetor[], int e, int d);

/**
 * @brief tamanhovet fun��o para obter o tamanho total do vetor, de acordo com o tamanho da biblioteca, da arvore e seus nos
 * @param vetor variavel do tipo livro que contem informa��es dos livros, para ordena��o
 * @param t variavel usada para armazenar o tamanho que o vetor deve conter
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param raiz no que contem as informa�oes dos livros
 * @return retorna o tamanho total do vetor
 */
int tamanhovet(Livros* vetor[], int t, FILE* arvore_bin, FILE* biblioteca_bin, Arvore* raiz);

/**
 * @brief gerarListagem escreve arquivo texto que contem as informa��es dos livros de forma ordenada
 * @param vet vetor ordenado de livros
 * @param tam tamanho total do vetor
 */
void gerarListagem(Livros* vet[], int tam );

/**
 * @brief gerarOrdenacao faz a ordena��o do vetor que contem as informa��es dos livros
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 */
void gerarOrdenacao(FILE* biblioteca_bin, FILE* arvore_bin);

/**
 * @brief criaNoL cria um n� livre
 * @return retorna o endere�o desse novo n� livre
 */
NoLivre* criaNoL();

/**
 * @brief escreveNoL escreve informa�oes em um n� livre
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param cab cabe�alho da arvore binaria contida no arquivo binario
 * @param arvore variavel do tipo estrutra de arvore para obter as posi��es dos nos
 */
void escreveNoL(FILE* arvore_bin, Cabecalho* cab, ArvoreBMAIS* arvore);

/**
 * @brief criaLL instancia memoria para um livro
 * @return retorna o endere�o para armazenar informa�oes do tipo estrutura para livros
 */
LivroLivre* criaLL();

/**
 * @brief escreveLL escreve informa��es de livros na posi��o do livro desejada
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param cab cabe�alho da arvore binaria contida no arquivo binario
 * @param pos posi��o na qual deseja escrever o novo no
 */
void escreveLL(FILE* arvore_bin, Cabecalho_bib* cab, int pos);

/**
 * @brief valorMin percorre a arvore e obtem o n� com menor valor dado um n�(raiz) como parametro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore
 * @param raiz n� da arvore onde inica a busca pelo menor valor
 * @return retorna a posi��o do menor valor
 */
int valorMin(FILE* arvore_bin, Arvore* raiz);

/**
 * @brief valorMax percorre a arvore e obtem o maior valor de acordo com um n� (raiz) passado como parametro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz raiz na qual sera inicalizado a busca
 * @return retorna a posi��o do maior valor encontrado (maior folha)
 */
int valorMax(FILE* arvore_bin, Arvore* raiz);


/**
 * @brief retira remove o valor passado codigo como chave, com ajuda de fun�oes auxiliares, se nao tiver filhos ela remove o n�,
 *  se tiver somente filho da direita ele procura o menor valor de seus filhos (o mais a esquerda) e "puxa" o valor para a nova posi��o
 * fazendo o ponteiro do pai do removido apontar para esse novo n� e os ponteiro apontados pelo removido para esse n� (exceto o que apontava pra ele
 * se tiver filho a esquerda a fun��o vai a esquerda ate o final e faz o mesmo processo
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param codigo codigo do livro que sera removido
 * @param raiz n� da arvore
 * @return retorna as novas posi��es
 */
int retira(FILE* arvore_bin, FILE* biblioteca_bin, int codigo, Arvore* raiz);

/**
 * @brief remover dado o codigo do livro a ser removido, com ajuda de fun��es auziliares, remove o n� mantendo a estrutura da arvore
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca dos livros
 */
void remover(FILE* arvore_bin, FILE* biblioteca_bin);

/**
 * @brief altura_arvore fun��o para obter a altura total da arvore, da raiz ao topo do maior lado, usada para auxiliar na impress�o por nivel
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz n� da arvore binaria
 * @return retorna a altura da arvore, no seu lado mais alto
 */
int altura_arvore( FILE* arvore_bin, Arvore* raiz);

/**
 * @brief imprimeNivel_aux auxilia na impressao da arvore binaria por niveis, fazendo a impresssao do codigo na tela
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz n� da arvore binaria
 * @param i variavel de controle usada para impressao de linha por linha
 */
void imprimeNivel_aux(FILE* arvore_bin, Arvore* raiz, int i);

/**
 * @brief imprimeNivel com ajuda de fun�oes auxiliares, faz a impressao dos codigos dos livros contido na arvore por niveis, utilizando sua altura
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 */
void imprimeNivel(FILE* arvore_bin);

Fila * start();

int filavazia(Fila *fila);

No *criarNo(void *dados);

Fila *limpar(Fila *fila);

int tamanhofila (Fila *fila);

void enqueue(Fila *fila, void *dados);

No *dequeue(Fila *fila);

void imprimirFila(Fila *fila);

void printaArvore (FILE *f);
#endif

#endif // ARVOREBMAIS_H
