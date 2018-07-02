#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "start.h"
#include "sorts.h"
#include "function_clock.h"

Arguments *readArguments(int argc, char const *argv[]) {
	Arguments *newArgs = (Arguments *)malloc(sizeof(Arguments));

	newArgs->numQuantity = 0;
	newArgs->sortName = NULL;
	newArgs->inputFileName = NULL;
	newArgs->outputFileName = NULL;

	newArgs->sortMode = argv[0][0];

	if(newArgs->sortMode == 'N') {
		newArgs->numQuantity = atoi(argv[1]);
	}
	if(newArgs->sortMode == 'C') {
		newArgs->inputFileName = (char*)argv[1];
	}

	if(argc > 2) {
		newArgs->sortName = (char*)argv[2];
		if(argc > 3) {
			newArgs->outputFileName = (char*)argv[3];
		}
	}

	return newArgs;
}

void sortModeNumeric(Arguments *args) {
	int *vet = newRandVet(args->numQuantity);
	int sortType = SORT_TYPE_COMPARE;
	FILE *outputFile = stdout;

	if(args->sortName)
		sortType = getSortType(args->sortName);
	if(args->outputFileName)
		outputFile = fopen(args->outputFileName, "w+");

	switch(sortType) {
		case SORT_TYPE_COMPARE: {
			compareNumericSorts(vet, args->numQuantity);
			return;
		}

		case SORT_TYPE_INSERTION: {
			fprintf(outputFile, "InsertionSort:\n");
			numericInsertionSort(vet, args->numQuantity);
			break;
		}

		case SORT_TYPE_SELECTION: {
			fprintf(outputFile, "SelectionSort:\n");
			numericSelectionSort(vet, args->numQuantity);
			break;
		}

		case SORT_TYPE_QUICKSORT: {
			fprintf(outputFile, "QuickSort:\n");
			numericQuickSort(vet, 0, args->numQuantity-1);
			break;
		}

		case SORT_TYPE_MERGE: {
			fprintf(outputFile, "MergeSort:\n");
			numericMergeSort(vet, 0, args->numQuantity);
			break;
		}

		case SORT_TYPE_HEAP: {
			fprintf(outputFile, "HeapSort:\n");
			numericHeapSort(vet-1, args->numQuantity);
			break;
		}

		case SORT_TYPE_BUBBLE: {
			fprintf(outputFile, "BubbleSort:\n");
			numericBubbleSort(vet, args->numQuantity);
			break;
		}

		default: {
			fprintf(outputFile, "invalid sort name (%s)\n", args->sortName);
			return;
		}
	}

	fprintNumericVet(outputFile, vet, args->numQuantity);
	free(vet);
}

int *newRandVet(int length) {
	int i;
	int *newVet = (int *)malloc(sizeof(int) * length);

	for (i = 0; i < length; ++i) {
		newVet[i] = rand() % MAXRAND;
	}

	return newVet;
}

void fprintNumericVet(FILE *f, int vet[], int length) {
	int i, j, index;

	for(i = 0; i < ceil((double)length/NUMBERS_PER_LINE); ++i) {
		for(j = 0; j < NUMBERS_PER_LINE && i*NUMBERS_PER_LINE + j < length; ++j) {
			index = i*NUMBERS_PER_LINE + j;
			fprintf(f, "%4d ", vet[index]);
		}
		fprintf(f, "\n");
	}
}

void compareNumericSorts(int vet[], int length) {
	double timeTaken;

	timeTaken = getTimeTaken(SORT_TYPE_QUICKSORT, vet, length);
	printf("QuickSort took 		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(SORT_TYPE_HEAP, vet, length);
	printf("HeapSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(SORT_TYPE_MERGE, vet, length);
	printf("MergeSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(SORT_TYPE_INSERTION, vet, length);
	printf("InsertionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(SORT_TYPE_SELECTION, vet, length);
	printf("SelectionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTaken(SORT_TYPE_BUBBLE, vet, length);
	printf("BubbleSort took		%.4lf seconds.\n", timeTaken);
}

int getSortType(char *sortName) {
	if(!strcmp(sortName, "insertionsort")) return SORT_TYPE_INSERTION;

	if(!strcmp(sortName, "selectionsort")) return SORT_TYPE_SELECTION;

	if(!strcmp(sortName, "quicksort")) return SORT_TYPE_QUICKSORT;

	if(!strcmp(sortName, "mergesort")) return SORT_TYPE_MERGE;

	if(!strcmp(sortName, "heapsort")) return SORT_TYPE_HEAP;

	if(!strcmp(sortName, "bubblesort")) return SORT_TYPE_BUBBLE;

	return SORT_TYPE_INVALID;
}

void sortModeString(Arguments *args) {
	char **vet;
	int length;
	int sortType = SORT_TYPE_COMPARE;
	FILE *outputFile = stdout;
	FILE *inputFile = stdin;

	if(args->sortName)
		sortType = getSortType(args->sortName);
	if(args->inputFileName)
		inputFile = fopen(args->inputFileName, "r+");
	if(args->outputFileName)
		outputFile = fopen(args->outputFileName, "w+");

	vet = readStringsInFile(inputFile, &length);

	switch(sortType) {
		case SORT_TYPE_COMPARE: {
			compareStringSorts(vet, length);
			return;
		}

		case SORT_TYPE_INSERTION: {
			fprintf(outputFile, "InsertionSort:\n");
			stringInsertionSort(vet, length);
			break;
		}

		case SORT_TYPE_SELECTION: {
			fprintf(outputFile, "SelectionSort:\n");
			stringSelectionSort(vet, length);
			break;
		}

		case SORT_TYPE_QUICKSORT: {
			fprintf(outputFile, "QuickSort:\n");
			stringQuickSort(vet, 0, length-1);
			break;
		}

		case SORT_TYPE_MERGE: {
			fprintf(outputFile, "MergeSort:\n");
			stringMergeSort(vet, 0, length);
			break;
		}

		case SORT_TYPE_HEAP: {
			fprintf(outputFile, "HeapSort:\n");
			stringHeapSort(vet-1, length);
			break;
		}

		case SORT_TYPE_BUBBLE: {
			fprintf(outputFile, "BubbleSort:\n");
			stringBubbleSort(vet, length);
			break;
		}

		default: {
			fprintf(outputFile, "invalid sort name (%s)\n", args->sortName);
			return;
		}
	}

	fprintStringVet(outputFile, vet, length);
	free(vet);
}

char **readStringsInFile(FILE *f, int *length) {
	int i, maxLength;
	char **newVet;
	char str[256];

	maxLength = 2;
	newVet = (char **)malloc(sizeof(char *) * maxLength);

	for(i = 0; !feof(f); ++i) {
		if(i+1 > maxLength) {
			maxLength *= 2;
			newVet = (char **)realloc(newVet, sizeof(char *) * maxLength);
		}
		fscanf(f, " %[^\n]%*c", str);
		newVet[i] = strcpy(malloc(sizeof(char) * strlen(str) + 1), str);
	}

	maxLength = i;
	newVet = (char **)realloc(newVet, sizeof(char *) * maxLength);

	*length = maxLength;
	return newVet;
}

void fprintStringVet(FILE *f, char *vet[], int length) {
	int i;

	for(i = 0; i < length; ++i) {
		fprintf(f, "%s\n", vet[i]);
	}
}

void compareStringSorts(char *vet[], int length) {
	double timeTaken;

	timeTaken = getTimeTakenStr(SORT_TYPE_QUICKSORT, vet, length);
	printf("QuickSort took 		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(SORT_TYPE_HEAP, vet, length);
	printf("HeapSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(SORT_TYPE_MERGE, vet, length);
	printf("MergeSort took		%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(SORT_TYPE_INSERTION, vet, length);
	printf("InsertionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(SORT_TYPE_SELECTION, vet, length);
	printf("SelectionSort took	%.4lf seconds.\n", timeTaken);

	timeTaken = getTimeTakenStr(SORT_TYPE_BUBBLE, vet, length);
	printf("BubbleSort took		%.4lf seconds.\n", timeTaken);
}
