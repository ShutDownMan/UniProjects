//
// Created by Jedson on 10/19/2018.
//

#include <stdlib.h>

#include "BTree.h"
#include "Queue.h"

//- INITIALIZE -//

/**
 * esta função cria um cabeçalho para uma árvore B vazia e escreve no arquivo indicado
 * @param f é o arquivo a ser escrito
 * @precondition arquivo tem que estar aberto e ter direitos de escrita
 * @postcondition cabeçalho para árvore B vazia é escrito no arquivo
 */
void createEmptyBTree(FILE *f) {
    BTreeHeader header;

    /// inicializa cabeçalho para valores padrões
    header.root = -1;
    header.nodesQuantity = 0;
    header.freeNodesRoot = -1;
    header.freeNodesQuantity = 0;

    /// escreve cabeãlho em arquivo
    writeHeaderToFile(f, &header);
}

/**
 * esta função aloca memória e inicializa um nó de árvore B
 * @return nó de árvore B alocado e inicializado
 * @precondition nenhuma
 * @postcondition nó é alocado e inicializado em memória
 */
BTreeNode *createNode() {
    /// aloca espaço em memória para o nó
    BTreeNode *node = (BTreeNode *) malloc(sizeof(BTreeNode));

    /// para cada elemento nos campos
    for (int i = 0; i < ORDER; ++i) {
        /// inicializa para seus valores padrões
        node->keys[i] = 0;
        node->data[i] = -1;
        node->children[i] = -1;
    }

    /// quantidade de chaveze e posição de nó inicializados para valores padrão
    node->keyNum = 0;
    node->nodePos = -1;

    /// retorna nó
    return node;
}

//- WRITE -//

/**
 * esta função escreve no arquivo indicado o cabeçalho passado
 * @param f é o arquivo indicado
 * @param header é o cabeçalho a ser escrito no arquivo
 * @precondition arquivo tem que estar aberto e ter direitos de escrita
 */
void writeHeaderToFile(FILE *f, BTreeHeader *header) {
    if (!header)
        return;

    fseek(f, 0, SEEK_SET);

    fwrite(header, sizeof(BTreeHeader), 1, f);
}

/**!
 * esta função escreve um nó de árvore B em um arquivo indicado
 * @param f arquivo indicado
 * @param node nó a ser escrito
 * @param header cabeçalho do arquivo
 * @return posição na qual o nó foi escrito no arquivo
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition nó é escrito no arquivo
 */
int writeNodeToFile(FILE *f, BTreeNode *node, BTreeHeader *header) {
    int pos;

    /// se header ou nó são nulos
    if (!header || !node)
        return -1; //< retorna posição inválida
    /// se nó possui posição inválida no arquivo
    if ((pos = node->nodePos) == -1) {
        /// se não existem posições livres dentro do arquivo
        if ((pos = header->freeNodesRoot) == -1) {
            /// coloca posição para topo do arquivo
            pos = header->nodesQuantity++;
        } else {
            /// atualiza posição livre no arquivo
            FreeNode *freeNode = readFreeNode(f, pos);
            header->freeNodesRoot = freeNode->nextNode;
            free(freeNode);
        }
    }

//    printf("pos = %d\n", pos);

    /// armazena posição do nó em arquivo no nó
    node->nodePos = pos;

    /// calcula posição para escrita do nó em arquivo
    fseek(f, sizeof(BTreeHeader) + sizeof(BTreeNode) * pos, SEEK_SET);

    /// escreve nó
    fwrite(node, sizeof(BTreeNode), 1, f);

    /// retorna posição de escrita
    return pos;
}

/**
 * esta função insere um valor na árvore B que se encontra no arquivo indicado
 * @param f arquivo indicado
 * @param info valor a ser inserido na árvore
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition valor é inserido no arquivo
 */
void insert(FILE *f, int info) {
    /// cabeçalho do arquivo
    BTreeHeader *header = readHeader(f);
    /// raiz da árvore
    BTreeNode *root = readBTreeNode(f, header->root);
    BTreeNode *newNode;

    /// se árvore é vazia
    if (!root) {
        /// cria um novo nó para ser raiz
        root = createNode();

        /// atribui valor para chaves
        root->keys[0] = info;
        root->keyNum = 1;

        /// atualiza cabeçalho para apontar para raiz
        header->root = writeNodeToFile(f, root, header);
    } else {
        /// função auxiliar para inserção
        insertAux(f, header, root, info);
        /// se ocorreu overflow no nó
        if (overflow(root)) {
            /// splita o nó
            int m;
            newNode = split(root, &m);
            BTreeNode *newRoot = createNode();

            /// inicializa novos nós criados no split
            newRoot->keys[0] = m;
            newRoot->children[0] = header->root;
            newRoot->keyNum = 1;

            newRoot->children[1] = writeNodeToFile(f, newNode, header);
            header->root = writeNodeToFile(f, newRoot, header);

            /// libera memória utilizada pelos nós em memória
            freeBTreeNode(newNode);
            freeBTreeNode(newRoot);
        }
        /// escreve raiz no arquivo
        writeNodeToFile(f, root, header);
    }

//    printHeader(header);
    /// escreve cabeçalho no arquivo
    writeHeaderToFile(f, header);

    /// libera memória utilizada pela raiz e pelo cabeçalho
    freeBTreeNode(root);
    free(header);
}

/**
 * esta função é uma recursiva auxiliar de inserir
 * @param f é o arquivo a ser inserido o valor
 * @param header é o cabeçalho do arquivo
 * @param currentNode nó atual
 * @param info valor a ser inserido no arquivo
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition valor é inserido no arquivo
 */
void insertAux(FILE *f, BTreeHeader *header, BTreeNode *currentNode, int info) {
    int pos = 0;

    /// se valor não existe no nó atual
    if (!searchBTreePos(currentNode, info, &pos)) {
        /// se nó atual é folha
        if (isLeaf(currentNode)) {
            /// insere valor no nó atual
            insertOnRight(currentNode, pos, info, -1);
        } else {
            /// lê nó indicado para inserção
            BTreeNode *node = readBTreeNode(f, currentNode->children[pos]);
            /// insere no nó lido
            insertAux(f, header, node, info);
            /// se ocorreu oferflow no nó indicado
            if (overflow(node)) {
                /// splita o nó
                int m;
                BTreeNode *aux = split(node, &m);
                insertOnRight(currentNode, pos, m, writeNodeToFile(f, aux, header));

                /// escreve nós splitados no arquivo
                writeNodeToFile(f, node, header);

                /// libera memória utilizada pelo nó indicado
                freeBTreeNode(aux);
            }
        }
    }
    /// atualiza nó atual em arquivo
    writeNodeToFile(f, currentNode, header);
}

/**
 * esta função insere o o valor passado no seu lugar correto no nó
 * @param node é o nó a ser inserido o valor
 * @param pos é a posição a ser inserido o nó
 * @param info é o valor a ser inserido
 * @param p é o endereço para filho a direita do valor inserido
 */
void insertOnRight(BTreeNode *node, int pos, int info, int p) {
    /// move todos valores antes de pos para direita
    for (int i = node->keyNum + 1; i > pos; --i) {
        node->keys[i] = node->keys[i - 1];
        node->children[i + 1] = node->children[i];
    }

    /// insere valor em seu lugar correto
    node->keys[pos] = info;
    node->children[pos + 1] = p;
    node->keyNum++;
}

/**
 * esta função testa se ocorreu everflow em um nó
 * @param node nó a ser testado
 * @return 1 para verdadeiro e 0 para falso
 * @precondition node não pode ser nulo
 * @postcondition nenhuma
 */
int overflow(BTreeNode *node) {
    return (node->keyNum == ORDER);
}

/**
 * esta função faz a operação split no nó indicado
 * @param node é o nó a ser feito o splot
 * @param m é o valor mediano do nó
 * @return novo nó criado no split
 * @precondition node não pode ser nulo
 * @postcondition um novo nó é criado e retornado
 */
BTreeNode *split(BTreeNode *node, int *m) {
    /// cria novo nó
    BTreeNode *newNode = createNode();

    /// calcula posição mediana
    int q = ORDER / 2;
    newNode->keyNum = q;
    node->keyNum = q;

    /// atribui para m valor da chave mediana
    *m = node->keys[q];

    /// atrbui valores acima da posição mediana de node para newNode
    newNode->children[0] = node->children[q + 1];
    for (int i = 0; i < newNode->keyNum; ++i) {
        newNode->keys[i] = node->keys[q + i + 1];
        newNode->children[i + 1] = node->children[q + i + 2];
//        root->keys[q + i + 1] = 0;
//        root->children[q + i + 2] = -1;
    }

    /// retona nó criado na operação
    return newNode;
}

/**
 * esta função procura se um valor existe em um nó e se não modifica pos \
 * para apontar o lugar que este iria se encaixar
 * @param node nó a ser pesquisado
 * @param info valor a ser pesquisado
 * @param pos posição apropriada para o valor
 * @return se valor foi encontrado ou não
 * @precondition node e pos não podem ser nulos
 */
int searchBTreePos(BTreeNode *node, int info, int *pos) {
    /// passa pelas chaves procurando por um valor maior que o valor passado
    for ((*pos) = 0; (*pos) < node->keyNum; (*pos)++) {
        if (info == node->keys[(*pos)])
            return 1;
        else if (info < node->keys[(*pos)])
            return 0;
    }
    return 0;
}

/**
 * testa se nó passado é folha
 * @param node é o nó a ser testado
 * @return 1 para verdadeiro e 0 para falso
 * @precondition node não pode ser nulo
 * @postcondition nenhuma
 */
int isLeaf(BTreeNode *node) {
    return (node->children[0] == -1);
}

//- READ -//

/**
 * esta função lê o cabeçalho do arquivo indicado
 * @param f arquivo indicado
 * @return poteiro para cabeçalho lido
 * @precondition arquivo tem que estar aberto e com direito de escrita
 * @postcondition espaço em memória para o cabeçalho é alocado e inicializado
 */
BTreeHeader *readHeader(FILE *f) {
    /// aloca espaço na memória para o cabeçalho
    BTreeHeader *header = (BTreeHeader *) malloc(sizeof(BTreeHeader));

    /// vai para posição correta
    fseek(f, 0, SEEK_SET);

    /// lê cabeçalho
    fread(header, sizeof(BTreeHeader), 1, f);

    /// retorna cabeçalho lido
    return header;
}

/**
 * esta função lê um nó em um arquivo inidacado na posição passada
 * @param f é o arquivo indicado
 * @param pos é a posição passada
 * @return nó lido
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition espaço em memória para o nó é alocado e inicializado
 */
BTreeNode *readBTreeNode(FILE *f, int pos) {
    BTreeNode *node;

    /// se posição é invalida
    if (pos == -1)
        return NULL;

    /// aloca espaço em memória para o nó
    node = (BTreeNode *) malloc(sizeof(BTreeNode));

    /// calcula posição do nó em arquivo
    fseek(f, sizeof(BTreeHeader) + sizeof(BTreeNode) * pos, SEEK_SET);

    /// lê nó do arquivo
    fread(node, sizeof(BTreeNode), 1, f);

    /// retorna nó lido
    return node;
}

/**
 * esta função lê um nó livre no arquivo indicado na posição passada
 * @param f é o arquivo indicado
 * @param pos é a posição passada
 * @return nó livre lido
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition espaço em memória para o nó livre é alocado e inicializado
 */
FreeNode *readFreeNode(FILE *f, int pos) {
    FreeNode *node;

    /// se posição passada é invalida
    if (pos == -1)
        return NULL;

    /// aloca memória para nó
    node = (FreeNode *) malloc(sizeof(FreeNode));

    /// calcula posição do nó
    fseek(f, sizeof(BTreeHeader) + sizeof(BTreeNode) * pos, SEEK_SET);

    /// lê nó do arquivo
    fread(node, sizeof(FreeNode), 1, f);

    /// retorna nó lido
    return node;
}

//- REMOVE -//

/**
 * esta função libera memória de nó de árvore B
 * @param node nó a ser liberado
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void freeBTreeNode(BTreeNode *node) {
    /// se nó passado não é nulo
    if (!node)
        free(node); //< libera memória utilziada por este
}

//- SHOW -//

/**
 * esta função printa na saida padrão o cabeçalho passado
 * @param header cabeçalho a ser printado
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printHeader(BTreeHeader *header) {
    printf("--------------------\n");
    printf("Root = %d\n", header->root);
    printf("Node Quantity = %d\n", header->nodesQuantity);
    printf("Free Nodes Root = %d\n", header->freeNodesRoot);
    printf("--------------------\n");
}

/**
 * esta função printa na saida padrão a árvore B no arquivo indicado
 * @param f arquivo que contém árvore B
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printBTree(FILE *f) {
    /// lê cabeçalho e raiz da árvore
    BTreeHeader *header = readHeader(f);
    BTreeNode *root = readBTreeNode(f, header->root);
    /// cria fila
    Queue *q = createQueue();
    int nodeCount;

    /// coloca raiz na fila
    pushQ(q, root);

    /// enquanto não se acabarem os nós
    nodeCount = q->count;
    while (nodeCount) {
        /// printa os nós do nível atual na saida padrão
        while (nodeCount > 0) {
            QNode *qNode = popQ(q);
            BTreeNode *bTreeNode = (BTreeNode *) qNode->info;

            printBTreeNodeKeys(bTreeNode);
            printf(" ");

            /// puxa os seus filhos para a fila
            for (int i = 0; i <= bTreeNode->keyNum; ++i) {
                if (bTreeNode->children[i] != -1)
                    pushQ(q, readBTreeNode(f, bTreeNode->children[i]));
            }
            nodeCount--;

            free(qNode);
            freeBTreeNode(bTreeNode);
        }
        printf("\n");
        nodeCount = q->count;
    }

    freeBTreeNode(root);
    deleteQueue(q);
}

/**
 * esta função printa a posição em arquivo dos filhos do nó indicado
 * @param node é o nó a ser printado na saida padrão
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printBTreeNodeChildren(BTreeNode *node) {
    printf("[");
    for (int i = 0; i < node->keyNum; ++i) {
        printf("%d,", node->children[i]);
    }
    printf("%d", node->children[node->keyNum]);
    printf("]");
}

/**
 * esta função printa o valor das chaves nó indicado
 * @param node é o nó a ser printado na saida padrão
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printBTreeNodeKeys(BTreeNode *node) {
    printf("[");
    for (int i = 0; i < node->keyNum - 1; ++i) {
        printf("%d,", node->keys[i]);
    }
    printf("%d", node->keys[node->keyNum - 1]);
    printf("]");
}