//
// Created by Jedson on 11/2/2018.
//

#include <stdlib.h>
#include "Registy.h"

//- INITIALIZE -//

/*!
 * função para inicializar arquivo de registros
 * @param f arquivo de registros a ser inicializado
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
void createEmptyRegistryFile(FILE *f) {
    /// inicializa cabeçalho
    RegistryHeader header = {.topPos = 0};

    /// escreve novo cabeçalho no arquivo
    writeRegistryHeader(f, &header);
}

/*!
 * função para criação de registro
 * @return registro alocado e inicializado
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
Entry *createEntry() {
    /// aloca memória para novo registro
    Entry *newEntry = (Entry *) malloc(sizeof(Entry));

    /// inicializa campos do registro
    newEntry->file = -1;
    newEntry->quant = 0;
    newEntry->entryPos = -1;
    newEntry->nextEntryPos = -1;

    return newEntry;
}

//- WRITE -//

/*!
 * função para escrita de cabeçalgo em arquivo de registros
 * @param f arquivo a ser escrito
 * @param header cabeçalho a ser escrito no arquivo
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
void writeRegistryHeader(FILE *f, RegistryHeader *header) {
    /// vai para inicio do arquivo
    fseek(f, 0, SEEK_SET);

    /// escreve novo cabeçalho
    fwrite(header, sizeof(RegistryHeader), 1, f);
}

/*!
 * função para escrita de registro em arquivo
 * @param f arquivo de registros
 * @param header cabeçalho do arquivo
 * @param entry registro a ser escrito
 * @return posição de escrita do registro
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
int writeEntryToFile(FILE *f, RegistryHeader *header, Entry *entry) {
    int pos;

    /// se posição do registro é invalida
    if ((pos = entry->entryPos) == -1) {
        /// atribui posição para final do arquivo
        pos = header->topPos++;
        /// escreve cabeçalho no arquivo
        writeRegistryHeader(f, header);
    }

    /// atualiza posição no registro
    entry->entryPos = pos;

    /// vai para posição calculada
    fseek(f, sizeof(RegistryHeader) + sizeof(Entry) * pos, SEEK_SET);

    /// escreve registro
    fwrite(entry, sizeof(Entry), 1, f);

    return pos;
}

//- READ -//

/*!
 * lê cabeçalho do arquivo passado
 * @param f arquivo de registros
 * @return cabeçalho do arquivo
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
RegistryHeader *readRegistryHeader(FILE *f) {
    /// aloca memória para cabeçalho a ser lida
    RegistryHeader *header = (RegistryHeader *) malloc(sizeof(RegistryHeader));

    /// vai para o inicio do arquivo
    fseek(f, 0, SEEK_SET);

    /// lê cabeçalho
    fread(header, sizeof(RegistryHeader), 1, f);

    return header;
}

/*!
 * função para leitura de registro a partir de posição dada
 * @param f arquivo de registros
 * @param pos posição para leitura
 * @return registro lido do arquivo
 * @precondition arquivos tem que estar abertos e ter direito de leitura
 * @postcondition nenhuma
 */
Entry *readEntryFromFile(FILE *f, int pos) {
    /// aloca memória para registro a ser lido
    Entry *entry = (Entry *) malloc(sizeof(Entry));

    /// se posição a ser lida é invalida retorna NULL
    if (pos == -1) return NULL;

    /// vai para posição calculada
    fseek(f, sizeof(RegistryHeader) + sizeof(Entry) * pos, SEEK_SET);

    /// lê registro do arquivo
    fread(entry, sizeof(Entry), 1, f);

    return entry;
}

//- SHOW -//

void printRegistryHeader(RegistryHeader *header) {
    printf("-----------------\n");
    printf("topPos = %d\n", header->topPos);
    printf("-----------------\n");
}

void printEntry(Entry *entry) {
    printf("-----------------\n");
    printf("fileNumber = %d\n", entry->file);
    printf("Word quantity = %d\n", entry->quant);
    printf("Entry position = %d\n", entry->entryPos);
    printf("Next entry position = %d\n", entry->nextEntryPos);
    printf("-----------------\n");
}

