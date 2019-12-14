#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
//#include<conio.h>
#include<math.h>
#include <string.h>
#include "arvorebmais.h"
#define MAX 100



/**
 * @brief lerNome lê o nome do arquivo passado como parametro
 * @param argv
 * @return
 */
char *lerNome(const char *argv[]){

	return ((char*)argv[0]);

}


/**
 * @brief escreveCabBib funcao que escreve o cabecalho do livro no arquivo binario
 * @param biblioteca_bin ponteiro para o arquivo binario
 * @param livro ponteiro para cabeçalho da biblioteca de livros
 */
void escreveCabBib(FILE* biblioteca_bin, Cabecalho_bib *livro){

	if(!livro)
		return;


	fseek(biblioteca_bin, 0, SEEK_SET);

	fwrite(livro, sizeof(Cabecalho_bib),1,biblioteca_bin);

}

/**
 * @brief criaCabBib cria o cabeçalho do livro no arquivo binario (biblioteca)
 * @param biblioteca_bin ponteiro para arquivo binario
 */
void criaCabBib(FILE* biblioteca_bin){

	Cabecalho_bib livro;

	livro.topo=0;
	livro.livre=-1;

	escreveCabBib(biblioteca_bin, &livro);
}

/**
 * @brief EscreveCabArv escreve o cabeçalho do no (raiz) no arquivo binario
 * @param arvore_bin ponteiro para o arquivo binario que contem a arvore binaria
 * @param arvore variavel do tipo cabeçalho, que contem o cabeçalho do arquivo binario
 */
void EscreveCabArv(FILE* arvore_bin, Cabecalho* arvore){

	if(!arvore)
		return;

	fseek(arvore_bin, 0, SEEK_SET);

	fwrite(arvore, sizeof(Cabecalho),1,arvore_bin);

}

/**
 * @brief criaCabArv cria o cabeçalho para o arquivo binario das arvores
 * @param arvore_bin ponteiro para o arquivo binario que contem a arvore binaria
 */
void criaCabArv(FILE* arvore_bin){

	Cabecalho arvore;

	arvore.raiz=-1;
	arvore.topo=0;
	arvore.livre=-1;

	EscreveCabArv(arvore_bin, &arvore);

}

/**
 * @brief obterLivros dado um arquivo binario que contem os livros e a posição desejada a função vai para a posição passada e le o que tem nela
 * @param biblioteca_bin ponteiro para arquivo binario que contem os livros
 * @param posicao posição de onde deseja fazer a leitura do arquivo binario
 * @return retorna uma estrutura tipo ponteiro para Livros que contem as informações lidas na posição
 */
Livros* obterLivros(FILE* biblioteca_bin, int posicao){

	Livros *aux;

	if(posicao==-1)
		return NULL;

	aux=(Livros*)malloc(sizeof(Livros));

	fseek(biblioteca_bin, sizeof(Cabecalho_bib)+sizeof(Livros)*posicao, SEEK_SET);

	fread(&aux->codigo, sizeof(int), 1, biblioteca_bin);
	fread(aux->titulo, sizeof(char)*MAX,1,biblioteca_bin);
	fread(aux->autor, sizeof(char)*MAX, 1, biblioteca_bin);
	fread(&aux->quant_exemp, sizeof(int),1,biblioteca_bin);

	return aux;
}

/**
 * @brief lerNos faz a leitura do no da arvore contido no ponteiro para arquivo binario passado como parametro e na posição também passada como paramtro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura de arvore
 * @param posicao posição na qual deseja ser o nó
 * @return retorna as informaçoes contidas no nó lido
 */
ArvoreBMAIS* lerNos(FILE* arvore_bin, int posicao){

	ArvoreBMAIS *aux;

	if(posicao==-1)
		return NULL;

	aux = (ArvoreBMAIS*)malloc(sizeof(ArvoreBMAIS));

	fseek(arvore_bin, sizeof(Cabecalho)+sizeof(ArvoreBMAIS)*posicao, SEEK_SET);

	fread(aux, sizeof(ArvoreBMAIS),1,arvore_bin);

	return aux;
}

/**
 * @brief lerCabLivro le o cabeçalho do livro contido no arquivo binario
 * @param biblioteca_bin ponteiro para arquivo binario que contem os livros
 * @return retorna as informaçoes contidas no cabeçalho do livro armazenado no arquivo binario, do tipo cabecalho_bib
 */
Cabecalho_bib* lerCabLivro(FILE* biblioteca_bin){

	Cabecalho_bib *aux=(Cabecalho_bib*)malloc(sizeof(Cabecalho_bib));

	fseek(biblioteca_bin, 0, SEEK_SET);

	fread(aux, sizeof(Cabecalho_bib),1,biblioteca_bin);

	return aux;
}


/**
 * @brief lerCabArv obtem as informações contidas no cabeçalho da arvore armazenada no arquivo binario
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore
 * @return retorna as informaçoes contidas no cabeçalho, do tipo estrutura Cabeçalho
 */
Cabecalho* lerCabArv(FILE* arvore_bin){

	Cabecalho *aux=(Cabecalho*)malloc(sizeof(Cabecalho));

	fseek(arvore_bin,0,SEEK_SET);

	fread(aux, sizeof(Cabecalho),1,arvore_bin);

	return aux;
}

/**
 * @brief inicializarBib aloca a memoria para contem livros e seta seus parametros como nulos
 * @return retorna a instancia de memoria alocada
 */
Livros* inicializarBib(){

	Livros* novo=(Livros*)malloc(sizeof(Livros));

	novo->codigo=0;
	novo->titulo[0]='\0';
	novo->autor[0]='\0';
	novo->quant_exemp=0;

	return novo;
}

/**
 * @brief inicializarArv aloca memoria para uma estrutura de arvore e seta seus dados como nulos e livres
 * @return retorna uma estrutra de arvore instanciada na memoria
 */
Arvore* inicializarArv() {

	Arvore* aux = (Arvore*)malloc(sizeof(Arvore));

	Dados registros;

	registros.codigo = 0;
	registros.posicao = -1;

	aux->registro = registros;
	aux->dir = -1;
	aux->esq = -1;
	aux->posicao = -1;

	return aux;
}

// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// --- A R V O R E   B+ ---------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------

ArvoreBMAIS *inicializarBmais() {

	ArvoreBMAIS *arvore = (ArvoreBMAIS*)malloc(sizeof(ArvoreBMAIS));

	Dados registros;

	registros.codigo  =  0;
	registros.posicao = -1;

	arvore->chave[0].codigo =  0;
	arvore->chave[0].posicao = -1;
	arvore->filho[0]  =  0;
	// arvore->pai[0]    =  0;
	arvore->eh_folha  = -1;
	arvore->numChaves =  0;

	return arvore;

}

void escreve_arvore_aux(FILE *arvorebin, ArvoreBMAIS *raiz, int pos){

	fseek(arvorebin, sizeof (Cabecalho) + sizeof (ArvoreBMAIS)*pos, SEEK_SET );

	fwrite(raiz, sizeof(ArvoreBMAIS), 1, arvorebin);
}

ArvoreBMAIS *Split(FILE *arvoreBin, ArvoreBMAIS *raiz, int *m, int pos){
	ArvoreBMAIS *y = (ArvoreBMAIS*)malloc(sizeof (ArvoreBMAIS));

	int k = 0, i;
	if(!raiz->eh_folha){
		y->eh_folha = 0;
		k = 1;
	}else{
		y->eh_folha = 1;
	}

	int q = raiz->numChaves/2;

	y->numChaves = raiz->numChaves - q - k;
	raiz->numChaves = q;

	*m = raiz->chave[q].codigo;
	y->filho[0] = raiz->filho[q+k];
	for (i = 0; i < y->numChaves; i++){
		y->chave[i] = raiz->chave[q+i+k];
		y->filho[i+1] = raiz->filho[q+i+1+k];
	}

	escreve_arvore_aux(arvoreBin, raiz, pos);

	return y;
}

void adiciona_direita(ArvoreBMAIS *raiz, int pos, int codigo, int pos_livro){
	int i;
	int k=1;
	if(raiz->eh_folha){
		k = 0;
	}

	for (i = raiz->numChaves; i < pos;i--) {
		raiz->chave[i] = raiz->chave[i-1];
		raiz->filho[i+k] = raiz->filho[i+k-1];
	}

	raiz->chave[pos].codigo = codigo;
	raiz->filho[pos+k] = pos_livro;
	raiz->numChaves++;
}

int overflow(ArvoreBMAIS *raiz){

	return (raiz->numChaves == 5); // NO LUGAR DE 5 COLOCAR ORDEM
}

int buscar_arvore_bmais(ArvoreBMAIS *raiz, int codigo, int *pos){
	for ((*pos) = 0; (*pos) < raiz->numChaves ; (*pos)++){
		if(codigo == raiz->filho[(*pos)]){
			return 1;
		}
		else if(codigo < raiz->chave[(*pos)].codigo){
			break;
		}
	}
	return 0;
}

void insere_aux(FILE *arvoreBin, int pos_livro, int codigo, int pos_raiz){
	int pos;

	ArvoreBMAIS *raiz = lerNos(arvoreBin, pos_raiz);

	if(!buscar_arvore_bmais(raiz, codigo, &pos)){
		if(raiz->eh_folha){
			adiciona_direita(raiz, pos, codigo, pos_livro);
			escreve_arvore_aux(arvoreBin, raiz, pos_raiz);
		}else{
			insere_aux(arvoreBin, pos_livro, codigo, raiz->filho[pos]);
			ArvoreBMAIS *filho = lerNos(arvoreBin, raiz->filho[pos]);

			if(overflow(filho)){
				int m;
				Cabecalho *cab = lerCabArv(arvoreBin);
				ArvoreBMAIS *aux = Split(arvoreBin, filho, &m, raiz->filho[pos]);
				int nova_pos = escreveArv(arvoreBin, aux, cab);
				if(filho->eh_folha){
					aux->filho[ORDEM] = filho->filho[ORDEM];
					filho->filho[ORDEM] = nova_pos;
				}
				adiciona_direita(raiz, pos, m, nova_pos);

				escreve_arvore_aux(arvoreBin, aux, nova_pos);
				escreve_arvore_aux(arvoreBin, filho, raiz->filho[pos]);
				escreve_arvore_aux(arvoreBin, raiz, pos_raiz);
				free(aux);
			}
		}
	}
}

void insereBMais (FILE *arvoreBin, int codigo, int pos_livro, Cabecalho *cab){

	ArvoreBMAIS *raiz = lerNos(arvoreBin, cab->raiz);

	if(!raiz){
		raiz = inicializarBmais();
		raiz->chave[0].codigo = codigo;
		raiz->filho[0] = pos_livro;
		raiz->filho[ORDEM] = -1;
		raiz->numChaves = 1;
		cab->raiz = escreveArv(arvoreBin, raiz, cab);
		EscreveCabArv(arvoreBin, cab);
		free(raiz);
		free(cab);
		return;
	}

	insere_aux(arvoreBin, pos_livro, codigo, cab->raiz);
	cab = lerCabArv(arvoreBin);

	raiz = lerNos(arvoreBin, cab->raiz);

	if(overflow(raiz)){
		int m;
		ArvoreBMAIS *aux = Split(arvoreBin, raiz, &m, cab->raiz);
		int nova_pos = escreveArv(arvoreBin, aux, cab);

		if(raiz->eh_folha){
			aux->filho[ORDEM] = raiz->filho[ORDEM];
			raiz->filho[ORDEM] = nova_pos;
		}

		ArvoreBMAIS *novaraiz = inicializarBmais();
		novaraiz->chave[0].codigo = m;
		novaraiz->filho[0] = cab->raiz;
		novaraiz->filho[1] = nova_pos;
		novaraiz->numChaves = 1;
		novaraiz->eh_folha = 0;

		escreve_arvore_aux(arvoreBin, aux, nova_pos);
		escreve_arvore_aux(arvoreBin, raiz, cab->raiz);

		cab->raiz = escreveArv(arvoreBin, novaraiz, cab);
		EscreveCabArv(arvoreBin, cab);

		free(aux);
		free(novaraiz);
	}

	free(raiz);
}

void leituraConsole(FILE *arquivo, FILE *dados){

	Livros *livro = inicializarBib();

	printf("Codigo: ");
	scanf("%d", &livro->codigo );

	printf("Nome do Livro: ");
	scanf(" %[^\n]%*c", livro->titulo);

	printf("Nome do Autor: ");
	scanf(" %[^\n]%*c", livro->autor);

	printf("Quantidade de Exemplares: ");
	scanf("%d", &livro->quant_exemp);

	if (livro->codigo == -1 || !livro->titulo[0] || !livro->autor[0] || livro->quant_exemp == -1){

		printf("Cadastro Invalido!\n");
	}else{
		Cabecalho_bib *indice = lerCabLivro(dados);
		Cabecalho *arq = lerCabArv(arquivo);
		int pos = escreveBib(dados, indice, livro);

		insereBMais(arquivo, livro->codigo, pos, arq);
		free(indice);
		escreveCabBib(dados, indice);

	}
}

void liberaNoh (ArvoreBMAIS *node){
	if(node)
		free(node);
}



Fila * start()
{
	Fila *aux = (Fila*)malloc(sizeof (Fila));

	aux->final = NULL;
	aux->inicio = NULL;
	aux->n = 0;

	return aux;
}

int filavazia(Fila *fila){

	return (fila->inicio) ? 0:1;
}

No *criarNo(void *dados){

	No *aux = (No*)malloc(sizeof(No));

	aux->info = dados;
	aux->prox = NULL;
	aux->ant = NULL;

	return aux;
}

Fila *limpar(Fila *fila){

	if(!filavazia(fila)){
		No *aux;
		while(fila->inicio)
		{
			aux = fila->inicio;
			fila->inicio = fila->inicio->prox;
			free(aux);
		}
		free(fila);
	}
}

int tamanhofila (Fila *fila);

void enqueue(Fila *fila, void *dados){

	if(!fila) return;

	No* auxf = criarNo(dados);

	if(!fila->inicio) {
		fila->inicio = fila->final = auxf;
	} else {
		fila->final->prox = auxf;
		fila->final = auxf;
	}

	fila->n++;
}

No *dequeue(Fila *fila){

	if(filavazia(fila)) return NULL;
	if(fila->inicio == NULL) return NULL;

	No *aux = fila->inicio;
	fila->inicio = aux->prox;

	if(!fila->inicio){
		fila->final = NULL;
	}

	fila->n--;

	return aux;
}

void imprimirFila(Fila *fila){

	if(filavazia(fila)) return;

	struct no *aux = fila->inicio;

	while(aux){
		printf("[%d]->", aux->info);
		aux = aux->prox;
	}
	printf("NULL\n");
}

// AQUI
void printaNoArvoreBmais(ArvoreBMAIS *node);

void printaArvore (FILE *f){

    /// lê cabeçalho e raiz da árvore
    Cabecalho *header = lerCabArv(f);
    ArvoreBMAIS *root = lerNos(f, header->raiz);
    /// cria fila
    Fila *q = start();
    int nodeCount;

    /// coloca raiz na fila
    enqueue(q, root);

    /// enquanto não se acabarem os nós
    nodeCount = q->n;
    while (nodeCount) {
        /// printa os nós do nível atual na saida padrão
        while (nodeCount) {
            No *qNode = dequeue(q);
            ArvoreBMAIS *bTreeNode = (ArvoreBMAIS *) qNode->info;

            printaNoArvoreBmais(bTreeNode);
            printf(" ");

            /// puxa os seus filhos para a fila
            for (int i = 0; i <= bTreeNode->numChaves; ++i) {
                if (bTreeNode->filho[i] != -1)
                    enqueue(q, lerNos(f, bTreeNode->filho[i]));
            }
            nodeCount--;

            free(qNode);
            liberaNoh(bTreeNode);
        }
        printf("\n");
        nodeCount = q->n;
    }

    liberaNoh(root);
    limpar(q);
}

void printaNoArvoreBmais(ArvoreBMAIS *node) {
	printf("[");
	if (node->numChaves) {
		for (int i = 0; i < node->numChaves - 1; ++i) {
			printf("%d,", node->chave[i].codigo);
		}
		printf("%d", node->chave[node->numChaves - 1]);
	} else {
		printf("!");
	}
	printf("]");
}

void imprimeInOrd(FILE *registros, Cabecalho *indice, FILE *dados, Cabecalho_bib *raizDat, ArvoreBMAIS *raiz){

	ArvoreBMAIS *aux = NULL;
	Livros *livro = (Livros*)malloc(sizeof (Livros));

	if(!raiz){
		return;
	}

	for(int i = 0; i < raiz->numChaves; ++i){
		imprimeInOrd(registros, indice, dados, raizDat, aux = lerNos(registros, raiz->filho[i]));

		livro = obterLivros(dados, raiz->posicao); // AQUI raiz->chave[i].registroPos
		imprimir_livro(livro);

		printf("\n");

		liberaNoh(aux);
		free(livro);
	}

	imprimeInOrd(registros, indice, dados, raizDat, aux = lerNos(registros, raiz->filho[raiz->numChaves]));
	liberaNoh(aux);
}

void imprimeRegistro(FILE *registro, FILE *dados){

	system("clear");
	Cabecalho *indice = lerCabArv(registro);
	Cabecalho_bib *raizDat = lerCabLivro(dados);

	ArvoreBMAIS *raiz = lerNos(registro, indice->topo);

	if(raiz){
		imprimeInOrd(registro, indice, dados, raizDat, raiz);
	}

	free(indice);
	free(dados);
}
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------
/**
 * @brief obterNoLivre obtem o no da posição passada como parametro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param posicao posição passada como parametro para verificar se o no esta livre
 * @return retorna o endereço do nó livre
 */
NoLivre* obterNoLivre(FILE* arvore_bin, int posicao){

	if(posicao==-1)
		return NULL;

	NoLivre* aux=(NoLivre*)malloc(sizeof(NoLivre));

	fseek(arvore_bin,sizeof(Cabecalho)+sizeof(ArvoreBMAIS)*posicao,SEEK_SET);

	fread(aux, sizeof(NoLivre),1,arvore_bin);

	return aux;
}

/**
 * @brief obterLivroLivre dada uma posição como parametro obtem o livro contido nela
 * @param biblioteca_bin ponteiro para arquivo que contem os livros
 * @param posicao posição do livro
 * @return retorna o livro
 */
LivroLivre* obterLivroLivre(FILE* biblioteca_bin, int posicao){

	if(posicao==-1)
		return NULL;

	LivroLivre *aux=(LivroLivre*)malloc(sizeof(LivroLivre));
	fseek(biblioteca_bin, sizeof(Cabecalho_bib)+sizeof(Livros)*posicao, SEEK_SET);

	fread(aux, sizeof(LivroLivre),1,biblioteca_bin);

	return aux;
}

/**
 * @brief escreveBib escreve o livro no arquivo binario da biblioteca
 * @param biblioteca_bin ponteiro para arquivo binario que contem os livros
 * @param cabBib cabeçalho do arquivo que contem os livros
 * @param livro parametro onde vai ser escrito o livro
 * @return retorna a posição onde livro foi inserido
 */
int escreveBib(FILE* biblioteca_bin, Cabecalho_bib* cabBib, Livros *livro){

	if(!cabBib)
		return -1;

	int posicao=cabBib->livre;

	if(posicao==-1)
		posicao=cabBib->topo++;

	else{

		LivroLivre *novo=obterLivroLivre(biblioteca_bin, posicao);
		cabBib->livre = novo->prox;
		free(novo);

	}

	fseek(biblioteca_bin, sizeof(Cabecalho_bib)+sizeof(Livros)*posicao, SEEK_SET);

	fwrite(&livro->codigo, sizeof(int),1,biblioteca_bin);
	fwrite(livro->titulo, sizeof(char),MAX, biblioteca_bin);
	fwrite(livro->autor, sizeof(char), MAX, biblioteca_bin);
	fwrite(&livro->quant_exemp, sizeof(int),1,biblioteca_bin);

	return posicao;
}

/**
 * @brief escreveArv escreve o no da estrutura de arvore binaria o arquivo binario que à contem
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutra da arvore
 * @param no nó da estrutura da arvore passada
 * @param arvore cabeçalho do arquivo contendo a arvore
 * @return retorna a posição onde nó foi inserido no arquivo
 */
 int escreveArv(FILE* arvore_bin, ArvoreBMAIS* no, Cabecalho *arvore){

    if(!arvore || !no)
        return -1;

    int posicao;

    if(arvore->livre == -1) {
        posicao=arvore->topo++;
    } else {
        posicao = arvore->livre;
        NoLivre *livre = obterNoLivre(arvore_bin, posicao);
        arvore->livre = livre->prox;
        free(livre);
    }
    
    EscreveCabArv(arvore_bin, arvore);
    escreve_arvore_aux(arvore_bin, no, posicao);
    
    return posicao;
}

/**
 * @brief lerArquivo faz a leitura do arquivo inializado no programa
 * @param biblioteca_bin ponteiro para arquivo binario que contem a bliblioteca de livros
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutra para arvore binaria
 * @param linha_arq linha lida do arquivo de inicialização
 */
void lerArquivo( FILE* biblioteca_bin, FILE* arvore_bin, char *linha_arq){

	int i=0, tm;
	Cabecalho *cab = lerCabArv(arvore_bin);

	Cabecalho_bib *cabLivro = lerCabLivro(biblioteca_bin);
	Livros *livro = inicializarBib();

	sscanf(linha_arq, "%d;%n", &livro->codigo, &tm);
	i+=tm;

	sscanf(linha_arq +i, "%[^;];%n", livro->titulo, &tm);
	i+=tm;

	sscanf(linha_arq+i, "%[^;];%n", livro->autor, &tm);
	i+=tm;

	sscanf(linha_arq+i, "%d", &livro->quant_exemp);

	int posicao = escreveBib(biblioteca_bin, cabLivro, livro);

	insereBMais(arvore_bin, livro->codigo, posicao, cab);

	escreveCabBib(biblioteca_bin, cabLivro);

	free(livro);
}

/**
 * @brief imprimeArq imprime os dados dos livros
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 */
void imprimeArq(FILE* biblioteca_bin){

	Livros *l;

	Cabecalho_bib *cabecalho = lerCabLivro(biblioteca_bin);
	printf("Numero de livros armazenados: %d\n", cabecalho->topo);

	for(int i=0; i < cabecalho->topo; i++){

		printf("\n");

		l= obterLivros(biblioteca_bin, i);
		printf("codigo: %d\n",l->codigo);
		printf("titulo: %s\n",l->titulo);
		printf("autor: %s\n", l->autor);
		printf("quantidade de exemplares: %d\n",l->quant_exemp);

	}

}

/**
 * @brief imprimir_livro imprime informações do livro na console
 * @param livro parametro que contem as informaçoes dos livros
 */
void imprimir_livro(Livros* livro){


	printf("-----------------------------------------------\n");
	printf("codigo do livro: %d\n", livro->codigo);
	printf("titulo do livro: %s\n", livro->titulo);
	printf("autor do livro: %s\n",livro->autor);
	printf("quantidade de exemplares: %d\n",livro->quant_exemp);
	printf("-----------------------------------------------\n");

}

/**
 * @brief insere insere no arquivo binario da estrutura da arvore um nó contendo todas informaçoes do livro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore
 * @param codigo codigo do livro a ser inserido
 * @param posicao posição do livro no arquivo binario da biblioteca
 */
//void insere(FILE* arvore_bin, int codigo, int posicao){

//    Dados info;

//    info.codigo=codigo;
//    info.posicao=posicao;

//    Cabecalho *aux=lerCabArv(arvore_bin);

//    Arvore *raiz=lerNos(arvore_bin, aux->raiz);

//    if(!raiz){

//        raiz= inicializarArv();
//        raiz->registro=info;
//        aux->raiz=escreveArv(arvore_bin, raiz, aux);

//    }
//    else{

//        Arvore *novo, *noPai;

//        novo=inicializarArv();
//        novo->registro=info;


//        while(raiz !=NULL){

//            noPai= lerNos(arvore_bin, raiz->posicao);

//            if(raiz->registro.codigo < novo->registro.codigo)

//                raiz= lerNos(arvore_bin, raiz->dir);

//            else if(raiz->registro.codigo > novo->registro.codigo)

//                raiz= lerNos(arvore_bin, raiz->esq);

//            else if(raiz->registro.codigo == novo->registro.codigo)
//                break;
//        }

//        if(raiz==NULL){

//            int no_posicao=escreveArv(arvore_bin, novo, aux);

//            if(noPai->registro.codigo > novo->registro.codigo)

//                noPai->esq = no_posicao;

//            else
//                noPai->dir = no_posicao;

//            escreveArv(arvore_bin, noPai, aux);

//        }
//    }

//    EscreveCabArv(arvore_bin, aux);

//    free(aux);
//}



/**
 * @brief imprime_no imprime na console a estrutura arvore
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz no da arvore que será impresso
 */
//void imprime_no(FILE* arvore_bin, Arvore* raiz){


//    if(raiz==NULL)
//        printf("[]");

//    else{

//        printf("[%d, ",raiz->registro.codigo);

//        imprime_no(arvore_bin, lerNos(arvore_bin, raiz->esq));
//        printf(",");

//        imprime_no(arvore_bin, lerNos(arvore_bin, raiz->dir));
//        printf("]");
//    }
//}

/**
 * @brief imprimeArv obtem o cabeçalho da arvore e com a ajuda de uma função auxiliar imprime a estrutura da arvore binaria
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 */
//void imprimeArv(FILE* arvore_bin){

//    Cabecalho* cab= lerCabArv(arvore_bin);
//    Arvore* raiz= lerNos(arvore_bin, cab->raiz);

//    imprime_no(arvore_bin, raiz);

//}



/**
 * @brief imprimeInOrdem imprime a arvore inordem na console, do menor para o maior, usando seu codigo como requisito
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param raiz no que contem as informações dos livros
 * @param livro estrutura dos livro, que contem suas informações
 */
//void imprimeInOrdem( FILE* arvore_bin, FILE* biblioteca_bin, Arvore* raiz, Livros* livro){

//    if(raiz !=NULL){

//        imprimeInOrdem(arvore_bin, biblioteca_bin, lerNos(arvore_bin, raiz->esq), livro);

//        livro=obterLivros(biblioteca_bin, raiz->registro.posicao);

//        imprimir_livro(livro);

//        imprimeInOrdem(arvore_bin, biblioteca_bin, lerNos(arvore_bin, raiz->dir), livro);
//    }

//}

/**
 * @brief imprime_acervo imprime o acervo de livros armazenados no arquivo binario da biblioteca
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 */
//void imprime_acervo(FILE* arvore_bin, FILE* biblioteca_bin){

//    Cabecalho* cabe= lerCabArv(arvore_bin);

//    Arvore* raiz= lerNos(arvore_bin, cabe->raiz);
//    Livros* livro;




//    imprimeInOrdem(arvore_bin, biblioteca_bin, raiz,  livro);

//}

/**
 * @brief escanear le uma informação do teclado, via console
 * @return retorna a informação obtida na console
 */
//int escanear(){

//    int x;
//    printf("digite o codigo do livro: ");
//    scanf("%d", &x);
//    printf("\n");

//    return x;
//}

/**
 * @brief buscar função para fazer a busca de determinada chave dada como parametro, fazendo a busca nos nós da arvore, recursivamente
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param r parametro do tipo Arvore que contem as raizes dos nos
 * @param x chave buscada
 * @return
 */
//Arvore* buscar(FILE* arvore_bin, Arvore* r, int x){


//    if(r==NULL)
//        return NULL;

//    if(r->registro.codigo > x)
//        return buscar(arvore_bin, lerNos(arvore_bin, r->esq), x);

//    if(r->registro.codigo < x)
//        return buscar(arvore_bin, lerNos(arvore_bin, r->dir), x);

//    return r;

//}

/**
 * @brief buscar_livro função para buscar livro de acordo com seu código pre inserido e imprime livro, se encontrado
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param procurado codigo do livro usado como chave para busca
 */
//void buscar_livro(FILE* arvore_bin, FILE* biblioteca_bin, int procurado){


//    Arvore* temp;

//    Cabecalho* cab= lerCabArv(arvore_bin);
//    Arvore* raiz= lerNos(arvore_bin, cab->topo);




//    temp=buscar(arvore_bin, raiz, procurado);

//    if(temp == NULL)
//        printf("livro nao encontrado\n");

//    else{

//        Livros *l;

//        l=obterLivros(biblioteca_bin, temp->registro.posicao);
//        imprimir_livro(l);

//    }
//    free(temp);
//}

/**
 * @brief atualizaQuant função que encontra chave pre inserida e edita a informação de quantidade de exemplares no livro que contem tal chave
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutra da arvore binaria
 * @param posicao posição na qual o usuario deseja atualizar numero de exemplares
 * @param nova_quant parametro que armazena a nova quantidade de exemplares do livro
 */
//void atualizaQuant(FILE* biblioteca_bin, FILE* arvore_bin, int posicao){


//    int nova_quant;

//    printf("digite a nova quantidade: ");
//    scanf("%d",&nova_quant);
//    printf("\n");


//    Arvore* temp=(Arvore*)malloc(sizeof(Arvore));

//        Cabecalho* cab= lerCabArv(arvore_bin);
//        Arvore* raiz= lerNos(arvore_bin, cab->topo);

//        temp=buscar(arvore_bin, raiz, posicao);

//        if(temp==NULL)
//            printf("nao encontrado\n");

//        else{

//            Livros* l= obterLivros(biblioteca_bin, temp->registro.posicao);

//            fseek(biblioteca_bin, sizeof(Cabecalho_bib)+sizeof(Livros)*temp->registro.posicao, SEEK_SET);

//            l->quant_exemp=nova_quant;

//        fwrite(&l->codigo, sizeof(int),1,biblioteca_bin);
//        fwrite(l->titulo, sizeof(char),MAX, biblioteca_bin);
//        fwrite(l->autor, sizeof(char), MAX, biblioteca_bin);
//        fwrite(&l->quant_exemp, sizeof(int),1,biblioteca_bin);

//        }

//free(temp);
//}


/**
 * @brief divide auxilia na ordenação dos livros, com o metodo de divisão e conquista, faz a troca do elemento caso seja menor
 * @param vetor vetor de variaveis do tipo Livros que guarda um no (folha)
 * @param e lado esquerdo do vetor, inicializado como zero
 * @param d lado direito do vetor, a ultima posiçao dele ou no caso a ultima posição da arvore
 * @return  retorna o vetor divido para ordenação, com suas posições corrigidas,
 */
//int divide(Livros* vetor[], int e, int d){

//    int j=e, k;

//    Livros *pivo;
//    Livros *aux;

//    pivo=vetor[d];

//    for(k=e; k<d; k++){

//        vetor[k]->titulo[0]= toupper(vetor[k]->titulo[0]);
//        pivo->titulo[0]= toupper(pivo->titulo[0]);


//            if(strcmp(vetor[k]->titulo, pivo->titulo)< 0){

//                aux= vetor[j];
//                vetor[j]=vetor[k];
//                vetor[k]=aux;

//                j++;
//            }
//    }

//    vetor[d]=vetor[j];
//    vetor[j]=pivo;

//    return j;

//}

/**
 * @brief Quicksort metodo de ordenação de vetor de divisão e conquista, divide o vetor em duas partes e vai ordenando-as
 * @param vetor variavel do tipo Livro que contem a folha dele
 * @param e lado esquerdo do vetor, inicializado em 0
 * @param d lado direito do vetor, inicializado com o tamanho total dele
 */
//void Quicksort(Livros* vetor[], int e, int d){

//    int j;

//    if(e<d){
//        j=divide(vetor,e,d );
//        Quicksort(vetor, e, j-1);
//        Quicksort(vetor, j+1, d);
//    }
//}

/**
 * @brief tamanhovet função para obter o tamanho total do vetor, de acordo com o tamanho da biblioteca, da arvore e seus nos
 * @param vetor variavel do tipo livro que contem informações dos livros, para ordenação
 * @param t variavel usada para armazenar o tamanho que o vetor deve conter
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param raiz no que contem as informaçoes dos livros
 * @return retorna o tamanho total do vetor
 */
//int tamanhovet(Livros* vetor[], int t, FILE* arvore_bin, FILE* biblioteca_bin, Arvore* raiz){


//    if(raiz!=NULL){

//        int posicao;

//        vetor[t]=obterLivros(biblioteca_bin, raiz->registro.posicao);

//        if(raiz->esq!=-1)
//            posicao=tamanhovet(vetor, t+1, arvore_bin, biblioteca_bin, lerNos(arvore_bin, raiz->esq));
//        else
//             posicao=t;

//        if(raiz->dir!=-1)
//            posicao=tamanhovet(vetor, posicao+1, arvore_bin, biblioteca_bin, lerNos(arvore_bin, raiz->dir));

//        return posicao;
//    }

//    return t;
//}

/**
 * @brief gerarListagem escreve arquivo texto que contem as informações dos livros de forma ordenada
 * @param vet vetor ordenado de livros
 * @param tam tamanho total do vetor
 */
//void gerarListagem(Livros* vet[], int tam ){

//    FILE* lista;

//    lista=fopen("Biblioteca.txt", "w");


//    for(int i=0; i<tam; i++){

//        fprintf(lista,"%d; ",vet[i]->codigo);
//        fprintf(lista,"%s; ",vet[i]->titulo);
//        fprintf(lista,"%s; ",vet[i]->autor);
//        fprintf(lista,"%d\n ",vet[i]->quant_exemp);

//    }

//    fclose(lista);
//}

/**
 * @brief gerarOrdenacao faz a ordenação do vetor que contem as informações dos livros
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 */
//void gerarOrdenacao(FILE* biblioteca_bin, FILE* arvore_bin){

//    Cabecalho* cab=lerCabArv(arvore_bin);

//    Arvore* raiz=(Arvore*)malloc(sizeof(Arvore));

//    Cabecalho_bib*  l=lerCabLivro(biblioteca_bin);

//    Livros* vetor[l->topo];

//    raiz=lerNos(arvore_bin, cab->raiz);

//    int posicao=tamanhovet(vetor, 0, arvore_bin, biblioteca_bin, raiz);

//    Quicksort(vetor, 0, posicao);

//    gerarListagem(vetor, posicao);

//}

/**
 * @brief criaNoL cria um nó livre
 * @return retorna o endereço desse novo nó livre
 */
NoLivre* criaNoL(){

	NoLivre* novo=(NoLivre*)malloc(sizeof(NoLivre));

	novo->prox =-1;

	return novo;

}

/**
 * @brief escreveNoL escreve informaçoes em um nó livre
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param cab cabeçalho da arvore binaria contida no arquivo binario
 * @param arvore variavel do tipo estrutra de arvore para obter as posições dos nos
 */
//void escreveNoL(FILE* arvore_bin, Cabecalho* cab, ArvoreBMAIS* arvore){

//    if(!cab || arvore->posicao ==-1)
//        return;

//    int posicao = arvore->posicao;
//    NoLivre* novo = criaNoL();

//    novo->prox = cab->livre;
//    cab->topo--;
//    cab->livre = posicao;

//    fseek(arvore_bin, sizeof(Cabecalho)+sizeof(ArvoreBMAIS)*posicao, SEEK_SET);
//    fwrite(novo, sizeof(NoLivre),1,arvore_bin);

//    free(novo);

//}

/**
 * @brief criaLL instancia memoria para um livro
 * @return retorna o endereço para armazenar informaçoes do tipo estrutura para livros
 */
//LivroLivre* criaLL(){

//    LivroLivre* novo=(LivroLivre*)malloc(sizeof(LivroLivre));
//    novo->prox=-1;

//    return novo;

//}

/**
 * @brief escreveLL escreve informações de livros na posição do livro desejada
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param cab cabeçalho da arvore binaria contida no arquivo binario
 * @param pos posição na qual deseja escrever o novo no
 */
//void escreveLL(FILE* arvore_bin, Cabecalho_bib* cab, int pos){

//    if(!cab || pos ==-1)
//        return;

//    int posicao=pos;
//    LivroLivre *novo = criaLL();

//    novo->prox = cab->livre;
//    cab->topo--;
//    cab->livre=posicao;

//    fseek(arvore_bin, sizeof(Cabecalho_bib)+sizeof(Livros)*posicao, SEEK_SET);
//    fwrite(novo, sizeof(LivroLivre),1,arvore_bin);

//    free(novo);

//}

/**
 * @brief valorMin percorre a arvore e obtem o nó com menor valor dado um nó(raiz) como parametro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore
 * @param raiz nó da arvore onde inica a busca pelo menor valor
 * @return retorna a posição do menor valor
 */
//int valorMin(FILE* arvore_bin, Arvore* raiz){

//    while(raiz !=NULL && raiz->esq != -1)
//        raiz = lerNos(arvore_bin, raiz->esq);

//    return raiz->posicao;

//}

/**
 * @brief valorMax percorre a arvore e obtem o maior valor de acordo com um nó (raiz) passado como parametro
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz raiz na qual sera inicalizado a busca
 * @return retorna a posição do maior valor encontrado (maior folha)
 */
//int valorMax(FILE* arvore_bin, Arvore* raiz){

//    while(raiz !=NULL && raiz->dir !=-1 )
//        raiz = lerNos(arvore_bin, raiz->dir);

//    return raiz->posicao;
//}


/**
 * @brief retira remove o valor passado codigo como chave, com ajuda de funçoes auxiliares, se nao tiver filhos ela remove o nó,
 *  se tiver somente filho da direita ele procura o menor valor de seus filhos (o mais a esquerda) e "puxa" o valor para a nova posição
 * fazendo o ponteiro do pai do removido apontar para esse novo nó e os ponteiro apontados pelo removido para esse nó (exceto o que apontava pra ele
 * se tiver filho a esquerda a função vai a esquerda ate o final e faz o mesmo processo
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca de livros
 * @param codigo codigo do livro que sera removido
 * @param raiz nó da arvore
 * @return retorna as novas posições
 */
//int retira(FILE* arvore_bin, FILE* biblioteca_bin, int codigo, Arvore* raiz){

//    if(codigo <= 0)
//        return -1;


//    if(raiz==NULL){

//        printf("Codigo nao encontrado\n");
//        return -1;
//    }

//    Cabecalho* cab =lerCabArv(arvore_bin);
//    Cabecalho_bib* cab_l = lerCabLivro(biblioteca_bin);

//    if(raiz->registro.codigo >codigo){

//        raiz->esq = retira(arvore_bin, biblioteca_bin, codigo, lerNos(arvore_bin, raiz->esq));
//        escreveArv(arvore_bin, raiz, cab);
//    }
//    else if(raiz->registro.codigo < codigo){

//        raiz->dir = retira(arvore_bin, biblioteca_bin, codigo, lerNos(arvore_bin, raiz->dir));
//        escreveArv(arvore_bin, raiz, cab);
//    }
//    else{

//        escreveLL(biblioteca_bin, cab_l, raiz->registro.posicao);

//        if(raiz->esq == -1 && raiz->dir ==-1){

//            escreveNoL(arvore_bin, cab, raiz);

//            escreveCabBib(biblioteca_bin, cab_l);
//            EscreveCabArv(arvore_bin, cab);

//            return -1;
//        }
//        else if(raiz->esq ==-1){

//            Arvore* minimo = lerNos(arvore_bin, valorMin(arvore_bin, lerNos(arvore_bin, raiz->dir)));

//            int ant_pos_livro = minimo->registro.posicao;

//            minimo->registro.posicao =-1;

//            escreveArv(arvore_bin, minimo, cab);
//            retira(arvore_bin, biblioteca_bin, minimo->registro.codigo, lerNos(arvore_bin, raiz->dir));

//            if(raiz->dir != minimo->posicao)
//                minimo->dir = raiz->dir;

//            if(cab->raiz == raiz->posicao)
//                cab->raiz = minimo->posicao;

//            minimo->registro.posicao = ant_pos_livro;

//            escreveArv(arvore_bin, minimo, cab);

//            escreveCabBib(biblioteca_bin, cab_l);
//            EscreveCabArv(arvore_bin, cab);

//            return minimo->posicao;
//        }
//        else{

//            Arvore *maximo= lerNos(arvore_bin, valorMax(arvore_bin, lerNos(arvore_bin, raiz->esq)));

//            int ant_pos_livro = maximo->registro.posicao;

//            maximo->registro.posicao =-1;

//            escreveArv(arvore_bin, maximo, cab);
//            retira(arvore_bin, biblioteca_bin, maximo->registro.codigo, lerNos(arvore_bin, raiz->esq));

//            if(raiz->esq != maximo->posicao)
//                maximo->esq = raiz->esq;

//            if(cab->raiz == raiz->posicao)
//                cab->raiz = maximo->posicao;

//            maximo->dir = raiz->dir;

//            maximo->registro.posicao = ant_pos_livro;

//            escreveArv(arvore_bin, maximo, cab);

//            escreveCabBib(biblioteca_bin, cab_l);
//            EscreveCabArv(arvore_bin, cab);

//            return maximo->posicao;

//        }

//    }

//}

/**
 * @brief remover dado o codigo do livro a ser removido, com ajuda de funções auziliares, remove o nó mantendo a estrutura da arvore
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param biblioteca_bin ponteiro para arquivo binario que contem a biblioteca dos livros
 */
//void remover(FILE* arvore_bin, FILE* biblioteca_bin){

//    int cod;

//        printf("digite o codigo do livro: ");
//        scanf("%d", &cod);
//        printf("\n");

//    Cabecalho* cab = lerCabArv(arvore_bin);
//    Cabecalho_bib* cab_l = lerCabLivro(biblioteca_bin);

//    Arvore* raiz = lerNos(arvore_bin, cab->raiz);

//    if(cod > 0){

//        retira(arvore_bin, biblioteca_bin, cod, raiz);
//    }

//}

/**
 * @brief altura_arvore função para obter a altura total da arvore, da raiz ao topo do maior lado, usada para auxiliar na impressão por nivel
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz nó da arvore binaria
 * @return retorna a altura da arvore, no seu lado mais alto
 */
//int altura_arvore( FILE* arvore_bin, Arvore* raiz){

//    if(raiz==NULL)
//        return 0;

//    int alturaEsq= altura_arvore(arvore_bin, lerNos(arvore_bin, raiz->esq));
//    int alturaDir= altura_arvore(arvore_bin, lerNos(arvore_bin, raiz->dir));

//    return ((alturaEsq > alturaDir)? alturaEsq+1: alturaDir+1);
//}

/**
 * @brief imprimeNivel_aux auxilia na impressao da arvore binaria por niveis, fazendo a impresssao do codigo na tela
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 * @param raiz nó da arvore binaria
 * @param i variavel de controle usada para impressao de linha por linha
 */
//void imprimeNivel_aux(FILE* arvore_bin, Arvore* raiz, int i){

//    if(raiz == NULL)
//        return;

//    if(i==0)
//        printf(" %d ",  raiz->registro.codigo);

//    else if(i>=1){

//        imprimeNivel_aux(arvore_bin, lerNos(arvore_bin, raiz->esq) , i-1);
//        imprimeNivel_aux(arvore_bin, lerNos(arvore_bin, raiz->dir), i-1);
//    }
//}

/**
 * @brief imprimeNivel com ajuda de funçoes auxiliares, faz a impressao dos codigos dos livros contido na arvore por niveis, utilizando sua altura
 * @param arvore_bin ponteiro para arquivo binario que contem a estrutura da arvore binaria
 */
//void imprimeNivel(FILE* arvore_bin){


//    Cabecalho* aux= lerCabArv(arvore_bin);
//    Arvore* raiz = lerNos(arvore_bin, aux->raiz);

//    int h=altura_arvore(arvore_bin, raiz);


//    for(int i=0; i<h ; i++){

//        imprimeNivel_aux(arvore_bin, raiz, i);
//        printf("\n");
//    }
//}
