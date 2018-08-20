#ifndef FUNCTION_CLOCK
#define FUNCTION_CLOCK

/**
	@brief getTimeTaken armazena e retorna o tempo tomado por um
		determinado método de ordenação em inteiros
	@param sortType método de ordenação
	@param vet vetor de inteiros
	@param length tamanho do vetor
	@return tempo tomado pelo método em segundos
	@precondition nenhuma
	@postcondition nenhuma
*/
double getTimeTaken(int sortType, int vet[], int length);

/**
	@brief copyVet retorna uma cópia de um vetor de inteiros
	@param vet vetor de inteiros original
	@param length tamanho do vetor
	@return vetor cópia
	@precondition nenhuma
	@postcondition nenhuma
*/
int *copyVet(int vet[], int length);

/**
	@brief getTimeTaken armazena e retorna o tempo tomado por um
		determinado método de ordenação em strings
	@param sortType método de ordenação
	@param vet vetor de strings
	@param length tamanho do vetor
	@return tempo tomado pelo método em segundos
	@precondition nenhuma
	@postcondition nenhuma
*/
double getTimeTakenStr(int sortType, char *vet[], int length);

/**
	@brief copyStrVet retorna uma cópia de um vetor de inteiros
	@param vet vetor de strings original
	@param length tamanho do vetor
	@return vetor cópia
	@precondition nenhuma
	@postcondition nenhuma
*/
char **copyStrVet(char *vet[], int length);

#endif