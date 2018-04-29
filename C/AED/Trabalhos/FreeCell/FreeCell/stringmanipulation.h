#ifndef STRINGMANIPULATION_H
#define STRINGMANIPULATION_H

#define HELP -1
#define MOVETOFREECELLS 1
#define MOVETOHOMECELLS 2
#define MOVEFROMFREECELLS 3
#define MOVECOLTOCOL 4
#define FINDCARD 5

// STRING MANIPULATION //

///
/// \brief getSuitByInd, pega código char do naipe a partir do indice
/// \param ind, indice do naipe
/// \return char correspondente ao indice do naipe
///
char getSuitByInd(unsigned char ind);

///
/// \brief getRankByInd, pega código char da ordem a partir do indice
/// \param ind, indice da ordem
/// \return char correspondente ao indice da ordem
///
char getRankByInd(unsigned char ind);

///
/// \brief getCmdType, lê comando e determina seu tipo
/// \param cmd, string a ser lida
/// \return tipo do comando
///
int getCmdType(char cmd[]);

///
/// \brief skipSpaces, pula espaços de dada string
/// \param str, string a ser lida
/// \return quantidade de espaços a ser pulada
///
int skipSpaces(char str[]);

///
/// \brief readLine, lê da entrada padrão uma linha
/// \param str, armazena linha lida
///
void readLine(char str[]);

///
/// \brief strToUpper, transforma toda string em letras maiúsculas
/// \param str, string a ser manipulada
///
void strToUpper(char str[]);

///
/// \brief testCmdMoveToFreeCells, testa se comando é para mover para free cells
/// \param cmd, comando a ser checkado
/// \return se comando é válido
///
int testCmdMoveToFreeCells(char cmd[]);

///
/// \brief testCmdMoveToHomeCells, testa se comando é para mover para home cells
/// \param cmd, comando a ser checkado
/// \return se comando é válido
///
int testCmdMoveToHomeCells(char cmd[]);

///
/// \brief testCmdMoveFromFreeCells, testa se comando é para mover das free cells
/// \param cmd, comando a ser checkado
/// \return se comando é válido
///
int testCmdMoveFromFreeCells(char cmd[]);

///
/// \brief testCmdMoveColToCol, testa se comando é para mover coluna pra coluna
/// \param cmd, comando a ser checkado
/// \return se comando é válido
///
int testCmdMoveColToCol(char cmd[]);

int testCmdFindCard(char cmd[]);

int getIndBySuit(char suit);

int getIndByRank(char rank);

///
/// \brief readCmd1, executa parse em comando de (mover para free cells)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
/// \param colTo, armazena segunda coluna lida
///
void readCmd1(char cmd[], char *colFrom, char *colTo);

///
/// \brief readCmd2, executa parse em comando de (mover para home cells)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
///
void readCmd2(char cmd[], char *colFrom);

///
/// \brief readCmd3, executa parse em comando de (mover das free cells)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
/// \param colTo, armazena segunda coluna lida
///
void readCmd3(char cmd[], char *colFrom, char *colTo);

///
/// \brief readCmd4, executa parse em comando de (mover coluna para coluna)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
/// \param cardQnt, armazena quantidade de cartas lida
/// \param colTo, armazena segunda coluna lida
///
void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo);

///
/// \brief !!, executa parse em comando de (procurar a carta na mesa)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena naipe lido
/// \param colTo, armazena ordem lida
///
void readCmd5(char cmd[], char *suit, char *rank);


#endif // STRINGMANIPULATION_H
