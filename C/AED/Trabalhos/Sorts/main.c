#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "start.h"

/**
	@brief 
	@param 
	@precondition 
	@postcondition 
*/
int main(int argc, char const *argv[]) {
	Arguments *args = NULL;

	srand(time(NULL));

	/* argumentos passados na execução são carregados para
		uma estrutura */
	args = readArguments(argc-1, argv+1);

	/// modo de ordenação numérico
	if(args->sortMode == 'N') {
		/// chama função de controle do modo de ordenação numérico
		sortModeNumeric(args);
	}
	/// modo de execução por string
	if(args->sortMode == 'C') {
		/// chama função de controle do modo de ordenação por string
		sortModeString(args);
	}

	free(args);

	return 0;
}