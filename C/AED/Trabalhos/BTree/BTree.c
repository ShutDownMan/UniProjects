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
    header.topPos = 0;
    header.freeNodesRoot = -1;
    header.freeNodesQuantity = 0;

    /// escreve cabeãlho em arquivo
    writeBTreeHeaderToFile(f, &header);
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
        node->keys[i].id = 0;
        node->keys[i].regPos = -1;
        node->children[i] = -1;
    }

    /// quantidade de chaveze e posição de nó inicializados para valores padrão
    node->keyNum = 0;
    node->nodePos = -1;

    /// retorna nó
    return node;
}

FreeNode *createFreeNode() {
    FreeNode *newFreeNode = (FreeNode *) malloc(sizeof(FreeNode));

    newFreeNode->nextNode = -1;

    return newFreeNode;
}

//- WRITE -//

/**
 * esta função escreve no arquivo indicado o cabeçalho passado
 * @param f é o arquivo indicado
 * @param header é o cabeçalho a ser escrito no arquivo
 * @precondition arquivo tem que estar aberto e ter direitos de escrita
 */
void writeBTreeHeaderToFile(FILE *f, BTreeHeader *header) {
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
int writeNodeToFile(FILE *f, BTreeHeader *header, BTreeNode *node) {
    int pos;

    /// se header ou nó são nulos
    if (!header || !node)
        return -1; //< retorna posição inválida
    /// se nó possui posição inválida no arquivo
    if ((pos = node->nodePos) == -1) {
        /// se não existem posições livres dentro do arquivo
        if ((pos = header->freeNodesRoot) == -1) {
            /// coloca posição para topo do arquivo
            pos = header->topPos++;
        } else {
            /// atualiza posição livre no arquivo
            FreeNode *freeNode = readBTreeFreeNode(f, pos);
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
 * @param id valor a ser inserido na árvore
 * @precondition arquivo tem que estar aberto e ter direito de escrita
 * @postcondition valor é inserido no arquivo
 */
void insertBTree(FILE *f, int id, int regPos) {
    /// cabeçalho do arquivo
    BTreeHeader *header = readBTreeHeader(f);
    /// raiz da árvore
    BTreeNode *root = readBTreeNode(f, header->root);
    BTreeNode *newNode;

    RegData data = {.id = id, .regPos = regPos};

    /// se árvore é vazia
    if (!root) {
        /// cria um novo nó para ser raiz
        root = createNode();

        /// atribui valor para chaves
        root->keys[0] = data;
        root->keyNum = 1;

        /// atualiza cabeçalho para apontar para raiz
        header->root = writeNodeToFile(f, header, root);
    } else {
        /// função auxiliar para inserção
        insertAux(f, header, root, data);
        /// se ocorreu overflow no nó
        if (overflow(root)) {
            /// splita o nó
            RegData m;

            newNode = split(root, &m);
            BTreeNode *newRoot = createNode();

            /// inicializa novos nós criados no split
            newRoot->keys[0] = m;
            newRoot->children[0] = header->root;
            newRoot->keyNum = 1;

            newRoot->children[1] = writeNodeToFile(f, header, newNode);
            header->root = writeNodeToFile(f, header, newRoot);

            /// libera memória utilizada pelos nós em memória
            freeBTreeNode(newNode);
            freeBTreeNode(newRoot);
        }
        /// escreve raiz no arquivo
        writeNodeToFile(f, header, root);
    }

//    printHeader(header);
    /// escreve cabeçalho no arquivo
    writeBTreeHeaderToFile(f, header);

    printf("-----------\n");
    printBTree(f);
    printf("-----------\n");

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
void insertAux(FILE *f, BTreeHeader *header, BTreeNode *currentNode, RegData info) {
    int pos = 0;

    /// se valor não existe no nó atual
    if (!searchBTreePos(currentNode, info.id, &pos)) {
        /// se nó atual é folha
        if (isLeaf(currentNode)) {
            /// insere valor no nó atual
            insertOnRight(currentNode, pos, info, -1);
        } else {

            /// lê nó indicado para inserção
            BTreeNode *node = readBTreeNode(f, currentNode->children[pos]);
            /// insere no nó lido
            insertAux(f, header, node, info);
            /// se ocorreu overflow no nó indicado
            if (overflow(node)) {
                /// splita o nó
                RegData m;
                BTreeNode *aux = split(node, &m);
                insertOnRight(currentNode, pos, m, writeNodeToFile(f, header, aux));

                /// escreve nós splitados no arquivo
                writeNodeToFile(f, header, node);

                /// libera memória utilizada pelo nó indicado
                freeBTreeNode(aux);
            }
        }
    }
    /// atualiza nó atual em arquivo
    writeNodeToFile(f, header, currentNode);
}

/**
 * esta função insere o o valor passado no seu lugar correto no nó
 * @param node é o nó a ser inserido o valor
 * @param pos é a posição a ser inserido o nó
 * @param info é o valor a ser inserido
 * @param p é o endereço para filho a direita do valor inserido
 */
void insertOnRight(BTreeNode *node, int pos, RegData info, int p) {
    /// move todos valores antes de pos para direita
    for (int i = node->keyNum; i > pos; --i) {
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
BTreeNode *split(BTreeNode *node, RegData *m) {
    /// cria novo nó
    BTreeNode *newNode = createNode();

    /// calcula posição mediana
    int q = (ORDER - 1) / 2;
    newNode->keyNum = q;
    node->keyNum = q;

    /// atribui para m valor da chave mediana
    *m = node->keys[q];

    /// atribui valores acima da posição mediana de node para newNode
    newNode->children[0] = node->children[q + 1];
    for (int i = 0; i < newNode->keyNum; ++i) {
        newNode->keys[i] = node->keys[q + i + 1];
        newNode->children[i + 1] = node->children[q + i + 2];
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
        if (info == node->keys[(*pos)].id)
            return 1;
        else if (info < node->keys[(*pos)].id)
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
BTreeHeader *readBTreeHeader(FILE *f) {
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
FreeNode *readBTreeFreeNode(FILE *f, int pos) {
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

void removeBTree(FILE *fTree, int id) {
    BTreeHeader *header = readBTreeHeader(fTree);
    BTreeNode *root = readBTreeNode(fTree, header->root);

    RegData data = {.id = id, .regPos = -1};

    removeBTreeAux(fTree, header, root, data);

    freeBTreeNode(root);
    free(header);
}

void removeBTreeAux(FILE *fTree, BTreeHeader *header, BTreeNode *node, RegData info) {
    int pos;
    searchBTreePos(node, info.id, &pos);

    if (pos < node->keyNum && node->keys[pos].id == info.id) {
        if (isLeaf(node)) {
            removeFromLeaf(node, pos);
        } else {
            removeFromInnerNode(fTree, header, node, pos);
        }
        writeNodeToFile(fTree, header, node);
    } else {
        if (isLeaf(node)) {
            printf("The value [%d] is not present in tree\n", info);
            return;
        }

        int flag = (pos == node->keyNum);

        BTreeNode *nextNode = readBTreeNode(fTree, node->children[pos]);
//        printf("nextNode->keyNum = %d\n", nextNode->keyNum);
        printBTreeNodeKeys(nextNode);
        if (nextNode->keyNum < ORDER / 2) {
            fill(fTree, header, node, pos);
        }

        BTreeNode *prevNode = NULL;
        BTreeNode *modifiedNode = NULL;
        if (flag && pos > node->keyNum) {
            removeBTreeAux(fTree, header, prevNode = readBTreeNode(fTree, node->children[pos - 1]), info);
            modifiedNode = prevNode;
        } else {
//            printf("removeBTreeAux (0)\n");
            removeBTreeAux(fTree, header, nextNode, info);
            modifiedNode = nextNode;
        }

        if (modifiedNode->keyNum < ORDER / 2) {
            fill(fTree, header, node, pos);
        }

        freeBTreeNode(prevNode);
        freeBTreeNode(nextNode);
    }
}

void removeFromLeaf(BTreeNode *node, int pos) {
    for (int i = pos + 1; i < node->keyNum; ++i) {
        node->keys[i - 1] = node->keys[i];
    }

    node->keyNum--;
}

void removeFromInnerNode(FILE *fTree, BTreeHeader *header, BTreeNode *node, int pos) {
    RegData k = node->keys[pos];

    BTreeNode *leftChildNode = readBTreeNode(fTree, node->children[pos]);
    BTreeNode *rightChildNode = readBTreeNode(fTree, node->children[pos + 1]);

//    printf("removeFromInnerNode (0)\n");

    if (leftChildNode->keyNum >= ORDER / 2) {
        RegData pred = getPred(fTree, node, pos);
        node->keys[pos] = pred;
        removeBTreeAux(fTree, header, leftChildNode, pred);
    } else if (rightChildNode->keyNum >= ORDER / 2) {
        RegData succ = getSucc(fTree, node, pos);
        node->keys[pos] = succ;
        removeBTreeAux(fTree, header, rightChildNode, succ);
    } else {
//        printf("removeFromInnerNode (1)\n");
        merge(fTree, header, node, pos);
        removeBTreeAux(fTree, header, leftChildNode, k);
    }

    writeNodeToFile(fTree, header, leftChildNode);
    writeNodeToFile(fTree, header, rightChildNode);
    writeNodeToFile(fTree, header, node);

    freeBTreeNode(leftChildNode);
    freeBTreeNode(rightChildNode);
}

RegData getPred(FILE *f, BTreeNode *node, int pos) {
    BTreeNode *current = readBTreeNode(f, node->children[pos]);
    BTreeNode *next = NULL;
    RegData pred;

    while (!isLeaf(current)) {
        next = readBTreeNode(f, node->keyNum);
        freeBTreeNode(current);
        current = next;
    }

    pred = current->keys[current->keyNum - 1];
    freeBTreeNode(current);

    return pred;
}


RegData getSucc(FILE *f, BTreeNode *node, int pos) {
    BTreeNode *current = readBTreeNode(f, node->children[pos + 1]);
    BTreeNode *next = NULL;
    RegData succ;

    while (!isLeaf(current)) {
        next = readBTreeNode(f, 0);
        freeBTreeNode(current);
        current = next;
    }

    succ = current->keys[0];
    freeBTreeNode(current);

    return succ;
}

void merge(FILE *fTree, BTreeHeader *header, BTreeNode *node, int pos) {
    BTreeNode *child = readBTreeNode(fTree, pos);
    BTreeNode *sibling = readBTreeNode(fTree, pos + 1);

//    printf("merge (0)\n");

    child->keys[(ORDER - 1) / 2 - 1] = node->keys[pos];

    for (int i = 0; i < sibling->keyNum; ++i) {
        child->keys[i + (ORDER - 1) / 2] = sibling->keys[i];
    }

    if (!isLeaf(child)) {
        for (int i = 0; i <= sibling->keyNum; ++i)
            child->children[i + (ORDER - 1) / 2] = sibling->children[i];
    }

    for (int i = pos + 1; i < node->keyNum; ++i)
        node->keys[i - 1] = node->keys[i];

    for (int i = pos + 2; i <= node->keyNum; ++i)
        node->children[i - 1] = node->children[i];

    child->keyNum += sibling->keyNum + 1;
    node->keyNum--;

    writeNodeToFile(fTree, header, child);
    writeNodeToFile(fTree, header, node);

    writeBTreeFreeNodesList(fTree, header, sibling);

    writeBTreeHeaderToFile(fTree, header);

    freeBTreeNode(sibling);
    freeBTreeNode(child);
}

void fill(FILE *fTree, BTreeHeader *header, BTreeNode *node, int pos) {
    BTreeNode *childPrev = readBTreeNode(fTree, node->children[pos - 1]);
    BTreeNode *childNext = readBTreeNode(fTree, node->children[pos + 1]);

    if (pos != 0 && childPrev->keyNum - 1 >= ORDER / 2) {
//        printf("fill (0)\n");
        borrowFromPrev(fTree, header, node, pos);
    } else if (pos != node->keyNum && childNext->keyNum - 1 >= ORDER / 2) {
        borrowFromNext(fTree, header, node, pos);
    } else {
        if (pos != node->keyNum) {
            merge(fTree, header, node, pos);
        } else {
            merge(fTree, header, node, pos - 1);
        }
    }

    freeBTreeNode(childNext);
    freeBTreeNode(childPrev);
}

void borrowFromPrev(FILE *fTree, BTreeHeader *header, BTreeNode *node, int pos) {
    BTreeNode *child = readBTreeNode(fTree, node->children[pos]);
    BTreeNode *sibling = readBTreeNode(fTree, node->children[pos - 1]);

    for (int i = child->keyNum - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!isLeaf(child)) {
        for (int i = child->keyNum; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }

    child->keys[0] = node->keys[pos - 1];

    if (!isLeaf(child))
        child->children[0] = sibling->children[sibling->keyNum];

    node->keys[pos - 1] = sibling->keys[sibling->keyNum - 1];

    child->keyNum += 1;
    sibling->keyNum -= 1;

    writeNodeToFile(fTree, header, child);
    writeNodeToFile(fTree, header, sibling);
    writeNodeToFile(fTree, header, node);

    freeBTreeNode(child);
    freeBTreeNode(sibling);
}

void borrowFromNext(FILE *fTree, BTreeHeader *header, BTreeNode *node, int pos) {
    BTreeNode *child = readBTreeNode(fTree, node->children[pos]);
    BTreeNode *sibling = readBTreeNode(fTree, node->children[pos + 1]);

    child->keys[(child->keyNum)] = node->keys[pos];

    if (!isLeaf(child)) {
        child->children[(child->keyNum) + 1] = sibling->children[0];
    }

    child->keys[pos] = node->keys[0];

    for (int i = 1; i < sibling->keyNum; ++i) {
        sibling->keys[i - 1] = sibling->keys[i];
    }

    if (!isLeaf(sibling)) {
        for (int i = 1; i <= sibling->keyNum; ++i) {
            sibling->children[i - 1] = sibling->children[i];
        }
    }

    child->keyNum += 1;
    sibling->keyNum -= 1;

    writeNodeToFile(fTree, header, child);
    writeNodeToFile(fTree, header, sibling);
    writeNodeToFile(fTree, header, node);

    freeBTreeNode(child);
    freeBTreeNode(sibling);
}

void writeBTreeFreeNodesList(FILE *fTree, BTreeHeader *header, BTreeNode *node) {
    int pos;
    FreeNode *freeNode;

    if (!header || !node)
        return;

    pos = node->nodePos;
    freeNode = createFreeNode();

    freeNode->nextNode = header->freeNodesRoot;
    header->freeNodesRoot = pos;

    header->freeNodesQuantity++;

    fseek(fTree, sizeof(BTreeHeader) + sizeof(BTreeNode) * pos, SEEK_SET);

    fwrite(freeNode, sizeof(FreeNode), 1, fTree);

    free(freeNode);
}

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
    printf("Node Quantity = %d\n", header->topPos);
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
    BTreeHeader *header = readBTreeHeader(f);
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
        while (nodeCount) {
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
    if (node->keyNum) {
        for (int i = 0; i < node->keyNum - 1; ++i) {
            printf("%d,", node->keys[i].id);
        }
        printf("%d", node->keys[node->keyNum - 1]);
    } else {
        printf("!");
    }
    printf("]");
}