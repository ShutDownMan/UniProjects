#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[]) {
    /// conjunto de dominós de entrada
    List *inputSet = createList();
    /// conjunto de dominós resposta
    List *gameSet = createList();
    /// variáveis de iterador e quantidade de dominós a serem lida
    int i, setQnt;
    /// variável ponteiro para arquivo de entrada e saída
    FILE *inF, *outF;

    /// se argumentos de entrada tem tamanho 2
    if(argc == 3) {
        /// se conseguiu abrir arquivo de entrada e saida
        if((inF = fopen(argv[1], "r+")) && (outF = fopen(argv[2], "w+"))) {
            /// lê do arquivo de entrada a quantidade de dominóes no conjunto
            fscanf(inF, "%d", &setQnt);
            /// para i começando em zero, até quantidade de dominós no conjuunto ser zero
            for(i = 0; setQnt; ++i) {
                /// lê do arquivo de entrada o conjunto de dominós de entrada
                readInputSet(inF, inputSet, setQnt);

                /// printa no arquivo de saida o conjunto de dominós de entrada
                printSet(outF, inputSet);

                fprintf(outF, "Teste %d\n", i+1);
                /// se jogo é possível
                if(isPossibleGame(inputSet, gameSet)) {
                    /// printa sim, e o conjunto resposta
                    fprintf(outF, "sim\n");
                    printSet(outF, gameSet);

                    /// libera memória utilizada pelo conjunto resposta
                    freeList(gameSet);
                } else { //< se jogo não é possível
                    /// printa 'não' na saida padão
                    fprintf(outF, "nao\n");
                }

                /// libera memória dos dominós e dos nós utilizados
                freeListInfo(inputSet);

                /// separador de testes
                fscanf(inF, "%d", &setQnt);
            }
        } else {
            printf("Erro na abertura dos arquivos (%s | %s)!\n", argv[1], argv[2]);
        }
    }

    return 0;
}


/*!
 * \brief readInputSet, lê do arquivo de entrada as peças que serão usadas
 * \param inF, arquivo de entrada
 * \param inList, lista a ser inserida as peças
 * \param setQnt, quantidade de peças a serem lidas
 */
void readInputSet(FILE *inF, List *inList, int setQnt) {
    int i, x, y;

    /// para i começando em zero e indo até o tamanho do conjunto
    for(i = 0; i < setQnt; ++i) {
        /// lê do arquivo de entrada a parte esquerda e direita do dominó
        fscanf(inF, "%d %d", &x, &y);
        /// insere na cabeça o dominó lido
        insertOnHead(inList, createDomino(x, y));
    }
}

/*!
 * \brief createList, cria uma estrutura de lista encadeada com cabeça e cauda
 * \return ponteiro para lista criada e inicializada
 */
List *createList() {
    /// aloca memória para uma nova lista
    List *newList = (List *)malloc(sizeof(List));

    /// inicializa campos da estrutura
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;

    /// retora estrutura alocada e inicializada
    return newList;
}

/*!
 * \brief createDomino, cria uma estrutura dominó que contem os valores dos lados x e y da peça
 * \param x, lado esquerdo
 * \param y, lado direito
 * \return ponteiro para peça criada e inicializada
 */
Domino *createDomino(int x, int y) {
    /// aloca memória para um novo dominó
    Domino *newDomino = (Domino *)malloc(sizeof(Domino));

    /// inicializa campos da estrutura
    newDomino->esq = x;
    newDomino->dir = y;

    /// retora estrutura alocada e inicializada
    return newDomino;
}

/*!
 * \brief insertOnHead, insere valor passado na cabeça da lista
 * \param aList, lista a ser inserido o valor
 * \param info, valor a ser inserido
 * \return lista original modificada
 */
List *insertOnHead(List *aList, ItemType info) {
    /// aloca memória para um novo nó
    Node *newNode = createNode(info);

    /// insere novo nó na cabeça da lista
    newNode->next = aList->head;
    aList->head = newNode;

    /// modifica ponteiro da cauda se necessário
    if(aList->tail == NULL) aList->tail = newNode;

    /// incrementa tamanho da lista e retorna lista original
    aList->length++;
    return aList;
}

/*!
 * \brief insertOnTail, insere valor passado na cauda da lista
 * \param aList, lista a ser inserido o valor
 * \param info, valor a ser inserido
 * \return lista original modificada
 */
List *insertOnTail(List *aList, ItemType info) {
    /// aloca memória para um novo nó
    Node *newNode = createNode(info);

    /// se lista é vazia coloca nó na cabeça e atualiza a cauda
    if(!aList->head) {
        aList->head = newNode;
        aList->tail = newNode;

        /// incrementa tamanho da lista e retorna lista original modificada
        aList->length++;
        return aList;
    }

    /// coloca nó na cauda, atualiza ponteiro para cauda
    aList->tail->next = newNode;
    aList->tail = newNode;

    /// incrementa tamanho da lista e retorna lista original modificada
    aList->length++;
    return aList;
}

/*!
 * \brief createNode, cria uma estrutura de nó que contém um valor e um ponteiro para o proximo nó na lista
 * \param info, valor armazenado pelo nó
 * \return nó criado e inicializado
 */
Node *createNode(ItemType info) {
    /// aloca memória para um novo nó
    Node *newNode = (Node *)malloc(sizeof(Node));

    /// inicializa campos da estrutura
    newNode->info = info;
    newNode->next = NULL;

    /// retorna estrutura alocada e inicializada
    return newNode;
}

/*!
 * \brief printSet, printa no arquivo de saida a lista passada
 * \param outF, arquivo de saida
 * \param set, lista a ser printada
 */
void printSet(FILE *outF, List *set) {
    /// variável de iteração
    Node *tracer;

    /// para tracer começando no começo da lista e indo até o final
    for(tracer = set->head; tracer; tracer = tracer->next) {
        /// printa no arquivo de saida a parte esquerda e direita do dominó
        fprintf(outF, "%d %d", tracer->info->esq, tracer->info->dir);
        /// se o próximo nó existe, printa separador
        if(tracer->next)
            fprintf(outF, "|");
    }
    fprintf(outF, "\n");
}

/*!
 * \brief freeList, libera nós da lista passada
 * \param aList, lista a ser liberada
 */
void freeList(List *aList) {
    /// variável iterador e auxiliar
    Node *tracer, *aux;

    /// para tracer começando no começo da lista e indo até o final
    for(tracer = aList->head; tracer; ) {
        /// auxiliar recebe o próximo do atual
        aux = tracer->next;
        /// libera memória do nó do atual
        free(tracer);
        /// atual se torna o próximo
        tracer = aux;
    }

    /// volta campos da estrutura da lista para valores padrões
    aList->head = NULL;
    aList->tail = NULL;
    aList->length = 0;
}

/*!
 * \brief freeListInfo, libera nós e conteúdo da lista passada
 * \param aList, lista a ser liberada
 */
void freeListInfo(List *aList) {
    /// variável iterador e auxiliar
    Node *tracer, *aux;

    /// para tracer começando no começo da lista e indo até o final
    for(tracer = aList->head; tracer; ) {
        /// auxiliar recebe o próximo do atual
        aux = tracer->next;
        /// libera memória do dominó do atual
        free(tracer->info);
        /// libera memória do nó do atual
        free(tracer);
        /// atual se torna o próximo
        tracer = aux;
    }

    /// volta campos da estrutura da lista para valores padrões
    aList->head = NULL;
    aList->tail = NULL;
    aList->length = 0;
}

/*!
 * \brief isPossibleGame, testa se jogo é possivel passados as peças deste
 * \param aList, peças do jogo
 * \param gameSet, sequência resposta se jogo for possivel
 * \return um inteiro indicando se o jogo é possível
 */
int isPossibleGame(List *inList, List *gameSet) {
    /// variável iteradora e flag de resultado
    int i, isPossible;
    /// lista de dominós disponíveis
    List *available = createList();
    /// dominó pivô
    Domino *pivot;

    /// copia lista de entrada para conjunto de dominós disponíveis
    cpyList(available, inList);

    /// flag de resultado falsa
    isPossible = 0;
    /// para i começando em zero, indo até o tamanho da lista ou até achar um jogo possível
    for(i = 0; i < inList->length && !isPossible; ++i) {
        /// tira o primeiro nó da lista e usa como pivô
        pivot = pop(available);

        /// testa recursivamente se o pivô escolhido forma um jogo válido
        if(isPossiblePivot(pivot, available, gameSet)) {
            /// flag de resultado verdadeira e insere pivô na cabeça da lista resultado
            isPossible = 1;
            insertOnHead(gameSet, pivot);
        } else { ///< se lado esquerdo do pivô não forma jogo válido
            /// "gira" dominó pivô
            swap(&pivot->esq, &pivot->dir);

            /// testa recursivamente se o pivô escolhido forma um jogo válido
            if(isPossiblePivot(pivot, available, gameSet)) {
                /// flag de resultado verdadeira e insere pivô na cabeça da lista resultado
                isPossible = 1;
                insertOnHead(gameSet, pivot);
            } else { //< nenhuma dos lados do pivô formam jogo válido
                /// volta nos dominós disponíveis pivô atual
                insertOnTail(available, pivot);
            }
        }
    }

    /// libera lista auxiliar de dominós disponíveis
    freeList(available);

    /// retorna flag de resultado
    return isPossible;
}

/*!
 * \brief isPossiblePivot, testa se jogo é possivel passado um pivô e as peças livres
 * \param pivot, peça pivô usada para procurar uma peça que contém o valor do seu lado direito
 * \param inList, peças livres
 * \param gameSet, sequência resposta se jogo for possivel
 * \return um inteiro indicando se o jogo é possível
 */
int isPossiblePivot(ItemType pivot, List *inList, List *gameSet) {
    /// flag auxiliar e de resultado
    int matching, isPossible;
    /// variável iteradora
    Node *tracer;
    /// variável novo pivô escolhido
    Domino *newPivot;
    /// lista de dominós disponíveis
    List *available = createList();

    /// flag de resultado recebe falso
    isPossible = 0;

    /// copia lista de entrada para dominós disponíveis
    cpyList(available, inList);

    /// se lista de diponíveis é vazia flag de resultado é verdadeira
    if(!available->length) isPossible = 1;

    /// para tracer começando no inicio da lista, indo até o final ou até achar jogo válido
    for(tracer = inList->head; tracer && !isPossible;) {
        /// flag auxiliar recebe falso
        matching = 0;
        /// se número "direito" do pivô e do nó atual são iguais
        if(pivot->dir == tracer->info->esq) {
            /// flag auxiliar recebe verdadeiro
            matching = 1;
        } else if(pivot->dir == tracer->info->dir) { //< se número "direito" do pivô e do "esquerdo" nó atual são iguais
            /// flag auxiliar recebe verdadeiro
            matching = 1;
            /// "gira" dominó do nó atual
            swap(&tracer->info->esq, &tracer->info->dir);
        }

        /// se flag auxiliar é verdadeira
        if(matching) {
            /// escolhe dominó como novo pivô
            newPivot = tracer->info;

            /// remove pivô da lista de disponíveis
            removeNode(available, newPivot);

            /// testa recursivamente se existe jogo possível com novo pivô
            if(isPossiblePivot(newPivot, available, gameSet)) {
                /// insere novo pivô na lista resposta
                insertOnHead(gameSet, newPivot);
                /// flag de resposta recebe verdadeiro
                isPossible = 1;
            } else { //< se não existir jogo possível
                /// insere pivô de volta na lista de disponíveis
                insertOnHead(available, newPivot);
                /// vai para próximo nó
                tracer = tracer->next;
            }
        } else { //< se flag auxiliar é falsa
            /// vai para próximo nó
            tracer = tracer->next;
        }
    }

    /// libera lista auxiliar de dominós disponíveis
    freeList(available);

    /// retorna flag de resultado
    return isPossible;
}

/*!
 * \brief cpyList, copia elementos da lista from para lista dest
 * \param dest, lista que recebe elementos
 * \param from, lista que elementos são copiados
 */
void cpyList(List *dest, List *from) {
    /// variável iteradora
    Node *tracer;

    /// para tracer começando no inicio da lista original e indo até o final
    for(tracer = from->head; tracer; tracer = tracer->next) {
        /// copia para lista destino o nó atual
        insertOnTail(dest, tracer->info);
    }
}

/*!
 * \brief removeNode, remove nós na lista com o valor passado
 * \param aList, lista a ser modificada
 * \param info, valor a procura
 */
void removeNode(List *aList, ItemType info) {
    /// variável iteradora e auxiliar
    Node *tracer, *aux;

    /// se lista é vazia retorna
    if(!aList->head) return;

    /// se o nó a ser retirado é a cabeça da lista
    if(aList->head->info == info) {
        /// auxiliar recebe antiga cabeça e atualiza a cabeça da lista
        aux = aList->head;
        aList->head = aList->head->next;

        /// se cabeça se tornou nula, atualiza cauda da lista
        if(!aList->head) aList->tail = NULL;

        /// libera antiga cabeça e atualiza tamanho da lista
        free(aux);
        aList->length--;
        return;
    }

    /// para tracer começando no inicio da lista e indo até o final
    for(tracer = aList->head; tracer->next; ) {
        /// se (proximo de) nó atual é nó a ser retirado
        if(tracer->next->info == info) {
            /// auxiliar recebe (proximo de) nó atual e atualiza ponteiro para proximo do nó atual
            aux = tracer->next;
            tracer->next = aux->next;

            /// se nó a ser retirado é cauda da lista
            if(aux == aList->tail) {
                /// atualiza cauda da lista
                aList->tail = tracer;
            }

            /// libera nó e atualiza tamanho da lista
            free(aux);
            aList->length--;
        } else { //<  se (proximo de) nó atual não é nó a ser retirado
            /// vai para proximo nó
            tracer = tracer->next;
        }
    }
}

/*!
 * \brief pop, remove primeiro nó da lista e retorna valor armazenado por ele
 * \param aList, lista a ser modificada
 * \return valor armazenado pelo primeiro nó da lista
 */
ItemType pop(List *aList) {
    /// variável auxiliar
    Node *aux;
    /// variável resultado
    ItemType res;

    /// se tamanho da lista original é 0, retorna nulo
    if(!aList->length) return NULL;

    /// auxiliar recebe cabeça da lista e cabeça da lista é atualizada
    aux = aList->head;
    aList->head = aList->head->next;

    /// se lista se tornou vazia, atualiza a cauda
    if(!aList->head) aList->tail = NULL;

    /// resultado recebe conteúdo do nó antiga cabeça
    res = aux->info;

    /// nó é liberado e tamanho da lista é atualizado
    free(aux);
    aList->length--;

    /// retorna conteúdo do primeiro nó da lista
    return res;
}

/*!
 * \brief swap, troca o valor de dois inteiros um pelo outro
 * \param a, primeiro valor
 * \param b, segundo valor
 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
