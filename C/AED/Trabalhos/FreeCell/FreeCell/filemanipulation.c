#include "filemanipulation.h"

///
/// \brief  openBinaryFile, abre arquivo binário
/// \param  fileName, nome do arquivo
/// \param  mode, modo de abertura
/// \return arquivo aberto
/// \pre    nenhuma
/// \post   nenhuma
///
FILE *openBinaryFile(char fileName[], char mode[]) {
    // essa função nem deveria existir
    return fopen(fileName, mode);
}

///
/// \brief  createEmptyList, inicializa uma lista de nós em arquivo
/// \param  f, arquivo a ser modificado
/// \pre    nenhuma
/// \post   lista é criada dentro do arquivo
///
void createEmptyList(FILE *f) {
    /// aloca memória para estrutura do cabeçalho
    Header *newHeader = (Header *) malloc(sizeof(Header));
    int i;

    /// inicializa cada uma das pilhas no arquivo
    for(i = 0; i < 4; ++i) {
        newHeader->freeCellsHeads[i] = -1;
        newHeader->homeCellsHeads[i] = -1;
        newHeader->tableauHeads[i] = -1;
        newHeader->tableauHeads[i+4] = -1;
    }

    /// inicializa indice do topo do arquivo
    newHeader->topPos = 0;

    /// escreve cabeçalho inicializado em arquivo
    writeHeaderToFile(f, newHeader);
    /// libera memória do cabeçalho
    free(newHeader);
}

///
/// \brief  createFileNode, inicializa um nó de arquivo
/// \param  val, valor a ser salvo
/// \return nó alocado e inicializado
/// \pre    nenhuma
/// \post   nenhuma
///
FileNode *createFileNode(ItemType val) {
    /// aloca memória para estrutura de nó em arquivo
    FileNode *newNode = (FileNode *) malloc(sizeof(FileNode));

    /// inicializa campos da estrutura
    newNode->val = val;
    newNode->next = -1;

    /// retorna nó
    return newNode;
}

///
/// \brief  writeHeaderToFile, escreve cabeçalho em arquivo
/// \param  f, arquivo a ser modificado
/// \param  header, cabeçalho a ser escrito
/// \pre    arquivo não pode ser nulo
/// \post   cabeçalho é escrito no arquivo
///
void writeHeaderToFile(FILE *f, Header *header) {
    /// vai para o começo do arquivo
    fseek(f, 0, SEEK_SET);
    /// escreve cabeçalho
    fwrite(header, sizeof(Header), 1, f);
}

///
/// \brief  writeNodeToFile, escreve nó em arquivo
/// \param  f, arquivo a ser modificado
/// \param  toWrite, nó a ser escrito
/// \param  pos, posição no arquivo a ser escrito
/// \pre    arquivo não pode ser nulo
/// \post   nó é escrito no arquivo
///
void writeNodeToFile(FILE *f, FileNode *toWrite, int pos) {
    /// vai para posição fornecida para escrever
    fseek(f, sizeof(Header) + sizeof(FileNode)*pos, SEEK_SET);
    /// escreve no arquivo
    fwrite(toWrite, sizeof(FileNode), 1, f);
}


///
/// \brief  readHeader, lê cabeçalho do arquivo
/// \param  f, arquivo a ser lido
/// \return cabeçalho lido
/// \pre    arquivo não pode ser nulo
/// \post   nenhuma
///
Header *readHeader(FILE *f) {
    /// aloca memória para estrutura de cabeçalho
    Header *readHeader = (Header *) malloc(sizeof(Header));

    /// vai para o começo do arquivo
    fseek(f, 0, SEEK_SET);
    /// lê cabeçalho
    fread(readHeader, sizeof(Header), 1, f);

    /// retorna cabeçalho lido
    return readHeader;
}

///
/// \brief  readFileNode, lê um nó em arquivo
/// \param  f, arquivo a ser lido
/// \param  pos, posição do nó em arquivo
/// \return nó lido
/// \pre    arquivo não pode ser nulo
/// \post   nenhuma
///
FileNode *readFileNode(FILE *f, int pos) {
    /// aloca memória para estrutura de nó em arquivo
    FileNode *toRead = (FileNode *) malloc(sizeof(FileNode));

    /// vai para posição do nó fornecida
    fseek(f, sizeof(Header) + sizeof(FileNode)*pos, SEEK_SET);
    /// lê nó em arquivo
    fread(toRead, sizeof(FileNode), 1, f);

    /// retorna nó lido
    return toRead;
}

///
/// \brief  insertNodeOnFreeCell, insere nó em free cell no arquivo
/// \param  f, arquivo a ser modificado
/// \param  index, index da free cell
/// \param  val, carta a ser inserida
/// \pre    arquivo não pode ser nulo
/// \post   nó é inserida
///
void insertNodeOnFreeCell(FILE *f, int index, ItemType val) {
    Header *header = readHeader(f);
    FileNode *toWrite = createFileNode(val);

    /// coloca proximo do nó criado como cabeça da pilha de células livres
    toWrite->next = header->freeCellsHeads[index];

    /// escreve nó no arquivo, modifica cabeça da pilha e posição do final do arquivo
    writeNodeToFile(f, toWrite, header->topPos);
    header->freeCellsHeads[index] = header->topPos;
    header->topPos++;

    /// escreve cabeçalho modificado
    writeHeaderToFile(f, header);

    /// libera memória do nó auxiliar
//    printf("freeCellsHeads[%d] = %d\n", index, header->freeCellsHeads[index]);
    free(toWrite);
}

///
/// \brief  insertNodeOnHomeCell, insere nó em home cell no arquivo
/// \param  f, arquivo a ser modificado
/// \param  index, index do da lista a ser inserido
/// \param  val, carta a ser inserida
/// \pre    arquivo não pode ser nulo
/// \post   nó é inserido
///
void insertNodeOnHomeCell(FILE *f, int index, ItemType val) {
    Header *header = readHeader(f);
    FileNode *toWrite = createFileNode(val);

    /// coloca proximo do nó criado como cabeça das pilhas de fundações
    toWrite->next = header->homeCellsHeads[index];

    /// escreve nó no arquivo, modifica cabeça da pilha e posição do final do arquivo
    writeNodeToFile(f, toWrite, header->topPos);
    header->homeCellsHeads[index] = header->topPos;
    header->topPos++;

    /// escreve cabeçalho modificado
    writeHeaderToFile(f, header);

    /// libera memória do nó auxiliar
//    printf("homeCellsHeads[%d] = %d\n", index, header->homeCellsHeads[index]);
    free(toWrite);
}

///
/// \brief  insertNodeOnTableau, insere nó em tableau no arquivo
/// \param  f, arquivo a ser modificado
/// \param  index, index da pilha a ser inserido
/// \param  val, carta a ser inserida
/// \pre    arquivo não pode ser nulo
/// \post   nó é inserido
///
void insertNodeOnTableau(FILE *f, int index, ItemType val) {
    Header *header = readHeader(f);
    FileNode *toWrite = createFileNode(val);

    /// coloca proximo do nó criado como cabeça da pilha do tableau
    toWrite->next = header->tableauHeads[index];

    /// escreve nó no arquivo, modifica cabeça da pilha e posição do final do arquivo
    writeNodeToFile(f, toWrite, header->topPos);
    header->tableauHeads[index] = header->topPos;
    header->topPos++;

    /// escreve cabeçalho modificado
    writeHeaderToFile(f, header);

    /// libera memória do nó auxiliar
//    printf("tableauHeads[%d] = %d\n", index, header->tableauHeads[index]);
    free(toWrite);
}
