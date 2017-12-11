#include <stdio.h>

#define MAXSTR 1024

int main(int argc, char const *argv[]) {
	char D[MAXSTR], S[MAXSTR], resistente = 1;
	int i, j;

	while(scanf("%[^\n]%*c%[^\n]%*c", D, S) != EOF) {
		for (i = 0; D[i] && resistente; ++i) {

			if(D[i] == S[0]) {
				resistente = 1;
				
				for (j = 0; S[j]; ++j) {
					if(!D[i+j] && D[i+j] != S[j]) resistente = 0;
				}

				if(resistente) {
					printf("[%s] in %s\n", S, &D[i]);
					printf("Resistente\n");
				} else {
					resistente = 0;
				}
			}
			if(!resistente) {
				printf("[%s] in %s\n", S, &D[i]);
				printf("Nao resistente\n");
			}
		}
	}

	return 0;
}