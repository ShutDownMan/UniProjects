#include "start.h"
#include "sorts.h"
#include "function_clock.h"

/**
	@brief readArguments lê dos argumentos passado e armazena em uma estrutura
	@param argc armazena tamanho do vetor de argumentos
	@param argv vetor de argumentos
	@return estrutura com os argumentos inicializados
	@precondition nenhuma
	@postcondition nenhuma
*/
Arguments *readArguments(int argc, char const *argv[]) {
	/// estrutura de argumentos é inicializada
	Arguments *newArgs = (Arguments *)malloc(sizeof(Arguments));

	/// campos são inicialados
	newArgs->numQuantity = 0;
	newArgs->sortName = NULL;
	newArgs->inputFileName = NULL;
	newArgs->outputFileName = NULL;

	/// modo de ordenação
	newArgs->sortMode = argv[0][0];

	/// se for numérico
	if(newArgs->sortMode == 'N') {
		/// pega quantidade de números a serem ordenados
		newArgs->numQuantity = atoi(argv[1]);
	}
	/// se for string
	if(newArgs->sortMode == 'C') {
		/// armazena nome do arquivo de entrada
		newArgs->inputFileName = (char*)argv[1];
	}

	/// se existem mais argumentos
	if(argc > 2) {
		/// armazena tipo de ordenação
		newArgs->sortName = (char*)argv[2];
		if(argc > 3) {
			/// armazena nome do arquivo de saída
			newArgs->outputFileName = (char*)argv[3];
		}
	}

	/// retorna estrutura com as informações para execução
	return newArgs;
}

/**
	@brief sortModeNumeric cria e ordena vetor seguindo especificações dadas
	@param args especificações de execução
	@precondition args tem que estar alocado e inicializado
	@postcondition nenhuma
*/
void sortModeNumeric(Arguments *args) {
	/// inicializa um novo vetor desordenado
	int *vet = newRandVet(args->numQuantity);
	/// tipo padrão comparação e saida padrão
	int sortType = SORT_TYPE_COMPARE;
	FILE *outputFile = stdout;

	/// se tipo de ordenação foi especificado
	if(args->sortName)
		/// pega valor numérico do tipo especificado
		sortType = getSortType(args->sortName);
	/// se nome do arquivo de saída foi especificado
	if(args->outputFileName)
		/// abre arquivo
		outputFile = fopen(args->outputFileName, "w+");

	switch(sortType) {
		case SORT_TYPE_COMPARE: {
			/// compara tempo entre os algoritimos de ordenação
			compareNumericSorts(vet, args->numQuantity);
			return;
		}

		case Insertion: {
			/// ordena vetor pelo algoritimo insertion
			numericInsertionSort(vet, args->numQuantity);
			break;
		}

		case Selection: {
			/// ordena vetor pelo algoritimo selecion
			numericSelectionSort(vet, args->numQuantity);
			break;
		}

		case Quicksort: {
			/// ordena vetor pelo algoritimo quicksort
			numericQuickSort(vet, 0, args->numQuantity-1);
			break;
		}

		case Merge: {
			/// ordena vetor pelo algoritimo merge
			numericMergeSort(vet, 0, args->numQuantity);
			break;
		}

		case Heap: {
			/// ordena vetor pelo algoritimo heap
			numericHeapSort(vet-1, args->numQuantity);
			break;
		}

		case Bubble: {
			/// ordena vetor pelo algoritimo bubble
			numericBubbleSort(vet, args->numQuantity);
			break;
		}

		default: {
			/// algoritimo de ordenação inválido
			fprintf(outputFile, "invalid sort name (%s)\n", args->sortName);
			return;
		}
	}

	/// printa vetor ordenado e libera memória utilizada
	fprintNumericVet(outputFile, vet, args->numQuantity);
	free(vet);
}

/**
	@brief newRandVet aloca memória, inicializa e retorna um vetor de inteiros desordenado
	@param length tamanho do vetor a ser criado
	@return vetor de inteiros desordenado
	@precondition nenhuma
	@postcondition nenhuma
*/
int *newRandVet(int length) {
	int i;
	/// aloca memória para um novo vetor
	int *newVet = (int *)malloc(sizeof(int) * length);

	/// cria um vetor desordenado
	for (i = 0; i < length; ++i) {
		newVet[i] = rand() % MAXRAND;
	}

	/// retorna novo vetor
	return newVet;
}

/**
	@brief fprintNumericVet printa em arquivo um vetor de inteiros
	@param f é o arquivo de saída
	@param vet é o vetor de inteiros
	@param length é o tamanho do vetor
	@precondition arquivo tem que estar aberto
	@postcondition nenhuma
*/
void fprintNumericVet(FILE *f, int vet[], int length) {
	int i, j, index;

	/// printa vetor na saida padrão
	for(i = 0; i < ceil((double)length/NUMBERS_PER_LINE); ++i) {
		for(j = 0; j < NUMBERS_PER_LINE && i*NUMBERS_PER_LINE + j < length; ++j) {
			index = i*NUMBERS_PER_LINE + j;
			fprintf(f, "%5d ", vet[index]);
		}
		fprintf(f, "\n");
	}
}

/**
	@brief compareNumericSorts compara e mostra os tempos entre os algoritimos
	@param vet é o vetor de inteiros
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition nenhuma
*/
void compareNumericSorts(int vet[], int length) {
	double timeTaken;

	/// pega o tempo de execução de cada algoritimo e printa na saida padrão

	timeTaken = getTimeTaken(Quicksort, vet, length);
	printf("QuickSort took 		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(Heap, vet, length);
	printf("HeapSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(Merge, vet, length);
	printf("MergeSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(Insertion, vet, length);
	printf("InsertionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(Selection, vet, length);
	printf("SelectionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(Bubble, vet, length);
	printf("BubbleSort took		%.4lf seconds.\n", timeTaken);
}

/**
	@brief getSortType transforma tipo de ordenação de texto em inteiro
	@param sortName nome do algoritimo
	@return inteiro correspondente
	@precondition nenhuma
	@postcondition nenhuma
*/
int getSortType(char *sortName) {
	/// testa cada nome e retona seu inteiro correspondente

	if(!strcmp(sortName, "insertionsort")) return Insertion;

	if(!strcmp(sortName, "selectionsort")) return Selection;

	if(!strcmp(sortName, "quicksort")) return Quicksort;

	if(!strcmp(sortName, "mergesort")) return Merge;

	if(!strcmp(sortName, "heapsort")) return Heap;

	if(!strcmp(sortName, "bubblesort")) return Bubble;

	/// nome do algoritimo inválido
	return SORT_TYPE_INVALID;
}

/**
	@brief sortModeString cria e ordena vetor seguindo especificações dadas
	@param args especificações de execução
	@precondition args tem que estar alocado e inicializado
	@postcondition nenhuma
*/
void sortModeString(Arguments *args) {
	char **vet;
	int i, length;
	int sortType = SORT_TYPE_COMPARE;
	FILE *outputFile = stdout;
	FILE *inputFile = stdin;


	/// pega valor numérico do tipo especificado
	if(args->sortName)
		sortType = getSortType(args->sortName);
		/// abre arquivo de entrada
	if(args->inputFileName)
		inputFile = fopen(args->inputFileName, "r+");
		/// abre arquivo de saída
	if(args->outputFileName)
		outputFile = fopen(args->outputFileName, "w+");

	/// lê strings do arquivo
	vet = readStringsInFile(inputFile, &length);

	switch(sortType) {
		case SORT_TYPE_COMPARE: {
			compareStringSorts(vet, length);
			return;
		}

		case Insertion: {
			/// ordena vetor de strings pelo algoritimo insertion
			fprintf(outputFile, "InsertionSort:\n");
			stringInsertionSort(vet, length);
			break;
		}

		case Selection: {
			/// ordena vetor de strings pelo algoritimo selection
			fprintf(outputFile, "SelectionSort:\n");
			stringSelectionSort(vet, length);
			break;
		}

		case Quicksort: {
			/// ordena vetor de strings pelo algoritimo quicksort
			fprintf(outputFile, "QuickSort:\n");
			stringQuickSort(vet, 0, length-1);
			break;
		}

		case Merge: {
			/// ordena vetor de strings pelo algoritimo mergesort
			fprintf(outputFile, "MergeSort:\n");
			stringMergeSort(vet, 0, length);
			break;
		}

		case Heap: {
			/// ordena vetor de strings pelo algoritimo heapsort
			fprintf(outputFile, "HeapSort:\n");
			stringHeapSort(vet-1, length);
			break;
		}

		case Bubble: {
			/// ordena vetor de strings pelo algoritimo bubblesort
			fprintf(outputFile, "BubbleSort:\n");
			stringBubbleSort(vet, length);
			break;
		}

		default: {
			/// tipo inválido de ordenação
			fprintf(outputFile, "invalid sort name (%s)\n", args->sortName);
			return;
		}
	}

	/// printa vetor de strigs no arquivo de saída
	fprintStringVet(outputFile, vet, length);
	/// libera todas strings no vetor
	for(i = 0; i < length; ++i) {
		free(vet[i]);
	}
	/// libera memória utilizada pelo vetor
	free(vet);
}

/**
	@brief readStringsInFile lê cadeias de caractéres separadas por espaços ou nova linha
	@param f é o arquivo a ser lido
	@param length é o tamanho que o vetor de strings terá
	@return vetor de strings
	@precondition arquivo tem que estar aberto
	@postcondition length é atualizado para tamanho do vetor
*/
char **readStringsInFile(FILE *f, int *length) {
	int i, maxLength;
	char **newVet;
	char str[256];

	/// estrutura de vetor dinâmico

	/// é alocado 1 espaço de memória para o vetor inicialmente
	maxLength = 1;
	newVet = (char **)malloc(sizeof(char *) * maxLength);

	/// enquanto arquivo ainda possui linhas
	for(i = 0; !feof(f); ++i) {
		/// se tamanho alocado não foi estourado
		if(i+1 > maxLength) {
			/// dobra de tamanho alocado
			maxLength *= 2;
			/// realoca todo vetor
			newVet = (char **)realloc(newVet, sizeof(char *) * maxLength);
		}
		/// lê string no arquivo de entrada
		fscanf(f, " %s", str);
		/// aloca espaço para a string e armazena no vetor
		newVet[i] = strcpy(malloc(sizeof(char) * strlen(str) + 1), str);
	}

	/// realoca vetor para o tamanho final
	maxLength = i;
	newVet = (char **)realloc(newVet, sizeof(char *) * maxLength);

	*length = maxLength;
	/// retorna vetor
	return newVet;
}

/**
	@brief fprintStringVet printa em arquivo um vetor de strings
	@param f é o arquivo de saída
	@param vet é o vetor de strings
	@param length é o tamanho do vetor
	@precondition arquivo tem que estar aberto
	@postcondition nenhuma
*/
void fprintStringVet(FILE *f, char *vet[], int length) {
	int i;

	/// para cada string no vetor
	for(i = 0; i < length; ++i) {
		fprintf(f, "%s\n", vet[i]);
	}
}

/**
	@brief compareStringSorts compara e mostra os tempos entre os algoritimos
	@param vet é o vetor de strings
	@param length tamanho do vetor
	@precondition nenhuma
	@postcondition nenhuma
*/
void compareStringSorts(char *vet[], int length) {
	double timeTaken;

	/// pega o tempo de execução de cada algoritimo e printa na saida padrão

	timeTaken = getTimeTakenStr(Quicksort, vet, length);
	printf("QuickSort took 		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(Heap, vet, length);
	printf("HeapSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(Merge, vet, length);
	printf("MergeSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(Insertion, vet, length);
	printf("InsertionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(Selection, vet, length);
	printf("SelectionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(Bubble, vet, length);
	printf("BubbleSort took		%.4lf seconds.\n", timeTaken);
}
