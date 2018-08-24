#ifndef START_H
#define START_H

#define MAXRAND UINT_MAX

#define SORT_TYPE_INVALID -1
#define SORT_TYPE_COMPARE 0

/// enum que define os algoritimos de ordenação
typedef enum sortType {
	Insertion = 1,
	Selection,
	Quicksort,
	Merge,
	Heap,
	Bubble
} SortType;

#define DEFAULT_SORT_TYPE SORT_TYPE_QUICKSORT

#define NUMBERS_PER_LINE 11

/// estrutura que define os argumentos passados para a execução
typedef struct arguments {
	/// modo de ordenação (N ou C)
	char sortMode;
	/// quantidade de números a ser ordenada
	int numQuantity;

	/// nome do algoritimo de ordenação
	char *sortName;

	/// nome do arquivo de entrada
	char *inputFileName;
	/// nome do arquivo de saida
	char *outputFileName;
} Arguments;

/**
	@brief readArguments lê dos argumentos passado e armazena em uma estrutura
	@param argc armazena tamanho do vetor de argumentos
	@param argv vetor de argumentos
	@return estrutura com os argumentos inicializados
	@precondition nenhuma
	@postcondition nenhuma
*/
Arguments *readArguments(int argc, char const *argv[]);

/**
	@brief sortModeNumeric cria e ordena vetor seguindo especificações dadas
	@param args especificações de execução
	@precondition args tem que estar alocado e inicializado
	@postcondition nenhuma
*/
void sortModeNumeric(Arguments *args);

/**
	@brief newRandVet aloca memória, inicializa e retorna um vetor de inteiros desordenado
	@param length tamanho do vetor a ser criado
	@return vetor de inteiros desordenado
	@precondition nenhuma
	@postcondition nenhuma
*/
void compareNumericSorts(int vet[], int length);

/**
	@brief fprintNumericVet printa em arquivo um vetor de inteiros
	@param f é o arquivo de saída
	@param vet é o vetor de inteiros
	@param length é o tamanho do vetor
	@precondition arquivo tem que estar aberto
	@postcondition nenhuma
*/
int *newRandVet(int length);

/**
	@brief compareNumericSorts compara e mostra os tempos entre os algoritimos
	@param vet é o vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition nenhuma
*/
void fprintNumericVet(FILE *f, int vet[], int length);

/**
	@brief getSortType transforma tipo de ordenação de texto em inteiro
	@param sortName nome do algoritimo
	@return inteiro correspondente
	@precondition nenhuma
	@postcondition nenhuma
*/
int getSortType(char *sortName);

/**
	@brief sortModeString cria e ordena vetor seguindo especificações dadas
	@param args especificações de execução
	@precondition args tem que estar alocado e inicializado
	@postcondition nenhuma
*/
void sortModeString(Arguments *args);

/**
	@brief readStringsInFile lê cadeias de caractéres separadas por espaços ou nova linha
	@param f é o arquivo a ser lido
	@param length é o tamanho que o vetor de strings terá
	@return vetor de strings
	@precondition arquivo tem que estar aberto
	@postcondition length é atualizado para tamanho do vetor
*/
char **readStringsInFile(FILE *f, int *length);

/**
	@brief fprintStringVet printa em arquivo um vetor de strings
	@param f é o arquivo de saída
	@param vet é o vetor de strings
	@param length é o tamanho do vetor
	@precondition arquivo tem que estar aberto
	@postcondition nenhuma
*/
void fprintStringVet(FILE *f, char *vet[], int length);

/**
	@brief compareStringSorts compara e mostra os tempos entre os algoritimos
	@param vet é o vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition nenhuma
*/
void compareStringSorts(char *vet[], int length);

#endif // START_H