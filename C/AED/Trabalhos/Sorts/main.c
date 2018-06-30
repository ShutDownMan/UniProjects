#include <stdio.h>
#include <stdlib.h>

#include "start.h"

int main(int argc, char const *argv[]) {
	Arguments *args = NULL;

	args = readArguments(argc-1, argv+1);

	if(args->sortMode == 'N') {
		sortModeNumeric(args);
	}
	if(args->sortMode == 'C') {
		sortModeString(args);
	}

	free(args);

	return 0;
}