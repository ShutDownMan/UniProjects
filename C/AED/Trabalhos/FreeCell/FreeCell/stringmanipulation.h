#ifndef STRINGMANIPULATION_H
#define STRINGMANIPULATION_H

#define MAXSTR 64

#define HELP -1
#define MOVETOFREECELLS 1
#define MOVETOHOMECELLS 2
#define MOVEFROMFREECELLS 3
#define MOVECOLTOCOL 4
#define MOVEFROMFREECELLTOHOMECELL 7
#define FINDCARD 5
#define SAVEGAME 6

// STRING MANIPULATION //

///
/// \brief  getSuitByInd, pega código char do naipe a partir do indice
/// \param  ind, indice do naipe
/// \return char correspondente ao indice do naipe
/// \pre    nenhuma
/// \post   nenhuma
///
char getSuitByInd(unsigned char ind);

///
/// \brief  getRankByInd, pega código char da ordem a partir do indice
/// \return char correspondente ao indice da ordem               Z
/// \pre    nenhuma
/// \post   nenhuma
///
char getRankByInd(unsigned char ind);

///
/// \brief  readLine, lê da entrada padrão uma linha
/// \param  str, armazena linha lida
/// \pre    nenhuma
/// \post   linha é lida e armazenada em str
///
void readLine(char str[]);

///
/// \brief  getCmdType, lê comando e determina seu tipo
/// \param  cmd, string a ser lida
/// \return tipo do comando
/// \pre    nenhuma
/// \post   nenhuma
///
int getCmdType(char cmd[]);

///
/// \brief  strToUpper, transforma toda string em letras maiúsculas
/// \param  str, string a ser manipulada
/// \pre    nenhuma
/// \post   todos caractéres de str se transformam em uppercase
///
void strToUpper(char str[]);

///
/// \brief  testCmdMoveToFreeCells, testa se comando é para mover para free cells
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdMoveToFreeCells(char cmd[]);

///
/// \brief  testCmdMoveToHomeCells, testa se comando é para mover para home cells
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdMoveToHomeCells(char cmd[]);

///
/// \brief  testCmdMoveFromFreeCells, testa se comando é para mover das free cells
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdMoveFromFreeCells(char cmd[]);

///
/// \brief  testCmdMoveColToCol, testa se comando é para mover coluna pra coluna
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdMoveColToCol(char cmd[]);

///
/// \brief  testCmdFindCard, testa se comando é para achar carta
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdFindCard(char cmd[]);

///
/// \brief  getIndBySuit, retorna inteiro equivalente de um naipe fornecido
/// \param  suit, naipe fornecido
/// \return inteiro equivalente, -1 se não encontrado
/// \pre    nenhuma
/// \post   nenhuma
///
int getIndBySuit(char suit);

///
/// \brief  getIndByRank, retorna inteiro equivalente de uma ordem fornecida
/// \param  rank, ordem fornacida
/// \return inteiro equivalente, -1 se não encontrado
/// \pre    nenhuma
/// \post   nenhuma
///
int getIndByRank(char rank);

///
/// \brief  testCmdSaveGame, testa se comando é para salvar jogo
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdSaveGame(char cmd[]);

///
/// \brief  isValidFileName, testa se string é nome de arquivo válido
/// \param  str, string a ser checkada
/// \return se string é valida
/// \pre    nenhuma
/// \post   nenhuma
///
int isValidFileName(char str[]);

///
/// \brief  testCmdFromFreeToHomeCells, testa se comando é para mover das free cells para as home cells
/// \param  cmd, comando a ser checkado
/// \return se comando é válido
/// \pre    nenhuma
/// \post   nenhuma
///
int testCmdFromFreeToHomeCells(char cmd[]);

///
/// \brief  readCmd1, executa parse em comando de (mover para free cells)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \param  colTo, armazena segunda coluna lida
/// \pre    nenhuma
/// \post   colFrom e colTo recebem valores correspondentes
///
void readCmd1(char cmd[], char *colFrom, char *colTo);

///
/// \brief  readCmd2, executa parse em comando de (mover para home cells)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \pre    nenhuma
/// \post   colFrom recebe valor correspondente
///
void readCmd2(char cmd[], char *colFrom);

///
/// \brief  readCmd3, executa parse em comando de (mover das free cells)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \param  colTo, armazena segunda coluna lida
/// \pre    nenhuma
/// \post   colFrom e colTo recebem valores correspondentes
///
void readCmd3(char cmd[], char *colFrom, char *colTo);

///
/// \brief  readCmd4, executa parse em comando de (mover coluna para coluna)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \param  cardQnt, armazena quantidade de cartas lida
/// \param  colTo, armazena segunda coluna lida
/// \pre    nenhuma
/// \post   colFrom, colTo e cardQnt recebem valores correspondentes
///
void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo);

///
/// \brief  readCmd5, executa parse em comando de (procurar a carta na mesa)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena naipe lido
/// \param  colTo, armazena ordem lida
/// \pre    nenhuma
/// \post   suit e rank recebem valores correspondentes
///
void readCmd5(char cmd[], char *suit, char *rank);

///
/// \brief  readCmd6, executa parse em comando de (salvar mesa)
/// \param  fileName, nome do arquivo a ser salvo
/// \pre    nenhuma
/// \post   nenhuma
///
void readCmd6(char cmd[], char fileName[]);

///
/// \brief  readCmd7, executa parse em comando de (mover da free cells para home cells)
/// \param  cmd, string a ser parseada
/// \param  colFrom, armazena primeira coluna lida
/// \param  colTo, armazena segunda coluna lida
/// \pre    nenhuma
/// \post   colFrom e colTo recebem valores correspondentes
///
void readCmd7(char cmd[], char *colFrom);

#endif // STRINGMANIPULATION_H
