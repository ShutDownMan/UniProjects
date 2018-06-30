#ifndef START_H
#define START_H

#define SORT_TYPE_INVALID -1
#define SORT_TYPE_ALL 0
#define SORT_TYPE_INSERTION 1
#define SORT_TYPE_SELECTION 2
#define SORT_TYPE_QUICKSORT 3
#define SORT_TYPE_MERGE 4
#define SORT_TYPE_HEAP 5
#define SORT_TYPE_BUBBLE 6

#define DEFAULT_SORT_TYPE SORT_TYPE_QUICKSORT

#define NUMBERS_PER_LINE 12

typedef struct arguments {
	/// modo de ordenação (N ou C)
	char sortMode;
	/// quantidade de números a ser ordenada
	int numQuantity;

	/// nome do algorítimo de ordenação
	char *sortName;

	/// nome do arquivo de entrada
	char *inputFileName;
	/// nome do arquivo de saida
	char *outputFileName;

} Arguments;

/*!
* @brief readArguments, 
* @param argc, 
* @param argv, 
* @pre 
* @post 
*/

Arguments *readArguments(int argc, char const *argv[]);

void sortModeNumeric(Arguments *args);

void sortModeString(Arguments *args);

void compareSorts(int vet[], int length);

int *newRandVet(int length);

void fprintVet(FILE *f, int vet[], int length);

int getSortType(char *sortName);

#endif // START_H