#include <stdio.h>
#include <ctype.h>

#include "stringmanipulation.h"

// (v)copas, (p)espadas, (p)paus, (v)ouros,
char suits[4] = {'c', 'e', 'p', 'o'};
char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

// STRING MANIPULATION //

///
/// \brief  getSuitByInd, pega código char do naipe a partir do indice
/// \param  ind, indice do naipe
/// \return char correspondente ao indice do naipe
/// \pre    nenhuma
/// \post   nenhuma
///
char getSuitByInd(unsigned char ind) {
    /// se indice é menor q o numero de naipes
    if(ind < 4) {
        /// retorna caractere equivalente
        return suits[ind];
    }
    return ' ';
}

///
/// \brief  getRankByInd, pega código char da ordem a partir do indice
/// \return char correspondente ao indice da ordem
/// \pre    nenhuma
/// \post   nenhuma
///
char getRankByInd(unsigned char ind) {
    /// se indice esta dentro do número de sequências
    if(ind < 13) {
        /// retorna caractere equivalente
        return ranks[ind];
    }
    return ' ';
}

///
/// \brief  readLine, lê da entrada padrão uma linha
/// \param  str, armazena linha lida
/// \pre    nenhuma
/// \post   linha é lida e armazenada em str
///
void readLine(char str[]) {
    scanf("%[^\n]%*c", str);
}

///
/// \brief  getCmdType, lê comando e determina seu tipo
/// \param  cmd, string a ser lida
/// \return tipo do comando
/// \pre    nenhuma
/// \post   nenhuma
///
int getCmdType(char cmd[]) {
    /// se comando é vazio, nada a fazer
    if(!cmd[0]) return 0;

    /// se comando é pedido de ajuda
    if(cmd[0] == '?') return HELP;

    /// testa se comando é para mover para células livres
    if(testCmdMoveToFreeCells(cmd)) return MOVETOFREECELLS;

    /// testa se comando é para mover para as pilhas de fundação
    if(testCmdMoveToHomeCells(cmd)) return MOVETOHOMECELLS;

    /// testa se comando é para mover das células livres
    if(testCmdMoveFromFreeCells(cmd)) return MOVEFROMFREECELLS;

    /// testa se comando é para mover de coluna para coluna
    if(testCmdMoveColToCol(cmd)) return MOVECOLTOCOL;

    /// testa se comando é para procurar uma carta na mesa
    if(testCmdFindCard(cmd)) return FINDCARD;

    /// testa se comando é para salvar o jogo
    if(testCmdSaveGame(cmd)) return SAVEGAME;

    /// se nenhuma comando foi lido, retorna 0
    return 0;
}

///
/// \brief  inputCmd, lê da entrada padrão um comando e o executa
/// \param  table, mesa de jogo que o comando sera executado
/// \pre    pilha de saida  não pode ser nula
/// \post   movimento é executado
///
int testCmdMoveToFreeCells(char cmd[]) {
    char colFrom = 0, colTo = 0;

    /// lê linha com formato do comando atual
    sscanf(cmd, " ^%c > %c ", &colFrom, &colTo);

    /// se coluna de saída é válida
    if(toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H') {
        /// se coluna de entrada é válida
        return (!colTo || (colTo >= 'A' && colTo <= 'D'));
    }

    /// comando é inválido
    return 0;
}

///
/// \brief  testCmdMoveToHomeCells, testa se comando é para mover para home cells
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdMoveToHomeCells(char cmd[]) {
    char colFrom = 0;

    /// lê linha com formato do comando atual
    sscanf(cmd, " *%c ", &colFrom);

    /// se coluna de saída é válida
    return (toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H');
}

///
/// \brief  testCmdMoveFromFreeCells, testa se comando é para mover das free cells
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdMoveFromFreeCells(char cmd[]) {
    char colFrom = 0, colTo = 0;

    /// lê linha com formato do comando atual
    sscanf(cmd, " v%c > %c ", &colFrom, &colTo);

    /// se coluna de saída é válida
    if(toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H') {
        /// se coluna de entrada é válida
        return (!colTo || (colTo >= 'A' && colTo <= 'D'));
    }

    /// comando é inválido
    return 0;
}

///
/// \brief  testCmdMoveColToCol, testa se comando é para mover coluna pra coluna
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdMoveColToCol(char cmd[]) {
    char colFrom = 0, colTo = 0;
    int cardQnt = 0, i = 0, j = 0;

    /// lê linha com formato do comando atual
    sscanf(cmd, " %c%n", &colFrom, &i);
    sscanf(cmd+i, "%d%n", &cardQnt, &j);
    sscanf(cmd+i+j, " > %c ", &colTo);

    /// se coluna de saída é válida
    if(toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H') {
        /// se coluna de entrada é válida
        return (colTo >= 'A' && colTo <= 'H');
    }

    /// comando é inválido
    return 0;
}

///
/// \brief  testCmdFindCard, testa se comando é para achar carta
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdFindCard(char cmd[]) {
    char fromCol = 0, toCol = 0;

    /// lê linha com formato do comando atual
    sscanf(cmd, " ( %c , %c ) ", &fromCol, &toCol);

    /// se naipe é válido
    if(getIndBySuit(fromCol) != -1) {
        /// se ordem é válida
        return (getIndByRank(toCol) != -1);
    }

    /// comando é inválido
    return 0;
}

///
/// \brief  getIndBySuit, retorna inteiro equivalente de um naipe fornecido
/// \param  suit, naipe fornecido
/// \return inteiro equivalente, -1 se não encontrado
/// \pre    nenhuma
/// \post   nenhuma
///
int getIndBySuit(char suit) {
    int i;

    /// para cada naipe
    for(i = 0; i < 4; ++i) {
        /// se naipe atual é igual o fornecido
        if(toupper(getSuitByInd(i)) == toupper(suit)) {
            /// retorna indice
            return i;
        }
    }

    /// naipe não encontrado
    return -1;
}

///
/// \brief  getIndByRank, retorna inteiro equivalente de uma ordem fornecida
/// \param  rank, ordem fornacida
/// \return inteiro equivalente, -1 se não encontrado
/// \pre    nenhuma
/// \post   nenhuma
///
int getIndByRank(char rank) {
    int i;

    /// para cada ordem
    for(i = 0; i < 13; ++i) {
        /// se ordem atual é igual a fornecida
        if(toupper(getRankByInd(i)) == toupper(rank)) {
            /// retorna indice
            return i;
        }
    }

    /// ordem não encontrada
    return -1;
}

///
/// \brief  testCmdSaveGame, testa se comando é para salvar jogo
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdSaveGame(char cmd[]) {
    char fileName[64] = {0};
    int n = 0;

    /// lê linha com formato do comando atual
    sscanf(cmd, " save \"%[^\"]\"%n", fileName, &n);

    /// se leu linha inteira
    if(n) {
        /// comando válido se nome de arquivo é válido
        printf("%s\n", fileName);
        return isValidFileName(fileName);
    }

    /// comando é inválido
    return 0;
}

///
/// \brief  isValidFileName, testa se string é nome de arquivo válido
/// \param  str, string a ser checkada
/// \return se string é valida
/// \pre    nenhuma
/// \post   nenhuma
///
int isValidFileName(char str[]) {
    int i;

    /// para cada char na string
    for(i = 0; str[i]; ++i) {
        /// se char não é alfanumérico
        if(!isalpha(str[i])) {
            /// se ele não é ponto ou underline
            if(str[i] != '.' && str[i] != '_') {
                /// nome é inválido
                return 0;
            }
        }
    }

    /// nome do arquivo é válido
    return 1;
}

///
/// \brief  readCmd1, executa parse em comando de (mover para free cells)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \param  colTo, armazena segunda coluna lida
/// \pre    nenhuma
/// \post   colFrom e colTo recebem valores correspondentes
///
void readCmd1(char cmd[], char *colFrom, char *colTo) {
    /// lê comando e armazena nos argumentos passados
    sscanf(cmd, " ^%c > %c ", colFrom, colTo);
    *colFrom = toupper(*colFrom);
    *colTo = toupper(*colTo);
}

///
/// \brief  readCmd2, executa parse em comando de (mover para home cells)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \pre    nenhuma
/// \post   colFrom recebe valor correspondente
///
void readCmd2(char cmd[], char *colFrom) {
    /// lê comando e armazena nos argumentos passados
    sscanf(cmd, " *%c ", colFrom);
    *colFrom = toupper(*colFrom);
}

///
/// \brief  readCmd3, executa parse em comando de (mover das free cells)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \param  colTo, armazena segunda coluna lida
/// \pre    nenhuma
/// \post   colFrom e colTo recebem valores correspondentes
///
void readCmd3(char cmd[], char *colFrom, char *colTo) {
    /// lê comando e armazena nos argumentos passados
    sscanf(cmd, " v%c > %c ", colFrom, colTo);
    *colFrom = toupper(*colFrom);
    *colTo = toupper(*colTo);
}

///
/// \brief  readCmd4, executa parse em comando de (mover coluna para coluna)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \param  cardQnt, armazena quantidade de cartas lida
/// \param  colTo, armazena segunda coluna lida
/// \pre    nenhuma
/// \post   colFrom, colTo e cardQnt recebem valores correspondentes
///
void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo) {
    /// lê comando e armazena nos argumentos passados
    int i = 0, j = 0;
    sscanf(cmd, " %c%n", colFrom, &i);
    sscanf(cmd+i, "%d%n", cardQnt, &j);
    sscanf(cmd+i+j, " > %c ", colTo);
}

///
/// \brief  readCmd5, executa parse em comando de (procurar a carta na mesa)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena naipe lido
/// \param  colTo, armazena ordem lida
/// \pre    nenhuma
/// \post   suit e rank recebem valores correspondentes
///
void readCmd5(char cmd[], char *suit, char *rank) {
    /// lê comando e armazena nos argumentos passados
    sscanf(cmd, " ( %c , %c ) ", suit, rank);
    *suit = tolower(*suit);
}

///
/// \brief  readCmd6, executa parse em comando de (salvar mesa)
/// \param  fileName, nome do arquivo a ser salvo
/// \pre    nenhuma
/// \post   nenhuma
///
void readCmd6(char cmd[], char fileName[]) {
    /// lê comando e armazena nos argumentos passados
    sscanf(cmd, " save \"%[^\"]\"", fileName);
}
